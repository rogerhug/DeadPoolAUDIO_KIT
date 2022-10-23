

#include "SynthOscillator.h"
#include <cmath>
#include "../JuceLibraryCode/JuceHeader.h"    // only for double_Pi constant

SynthOscillator::SynthOscillator() : phase(0) 
{
        mSampelRate = 44100;
        mWaveForm = 0;
        Bluenoise = new noiseModelClass();
        Bluenoise->initialize();
     
        mBufferWhiteNoise.resize(TABELSIZE*2);
        mBufferBlueNoise.resize(TABELSIZE*2);
        mBufferPinkNoise.resize(TABELSIZE*2);
        mBufferPurpleNoise.resize(TABELSIZE*2);

        sine1 =new double[TABELSIZE];
        SawD1= new double[TABELSIZE];
        SawU1= new double[TABELSIZE];
        Sqrt1= new double[TABELSIZE];
        for (int i = 0; i < TABELSIZE; i++)
        {
            sine1[i] = sin(i / (double)TABELSIZE * 2 * double_Pi);
            SawU1[i] =1- (i / (double)TABELSIZE * 2) ;
            SawD1[i] = -1+(i / (double)TABELSIZE  *2  );

            Sqrt1[i] = -0.5;
         if(i> TABELSIZE/4)
                Sqrt1[i] = 1;
         if (i > TABELSIZE / 2)
             Sqrt1[i] = -0.7;
            

         
        }
        CwSine = new CWTOsc(sine1, TABELSIZE);
        CwSawU = new CWTOsc(SawU1, TABELSIZE );
        CwSawD = new CWTOsc(SawD1, TABELSIZE);
        CwSqr = new CWTOsc(Sqrt1, TABELSIZE);
        
        Bluenoise->step(mBufferWhiteNoise.data(), mBufferBlueNoise.data()
            , mBufferPinkNoise.data(), mBufferPurpleNoise.data());
        for (int i = 0; i < TABELSIZE; i++)
        {
            mOscWhitenoise = new CWTOsc(mBufferWhiteNoise.data(), TABELSIZE);
            mOscBluenoise = new CWTOsc(mBufferBlueNoise.data(), TABELSIZE);
            mOscPinknoise = new CWTOsc(mBufferPinkNoise.data(), TABELSIZE);
            mOscPurplenoise = new CWTOsc(mBufferPurpleNoise.data(), TABELSIZE);
        }
        
      
     
      
  getForm(0);

}

void SynthOscillator::prepare(int samplerate, int blocksize)
{
    mSampelRate = samplerate;
    mBlockSize = blocksize;
    init();
}

void SynthOscillator::init()
{
    Bluenoise->initialize();
    Bluenoise->step(mBufferWhiteNoise.data(), mBufferBlueNoise.data()
        , mBufferPinkNoise.data(), mBufferPurpleNoise.data());
    CwSine->setLUT(sine1, mBlockSize);
    CwSawU->setLUT(SawU1, mBlockSize);
    CwSawD->setLUT(SawD1, mBlockSize);
    CwSqr->setLUT(Sqrt1, mBlockSize);
    getForm(0);
 
}

float SynthOscillator::getSample()
{
    
    const int waveform = mWaveForm;
    float sample = 0.0f;
    
    switch (waveform)
    {
    case 0:
        sample = CwSine->process(&mOsc1_ctx);
      
        break;
    case 1:
        sample = CwSawU->process(&mOsc1_ctx);
    
        break;
    case 2:
        sample = CwSawD->process(&mOsc1_ctx);
     
        break;
    case 3:
        sample = CwSqr->process(&mOsc1_ctx);
     
        break;
    case 4:
        sample= mOscWhitenoise->process(&mOsc1_ctx);
        break;
    case 5:
        sample= mOscBluenoise->process(&mOsc1_ctx);
        break;
    case 6:
        sample= mOscPinknoise->process(&mOsc1_ctx);
        break;
    case 7:
        sample= mOscPurplenoise->process(&mOsc1_ctx);
        break;
    default:
        break;
            
    }

 
   return sample;
}

const double* SynthOscillator::getForm(float f)
{
    const int n = f;
    if(n==0)
    return sine1;
    if (n == 1)
        return SawU1;
    if (n == 2)
        return SawD1;
    if (n == 3)
        return Sqrt1;
    if (n == 4)
        return mBufferWhiteNoise.data();
    if (n == 5)
        mBufferBlueNoise.data();
    if (n == 6)
        mBufferPinkNoise.data();
    if (n == 7)
        mBufferPurpleNoise.data();




}

