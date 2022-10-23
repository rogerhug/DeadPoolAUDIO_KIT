/*
  ==============================================================================

    playSampelFile.cpp
    Created: 17 May 2021 6:41:07pm
    Author:  Roger Hug

  ==============================================================================
*/

#include "playSampelFile.h"
#include <math.h>
#include <algorithm>

#include "../resampler/resample.cpp"

AudioSample::AudioSample()

{

    waveSize=SAMPLERATEAUDIO/2;

    data2 = 0;
    mBlockSize = 512;
    mSamplRate = 44100;
    
   
    
    for(int i=0;i< MAX_VOICES;i++)
    {
        mSampelIndxPoly[i]=0;
 
    }

   
    mSynthPitchEnv = 0.5;
    // WDL_Resampler::SetMode arguments are bool interp, int filtercnt, bool sinc, int sinc_size, int sinc_interpsize
    // sinc mode will get better results, but will use more cpu
    // todo: explain arguments
    mResampler.SetMode(true, 0, false, 64, 32);
    mResampler.SetFilterParms();
    // set it output driven
    mResampler.SetFeedMode(false);
    // set input and output samplerates
    mResampler.SetRates(SAMPLERATESYNTH, SAMPLERATESYNTH);
    mSampleIndx = 0;
    mResampler.Reset();
    
    ampEG.updateParams();
    ampEG.init(0);
    ampEGF.updateParams();
    ampEGF.init(0);
    ampEGP.updateParams();
    ampEGP.init(0);
    moogF.init();
    echo =new echogeneratorModelClass();
    echo->initialize();
  


    oscilatorUpdate();
   
}

AudioSample::~AudioSample() {
    
    
}


void AudioSample::init(int block,int sp)
{
    oscillator.init();
    mResampler.Reset();
    mResampler.SetRates(SAMPLERATEAUDIO, SAMPLERATEAUDIO);
    mSampleIndx = 0;
    for (int i = 0; i < 7; i++)
        mSampelIndxPoly[i] = 0;
   memcpy(mAudioToResample,mp.getInitWave(), SAMPLERATESYNTH*sizeof(double));
    
    waveSize = SAMPLERATESYNTH;
    mSamplRate = sp;
    mBlockSize = block;
    oscillator.prepare(sp, block);
   
}
inline double fastClipSp(double x, double low, double high)
{
    double x1 = fabs(x - low);
    double x2 = fabs(x - high);
    x = x1 + low + high - x2;

    return x * 0.5;
}
inline float minmaxSPPitch(float a) {
    float result = 0; result = a;
    if (result > 4) { result = 4; }
    if (result < 0.1) { result = 0.1; }
    return result;
}

inline float minmax01(float a) {
    float result = 0; result = a;
    if (result > 1) { result = 1; }
    if (result < 0.0) { result = 0.0; }
    return result;
}

void AudioSample::parasIn(ParasSamplerControll &mpc)
{
    mp =mpc;
    if (int(mp.mEngineMode) == 0)
        oscilatorUpdate();
}

void AudioSample::processAudioSampel(const int *trigger,float*out, double* od,int nFrames)
{


    int swt = 0;
    
    const int sampelStart = mp.mSampleStart*  waveSize;
    const int sampelEnd =  mp.mSampleEnd* waveSize-10;
    const int sampelEndP = waveSize - 10;
 


 if (trigger[1]) {
        ampEG.start();	ampEGF.start(); ampEGP.start();
        
    }
    else {
        ampEG.release();	ampEGF.release(); ampEGP.release();
    }

    float mAmpeg = ampEG.getSample();
    float mPitchEg = ampEGP.getSample()*2;

    float Level = mp.mVolume ;

    

    float PitchIn = (0.1 + mp.mWaveHertz);
   
     if (mp.ModstepsAmp[0] > 0.1) {
      PitchIn *= (1 - mp.getStepOuts()[0]);
     
    }

     float mPitchPos = (mp.mWaveHertzEnv - 0.5) * 2;
     float mPitchNeg = 1 - ((mp.mWaveHertzEnv) * 2);

     if (mPitchPos > 0.1) {
         PitchIn*= 1+(ampEGP.getSample() * mPitchPos);
       
     }
     if (mPitchNeg > 0.1) {
         PitchIn*=1-(ampEGP.getSample() * mPitchNeg);

     }
    const int Pitch = minmaxSPPitch(PitchIn) *  getWaveSize()*2;
    
    mResampler.SetRates(Pitch , getWaveSize());

    const int rateSQ=trigger[2];
  
    int numSamples = mResampler.ResamplePrepare(nFrames,1,&resampledAudio);




    const int pCount=trigger[0];
    const int Trigger= trigger[1];
    const int Rate = trigger[2];
    const int CountPoly = trigger[4];
   


   

for (int s = 0; s < numSamples; s++)
{
  
    if (mSampleIndx++ >= sampelEnd)
        mSampleIndx =  sampelEnd;

    (mSampelIndxPoly[0]++);
    (mSampelIndxPoly[1]++);
    (mSampelIndxPoly[2]++);
    (mSampelIndxPoly[3]++);

      
   

    if (int(mp.mSamplePlayMode) == 1 && int(mp.mEngineMode) == 1) { //--------------looop mode 
        if (Trigger > 0)
            mSampleIndx = sampelStart;

        if (mSampleIndx >= sampelEnd)
            mSampleIndx =  sampelEnd;
        resampledAudio[s] = fastClipSp(mAudioToResample[mSampleIndx] * SmootherSynth.Process(double(Level+(Level*mAmpeg))), -1, 1);

    }
 
  //--------------oneShoot modePoly4voice-----------------

    if (int(mp.mSamplePlayMode) == 0 && int(mp.mEngineMode) == 1) { 
        swt = 0;
        swt += Trigger;
        if (swt > 0) { mSampelIndxPoly[CountPoly] = 0; swt -= 1; }

            resampledAudio[s] = fastClipSp((
            mAudioToResample[mSampelIndxPoly[0]] +
            mAudioToResample[mSampelIndxPoly[1]] +
            mAudioToResample[mSampelIndxPoly[2]] +
            mAudioToResample[mSampelIndxPoly[3]] 
      
            ) * SmootherSynth.Process(double(mAmpeg) * Level),-1,1);

         if (mSampelIndxPoly[0] >= sampelEndP)
            mSampelIndxPoly[0] = sampelEndP;
        if (mSampelIndxPoly[1] >= sampelEndP)
            mSampelIndxPoly[1] = sampelEndP;
        if (mSampelIndxPoly[2] >= sampelEndP)
            mSampelIndxPoly[2] = sampelEndP;
        if (mSampelIndxPoly[3] >= sampelEndP)
            mSampelIndxPoly[3] = sampelEndP;

            
    

   }
   }

         if (mResampler.ResampleOut(od, numSamples, nFrames, 1) != nFrames)
        {
            //failed somehow
            memset(od, 0, nFrames * sizeof(double));
        }
         for (int i = 0; i < nFrames; i++) {
             out[i] = od[i];

          //   data1 = out[i];

         }

   
     
   
    }

 

void AudioSample::processSynthSampel(const int *trigger, float *Out,double *out1, int nFrames)
{

   if(int(mp.mEngineMode)==0){
   
    float level =  mp.mVolume;
    const int pCount=trigger[0];
    const int Trigger=trigger[1];
    const int size=SAMPLERATESYNTH;

    if (trigger[1] > 0) {
        ampEG.start();	ampEGF.start(); ampEGP.start();
    }
    else {
        ampEG.release();	ampEGF.release(); ampEGP.release();
    }

    float mAmpeg =ampEG.getSample();
    float mPitch = mp.mSynthFrequency;
    float mPitchEg = 0;
    float mPitchPos = (mp.mSynthFrequencyEnv - 0.5) * 2;
    float mPitchNeg = 1-((mp.mSynthFrequencyEnv)*2) ;
  
    if (mp.ModstepsAmp[0] > 0.1) {

        oscillator.setFrequency(mPitch * (1- mp.getStepOuts()[0]));
    }
    if (mPitchPos > 0.1) {
        mPitchEg = ampEGP.getSample() * mPitchPos;
        oscillator.setFrequency(mPitch + ( 1*mPitchEg));
    }
    if (mPitchNeg > 0.1 ) {
        mPitchEg = ampEGP.getSample() * mPitchNeg;
       
        oscillator.setFrequency(mPitch -(1* mPitchEg));
    }
    oscillator.getSample();
    for (int s = 0; s < nFrames; s++)
    {
   //  Out[s] = fastClipSp(oscillator.getSample() *SmootherSynth.Process(mAmpeg*level),-1,1);
     Out[s] = fastClipSp(double(oscillator.getSample()) *(mAmpeg * (level)), -1, 1);
   // out1[s] = fastClipSp(oscillator.getSample() * SmootherSynth.Process(mAmpeg+level), -1, 1);
 
    }
 
    }
                                      
  
        
}
double outD[2048] = { 0 };
void AudioSample::processOut(const int *trigger, float *Out,  int nFrames)
{
    mp.setClockModulator(trigger[3]);


    if (mp.ModstepsAmp[1] > 0.1) {

        moogF.setCutoff((mp.mVcfCut) * (1 - double(mp.getStepOuts()[1])));
    }

    

    float mFilterEg = 0;
    if (mp.mVcfEnv > 0.1) {
        mFilterEg = ampEGF.getSample() * mp.mVcfEnv;
        moogF.setCutoff(mp.mVcfCut * mFilterEg);
    }

    if (mp.ModstepsAmp[3] > 0.1) {
        echo->mpe.setDelayTime(mp.mDlTime * (1 -mp.getStepOuts()[3]));
    }
    if (mp.ModstepsAmp[4] > 0.1) {
        echo->mpe.setDelayFeed(mp.mDlFeed * (1 - mp.getStepOuts()[4]));
    }
 

    if (int(mp.mEngineMode) == 1)
    {

         processAudioSampel(trigger, Out, outD, nFrames);

      
    }
    if(int(mp.mEngineMode)==0)
    {
     
       processSynthSampel(trigger,  Out,outD,nFrames);

    }
  
    float f = 0;
    for (int s = 0; s < nFrames; s++)
    { 
        if (mp.ModstepsAmp[2] > 0.1) {

       Out[s] *= (1 - double(mp.getStepOuts()[2]));
    }
    
     
       
        echo->step(Out[s],&Out[s]);
        f =  Out[s];
        if(int(mp.mVcfMode)==1)
         Out[s] = moogF.process(f);
        if (int(mp.mVcfMode) == 2)
        Out[s] -= moogF.process(f);
      
      
       // Out[s] *= SmSpVolume.Process(double(mp.mVolume)*(1-double(mp.getStepOuts()[2])));
        

    //     comp.step(Out[s], Out[s]);

        
        
    }
        
        
        
    
    
     
    
}


void AudioSample::oscilatorUpdate()
{
    oscillator.setFrequency(mp.mSynthFrequency);
    oscillator.setWaveform(mp.mSynthWaveForm);
}







