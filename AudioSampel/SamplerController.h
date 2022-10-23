/*
  ==============================================================================

    SamplerController.h
    Created: 2 Jul 2022 5:53:56pm
    Author:  roger hug

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <math.h>
#include <algorithm>
//==============================================================================
/*
*/
struct ParasSamplerControll
{


    //-----main
    float mEngineMode;
    int mEngineNumber;
    float mVolume;
    float mVolume_t;
    float mVolumeMix;
    float mPitch_t;
    float mPitch_all;
    float mGate;
    float mModulator;
    float mTimes;
    float mMixerHide;
    //--------------synth-----
    float mSynthWaveForm;
    float mSynthFrequency;
    float mSynthFrequencyEnv;
    float mSynthLevel;
    float mSynthLevelMod;

    //--------------ADSR---------
    float mEnVelopeMode;

    float mAttack;
    float mDecay;
    float mSustain;
    float mRelease;

    float mAttackF;
    float mDecayF;
    float mSustainF;
    float mReleaseF;

    float mAttackP;
    float mDecayP;
    float mSustainP;
    float mReleaseP;


    //--------------audio------

    int wavesize;
    float mWaveNumbr;
    float mWaveHertz;
    float mWaveHertzEnv;
 
    float mSamplePlayMode;
    float mSampleStart;
    float mSampleEnd;
    float mSampleSize;

    //--------------filter

    float mVcfMode;
    float mVcfCut;
    float mVcfRes;
    float mVcfEnv;
    //-------------delay------

    float mDlMode;
    float mDlTime;
    float mDlFeed;
    float mDlVol;
    float mDlWet;



    //----------stepper----------
    int SeqCount;
    int stepCount;
    float mStepTime;
    float* Modsteps;
    float* ModstepsAmp;


    ParasSamplerControll();
   double initsine[44100] = { 0 };
    const double* getInitWave()
    { 
        double buffout[44100] = { 0 };
        const int tabelInit = 44100;
        for (int i = 0; i < tabelInit; i++) {
            initsine[i] = sin(i / (double)tabelInit * 441 * double_Pi);
            buffout[i] = 1 - (i / (double)tabelInit);
            initsine[i] *= buffout[i];
        }
        return initsine;
    }
    void setEngineNumber(int n) { mEngineNumber = n; }
    void setModulator(float n) { mModulator = n; }
    //------------------engine-------------------
    void setEnGineMode(float e) { mEngineMode = e;  }
    void setVolume(float v) { mVolume = v;   }
    void setGate(float g) {   mGate = g;  }
    //----------------oscilator------------------------
    void setSynthHertz(float h) { mSynthFrequency = h;  }
    void setSynthHertzEnvelope(float h) { mSynthFrequencyEnv = h;  }
    void setSynthOscMode(float m) { mSynthWaveForm = m;  }


    //------------------audio---------------------------------
    String AudioFile;
    void setWaveFile(String s);
    void setWaveSize(int s) { wavesize = s; }
    void setWaveNumr(float w) { mWaveNumbr = w; getWaveNr(); }
    const int getWaveNr() { return mWaveNumbr*63;  }
    void setWaveFileHertz(float h) { mWaveHertz = h;  }
    void setWaveHertzEnvelope(float h) { mWaveHertzEnv = h;  }
    void setWaveSizeDiv(float h) { mSampleSize = h; }
    void setWaveStart(float s) { mSampleStart = s;  }
    void setWaveENd(float e) { mSampleEnd = e;  }
    void setWavePlayMode(float m) { mSamplePlayMode = m;  }
   
   //---------------------ADSR------------------------
    void setAdsrMode(float m) { mEnVelopeMode = m; }
    void setAdsrParas(float* p);

    //-------------------filter------------------------
    void setFilterMode(float m) { mVcfMode = m;   }
    void setFilterCut(float c) { mVcfCut = c;     }
    void setFilterRes(float r) { mVcfRes = r;     }
    void setFilterEnv(float e) { mVcfEnv = e;     }

    //-------------------delay--------------

    void setDelayMode(float t) { mDlMode = t;  }
    void setDelayTime(float t) { mDlTime = t;  }
    void setDelayFeed(float t) { mDlFeed = t;  }
    void setDelayVolume(float t) { mDlVol = t;  }
    void setDelayMix(float t) { mDlWet = t;    }


    //-----------------------modulator-----------------------

    void setClockModulator(const int c) { stepCount = c; }
    void setInputSteps(const float* s)
    {
        memcpy(Modsteps, s, 16 * sizeof(float));
        getStepOuts();
    }
    void setInputstepAmps(const float* s)
    {
        memcpy(ModstepsAmp, s, 16 * sizeof(float));
        getStepOuts();
    }

    float modStepsout[10] = { 0,0,0,0,0,0,0,0 };
    float* getStepOuts()
    {
       

        modStepsout[0] = Modsteps[stepCount] * ModstepsAmp[0];//---pitch
        modStepsout[1] = Modsteps[stepCount] * ModstepsAmp[1];//---cut
        modStepsout[2] = Modsteps[stepCount] * ModstepsAmp[2];//---vol
        modStepsout[3] = Modsteps[stepCount] * ModstepsAmp[3];//---
        modStepsout[4] = Modsteps[stepCount] * ModstepsAmp[4];//---
        modStepsout[5] = Modsteps[stepCount] * ModstepsAmp[5];//---
        modStepsout[6] = Modsteps[stepCount] * ModstepsAmp[6];//---


        return modStepsout;
    }

    //*************************************mixer**************************
    void setVolume_t(float v) { mVolume_t = v; }
    void setVolumeAll(float v, int n);
    void setPitch_t(float v) { mPitch_t = v;  }
    void setPitchAll(float p, int n);

    void setMixer(float m) { mMixerHide = m; }

    const int getMixerHide() { return mMixerHide;}
    const bool getOscilatorHide() {
        if (int(mEngineMode) == 0)
            return true;
        if (int(mEngineMode) == 1)
            return false;
    }
      const bool getWaveFileHide() {
            if (int(mEngineMode) == 1)
                return true;
            if (int(mEngineMode) == 0)
                return false;
    }
    //---------------------------------

    const float* getParas();



private:
    float* SpParasbus;
};

