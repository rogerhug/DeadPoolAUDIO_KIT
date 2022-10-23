/*
  ==============================================================================

    playSampelFile.h
    Created: 17 May 2021 6:41:07pm
    Author:  Roger Hug

  ==============================================================================
*/

#pragma once


#include <JuceHeader.h>
#include"SamplerController.h"
#include"../resampler/resample.h"
#include"../filter/moog24db.h"
#include"../synth/SynthOscillator.h"
#include"../synth/ADSREnvelope.hpp"
#include"../echo/echogenerator.h"


constexpr auto SAMPLERATEAUDIO = 88200;
constexpr auto SAMPLERATESYNTH = 44100;
constexpr auto TABELSIZELFO = 512;
constexpr auto MAX_VOICES = 4;

class CParamSmooth
{
public:
    CParamSmooth() { a = 0.99; b = 1. - a; z = 0.; };
    ~CParamSmooth() {};
    inline double Process(double in) { z = (in * b) + (z * a); return z; }
private:
    double a, b, z;
};





class AudioSample
{
public:
    AudioSample();
    ~AudioSample();
    void init(int blocks, int spr);
    void setEngine(float e) { mEngine = int(e); }
    SynthOscillator oscillator;
    void setSynthPitchEnvelope(float e) { mSynthPitchEnv = e; }

    ADSREnvelope ampEG;
    ADSREnvelope ampEGF;
    ADSREnvelope ampEGP;
    float adsrP[50] = { 0 };
    void adsrparas(float* p,float m)
    {
        if (m == 0) {
            ampEG.setAttackDurationSeconds(p[1]);
            ampEG.setDecayDurationSeconds(p[2]);
            ampEG.sustainFraction = p[3];
            ampEG.setReleaseDurationSeconds(p[4]);
            ampEG.updateParams();
        }
        if (m == 1) {
            ampEGF.setAttackDurationSeconds(p[5]);
            ampEGF.setDecayDurationSeconds(p[6]);
            ampEGF.sustainFraction = p[7];
            ampEGF.setReleaseDurationSeconds(p[8]);
            ampEGF.updateParams();
 }

            if (m == 2) {
                ampEGP.setAttackDurationSeconds(p[9]);
                ampEGP.setDecayDurationSeconds(p[10]);
                ampEGP.sustainFraction = p[11];
                ampEGP.setReleaseDurationSeconds(p[12]);
              
                ampEGP.updateParams();
           
        }
           


    }
   
    void parasIn(ParasSamplerControll &mpc);

    moog24db moogF;
    echogeneratorModelClass *echo;

    void setWaveSize(int s) { waveSize = s; mp.setWaveSize(s); }
    void processAudioSampel(const int *trigger,float*Out,double *od,int nFrames);
    void processSynthSampel(const int*trigger,float*Out,double *out1,int nFrames);
    void processOut(const int* trigger,float*Out,int nFrames);

  
   
    void loadfile(int size,const double*in)
    {
       setWaveSize(size);
       memcpy(mAudioToResample, in,(size)*sizeof(double));

    }
   

   const int getWaveSize() { return mp.wavesize; }

   void oscilatorUpdate();


private:
    int mEngine;
    int waveSize;
    int mBlockSize;
    int mSamplRate;
    float mSynthPitchEnv;
    double data2;
    int mSampleIndx;
    unsigned int mSampelIndxPoly[32];
    WDL_Resampler mResampler;
    WDL_ResampleSample *resampledAudio=NULL;
    WDL_ResampleSample mAudioToResample[SAMPLERATEAUDIO];
    std::atomic<int> IcurrentPositionCount;
    std::atomic<int> IcurrentPositionCountDev;
    std::atomic<int> IcurrentPositionRate;
    std::atomic<int> IcurrentPositionTrigger;

    CParamSmooth SmootherSynth, SmootherSynthLevel, SmootherFilter , SmSpEnd ,SmSpVolume;

    ParasSamplerControll mp;

};
