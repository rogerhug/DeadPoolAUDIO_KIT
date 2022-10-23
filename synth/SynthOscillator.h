
#pragma once

#include"../synth/noise.h"
#include"../synth/LfoGen.h"
#include <vector>

#include<JuceHeader.h>
#include <algorithm>

using namespace std;
#include<algorithm>

#define TABELSIZE  512


class OscParamSmooth
{
public:
    OscParamSmooth() { a = 0.99; b = 1. - a; z = 0.; };
    ~OscParamSmooth() {};
    inline float Process(float in) { z = (in * b) + (z * a); return z; }

private:
    double a, b, z;
};

class SynthOscillator
{

    
public:
    SynthOscillator();
 
   void prepare(int samperate, int blocksize);
   void init();
   void setWaveform(float f) {
       mWaveForm = f;
       
     
   }
   void setMainPitch(float mp) { mMainPitch = mp; }
   void setFrequencyEnv(float cyclesPerSample) {
      
      phaseDelta *= cyclesPerSample;
      setFrequency(phaseDelta);

   }
       void setFrequency(float cyclesPerSample) {
         
           note = (cyclesPerSample * 100);    

               phaseDelta = MidiMessage::getMidiNoteInHertz(note) / mSampelRate;
               mOsc1_ctx.mPhaseIncr = phaseDelta;

             
        
        }
   float getSample();

   const double* getForm(float f);
   
   private:
       int mSampelRate;
       int mBlockSize;
   
    OscParamSmooth smPitch;
    bool nState;
    int note;
    // -------------synth---------------
    float mWaveForm;
    float  mMainPitch;
    //--------------state---------------

    CWTOscState mOsc1_ctx;
    //--------------forms-----------
    CWTOsc* mOscWhitenoise;
    CWTOsc* mOscBluenoise;
    CWTOsc* mOscPinknoise;
    CWTOsc* mOscPurplenoise;

    CWTOsc* CwSine;
    double* sine1;

    CWTOsc* CwSawD;
    double* SawD1;

    CWTOsc* CwSawU;
    double* SawU1;

    CWTOsc* CwSqr;
    double* Sqrt1;
  
    noiseModelClass *Bluenoise;
  
    CWTOsc* mOscTimerUp;
    CWTOscState Timerup__ctx;
    float phase;           // [0.0, 1.0]
    float phaseDelta;    // cycles per sample (fraction)
 
    std::vector<double> mBufferWhiteNoise;
    std::vector<double> mBufferBlueNoise;
    std::vector<double> mBufferPinkNoise;
    std::vector<double> mBufferPurpleNoise;
    
  
    

};
