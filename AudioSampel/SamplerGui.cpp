/*
  ==============================================================================

    SamplerGui.cpp
    Created: 22 Jun 2022 4:37:37pm
    Author:  bruce

  ==============================================================================
*/

#include <JuceHeader.h>
#include "SamplerGui.h"

//==============================================================================
SamplerGui::SamplerGui(AudioProcessorValueTreeState& vts)
:mod1(vts)
,lastValue(0)
,valueTreeStateGui(vts)
,urls(vts)
, ParameterNr(0)
, mDown(false)

{


    UstateParas = new float[50];
    for (int i = 0; i < 50; i++)
        UstateParas[i] = 0;
    mpc = new ParasSamplerControll();
  

    test = 0;

    engineNb = 0;
 
    getOscVisible();
    Ktimes = 2;
    mTimes = 10;

    mMemoryValue = 0;
//---------------Envelopes------------

    busEnvelopes = new float[20];

    Kcolor = 0;
   
    addAndMakeVisible(mod1);
   
    mod1.setVisible(false);
    modulatorparas = new float[50];
    modulatorStepParas = new float[50];
    for (int i = 0; i < 50; i++) {
        modulatorparas[i] = 0;
        modulatorStepParas[i] = 0;
       
    }
    kenvSLiderNr = 0;
    for (int i = 0; i < 20; i++)
       // busEnvelopes[i] = 0;


        busEnvelopes[1] = 0;
        busEnvelopes[2] = 0.8;
        busEnvelopes[3] = 0.7;
        busEnvelopes[4] = 0.1;
        busEnvelopes[5] = 0;
        busEnvelopes[6] = 0.5;
        busEnvelopes[7] = 0.4;
        busEnvelopes[8] = 0.1;
        busEnvelopes[9] = 0;
        busEnvelopes[10] = 0.6;
        busEnvelopes[11] = 0.5;
        busEnvelopes[12] = 0.2;

   /*
        urls.loadInit1(valueTreeStateGui, 1);
     
        urls.loadInit2(valueTreeStateGui, 1);
        urls.loadInit3(valueTreeStateGui, 1);
        urls.loadInit4(valueTreeStateGui, 1);
        urls.loadInit5(valueTreeStateGui, 1);
        urls.loadInit6(valueTreeStateGui, 1);
        urls.loadInit7(valueTreeStateGui, 1);
        */
      //  bin.loadWaveFile(urls.getUrlNb(engineNb)[mpc->getWaveNr()].toString().toRawUTF8(), 1);
     //   mpc->setWaveSize(bin.getSampleLength());
   //     sampelout.loadfile(bin.getSampleLength(), bin.getSample());

     

}

SamplerGui::~SamplerGui()
{
}

void SamplerGui::mouseUp(const juce::MouseEvent& event)

{
    mDown = false;
}


const int top = 30;
const int posL = 20;


//-----buts osc/wave
const int posOscWaveButL = 10;
const int posOscWaveButT = top;
const int posOscWaveButW = 70;
const int posOscWaveButRow = 20;

//--------buts main/mod/timer---------
const int posMainbutsL = 10;
const int posMainbutsT = top+40;
const int posMainbutsH = 60;
const int posMainbutsW = 70;

//--------buts loop/seq -------
const int posOneShoot_L = 10;
const int posOneShoot_T = top+100;
const int posOneShoot_W = 70;
const int posOneShoot_H = 20;


//---------synth/samplerfunct----

const int posWaveFileL = 20;
const int posWaveFileT = 5;

const int posFunktionL = 110;
const int posFunktionT = top;
const int posFunktionW = 100;


const int posWaveStL = 110;
const int posWaveStT = top+120;
const int posWaveStW = 100;

const int posWaveEndL = 260;
const int posWaveEndT = top+120;
const int posWaveEndW = 100;


//---------envelope--------
const int posEVButL = 260;
const int posEVButT = top;
const int posEVButW = 130;

const int posEVSliderL = 260;
const int posEVSliderT = top+25;
const int posEVSliderW = 100;

//------------Vcf.--------------

const int posFilterModeL = 410;
const int posFilterModeT = top;
const int posFilterModeW = 130;

const int posFilteSliderL = 410;
const int posFilteSliderT = top+25;
const int posFilteSliderW = 100;

//------------delay-----------

const int posDelayRow = 20;
const int posDelayModeL = 570;
const int posDelayModeT = top;
const int posDelayModeW = 130;

const int posDelaySliderL = 570;
const int posDelaySliderT = top + posDelayRow+5;
const int posDelaySliderW = 100;


//-------------timers buts-------
const int gridT = 25;
const int gridW = 30;
const int gridSL = 580;
const int gridST = 10;
//------------modulator-----
const int posModL = 430;
// ------------memory but--------
const int posMembutL = 410;
const int posMembutT = 110;
const int posMembutW = 290;



void SamplerGui::mouseDown(const juce::MouseEvent& event)
{
    mDown = true;
  
    const int hightY = event.getPosition().getY();
    const int widthX = event.getPosition().getX();
    const int  hightGrSH = hightY ;
    const int hightGr = hightY;
    const int widthGr = widthX ;
  //------------------------------osc-wave-button---------------------------------------

 if (widthX > posOscWaveButL && widthX < posOscWaveButL + posOscWaveButW && hightY > posOscWaveButT && hightY < posOscWaveButT + 40) {
     ParameterNr = 1;
      mpc->mEngineMode = ((float(hightY) - posOscWaveButT) / 40)+0.5;
      valueChanged( mpc->mEngineMode);
      repaint(posOscWaveButL, posOscWaveButT, 700, 160);

    }

 else  
    //----------------------------------modulator hide but-----------

    if ( widthX > posMainbutsL && widthX < posMainbutsL + posMainbutsW && hightY > posMainbutsT && hightY < posMainbutsT+60) {
        ParameterNr = 2;
        mpc->mModulator = ((float(hightY) - posMainbutsT) / 60)*3;
        valueChanged(mpc->mModulator);
        repaint();
       
    }

    else//---------------------------------------SQtime 4,8,16-----------
        if (widthGr >  gridSL && widthGr < gridSL+130 && hightGr >gridST && hightGr < gridST + (gridT * 4) && int(mpc->mModulator) == 2)
        {


            ParameterNr = 25;
            if (widthGr >  gridSL && widthGr< gridSL+(gridW) && hightGrSH >gridST  && hightGrSH < gridT )
                mTimes = 0;
            if (widthGr > gridSL + (gridW) && widthGr< gridSL + (gridW*2) && hightGrSH >gridST  && hightGrSH < gridT )
                mTimes = 1;
            if (widthGr > gridSL+ (gridW * 2) && widthGr< gridSL+ (gridW * 3) && hightGrSH >gridST  && hightGrSH < gridT)
                mTimes = 2;
            if (widthGr > gridSL+ (gridW * 3) && widthGr< gridSL+ (gridW * 4) && hightGrSH >gridST && hightGrSH < gridT)
                mTimes = 3;
            if (widthGr > gridSL && widthGr< gridSL+ (gridW ) && hightGrSH >gridST+ gridT && hightGrSH < gridST + gridT *2)
                mTimes = 4;
            if (widthGr >  gridSL+ (gridW) && widthGr< gridSL+(gridW * 2) && hightGrSH >gridST + gridT && hightGrSH < gridST + gridT *2)
                mTimes = 5;
            if (widthGr > gridSL+ (gridW * 2) && widthGr< gridSL+ (gridW * 3) && hightGrSH >gridST + gridT && hightGrSH < gridST + gridT *2)
                mTimes = 6;
            if (widthGr > gridSL+ (gridW * 3) && widthGr< gridSL+ (gridW * 4) && hightGrSH >gridST + gridT && hightGrSH < gridST + gridT*2)
                mTimes = 7;
            if (widthGr >  gridSL && widthGr<  gridSL+ (gridW ) && hightGrSH >gridST + (gridT*2) && hightGrSH < gridST + gridT *3)
                mTimes = 8;
            if (widthGr > gridSL+ (gridW) && widthGr< gridSL+ (gridW * 2) && hightGrSH >gridST + (gridT * 2) && hightGrSH < gridST + gridT *3)
                mTimes = 9;
            if (widthGr > gridSL+ (gridW * 2) && widthGr< gridSL+ (gridW * 3) && hightGrSH >gridST + (gridT * 2) && hightGrSH < gridST + gridT *3)
                mTimes = 10;
            if (widthGr > gridSL+ (gridW * 3) && widthGr< gridSL+ (gridW * 4) && hightGrSH >gridST + (gridT * 2) && hightGrSH < gridST + gridT *3)
                mTimes = 11;
            if (widthGr > gridSL && widthGr< gridSL+ (gridW ) && hightGrSH >gridST + (gridT * 3) && hightGrSH < gridST + gridT *4)
                mTimes = 12;
            if (widthGr > gridSL+ (gridW ) && widthGr<  gridSL+(gridW * 2) && hightGrSH >gridST + (gridT * 3) && hightGrSH < gridST + gridT *4)
                mTimes = 13;
            if (widthGr >gridSL+ (gridW * 2) && widthGr< gridSL+(gridW * 3) && hightGrSH >gridST + (gridT * 3) && hightGrSH < gridST + gridT *4)
                mTimes = 14;
            if (widthGr > gridSL+ (gridW * 3) && widthGr <gridSL+(gridW * 4) && hightGrSH >gridST + (gridT * 3) && hightGrSH < gridST + gridT *4)
                mTimes = 15;
            ;
            repaint(gridSL, gridST, 150, 100);

            valueChanged(mTimes);
        }
   
    //------------------------wavesizemode------------------------
    /*
    if (widthX > posWaveStL && widthX < posWaveStL+130 && hightY > posWaveStT && hightY < posWaveStT +20 && engineMode == 1) {
        for (int i = 0; i < 4; i++)
       
        if (widthX > posWaveStL && widthX < posWaveStL+30)
            mWaveSize = 0;
        if (widthX > posWaveStL+30 && widthX < posWaveStL + 60)
            mWaveSize = 1;
        if (widthX > posWaveStL + 60 && widthX < posWaveStL + 90)
            mWaveSize = 2;
        if (widthX > posWaveStL + 90 && widthX < posWaveStL + 120)
            mWaveSize = 3;

        ParameterNr = 26;
        valueChanged(mWaveSize);
        
    }
    */
    //------------------------filtermode value-------------

    if (widthX > posFilterModeL && widthX < posFilterModeL+ posFilterModeW && hightY > posFilterModeT && hightY < posFilterModeT +20) {
      ParameterNr = 11;
       mpc->mVcfMode = ((float(widthX) - posFilterModeL) / posFilterModeW) * 3;
       valueChanged(mpc->mVcfMode);
      repaint(posFilterModeL, posFilterModeT, posFilterModeW+10, 30);
   
}
else//----------------------delaymode value------------------------

if (widthX > posDelayModeL && widthX < posDelayModeL+ posDelayModeW && hightY > posDelayModeT && hightY < posDelayModeT+20) {
   ParameterNr = 14;
    mpc->mDlMode = ((float(widthX) - posDelayModeL) / posDelayModeW) * 5;
    valueChanged(mpc->mDlMode);
    repaint(posDelayModeL, posDelayModeT, posDelayModeW+10, 25);
 
}
 else//-----------------------------------------------looop---oneshoot-------------------
            if ( widthX > posOneShoot_L &&  widthX < posOneShoot_L + posOneShoot_W && hightY >   posOneShoot_T && hightY < posOneShoot_T+20 && int( mpc->mEngineMode) == 1) {
                ParameterNr = 23;
                mpc->mSamplePlayMode = ((float(widthX)- posOneShoot_L)/ posOneShoot_W)+0.5;
                valueChanged(mpc->mSamplePlayMode);
                repaint(posOneShoot_L, 0, 400, 185);
               
            }
  else//--------------------------------envelope....mode.----
                if (widthX >posEVButL && widthX < posEVButL + posEVButW && hightY > posEVButT && hightY < posEVButT+20) {
                   ParameterNr = 27;
                    mpc->mEnVelopeMode = ((float(widthX) - posEVButL) / posEVButW) * 3;
                    valueChanged(mpc->mEnVelopeMode);
                    repaint(posEVButL, posEVButT, posEVButW+30, 130);
                
                }
       
//---------------------memory but------------------------------


    if (widthX > posMembutL && widthX < posMembutL + posMembutW && hightY > top + posMembutT && hightY < top + posMembutT + 40 && int( mpc->mEngineMode) == 1) {
        ParameterNr = 26;
        mMemoryValue = ((float(widthX) - posMembutL)/ posMembutW)*5;
        valueChanged(mMemoryValue);
         repaint(posMembutL, top + posMembutT, posMembutW+30,30);
         repaint(posWaveFileL, posWaveFileT, 600, 20);
           
    }


    
   // repaint();
}

void SamplerGui::mouseDrag(const MouseEvent& event)
{
    const int hightY = event.getPosition().getY();
    const int widthX = event.getPosition().getX();


   



   
    //------------------------
    if (widthX > posFunktionL && widthX < posFunktionL+ posFunktionW && hightY >  posFunktionT + 80 && hightY < posFunktionT + 100 && int( mpc->mEngineMode)==1) {
        ParameterNr = 3;
        mpc->mWaveNumbr = (float(widthX) - posFunktionL)/ posFunktionW;
       valueChanged(mpc->mWaveNumbr);
        repaint(posFunktionL,  posFunktionT + 80,  posFunktionW+30, 20);
        repaint(posWaveFileL, posWaveFileT, 600, 20);
    }
    else
        if (widthX > posFunktionL && widthX < posFunktionL + posFunktionW && hightY > posFunktionT + 40 && hightY < posFunktionT + 60 && int( mpc->mEngineMode) == 1) {
             ParameterNr = 4;
             mpc->mWaveHertz = (float(widthX) - posFunktionL) / posFunktionW;
            valueChanged(mpc->mWaveHertz);
            repaint(posFunktionL, posFunktionT +40, posFunktionW+30, 20);
         
        }
        else
            if (widthX > posFunktionL && widthX < posFunktionL + posFunktionW && hightY > posFunktionT + 60 && hightY < posFunktionT + 80 && int( mpc->mEngineMode) == 1) {
                ParameterNr = 9;
                mpc->mWaveHertzEnv = (float(widthX) - posFunktionL)/ posFunktionW;
                valueChanged(mpc->mWaveHertzEnv);
                repaint(posFunktionL, posFunktionT + 60, posFunktionW+30, 25);
             
            }
    else
    if (widthX > posWaveStL && widthX < posWaveStL + posWaveStW && hightY >posWaveStT && hightY < posWaveStT+20  && int( mpc->mEngineMode) == 1 && int(mpc->mSamplePlayMode)==1) {
        ParameterNr = 21;
        mpc->mSampleStart = (float(widthX) - posWaveStL)/ posWaveStW;
        valueChanged(mpc->mSampleStart);
        repaint(posWaveStL, posWaveStT, posWaveStW+30, 30);

    }
    else
        if (widthX > posWaveEndL  && widthX < posWaveEndL + posWaveEndW && hightY >posWaveEndT && hightY < posWaveEndT +20 && int( mpc->mEngineMode) == 1 && int(mpc->mSamplePlayMode) == 1) {
            ParameterNr = 22;
            mpc->mSampleEnd = (float(widthX)- posWaveEndL)/ posWaveEndW;
            valueChanged(mpc->mSampleEnd);
            repaint(posWaveEndL, posWaveEndT, posWaveEndW+30, 20);
       
        }
       
            else
    if (widthX > posFunktionL && widthX < posFunktionL+ posFunktionW && hightY >  posFunktionT + posMainbutsT + 40 && hightY < posFunktionT + posMainbutsT + 60 && int( mpc->mEngineMode) == 0) {
      ParameterNr = 19;
      mpc->mSynthWaveForm = ((float(widthX) - posFunktionL) / posFunktionW)*8;
        valueChanged(mpc->mSynthWaveForm);
        repaint(posFunktionL , posFunktionT + posMainbutsT + 40, posFunktionW+30, 20);
    }
    else
        if (widthX > posFunktionL && widthX < posFunktionL+ posFunktionW && hightY > posFunktionT +40 && hightY < posFunktionT +60 && int( mpc->mEngineMode) == 0) {
          ParameterNr = 20;
         mpc->mSynthFrequency = ((float(widthX) - posFunktionL) / posFunktionW);
          valueChanged(mpc->mSynthFrequency);
          repaint(posFunktionL , posFunktionT +40, 150, 20);
        }
        else
            if (widthX > posFunktionL && widthX < posFunktionL + posFunktionW && hightY > posFunktionT + 60 && hightY < posFunktionT + 80 && int( mpc->mEngineMode) == 0) {
                ParameterNr = 8;
                mpc->mSynthFrequencyEnv = ((float(widthX) - posFunktionL) / posFunktionW);
                valueChanged(mpc->mSynthFrequencyEnv);
                repaint(posFunktionL, posFunktionT + 60, posFunktionW+30, 20);
            }
    else
if (widthX > posFunktionL && widthX < posFunktionL+ posFunktionW && hightY > posFunktionT && hightY < posFunktionT +20) {
    ParameterNr = 5;
    mpc->mVolume = (float(widthX) - posFunktionL) / posFunktionW;
    valueChanged(mpc->mVolume);
    repaint(posFunktionL , posFunktionT, posFunktionW+30, 20);
}
else
if (widthX > posFunktionL && widthX < posFunktionL+ posFunktionW && hightY > posFunktionT +20 && hightY < posFunktionT +40 && int(mpc->mSamplePlayMode)==1) {
  ParameterNr = 6;
  mpc->mGate = (float(widthX) - posFunktionL)/ posFunktionW;
   valueChanged(mpc->mGate);
   repaint(posFunktionL, posFunktionT + 20, posFunktionW+30, 20);
} 
 
    
    //------------------------pos envelope slider-Y---------------------
    if (widthX > posEVSliderL && widthX < posEVSliderL + posEVSliderW && hightY > posEVSliderT && hightY < posEVSliderT + 80) {
        if (int(mpc->mEnVelopeMode) == 0)
            kenvSLiderNr = 1 + ((float(hightY) - posEVSliderT) / 80) * 4;//busADsr

        if (int(mpc->mEnVelopeMode) == 1)
            kenvSLiderNr = 5 + ((float(hightY) - posEVSliderT) / 80) * 4;

        if (int(mpc->mEnVelopeMode) == 2)
            kenvSLiderNr = 9 + ((float(hightY) - posEVSliderT) / 80) * 4;

    } 
    test = kenvSLiderNr;
//----------------------------------------envelopeAmp-----------------------
if (widthX > posEVSliderL && widthX < posEVSliderL+ posEVSliderW && hightY > posEVSliderT && hightY < posEVSliderT+80 && int(mpc->mEnVelopeMode)==0) {
     ParameterNr = 7;
    if (kenvSLiderNr == 1) {
        busEnvelopes[1] = (float(widthX) - posEVSliderL)/ posEVSliderW;
        valueChanged(busEnvelopes[1]);
        repaint(posEVSliderL, posEVSliderT, posEVSliderW+30, 20);
        }
    else
    if (kenvSLiderNr == 2) {
     busEnvelopes[2] = (float(widthX) - posEVSliderL) / posEVSliderW;
     valueChanged(busEnvelopes[2]);
     repaint(posEVSliderL, posEVSliderT + 20, posEVSliderW+30, 20);
    }
    else
    if (kenvSLiderNr == 3) {
     busEnvelopes[3] = (float(widthX) - posEVSliderL) / posEVSliderW;
    valueChanged(busEnvelopes[3]);
    repaint(posEVSliderL, posEVSliderT + 40, posEVSliderW+30, 20);
    
    }
    else
    if (kenvSLiderNr == 4) {
    busEnvelopes[4] = (float(widthX) - posEVSliderL) / posEVSliderW;
    valueChanged(busEnvelopes[4]);
    repaint(posEVSliderL, posEVSliderT + 60, posEVSliderW+30, 20);
    }

    GetAdsrParas();
}

else//----------------------------------------envelopefilter-----------------------
if (widthX > posEVSliderL && widthX < posEVSliderL + posEVSliderW && hightY > posEVSliderT && hightY < posEVSliderT + 80 && int(mpc->mEnVelopeMode) == 1) {
    ParameterNr = 7;
    if (kenvSLiderNr == 5) {
        busEnvelopes[5] = (float(widthX) - posEVSliderL) / posEVSliderW;
        valueChanged(busEnvelopes[5]);
        repaint(posEVSliderL, posEVSliderT, posEVSliderW+30, 20);
    }
    else
    if (kenvSLiderNr == 6) {
       busEnvelopes[6] = (float(widthX) - posEVSliderL) / posEVSliderW;
       valueChanged(busEnvelopes[6]);
       repaint(posEVSliderL, posEVSliderT + 20, posEVSliderW+30, 20);

    }
    else
    if (kenvSLiderNr == 7) {
       busEnvelopes[7] = (float(widthX) - posEVSliderL) / posEVSliderW;
       valueChanged(busEnvelopes[7]);
       repaint(posEVSliderL, posEVSliderT + 40, posEVSliderW+30, 20);

    }
    else
    if (kenvSLiderNr == 8) {
       busEnvelopes[8] = (float(widthX) - posEVSliderL) / posEVSliderW;
       valueChanged(busEnvelopes[8]);
       repaint(posEVSliderL, posEVSliderT + 60, posEVSliderW+30, 20);

    }
   
    GetAdsrParas();
}

else//----------------------------------------envelopefilter-----------------------
if (widthX > posEVSliderL && widthX < posEVSliderL + posEVSliderW && hightY > posEVSliderT && hightY < posEVSliderT + 80 && int(mpc->mEnVelopeMode) == 2) {
    ParameterNr = 7;
    if (kenvSLiderNr == 9) {
        busEnvelopes[9] = (float(widthX) - posEVSliderL) / posEVSliderW;
        valueChanged(busEnvelopes[9]);
        repaint(posEVSliderL, posEVSliderT, posEVSliderW + 30, 20);
    }

    else
    if (kenvSLiderNr == 10) {
        busEnvelopes[10] = (float(widthX) - posEVSliderL) / posEVSliderW;
        valueChanged(busEnvelopes[10]);
        repaint(posEVSliderL, posEVSliderT + 20, posEVSliderW+30, 20);
    }
    else
    if (kenvSLiderNr == 11) {
        busEnvelopes[11] = (float(widthX) - posEVSliderL) / posEVSliderW;
        valueChanged(busEnvelopes[11]);
        repaint(posEVSliderL, posEVSliderT + 40, posEVSliderW+30, 20);
      }
    else
    if (kenvSLiderNr == 12) {
      busEnvelopes[12] = (float(widthX) - posEVSliderL) / posEVSliderW;
       valueChanged(busEnvelopes[12]);
      repaint(posEVSliderL, posEVSliderT + 60, posEVSliderW+30, 20);

    }

    GetAdsrParas();
}

else
if (widthX > posFilteSliderL && widthX < posFilteSliderL + posFilteSliderW && hightY > posFilteSliderT && hightY < posFilteSliderT+25) {
    ParameterNr = 12;
    mpc->mVcfCut = (((float(widthX) - posFilteSliderL) / posFilteSliderW));
    valueChanged(mpc->mVcfCut);
    repaint(posFilteSliderL, posFilteSliderT, posFilteSliderW+30, 30);
}
else
if (widthX > posFilteSliderL && widthX < posFilteSliderL + posFilteSliderW && hightY > posFilteSliderT+20 && hightY < posFilteSliderT +40 ) {
    ParameterNr = 13;
    mpc->mVcfRes = (((float(widthX) - posFilteSliderL) / posFilteSliderW));
    valueChanged(mpc->mVcfRes);
    repaint(posFilteSliderL, posFilteSliderT + 20, posFilteSliderW+30, 25);
}
else
if (widthX > posFilteSliderL && widthX < posFilteSliderL + posFilteSliderW && hightY > posFilteSliderT + 40 && hightY < posFilteSliderT+ 60) {
     ParameterNr = 10;
     mpc->mVcfEnv = (((float(widthX) - posFilteSliderL) / posFilteSliderW));
     valueChanged(mpc->mVcfEnv);
    repaint(posFilteSliderL, posFilteSliderT + 40, posFilteSliderW+30, 30);
}
else
if (widthX >posDelaySliderL && widthX < posDelaySliderL + posDelaySliderW && hightY > posDelaySliderT && hightY < posDelaySliderT + 20 && int(mpc->mModulator)==0) {
    ParameterNr = 15;
    mpc->mDlTime = ((float(widthX) - posDelaySliderL) / posDelaySliderW);
    valueChanged(mpc->mDlTime);
    repaint(posDelayModeL, posDelaySliderT, posDelaySliderW+30, 20);
}
else
if (widthX > posDelaySliderL && widthX < posDelaySliderL +posDelaySliderW && hightY >posDelaySliderT +20 && hightY < posDelaySliderT + 40 && int(mpc->mModulator) == 0) {
    ParameterNr = 16;
    mpc->mDlFeed = ((float(widthX) - posDelaySliderL) / posDelaySliderW);
    valueChanged(mpc->mDlFeed);
    repaint(posDelayModeL, posDelaySliderT+20, posDelaySliderW+30, 20);

}
else
if (widthX > posDelaySliderL && widthX < posDelaySliderL + posDelaySliderW&& hightY >posDelaySliderT+40 && hightY < posDelaySliderT+60 && int(mpc->mModulator) == 0) {
    ParameterNr = 17;
    mpc->mDlVol = ((float(widthX) - posDelaySliderL) / posDelaySliderW);
    valueChanged(mpc->mDlVol);
    repaint(posDelaySliderL, posDelaySliderT+40, posDelaySliderW+30, 20);
}
else
if (widthX > posDelaySliderL && widthX < posDelaySliderL + posDelaySliderW && hightY > posDelaySliderT+60 && hightY < posDelaySliderT+80 && int(mpc->mModulator) == 0) {
    ParameterNr = 18;
    mpc->mDlWet = ((float(widthX) - posDelaySliderL) / posDelaySliderW);
    repaint(posDelaySliderL, posDelaySliderT+60, posDelaySliderW+30, 20);
    valueChanged(mpc->mDlWet);
}
//-******************************************************************************
else//----------------------------------modulator---------------------------
if (widthX > posModL && widthX < posModL+300 && hightY >top && hightY < top+130 && int(mpc->mModulator)==1) {
    if (widthX > posModL && widthX < posModL + 140) {
       // memcpy(modulatorStepParas, mod1.stepValuesOut(), 16 * sizeof(float));
       valueChanged(modulatorStepParas[0]);
     
    }
    if (widthX > posModL + 140 && widthX < posModL + 160) {
        modulatorparas[0] = mod1.mTimebut;
    }
    if (widthX > posModL + 200 && widthX < posModL + 300) {
       //memcpy(modulatorparas, mod1.stepModValues(), 10 * sizeof(float));
      
      
    }
  

    ParameterNr = 0;
    
}
///******************************************************************************


   




ParameterNr = -1;

}

void SamplerGui::resized()
{
    mod1.setBounds(posModL, top, 300, 160);
}

void SamplerGui::paint (juce::Graphics& g)
{
    g.setFont(juce::Font("Consolas", 14.0f, juce::Font::bold));
    auto colour1 = juce::Colours::silver;
    switch (Kcolor) {
    case 0:
        colour1 = juce::Colours::red;
        break;
    case 1:
        colour1 = juce::Colours::orange;
        break;
    case 2:
        colour1 = juce::Colours::orangered;
        break;
    case 3:
        colour1 = juce::Colours::green;
        break;
    case 4:
        colour1 = juce::Colours::greenyellow;
        break;
    case 5:
        colour1 = juce::Colours::yellowgreen;
        break;
    case 6:
        colour1 = juce::Colours::lightgoldenrodyellow;
        break;
    default:
        break;

    }
    g.setColour(juce::Colours::green);
  
    g.drawText(mpc->AudioFile.toRawUTF8(), posWaveFileL, posWaveFileT, 600, 20, juce::dontSendNotification);

   // g.fillAll(juce::Colours::black);
    // clear the background
    juce::Rectangle<float> areaB(5, 5, getWidth() -20, getHeight() - 10);
  //  g.fillRoundedRectangle(areaB,10);
    juce::Rectangle<float> area(0, 0, getWidth(), getHeight());
    g.setColour(colour1);
    g.drawRoundedRectangle(area, 10, 5);
    g.setFont(juce::Font("Consolas", 14.0f, juce::Font::bold));
    drawButts(g);
    drawSliders(g);
    
}


void SamplerGui::drawButts(juce::Graphics& g)
{

    auto colour1 = juce::Colours::white;
   

    auto textColour = juce::Colours::black;

 
    
 //------------------------------synth..wave---------button--------------

    g.setColour(Colours::lightgreen);
    g.fillRect(posOscWaveButL, posOscWaveButT +2, posOscWaveButW, 40);
    const int owb =  mpc->mEngineMode;
     g.setColour(colour1);
    const int but_onE = posOscWaveButT + (owb*20);
    g.fillRect(posOscWaveButL, but_onE+1, posOscWaveButW, 16);
    g.setColour(juce::Colours::black);
    for (int i = 0; i < 2; i++)
    g.drawRect(posOscWaveButL, posOscWaveButT + (i * 20), posOscWaveButW, 20,2);
    g.setColour(textColour);
    g.drawText("Oscilator", posOscWaveButL + 8, posOscWaveButT, posOscWaveButW, 20, juce::dontSendNotification);
    g.drawText("WaveFile", posOscWaveButL + 10, posOscWaveButT +20, posOscWaveButW, 20, juce::dontSendNotification);
   
    //---------------------------------but main  modulator  timer -------------------------

      g.setColour(Colours::lightgreen);
      g.fillRect(posMainbutsL,  posMainbutsT, posMainbutsW, 60);
      g.setColour(colour1);
      const int emodbut = (posMainbutsT)+ (20 * int(mpc->mModulator));
      g.fillRect(posMainbutsL, emodbut, posMainbutsW, 16);
      
    if (int(mpc->mModulator) == 0) 
        mod1.setVisible(false);
     if (int(mpc->mModulator) == 1) 
         mod1.setVisible(true);
     if (int(mpc->mModulator) == 2)
        mod1.setVisible(false);

    g.setColour(juce::Colours::black);
    for(int i=0;i<3;i++)
    g.drawRect(posMainbutsL, posMainbutsT+(i*20), posMainbutsW, 20,2);
    g.setColour(textColour);

    g.drawText("Main", posMainbutsL + 15, posMainbutsT, posMainbutsW, 20, juce::dontSendNotification);
    g.drawText("Modulator", posMainbutsL + 10,  posMainbutsT + 20, posMainbutsW, 20, juce::dontSendNotification);
    g.drawText("Timers", posMainbutsL + 15, posMainbutsT + 40, posMainbutsW, 20, juce::dontSendNotification);

    if (int( mpc->mEngineMode) == 1) {
     
       
        //-----------------------buttons wavesize------------------ 

        /*
        g.setColour(colour1);
        const int wszbut = posWaveStL +(32 * mWaveSize);
       g.fillRect(wszbut+2, posWaveStT +2, 32, 16);
  
        g.setColour(juce::Colours::white);
        for (int i = 0; i < 5; i++)
            g.drawRect(posWaveStL+1 , posWaveStT, i * 32, 18);
            g.setColour(textColour);
            g.drawText("1/1", posWaveStL+5, posWaveStT, 30, 20, juce::dontSendNotification);
            g.drawText("3/4", posWaveStL + 35, posWaveStT, 30, 20, juce::dontSendNotification);
            g.drawText("1/2", posWaveStL + 68, posWaveStT, 30, 20, juce::dontSendNotification);
            g.drawText("1/4", posWaveStL + 98, posWaveStT, 30, 20, juce::dontSendNotification);
            */


        //----------------------------------------buttons oneShoot/loop..--------------


        g.setColour(Colours::lightgreen);
        g.fillRect(posOneShoot_L, posOneShoot_T, posOneShoot_W, 18);
        const int mbwos = posOneShoot_W / 2;
            g.setColour(colour1);
            const int pmbut = (mbwos * int(mpc->mSamplePlayMode));
            g.fillRect(posOneShoot_L + pmbut, posOneShoot_T, mbwos, 16);
            g.setColour(juce::Colours::black);
            for (int i = 0; i < 2; i++)
                g.drawRect(posOneShoot_L +(i * mbwos), posOneShoot_T, mbwos, 20,2);
      
        g.setColour(textColour);
        g.drawText("1SHt", posOneShoot_L +5 , posOneShoot_T, 35, 20, juce::dontSendNotification);
        g.drawText("LOOp", posOneShoot_L  + 40, posOneShoot_T, 35, 20, juce::dontSendNotification);

    }

    //----------------------------------------buttons Adsrmode--------------
    g.setColour(Colours::lightgreen);
    const int btevw = float(posEVButW) / 3;
    g.fillRect(posEVButL, posEVButT, posEVButW, 20);

    g.setColour(colour1);
    const int egMbut = posEVButL + (btevw * int(mpc->mEnVelopeMode));
    g.fillRect(egMbut, posEVButT , btevw, 16);
    g.setColour(juce::Colours::darkgreen);
    for (int i = 0; i < 3; i++)
        g.drawRect(posEVButL+1  + i * btevw, posEVButT+1, btevw, 18,1);

    g.setColour(textColour);
    g.drawText("AMP", posEVButL + 10, posEVButT, btevw, 20, juce::dontSendNotification);
    g.drawText("VCF", posEVButL + 50, posEVButT, btevw, 20, juce::dontSendNotification);
    g.drawText("CV", posEVButL + 95, posEVButT, btevw, 20, juce::dontSendNotification);

    

    char readout2[50] = { "raedout" };
    sprintf(readout2, "%f %i", mpc->mSamplePlayMode, kenvSLiderNr);
    g.setColour(juce::Colours::white);
   // g.drawText(readout2, 10, 200, 200, 30, juce::dontSendNotification);
  

    if (int(mpc->mModulator) != 1) {

        const int fm = mpc->mVcfMode;

        //--------------------------------buts filtermode---------------------
       
        const int fbutw = posFilterModeW / 3;
        g.setColour(Colours::lightgreen);
        g.fillRect(posFilterModeL, posFilterModeT , posFilterModeW, 20);
        g.setColour(colour1);
        const int vcfbut = posFilterModeL + (fbutw * fm);
        g.fillRect(vcfbut , posFilterModeT, fbutw, 16);

        g.setColour(juce::Colours::darkgreen);
        for (int i = 0; i < 4; i++)
            g.drawRect(posFilterModeL+1, posFilterModeT+1, i * fbutw, 18,1);



        g.setColour(textColour);

        g.drawText("off", posFilterModeL + 10, posFilterModeT, fbutw, 20, juce::dontSendNotification);
        g.drawText("Lp", posFilterModeL + 50, posFilterModeT, fbutw, 20, juce::dontSendNotification);
        g.drawText("Hp", posFilterModeL + 95, posFilterModeT, fbutw, 20, juce::dontSendNotification);
        g.setColour(juce::Colours::white);
    }
  ;
            // -------------------------------buts delaymode-----------------------
            if(int(mpc->mModulator) == 0) {
            g.setColour(Colours::lightgreen);
             g.fillRect(posDelayModeL, posDelayModeT, posDelayModeW, 20);
            g.setColour(colour1);
            const int mdl = mpc->mDlMode;
            const int mdbs = posDelayModeW / 5;
            const int dlbut = posDelayModeL + (mdbs * mdl);
            g.fillRect(dlbut, top+1, mdbs, 17);

              g.setColour(juce::Colours::darkgreen);
                for (int i = 0; i < 6; i++)
                    g.drawRect(posDelayModeL+1, posDelayModeT+1, i * mdbs, 18,1);


                g.setColour(textColour);
                g.drawText("off", posDelayModeL+5, posDelayModeT, mdbs, 20, juce::dontSendNotification);
                g.drawText("F", posDelayModeL+31, posDelayModeT, mdbs, 20, juce::dontSendNotification);
                g.drawText("S", posDelayModeL+56, posDelayModeT, mdbs, 20, juce::dontSendNotification);
                g.drawText("M1", posDelayModeL+80, posDelayModeT, mdbs, 20, juce::dontSendNotification);
                g.drawText("M2", posDelayModeL+106, posDelayModeT, mdbs, 20, juce::dontSendNotification);

               

            
        }
    
      

    //------------------------------time mode buts----------------------------------
    if (int(mpc->mModulator) == 2) {
        mod1.setVisible(false);

        g.setColour(Colours::lightblue);
        g.fillRect(gridSL, gridST, 4* gridW, 4* gridT);
        g.setColour(Colours::white);
        for (int i = 0; i < 5; i++) {
            for (int y = 0; y < 5; y++) {

                g.drawRect(gridSL, gridST, i * gridW,  y*gridT );
             
            }
        }
        g.setColour(juce::Colours::antiquewhite);
            const int swtb = mTimes;
            switch (swtb) {
               
            case 0:
            g.fillRect(gridSL,  gridST, gridW, gridT);
            break;
            case 1:
                g.fillRect(gridSL+ (gridW), gridST, gridW, gridT);
                break;
            case 2:
                g.fillRect(gridSL+ (gridW * 2),  gridST, gridW, gridT);
                break;
            case 3:
                g.fillRect(gridSL+(gridW * 3),  gridST, gridW, gridT);
                break;
            case 4:
                g.fillRect(gridSL, gridST + (gridT ), gridW, gridT);
                break;
            case 5:
                g.fillRect(gridSL+ (gridW ), gridST + (gridT), gridW, gridT);
                break;
            case 6:
                g.fillRect(gridSL+ (gridW * 2), gridST + (gridT ), gridW, gridT);
                break;
            case 7:
                g.fillRect(gridSL+ (gridW * 3),  gridST + (gridT ), gridW, gridT);
                break;
            case 8:
                g.fillRect( gridSL, gridST + (gridT * 2), gridW, gridT);
                break;
            case 9:
                g.fillRect(gridSL+ (gridW ), gridST + (gridT * 2), gridW, gridT);
                break;
            case 10:
                g.fillRect(gridSL+ (gridW * 2),gridST + (gridT * 2), gridW, gridT);
                break;
            case 11:
                g.fillRect(gridSL+ (gridW * 3), gridST + (gridT * 2), gridW, gridT);
                break;
            case 12:
                g.fillRect(gridSL,  gridST + (gridT * 3), gridW, gridT);
                break;
            case 13:
                g.fillRect(gridSL+ (gridW),gridST + (gridT * 3), gridW, gridT);
                break;
            case 14:
                g.fillRect(gridSL+ (gridW * 2),gridST + (gridT * 3), gridW, gridT);
                break;
            case 15:
                g.fillRect(gridSL+ (gridW * 3),gridST + (gridT * 3), gridW, gridT);
                break;
            default:
                break;
            
            }
        
          
            g.setColour(textColour);
        g.drawText("4/1", gridSL,  gridST, gridW, gridT, juce::dontSendNotification);
        g.drawText("3/1", gridSL+ (gridW ), gridST, gridW, gridT, juce::dontSendNotification);
        g.drawText("2/1", gridSL+ (gridW * 2),  gridST, gridW, gridT, juce::dontSendNotification);
        g.drawText("1/1", gridSL+ (gridW * 3),  gridST, gridW, gridT, juce::dontSendNotification);
    
        g.drawText("1/2", gridSL,gridST + (gridT ), gridW, gridT, juce::dontSendNotification);
        g.drawText("1/3", gridSL+ (gridW ),gridST + (gridT ), gridW, gridT, juce::dontSendNotification);
        g.drawText("1/4", gridSL+ (gridW * 2),gridST + (gridT), gridW, gridT, juce::dontSendNotification);
        g.drawText("1/6", gridSL+ (gridW * 3),gridST + (gridT ), gridW, gridT, juce::dontSendNotification);

        g.drawText("1/8",gridSL,gridST + (gridT * 2), gridW, gridT, juce::dontSendNotification);
        g.drawText("1/12",gridSL+ (gridW), gridST + (gridT *2), gridW, gridT, juce::dontSendNotification);
        g.drawText("1/16",gridSL+ (gridW * 2), gridST + (gridT * 2), gridW, gridT, juce::dontSendNotification);
        g.drawText("1/24",gridSL+ (gridW * 3), gridST + (gridT * 2), gridW, gridT, juce::dontSendNotification);

        g.drawText("1/32", gridSL, gridST + (gridT * 3), gridW, gridT, juce::dontSendNotification);
        g.drawText("1/48", gridSL+ (gridW ), gridST + (gridT * 3), gridW, gridT, juce::dontSendNotification);
        g.drawText("1/64", gridSL+ (gridW * 2),gridST + (gridT * 3), gridW, gridT, juce::dontSendNotification);
        g.drawText("1/96", gridSL+ (gridW * 3),gridST + (gridT * 3), gridW, gridT, juce::dontSendNotification);
      

    }  
    //-----------------------------------Memory but-------------------------------
    if (int(mpc->mModulator) != 1 && int(mpc->mEngineMode) == 1) {
        const int Membut = mMemoryValue;
        const int MebW = posMembutW / 5;
        g.setColour(Colours::lightgreen);
        g.fillRect(posMembutL,  top + posMembutT, posMembutW, 20);

           g.setColour(juce::Colours::antiquewhite);
           g.fillRect(posMembutL + (Membut * MebW), top + posMembutT, MebW, 20);
           

           g.drawText("Wave_Pool init*64 slot", posMembutL , top + posMembutT-25, posMembutW, 20, juce::dontSendNotification);
           g.setColour(juce::Colours::black);
        
           g.drawText("0-M", posMembutL+5, top + posMembutT , 50, 20, juce::dontSendNotification);
           g.drawText("MEM1", posMembutL+ MebW+5,top+ posMembutT, 50, 20, juce::dontSendNotification);
           g.drawText("MEM2", posMembutL + (MebW*2)+5, top + posMembutT, 50, 20, juce::dontSendNotification);
           g.drawText("MEM3", posMembutL + (MebW * 3) + 5, top + posMembutT, 50, 20, juce::dontSendNotification);
           g.drawText("MEM4", posMembutL + (MebW * 4) + 5, top + posMembutT, 50, 20, juce::dontSendNotification);
           g.setColour(juce::Colours::black);
           for (int i = 0; i < 6; i++) 
            g.drawRect(posMembutL, top + posMembutT, i * MebW,  20,2);
           }
}

void SamplerGui::drawSliders(juce::Graphics& g)
{
    auto colour1 = juce::Colours::blueviolet;


    auto textColour = juce::Colours::white;

   

    if (int( mpc->mEngineMode) == 0) {

      
        char sn[3] = { "0" };
        sprintf(sn, "%i", int(mpc->mSynthWaveForm));
        const int syOm = (mpc->mSynthWaveForm * posFunktionW)/8;
        g.setColour(colour1);
        g.fillRect(posFunktionL, posFunktionT + posMainbutsT + 44, syOm, 12);
        g.setColour(juce::Colours::white);
        g.drawRect(posFunktionL, posFunktionT + posMainbutsT + 40, posFunktionW, 20);//--slider
        g.drawRect(posFunktionL+ posFunktionW, posFunktionT + posMainbutsT + 40, 30, 20);//------reader
        g.setColour(textColour);
        g.drawText("SynthOsc", posFunktionL+10, posFunktionT + posMainbutsT + 40, 100, 20, juce::dontSendNotification);
        g.drawText(sn, posFunktionL+ posFunktionW+10, posFunktionT + posMainbutsT + 40, 30, 20, juce::dontSendNotification);


        char sm[3] = { "0" };
        sprintf(sm, "%i", int(mpc->mSynthFrequency));
        const int syH = mpc->mSynthFrequency * posFunktionW;
        g.setColour(colour1);
        g.fillRect(posFunktionL, posFunktionT +44, syH, 12);
        g.setColour(juce::Colours::white);
        g.drawRect(posFunktionL, posFunktionT +40, posFunktionW, 20);
        g.drawRect(posFunktionL+ posFunktionW, posFunktionT +40, 30, 20);
        g.setColour(textColour);
        g.drawText("Synth-Tune", posFunktionL+20, posFunktionT +40, posFunktionW, 20, juce::dontSendNotification);
        g.drawText(MidiMessage::getMidiNoteName(
            syH, true, true, 4), posFunktionL+ posFunktionW, posFunktionT +40, 30, 20, juce::dontSendNotification);
        //  g.drawText(sm, 205, 35, 30, 20, juce::dontSendNotification);
 
        char sme[3] = { "0" };
        sprintf(sme, "%.1f",(mpc->mSynthFrequencyEnv-0.5));
        const int evhz = (mpc->mSynthFrequencyEnv* posFunktionW);
        g.setColour(colour1);
        
        if(mpc->mSynthFrequencyEnv - 0.5 < 0 )
       
        g.fillRect(posFunktionL+ evhz, posFunktionT + 64, (50 - evhz),  12);
        if (mpc->mSynthFrequencyEnv - 0.5 > 0)
            g.fillRect(posFunktionL + 50, posFunktionT + 64,  (evhz / 2), 12);
 
        g.setColour(juce::Colours::white);
 
        g.drawRect(posFunktionL, posFunktionT + 60, 100, 20);
        g.drawRect(posFunktionL + posFunktionW, posFunktionT + 60, 30, 20);
        g.setColour(textColour);
        g.drawText("EnvelopeHZ", posFunktionL+20, posFunktionT +60, 100, 20, juce::dontSendNotification);
        g.drawText(sme, posFunktionL + posFunktionW+2, posFunktionT + 60, 30, 20, juce::dontSendNotification);
  }

    if (int(mpc->mEnVelopeMode) == 0 ) {
        char ea[3] = { "0" };
        sprintf(ea, "%.1f", busEnvelopes[1]);
        const int kevaa = busEnvelopes[1] * posEVSliderW;
        g.setColour(colour1);
        g.fillRect(posEVSliderL, posEVSliderT + 4, kevaa, 12);
        g.setColour(juce::Colours::white);
        g.drawRect(posEVSliderL, posEVSliderT, posEVSliderW, 20);
        g.drawRect(posEVSliderL + posEVSliderW, posEVSliderT, 30, 20);
        g.setColour(textColour);
        g.drawText("Amp-Attack", posEVSliderL + 10, posEVSliderT, posEVSliderW, 20, juce::dontSendNotification);
        g.drawText(ea, posEVSliderL + posEVSliderW+ 5, posEVSliderT, 30, 20, juce::dontSendNotification);

        char ed[3] = { "0" };
        sprintf(ed, "%.1f", busEnvelopes[2]);
        const int kevda = busEnvelopes[2] * posEVSliderW;
        g.setColour(colour1);
        g.fillRect(posEVSliderL, posEVSliderT + 24, kevda, 12);
        g.setColour(juce::Colours::white);
        g.drawRect(posEVSliderL, posEVSliderT + 20, posEVSliderW, 20);
        g.drawRect(posEVSliderL + posEVSliderW, posEVSliderT + 20, 30, 20);
        g.setColour(textColour);
        g.drawText("Amp-Decay", posEVSliderL + 10, posEVSliderT + 20, posEVSliderW, 20, juce::dontSendNotification);
        g.drawText(ed, posEVSliderL + posEVSliderW+5, posEVSliderT + 20, 30, 20, juce::dontSendNotification);

        char es[3] = { "0" };
        sprintf(es, "%.1f", busEnvelopes[3]);
        const int kevsa = busEnvelopes[3] * posEVSliderW;
        g.setColour(colour1);
        g.fillRect(posEVSliderL, posEVSliderT + 44, kevsa, 12);
        g.setColour(juce::Colours::white);
        g.drawRect(posEVSliderL, posEVSliderT + 40, posEVSliderW, 20);
        g.drawRect(posEVSliderL + posEVSliderW, posEVSliderT + 40, 30, 20);
        g.setColour(textColour);
        g.drawText("Amp-Sustain", posEVSliderL + 10, posEVSliderT + 40, posEVSliderW, 20, juce::dontSendNotification);
        g.drawText(es, posEVSliderL + posEVSliderW+5, posEVSliderT + 40, 30, 20, juce::dontSendNotification);

        char er[3] = { "0" };
        sprintf(er, "%.1f", busEnvelopes[4]);
        const int kevra = busEnvelopes[4] * posEVSliderW;
        g.setColour(colour1);
        g.fillRect(posEVSliderL, posEVSliderT + 64, kevra, 12);
        g.setColour(juce::Colours::white);
        g.drawRect(posEVSliderL, posEVSliderT + 60, posEVSliderW, 20);
        g.drawRect(posEVSliderL + posEVSliderW, posEVSliderT + 60, 30, 20);
        g.setColour(textColour);
        g.drawText("Amp-Release", posEVSliderL + 10, posEVSliderT + 60, 100, 20, juce::dontSendNotification);
        g.drawText(er, posEVSliderL + posEVSliderW+5, posEVSliderT + 60, 30, 20, juce::dontSendNotification);

    }

    if (int(mpc->mEnVelopeMode) == 1) {
        char eaf[3] = { "0" };
        sprintf(eaf, "%.1f", busEnvelopes[5]);
        const int kevaf = busEnvelopes[5] * posEVSliderW;
        g.setColour(colour1);
        g.fillRect(posEVSliderL, posEVSliderT + 4, kevaf, 12);
        g.setColour(juce::Colours::white);
        g.drawRect(posEVSliderL, posEVSliderT, posEVSliderW, 20);
        g.drawRect(posEVSliderL + posEVSliderW, posEVSliderT, 30, 20);
        g.setColour(textColour);
        g.drawText("Vcf-Attack", posEVSliderL + 10, posEVSliderT, posEVSliderW, 20, juce::dontSendNotification);
        g.drawText(eaf, posEVSliderL + posEVSliderW+ 5, posEVSliderT, 30, 20, juce::dontSendNotification);

        char edf[3] = { "0" };
        sprintf(edf, "%.1f", busEnvelopes[6]);
        const int kevdf = busEnvelopes[6] * posEVSliderW;
        g.setColour(colour1);
        g.fillRect(posEVSliderL, posEVSliderT + 24, kevdf, 12);
        g.setColour(juce::Colours::white);
        g.drawRect(posEVSliderL, posEVSliderT + 20, posEVSliderW, 20);
        g.drawRect(posEVSliderL + posEVSliderW, posEVSliderT + 20, 30, 20);
        g.setColour(textColour);
        g.drawText("Vcf-Decay", posEVSliderL + 10, posEVSliderT + 20, posEVSliderW, 20, juce::dontSendNotification);
        g.drawText(edf, posEVSliderL + posEVSliderW+5, posEVSliderT + 20, 30, 20, juce::dontSendNotification);

        char esf[3] = { "0" };
        sprintf(esf, "%.1f", busEnvelopes[7]);
        const int kevsf = busEnvelopes[7] * posEVSliderW;
        g.setColour(colour1);
        g.fillRect(posEVSliderL, posEVSliderT + 44, kevsf, 12);
        g.setColour(juce::Colours::white);
        g.drawRect(posEVSliderL, posEVSliderT + 40, posEVSliderW, 20);
        g.drawRect(posEVSliderL + posEVSliderW, posEVSliderT + 40, 30, 20);
        g.setColour(textColour);
        g.drawText("Vcf-Sustain", posEVSliderL + 10, posEVSliderT + 40, posEVSliderW, 20, juce::dontSendNotification);
        g.drawText(esf, posEVSliderL + posEVSliderW+5, posEVSliderT + 40, 30, 20, juce::dontSendNotification);

        char erf[3] = { "0" };
        sprintf(erf, "%.1f", busEnvelopes[8]);
        const int kvcrf = busEnvelopes[8] * posEVSliderW;
        g.setColour(colour1);
        g.fillRect(posEVSliderL, posEVSliderT + 64, kvcrf, 12);
        g.setColour(juce::Colours::white);
        g.drawRect(posEVSliderL, posEVSliderT + 60, posEVSliderW, 20);
        g.drawRect(posEVSliderL + posEVSliderW, posEVSliderT + 60, 30, 20);
        g.setColour(textColour);
        g.drawText("vcf-Release", posEVSliderL + 10, posEVSliderT + 60, posEVSliderW, 20, juce::dontSendNotification);
        g.drawText(erf, posEVSliderL + posEVSliderW+5, posEVSliderT + 60, 30, 20, juce::dontSendNotification);

    }
    
    if (int(mpc->mEnVelopeMode) == 2) {
        char eap[3] = { "0" };
        sprintf(eap, "%.1f", busEnvelopes[9]);
        const int kevap = busEnvelopes[9] * posEVSliderW;
        g.setColour(colour1);
        g.fillRect(posEVSliderL, posEVSliderT + 4, kevap, 12);
        g.setColour(juce::Colours::white);
        g.drawRect(posEVSliderL, posEVSliderT, posEVSliderW, 20);
        g.drawRect(posEVSliderL + posEVSliderW, posEVSliderT, 30, 20);
        g.setColour(textColour);
        g.drawText("CV-Attack", posEVSliderL + 10, posEVSliderT, posEVSliderW, 20, juce::dontSendNotification);
        g.drawText(eap, posEVSliderL + posEVSliderW+5, posEVSliderT, 30, 20, juce::dontSendNotification);

        char edp[3] = { "0" };
        sprintf(edp, "%.1f", busEnvelopes[10]);
        const int kevdp = busEnvelopes[10] * posEVSliderW;
        g.setColour(colour1);
        g.fillRect(posEVSliderL, posEVSliderT + 24, kevdp, 12);
        g.setColour(juce::Colours::white);
        g.drawRect(posEVSliderL, posEVSliderT + 20, posEVSliderW, 20);
        g.drawRect(posEVSliderL + posEVSliderW, posEVSliderT + 20, 30, 20);
        g.setColour(textColour);
        g.drawText("CV-Decay", posEVSliderL + 10, posEVSliderT + 20, posEVSliderW, 20, juce::dontSendNotification);
        g.drawText(edp, posEVSliderL + posEVSliderW+5, posEVSliderT + 20, 30, 20, juce::dontSendNotification);

        char esp[3] = { "0" };
        sprintf(esp, "%.1f", busEnvelopes[11]);
        const int kevsp = busEnvelopes[11] * posEVSliderW;
        g.setColour(colour1);
        g.fillRect(posEVSliderL, posEVSliderT + 44, kevsp, 12);
        g.setColour(juce::Colours::white);
        g.drawRect(posEVSliderL, posEVSliderT + 40, posEVSliderW, 20);
        g.drawRect(posEVSliderL + posEVSliderW, posEVSliderT + 40, 30, 20);
        g.setColour(textColour);
        g.drawText("CV-Sustain", posEVSliderL + 10, posEVSliderT + 40, posEVSliderW, 20, juce::dontSendNotification);
        g.drawText(esp, posEVSliderL + posEVSliderW+5, posEVSliderT + 40, 30, 20, juce::dontSendNotification);

        char erp[3] = { "0" };
        sprintf(erp, "%.1f", busEnvelopes[12]);
        const int kevrp = busEnvelopes[12] * posEVSliderW;
        g.setColour(colour1);
        g.fillRect(posEVSliderL, posEVSliderT + 64, kevrp, 12);
        g.setColour(juce::Colours::white);
        g.drawRect(posEVSliderL, posEVSliderT + 60, posEVSliderW, 20);
        g.drawRect(posEVSliderL + posEVSliderW, posEVSliderT + 60, 30, 20);
        g.setColour(textColour);
        g.drawText("CV-Release", posEVSliderL + 10, posEVSliderT + 60, posEVSliderW, 20, juce::dontSendNotification);
        g.drawText(erp, posEVSliderL + posEVSliderW+5, posEVSliderT + 60, 30, 20, juce::dontSendNotification);

    }
  

    if (int( mpc->mEngineMode) == 1) {

        // -----------SamplerSound------
        const int nb = mpc->mWaveNumbr*64 ;
        char wn[3] = { "0" };
        sprintf(wn, "%.2i", nb);
        g.setColour(colour1);
        const int mwn = mpc->mWaveNumbr * posFunktionW;
        g.fillRect(posFunktionL, posFunktionT + 80 +4, mwn, 12);
        g.setColour(juce::Colours::white);
        g.drawRect(posFunktionL, posFunktionT + 80, 100, 20);
        g.drawRect(posFunktionL+ posFunktionW, posFunktionT + 80, 30, 20);

        g.setColour(textColour);
        g.drawText("WaveNumber", posFunktionL+10, posFunktionT + 80, 100, 20, juce::dontSendNotification);
        g.drawText(wn, posFunktionL+105, posFunktionT + 80, 30, 20, juce::dontSendNotification);


        char wh[3] = { "0" };
        sprintf(wh, "%.1f", mpc->mWaveHertz);
        g.setColour(colour1);
        const int mwh = mpc->mWaveHertz * posFunktionW;
        g.fillRect(posFunktionL, posFunktionT +44, mwh, 12);
        g.setColour(juce::Colours::white);
        g.drawRect(posFunktionL, posFunktionT +40, posFunktionW, 20);
        g.drawRect(posFunktionL+ posFunktionW, posFunktionT +40, 30, 20);
        g.setColour(textColour);
        g.drawText("Wave-Tune", posFunktionL+10, posFunktionT +40, 100, 20, juce::dontSendNotification);
        g.drawText(wh, posFunktionL+105, posFunktionT +40, 30, 20, juce::dontSendNotification);


  


        char whe[3] = { "0" };
        sprintf(whe, "%.1f", mpc->mWaveHertzEnv-0.5);
        g.setColour(colour1);
        const int meh = mpc->mWaveHertzEnv * posFunktionW;
        if (mpc->mWaveHertzEnv - 0.5 < 0)
        g.fillRect(posFunktionL+meh, posFunktionT + 64,50- meh, 12);
        if (mpc->mWaveHertzEnv - 0.5 > 0)
         g.fillRect(posFunktionL + 50, posFunktionT + 64,  meh/2, 12);
        g.setColour(juce::Colours::white);
        g.drawRect(posFunktionL, posFunktionT + 60, posFunktionW, 20);
        g.drawRect(posFunktionL + posFunktionW, posFunktionT + 60, 30, 20);
        g.setColour(textColour);
        g.drawText("-__EnV__+", posFunktionL + 20, posFunktionT + 60, 100, 20, juce::dontSendNotification);
        g.drawText(whe, posFunktionL + 105, posFunktionT + 60, 30, 20, juce::dontSendNotification);
       
        if (int(mpc->mSamplePlayMode) == 1) {


            char ws[10] = { "0" };
            sprintf(ws, "%.1f", mpc->mSampleStart);
            const int mwst = mpc->mSampleStart * posWaveStW;
            g.setColour(colour1);
            g.fillRect(posWaveStL, posWaveStT + 4, mwst, 12);
            g.setColour(juce::Colours::white);
            g.drawRect(posWaveStL, posWaveStT, posWaveStW, 20);
            g.drawRect(posWaveStL + posWaveStW, posWaveStT, 30, 20);
            g.setColour(textColour);
            g.drawText("WaveStart", posWaveStL + 10, posWaveStT, posWaveStW, 20, juce::dontSendNotification);
            g.drawText(ws, posWaveStL + 105, posWaveStT, 30, 20, juce::dontSendNotification);

            char we[10] = { "0" };
            sprintf(we, "%.1f", mpc->mSampleEnd);
            const int mwen = mpc->mSampleEnd * posWaveEndW;
            g.setColour(colour1);
            g.fillRect(posWaveEndL, posWaveEndT + 4, mwen, 12);
            g.setColour(juce::Colours::white);
            g.drawRect(posWaveEndL, posWaveEndT, posWaveEndW, 20);
            g.drawRect(posWaveEndL + posWaveEndW, posWaveEndT, 30, 20);
            g.setColour(textColour);
            g.drawText("WaveLenght", posWaveEndL + 10, posWaveEndT, posWaveEndW, 20, juce::dontSendNotification);
            g.drawText(we, posWaveEndL + 105, posWaveEndT, 30, 20, juce::dontSendNotification);
        }
    }



        char wv[3] = { "0" };
        sprintf(wv, "%.1f", mpc->mVolume);
        const int kVol = mpc->mVolume * posFunktionW;
        g.setColour(colour1);
        g.fillRect(posFunktionL, posFunktionT +4, kVol, 12);
        g.setColour(juce::Colours::white);
        g.drawRect(posFunktionL, posFunktionT, posFunktionW, 20);
        g.drawRect(posFunktionL+ posFunktionW, posFunktionT, 30, 20);
        g.setColour(textColour);
        g.drawText("Gain", posFunktionL+10, posFunktionT, posFunktionW, 20, juce::dontSendNotification);
        g.drawText(wv, posFunktionL+105, posFunktionT, 30, 20, juce::dontSendNotification);


        if (int(mpc->mSamplePlayMode) == 1) {
            char wg[3] = { "0" };
            sprintf(wg, "%.1f", mpc->mGate);
            const int mgt = mpc->mGate * posFunktionW;
            g.setColour(colour1);
            g.fillRect(posFunktionL, posFunktionT + 24, mgt, 12);
            g.setColour(juce::Colours::white);
            g.drawRect(posFunktionL, posFunktionT + 20, posFunktionW, 20);
            g.drawRect(posFunktionL + posFunktionW, posFunktionT + 20, 30, 20);
            g.setColour(textColour);
            g.drawText("Gate", posFunktionL + 10, posFunktionT + 20, 100, 20, juce::dontSendNotification);
            g.drawText(wg, posFunktionL + posFunktionW+5, posFunktionT + 20, 30, 20, juce::dontSendNotification);

        }


        //-----------------filter-----------------
            if (int(mpc->mModulator) !=1) {
            mod1.setVisible(false);


            char fc[3] = { "0" };
            sprintf(fc, "%.1f", mpc->mVcfCut);
            const int fcut = mpc->mVcfCut* (posFilteSliderW);
            g.setColour(colour1);
            g.fillRect(posFilteSliderL, posFilteSliderT +4, fcut, 12);
            g.setColour(juce::Colours::white);
            g.drawRect(posFilteSliderL, posFilteSliderT , posFilteSliderW, 20);
            g.drawRect(posFilteSliderL + posFilteSliderW, posFilteSliderT , 30, 20);
            g.setColour(textColour);
            g.drawText("Cutoff", posFilteSliderL +10, posFilteSliderT , 100, 20, juce::dontSendNotification);
            g.drawText(fc, posFilteSliderL + posFilteSliderW+5, posFilteSliderT, 30, 20, juce::dontSendNotification);

            char fr[3] = { "0" };
            sprintf(fr, "%.1f", mpc->mVcfRes);
            const int fres = mpc->mVcfRes* (posFilteSliderW);
            g.setColour(colour1);
            g.fillRect(posFilteSliderL , posFilteSliderT+22, fres, 16);
            g.setColour(juce::Colours::white);
            g.drawRect(posFilteSliderL, posFilteSliderT+20, posFilteSliderW, 20);
            g.drawRect(posFilteSliderL + posFilteSliderW, posFilteSliderT+20, 30, 20);
            g.setColour(textColour);
            g.drawText("Resonance", posFilteSliderL +10, posFilteSliderT+20, posFilteSliderW, 20, juce::dontSendNotification);
            g.drawText(fr, posFilteSliderL + posFilteSliderW+5, posFilteSliderT+20, 60, 20, juce::dontSendNotification);

            char fe[3] = { "0" };
            sprintf(fe, "%.1f", mpc->mVcfEnv);
            const int fem = mpc->mVcfEnv * (posFilteSliderW);
             g.setColour(colour1);
          
                g.fillRect(posFilteSliderL, posFilteSliderT + 42, fem, 16);
           

            g.setColour(juce::Colours::white);
            g.drawRect(posFilteSliderL, posFilteSliderT+40, posFilteSliderW, 20);
            g.drawRect(posFilteSliderL + posFilteSliderW, posFilteSliderT+40, 30, 20);
            g.setColour(textColour);
            g.drawText("EnVelope_+", posFilteSliderL +10, posFilteSliderT+40, posFilteSliderW, 20, juce::dontSendNotification);
            g.drawText(fe, posFilteSliderL + posFilteSliderW+5, posFilteSliderT+40, 60, 20, juce::dontSendNotification);

            //-------delay---------------
           }
            if (int(mpc->mModulator) == 0) {
                char dt[3] = { "0" };
                sprintf(dt, "%.1f", mpc->mDlTime);
                const int dti = mpc->mDlTime * 99;
                g.setColour(colour1);
                g.fillRect(posDelaySliderL, posDelaySliderT+5, dti, 10);
                g.setColour(juce::Colours::white);
                g.drawRect(posDelaySliderL, posDelaySliderT, posDelaySliderW, 20);
                g.drawRect(posDelaySliderL + posDelaySliderW, posDelaySliderT, 30, 20);
                g.setColour(textColour);
                g.drawText("DelayTm", posDelaySliderL + 10, posDelaySliderT, 100, 20, juce::dontSendNotification);
                g.drawText(dt, posDelaySliderL + 105, posDelaySliderT, 30, 20, juce::dontSendNotification);

                char df[3] = { "0" };
                sprintf(df, "%.1f", mpc->mDlFeed);
                const int dfi = mpc->mDlFeed * 99;
                g.setColour(colour1);
                g.fillRect(posDelaySliderL, posDelaySliderT+25, dfi, 10);
                g.setColour(juce::Colours::white);
                g.drawRect(posDelaySliderL, posDelaySliderT+20, 100, 20);
                g.drawRect(posDelaySliderL + posDelaySliderW, posDelaySliderT+20, 30, 20);
                g.setColour(textColour);
                g.drawText("DelayFeed", posDelaySliderL + 10, posDelaySliderT+20, 100, 20, juce::dontSendNotification);
                g.drawText(df, posDelaySliderL + 105, posDelaySliderT+20, 30, 20, juce::dontSendNotification);

                char dv[3] = { "0" };
                sprintf(dv, "%.1f", mpc->mDlVol);
                const int dfv = mpc->mDlVol * 99;
                g.setColour(colour1);
                g.fillRect(posDelaySliderL, posDelaySliderT+45, dfv, 10);
                g.setColour(juce::Colours::white);
                g.drawRect(posDelaySliderL, posDelaySliderT+40, posDelaySliderW, 20);
                g.drawRect(posDelaySliderL + posDelaySliderW, posDelaySliderT+40, 30, 20);
                g.setColour(textColour);
                g.drawText("DelayVol", posDelaySliderL+10, posDelaySliderT+40, posDelaySliderW, 20, juce::dontSendNotification);
                g.drawText(dv, posDelaySliderL + posDelaySliderW+5, posDelaySliderT+40, 30, 20, juce::dontSendNotification);

                char dw[3] = { "0" };
                sprintf(dw, "%.1f", mpc->mDlWet);
                const int dfw = mpc->mDlWet * 99;
                g.setColour(colour1);
                g.fillRect(posDelaySliderL, posDelaySliderT+65, dfw, 10);
                g.setColour(juce::Colours::white);
                g.drawRect(posDelaySliderL, posDelaySliderT+60, posDelaySliderW, 20);
                g.drawRect(posDelaySliderL + posDelaySliderW, posDelaySliderT+60, 30, 20);
                g.setColour(textColour);
                g.drawText("DelayWed", posDelaySliderL+10, posDelaySliderT+60, posDelaySliderW, 20, juce::dontSendNotification);
                g.drawText(dw, posDelaySliderL + posDelaySliderW+5, posDelaySliderT+60, 30, 20, juce::dontSendNotification);
            }
    

}
void SamplerGui::initGui()
{ 
    
   
    memcpy(UstateParas, mpc->getParas(), 50 * sizeof(float));
    
    mMemoryValue = 0;

    Ktimes = mpc->mTimes;


   mpc->mEnVelopeMode = 0;
   busEnvelopes[1] = mpc->mAttack;
   busEnvelopes[2] = mpc->mDecay;
   busEnvelopes[3] = mpc->mSustain;
   busEnvelopes[4] = mpc->mRelease;

    repaint();
 
}
char serialParaValues[150] = { 0 };
char serialAdsrValues[65] = { 0 };
char stateN[50] = { "" };

String Uname = { "-" };
String UnameE = { "-" };

void SamplerGui::updateMixer(ParasSamplerControll& mpm,int n,int sp)

{ 
   mpc->setEngineNumber(sp);
   

    if (n == 0) {
      
        mpc->setVolume_t(mpm.mVolume);
        mpc->setVolume(mpm.mVolume);
       repaint(posFunktionL, top, 150, 20);

 }
    if (n == 1) {
        mpc->setPitch_t(mpm.mWaveHertz-0.1);
        mpc->setWaveFileHertz(mpm.mWaveHertz-0.1);
       //mpc->setSynthHertz(mpm.mSynthFrequency-0.1);
        mpc->mWaveHertz = mpm.mWaveHertz-0.1;
        sampelout.parasIn(*mpc);
            repaint(posFunktionL, top + 40, 150, 20);
    }
        if (n == 2) {
         
            mpc->setWaveNumr(mpm.mWaveNumbr);
            bin.loadWaveFile(urls.getUrlNb(engineNb)[mpc->getWaveNr()].toString().toRawUTF8(), 1);
            mpc->setWaveSize(bin.getSampleLength());
            sampelout.loadfile(bin.getSampleLength(), bin.getSample());
            urls.serial1(valueTreeStateGui, urls.getUrlNb(engineNb)[mpc->getWaveNr()].toString(), mpc->getWaveNr(), engineNb);
            repaint(posFunktionL, top + posMainbutsT + 40, 150, 20);
        }

        if (n == 3) {

            mpc->mDlWet = mpm.mDlWet;
            mpc->mDlWet = mpm.mDlWet;
            repaint(posDelayModeL, top + 80, 150, 20);
        }

        if (mpm.getMixerHide() == 4) {
            mpc->mGate = mpm.mGate;
            repaint(posFunktionL, top + 20, 150, 20);
        }
        sampelout.parasIn(*mpc);

   



}

void SamplerGui::serialParas(AudioProcessorValueTreeState& valueTreeState ,String name)
{   

    Uname = name;
    UnameE = name+"Adsr";


    float x = 0.00;
    sprintf(serialParaValues,
        
        "%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f"
        ,x,  mpc->mEngineMode,mpc->mModulator, mpc->mWaveNumbr, mpc->mWaveHertz,mpc->mVolume,mpc->mGate, mpc->mSynthFrequencyEnv, mpc->mWaveHertzEnv,x
        ,mpc->mVcfEnv,mpc->mVcfMode,mpc->mVcfCut,mpc->mVcfRes, mpc->mDlMode,mpc->mDlTime,mpc->mDlFeed,mpc->mDlVol,mpc->mDlWet,mpc->mSynthWaveForm,mpc->mSynthFrequency
        ,mpc->mSampleStart,mpc->mSampleEnd,mpc->mSamplePlayMode,x,mTimes/10,x

        );
        valueTreeState.state.setProperty(Uname, var(serialParaValues), nullptr);
        SPStateParas.setValue(var(serialParaValues));
        sprintf(serialAdsrValues, "%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f"
            ,x, busEnvelopes[1], busEnvelopes[2], busEnvelopes[3], busEnvelopes[4]
            , busEnvelopes[5], busEnvelopes[6], busEnvelopes[7], busEnvelopes[8]
            , busEnvelopes[9], busEnvelopes[10], busEnvelopes[11], busEnvelopes[12]
        );
        valueTreeState.state.setProperty(name+"Adsr", var(serialAdsrValues), nullptr);
          SPAdsrParas.setValue(var(serialAdsrValues));
}


void SamplerGui::unSerialParas(AudioProcessorValueTreeState& valueTreeState, String n)
{
   
    float outP = 0;
   // mod1.unSerialStepps(valueTreeState);
        SPStateParas.referTo(valueTreeState.state.getPropertyAsValue(n, nullptr, true));
        for (int i = 0; i <= 125; i += 5) {
            UstateParas[i / 5] = SPStateParas.getValue().toString().substring(i, i + 4).getFloatValue();
        }
        
        getOscVisible();
        mpc->setEnGineMode(UstateParas[1]);

        mpc->setModulator(UstateParas[2]);
        mpc->setWaveNumr(UstateParas[3]);
        mpc->setWaveFileHertz(UstateParas[4]);

        mpc->setPitch_t(mpc->mWaveHertz);
        mpc->setVolume(UstateParas[5]);
        mpc->setGate(UstateParas[6]);

   
        mpc->setSynthHertzEnvelope(UstateParas[7]);
 
        mpc->mWaveHertzEnv = UstateParas[8];
        mpc->setWaveHertzEnvelope(UstateParas[8]);
        outP = UstateParas[9];


        mpc->setFilterEnv(UstateParas[10]);
        mpc->setFilterMode(UstateParas[11]);
        mpc->setFilterCut(UstateParas[12]);
        sampelout.moogF.setCutoff(UstateParas[12]);
        mpc->setFilterRes(UstateParas[13]);
        sampelout.moogF.setRes(UstateParas[13]);
       


        mpc->setDelayMode(UstateParas[14]);
        sampelout.echo->mpe.setDelayMode(UstateParas[14]);
        mpc->setDelayTime(UstateParas[15]);
        sampelout.echo->mpe.setDelayTime(UstateParas[15]);
        mpc->setDelayFeed(UstateParas[16]);
        sampelout.echo->mpe.setDelayFeed(UstateParas[16]);
        mpc->setDelayVolume(UstateParas[17]);
        sampelout.echo->mpe.setDelayLevel(UstateParas[17]);
        mpc->setDelayMix(UstateParas[18]);
        sampelout.echo->mpe.setDelayMix(UstateParas[18]);


       
        mpc->setSynthOscMode(UstateParas[19]);
        sampelout.oscillator.setWaveform(UstateParas[19]);

        mpc->setSynthHertz(UstateParas[20]);


        mpc->setWaveStart(UstateParas[21]);

        mpc->setWaveENd(UstateParas[22]);
        mpc->setWavePlayMode(UstateParas[23]);
  
   
        Ktimes    = UstateParas[25]*10 ;
        outP = UstateParas[26];
        mMemoryValue = 0;


        SPAdsrParas.referTo(valueTreeState.state.getPropertyAsValue(UnameE, nullptr, true));
        for (int i = 0; i < 65; i+=5) {
            busEnvelopes[i / 5] = SPAdsrParas.getValue().toString().substring(i, i + 4).getDoubleValue();

            sampelout.ampEG.setAttackDurationSeconds(busEnvelopes[1]);
            sampelout.ampEG.setDecayDurationSeconds(busEnvelopes[2]);
            sampelout.ampEG.sustainFraction = busEnvelopes[3];
            sampelout.ampEG.setReleaseDurationSeconds(busEnvelopes[4]);

           sampelout.ampEGF.setAttackDurationSeconds(busEnvelopes[5]);
           sampelout.ampEGF.setDecayDurationSeconds(busEnvelopes[6]);
           sampelout.ampEGF.sustainFraction = busEnvelopes[7];
           sampelout.ampEGF.setReleaseDurationSeconds(busEnvelopes[8]);

           sampelout.ampEGP.setAttackDurationSeconds(busEnvelopes[9]);
           sampelout.ampEGP.setDecayDurationSeconds(busEnvelopes[10]);
           sampelout.ampEGP.sustainFraction = busEnvelopes[11];
           sampelout.ampEGP.setReleaseDurationSeconds(busEnvelopes[12]);
        }
        sampelout.ampEG.updateParams();
        sampelout.ampEGF.updateParams();
        sampelout.ampEGP.updateParams();
       

        urls.unserial(valueTreeState, engineNb);
        UrlUpdateFiles();
        
        sampelout.oscilatorUpdate(); 
        sampelout.oscillator.setFrequency(mpc->mSynthFrequency);
        sampelout.oscillator.setFrequencyEnv(mpc->mSynthFrequencyEnv);
     
        
        loadSample(urls.getUrlNb(int(mpc->mEngineNumber))[mpc->getWaveNr()].toString());//urls
        mpc->AudioFile = urls.getUrlNb(int(mpc->mEngineNumber))[mpc->getWaveNr()].toString();

        mod1.getStepOutValues();
        mod1.getStepOutValuesAmp();
        mpc->getStepOuts();
        ModulatorParasUpdate();
        sampelout.parasIn(*mpc);
        
      
               //------Synth
        repaint();
        GetParas();
}

const float* SamplerGui::GetParas()
{
    return UstateParas;
}




bool SamplerGui::getOscVisible()
{
    if(int( mpc->mEngineMode)==1)
    return false;
    if (int( mpc->mEngineMode) ==0)
    return true;

}

void SamplerGui::valueChanged(float newValue)
{
    if (lastValue == newValue)
        return;
    lastValue = newValue;

    switch (GetParaNr()) {
    case 0:

        break;
    case 1:
        
        mpc->mEngineMode = lastValue;
        mpc->setEnGineMode(mpc->mEngineMode);
        mod1.setEngine(mpc->mEngineMode);
        mpc->getOscilatorHide();
        mpc->getWaveFileHide();

        
        break;
    case 2:
        mpc->mModulator = lastValue;
        break;
    case 3:
        mpc->mWaveNumbr = lastValue;
        mpc->setWaveNumr(mpc->mWaveNumbr);
        bin.loadWaveFile(urls.getUrlNb(engineNb)[mpc->getWaveNr()].toString().toRawUTF8(), 1);
        mpc->setWaveSize(bin.getSampleLength());
        sampelout.loadfile(bin.getSampleLength(), bin.getSample());
        mpc->AudioFile = urls.getUrlNb(engineNb)[mpc->getWaveNr()].toString().toRawUTF8();
        //waveG.setIn(bin.getSample(), bin.getSampleLength());
        break;
    case 4:
        mpc->mWaveHertz = lastValue;
        mpc->setWaveFileHertz(lastValue);
        mpc->setPitch_t(lastValue);
        break;
    case 5:
        mpc->setVolume(lastValue);
        mpc->setVolume_t(lastValue);
        break;
    case 6:
        mpc->setGate(lastValue);
        break;
    case 7:
        busEnvelopes[kenvSLiderNr]= lastValue;
        if (int(mpc->mEnVelopeMode) == 0) {
            sampelout.ampEG.setAttackDurationSeconds(busEnvelopes[1]);
            sampelout.ampEG.setDecayDurationSeconds(busEnvelopes[2]);
            sampelout.ampEG.sustainFraction = busEnvelopes[3];
            sampelout.ampEG.setReleaseDurationSeconds(busEnvelopes[4]);
            sampelout.ampEG.updateParams();
        }
        if (int(mpc->mEnVelopeMode) == 1) {
            sampelout.ampEGF.setAttackDurationSeconds(busEnvelopes[5]);
            sampelout.ampEGF.setDecayDurationSeconds(busEnvelopes[6]);
            sampelout.ampEGF.sustainFraction = busEnvelopes[7];
            sampelout.ampEGF.setReleaseDurationSeconds(busEnvelopes[8]);
            sampelout.ampEGF.updateParams();
        }
        if (int(mpc->mEnVelopeMode) == 2) {
            sampelout.ampEGP.setAttackDurationSeconds(busEnvelopes[9]);
            sampelout.ampEGP.setDecayDurationSeconds(busEnvelopes[10]);
            sampelout.ampEGP.sustainFraction = busEnvelopes[11];
            sampelout.ampEGP.setReleaseDurationSeconds(busEnvelopes[12]);
            sampelout.ampEGP.updateParams();
        }
      GetAdsrParas();
        break;
    case 8:
        mpc->mSynthFrequencyEnv = lastValue;
        mpc->setSynthHertzEnvelope(lastValue);
        break;
    case 9:
        mpc->mWaveHertzEnv = lastValue;
        mpc->setWaveHertzEnvelope(lastValue);
        break;
    case 10:
        mpc->mVcfEnv = lastValue;
        mpc->setFilterEnv(lastValue);
        break;
    case 11:
        mpc->mVcfMode= lastValue;
        mpc->setFilterMode(lastValue);
        break;
    case 12:
        mpc->mVcfCut= lastValue;
        mpc->setFilterCut(lastValue);
        sampelout.moogF.setCutoff(lastValue);
        break;
    case 13:
        mpc->mVcfRes= lastValue;
        sampelout.moogF.setRes(lastValue);
        mpc->setFilterRes(lastValue);
        break;
    case 14:
        mpc->mDlMode= lastValue;
        mpc->setDelayMode(lastValue);
        sampelout.echo->mpe.setDelayMode(lastValue);
       
        break;
    case 15:
        mpc->mDlTime= lastValue;
        mpc->setDelayTime(lastValue);
        sampelout.echo->mpe.setDelayTime(float(lastValue));
        break;
    case 16:
        mpc->mDlFeed= lastValue;
        mpc->setDelayFeed(lastValue);
        sampelout.echo->mpe.setDelayFeed(lastValue);
        break;
    case 17:
        mpc->mDlVol= lastValue;
        mpc->setDelayVolume(lastValue);
        sampelout.echo->mpe.setDelayLevel(lastValue);
        break;
    case 18:
        mpc->mDlWet= lastValue;
        mpc->setDelayMix(lastValue);
        sampelout.echo->mpe.setDelayMix(lastValue);
        break;
    case 19:
        mpc->mSynthWaveForm = lastValue;
        mpc->setSynthOscMode(lastValue);
        sampelout.oscillator.setWaveform(lastValue);
        break;
    case 20:
        mpc->mSynthFrequency = lastValue;
         mpc->setSynthHertz(lastValue);
        sampelout.oscillator.setFrequency(lastValue);
     
        break;
    case 21:
        mpc->mSampleStart = lastValue;
        mpc->setWaveStart(lastValue);
        break;
    case 22:
        mpc->mSampleEnd = lastValue;
        mpc->setWaveENd(lastValue);
        break;
    case 23:
        mpc->mSamplePlayMode = lastValue;
        mpc->setWavePlayMode(lastValue);
        break;
    case 24:
      
        mpc->setWaveSizeDiv(lastValue);
        break;
    case 25:
        mTimes = lastValue;
        break;
    case 26:
        mMemoryValue = lastValue;
      
        if(mpc->mEngineNumber==0)
        urls.loadInit1(valueTreeStateGui, int(mMemoryValue));
        if (mpc->mEngineNumber == 1)
        urls.loadInit2(valueTreeStateGui, int(mMemoryValue));
        if (mpc->mEngineNumber == 2)
        urls.loadInit3(valueTreeStateGui, int(mMemoryValue));
        if (mpc->mEngineNumber == 3)
            urls.loadInit4(valueTreeStateGui, int(mMemoryValue));
        if (mpc->mEngineNumber == 4)
            urls.loadInit5(valueTreeStateGui, int(mMemoryValue));
        if (mpc->mEngineNumber == 5)
            urls.loadInit6(valueTreeStateGui, int(mMemoryValue));
        if (mpc->mEngineNumber == 6)
            urls.loadInit7(valueTreeStateGui, int(mMemoryValue));


        urls.serial1(valueTreeStateGui, urls.getUrlNb(engineNb)[mpc->getWaveNr()].toString(), mpc->getWaveNr(), mpc->mEngineNumber);
        bin.loadWaveFile(urls.getUrlNb(mpc->mEngineNumber)[mpc->getWaveNr()].toString().toRawUTF8(), 1);
        mpc->setWaveSize(bin.getSampleLength());
        sampelout.loadfile(bin.getSampleLength(), bin.getSample());
        mpc->AudioFile = urls.getUrlNb(mpc->mEngineNumber)[mpc->getWaveNr()].toString().toRawUTF8();

  
            

      
        break;
    default:
        break;

    }

    sampelout.parasIn(*mpc);
    
 
    if (onValueChanged != nullptr)
        onValueChanged();
}

