#include "SamplerController.h"


ParasSamplerControll::ParasSamplerControll()

{
    SpParasbus = new float[50];
   for (int i = 0; i < 50; i++)
        SpParasbus[i] = 0;
    AudioFile = { "not audiofile in slot load memory or drop.wav" };
    mEngineMode = 1;
    mEngineNumber = 0;
    mGate = 0.17;

    mVolume = 0.7;
    mVolumeMix = 1;
    mVolume_t = 0.7;

    mPitch_t = 0.5;
    mPitch_all = 0.5;
  
    mModulator = 0;
    mStepTime = 1;

    mTimes = 10;
    mMixerHide = 0;
    //---synth---

    mSynthWaveForm = 0;
    mSynthFrequency = 0.7;
    mSynthFrequencyEnv = 0.5;
    mSynthLevel = 0.5;
    mSynthLevelMod = 0.0;

    //------ADSR----------

    mAttack = 0.01;
    mDecay = 0.9;
    mSustain = 0.5;
    mRelease = 0.5;

    mAttackF = 0.01;
    mDecayF = 0.9;
    mSustainF = 0.5;
    mReleaseF = 0.5;

    mAttackP = 0.01;
    mDecayP = 0.9;
    mSustainP = 0.5;
    mReleaseP = 0.5;
  
    //   audio----
    wavesize = 44100;
    mWaveNumbr = 0.2;
    mWaveHertz = 0.5;
    mWaveHertzEnv = 0.5;
    mSampleSize = 44100;
    mSampleStart = 0;
    mSampleEnd = 0.9;
    mSamplePlayMode = 0;

    // ----filter

    mVcfMode = 0;
    mVcfCut = 0.95;
    mVcfRes = 0.1;
    mVcfEnv = 0;
  
    //-----delay

    mDlMode = 0.0;
    mDlTime = 0.5;
    mDlFeed = 0.5;
    mDlVol = 0.0;
    mDlWet = 0.0;
  

   Modsteps = new float[16];
   ModstepsAmp = new float[16];
   
    for (int i = 0; i < 16; i++) {

        Modsteps[i] = sin(i / (double)16 * double_Pi);;
        ModstepsAmp[i] = 0;
    }

    stepCount = 0;
 


}



void ParasSamplerControll::setWaveFile(String s)
{
    AudioFile = s;
}

void ParasSamplerControll::setAdsrParas(float* p)
{
    mAttack    = p[1];
    if (p[2] != 0) {   mDecay = p[2];    }
    if (p[3] != 0) {   mSustain = p[3];  }
    mRelease   = p[4];
   
    mAttackF = p[5];
    if (p[6] != 0) {  mDecayF = p[6];  }
    if (p[7] != 0) {  mSustainF = p[7]; }
    mReleaseF = p[8];

    mAttackP = p[9];
    if (p[9] != 0) {  mDecayP = p[9];  }
    if (p[10] != 0) { mSustainP = p[10]; }
    mReleaseP = p[11];


   
}

void ParasSamplerControll::setVolumeAll(float v, int n)
{ 
    if (n == mEngineNumber) {
      setVolume(mVolume_t*v);
     }
}

void ParasSamplerControll::setPitchAll(float p, int n)
{
    setWaveFileHertz((mPitch_t * (p * 2)));
    mPitch_all = p*2;
    if (n == mEngineNumber) {
        setWaveFileHertz((mPitch_t * (p*2)));
       // if(mEngineMode<1)
      //  setSynthHertz(0.1+(mPitch_t * p));
    }
}

const float* ParasSamplerControll::getParas()
{

    SpParasbus[1] = mEngineMode;
    SpParasbus[2] = mModulator;
    SpParasbus[3] = mWaveNumbr;
    SpParasbus[4] = mWaveHertz;
    SpParasbus[5] = mVolume;
    SpParasbus[6] = mGate;
    SpParasbus[7] = mSynthFrequencyEnv;
    SpParasbus[8] = mWaveHertzEnv;
    SpParasbus[9] = 0;
    SpParasbus[10] = mVcfEnv;
    SpParasbus[11] = mVcfMode;
    SpParasbus[12] = mVcfCut;
    SpParasbus[13] = mVcfRes;
    SpParasbus[14] = mDlMode;
    SpParasbus[15] = mDlTime;
    SpParasbus[16] = mDlFeed;
    SpParasbus[17] = mDlVol;
    SpParasbus[18] = mDlWet;
    SpParasbus[19] = mSynthWaveForm;
    SpParasbus[20] = mSynthFrequency;
    SpParasbus[21] = mSampleStart;
    SpParasbus[22] = mSampleEnd;
    SpParasbus[23] = mSamplePlayMode;
    SpParasbus[24] = 0;
    SpParasbus[25] = mTimes;


    return SpParasbus;
}

