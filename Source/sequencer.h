/*
  ==============================================================================

    sequencer.h
    Created: 7 Jun 2021 8:41:38am
    Author:  Roger Hug

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include"TriggersInit.h"


class sequencer  : public juce::Component
{
public:
  
    sequencer();
    ~sequencer() override { }
  
    void paint (juce::Graphics& g) override {}
    void resized() override  {}

    void init(AudioProcessorValueTreeState& valueTreeState,int n);

    void setPattern(int p,int s);

//*****************************************************************************************
//*******************************************triggers****************************************
//********************************************************************************************  
   
    void initTrSet_1(AudioProcessorValueTreeState& valueTreeState,int s,int v);
    void setTriggers(int s);

    int* getTriggers(int s); 

    void setHighlight(int h);
    int** getTriggersColor(int s);
   
    char nt[25] = { "" };//------------------triggers1-10----------------
    const char* triggerNames(int n, int e) { sprintf(nt, "triggers_Sp%.2i%.1i", n, e);  return nt; }
    void serialTriggers(AudioProcessorValueTreeState& valueTreeState,int s);
    void unSerialTriggers(AudioProcessorValueTreeState& valueTreeState, int s,bool on);
      Value Striggers[11];
    char* tsC() { return triggerserialC[0][mPattern]; };
   
    char *tsC2(); 
 
    TextButton triggermultibutA[16];


    //***************************************************************************************
    //****************************************paras_State_Pattern****************************
    //*************************************************************************************


     char npw[20] = { "" };//-----------------waveNr 1-10 ---------
    const char* paraWaveNames(int n,int e) { sprintf(npw, "p_StWSP%.2i", n);  return npw; }
    void setWaveNr(int w,int p,int s);
    void serialWaveParas(AudioProcessorValueTreeState& valueTreeState,int s);
    void unSerialWaveParas(AudioProcessorValueTreeState& valueTreeState, int s);
    const int getStateWave(int s);
    char* waveValuessTc(); 
    Value SPStateParasW[11];
    char npV[20] = { "" };//-----------------waveVolume 1-10 ---------
    const char* paraWaveVolumeNames(int n) { sprintf(npV, "p_StWVSP%.2i", n);  return npV; }
    void setWaveVolumeSt(double v, int p, int s); 
    void serialWaveVolumeParas(AudioProcessorValueTreeState& valueTreeState, int s);
    void unSerialWaveVolumeParas(AudioProcessorValueTreeState& valueTreeState, int s);
    const double getStateWaveVolume(int s);
    Value SPStateParasWV[11];
    char npP[20] = { "" };//-----------------wavePitch 1-10 ---------
    const char* paraPitchNames(int n) { sprintf(npP, "p_StPSP%.2i", n);  return npP; }
    void setPitchSt(double v, int p, int s);
    void serialPitchParas(AudioProcessorValueTreeState& valueTreeState ,int s);
    void unSerialPitchParas(AudioProcessorValueTreeState& valueTreeState, int s);
    const double getStatePitch(int s);
    Value SPStateParasP[11];
    char npDt[20] = { "" };//-----------------delay_time 1-10 ---------
    const char* paraDelayTNames(int n) { sprintf(npDt, "p_StDtSP%.2i", n);  return npDt; }
    void setDelayTSt(double v, int p, int s);
    void serialDelayTParas(AudioProcessorValueTreeState& valueTreeState, int s);
    void unSerialDelayTParas(AudioProcessorValueTreeState& valueTreeState, int s);
    const double getStateDelayT(int s);
    Value SPStateParasDT[11];
    char npDf[20] = { "" };//-----------------delay_feed 1-10 ---------
    const char* paraDelayFNames(int n) { sprintf(npDf, "p_StDfSP%.2i", n);  return npDf; }
    void setDelayFSt(double v, int p, int s);
    void serialDelayFParas(AudioProcessorValueTreeState& valueTreeState, int s);
    void unSerialDelayFParas(AudioProcessorValueTreeState& valueTreeState, int s);
    const double getStateDelayF(int s);
    Value SPStateParasDF[11];


    void resetParaState(AudioProcessorValueTreeState& valueTreeState,int s);

   const char *getus();//read something
private:
    TriggersInit triggersets;
     int mPattern;
   
    //-------------triggers----
    int **trigger1;
    char ***triggerserialC;
    int*** triggerserialI;
    //-------------Paras-------

    char** parasSerialCWave;
    char** parasSerialCWaveVolume;
    char** parasSerialCPitch;
    char** parasSerialCDelayT;
    char** parasSerialCDelayF;
  





    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (sequencer)
};
