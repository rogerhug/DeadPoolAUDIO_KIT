/*
  ==============================================================================

    sequencer.cpp
    Created: 4 Nov 2021 5:09:45pm
    Author:  r7

  ==============================================================================
*/

#include "sequencer.h"

sequencer::sequencer()
{

    mPattern = 0;
    //***************************************triggers*******************************
    trigger1 = new int* [16];
    for (int s = 0; s < 10; ++s) {
        trigger1[s] = new int[16];
        for (int i = 0; i < 16; ++i) {
            trigger1[s][i] = 0;
        }
    }


    triggerserialC = new char** [64];
    for (int s = 0; s < 10; ++s) {
        triggerserialC[s] = new char* [64];
        for (int p = 0; p < 10; p++) {
            triggerserialC[s][p] = new char[64];
            strcpy(triggerserialC[s][p], "1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,");          
        }
    }
    triggerserialI = new int** [16];
    for (int p = 0; p < 10; ++p) {
        triggerserialI[p] = new int* [16];
        for (int t = 0; t < 10; ++t) {
            triggerserialI[p][t] = new int[16];
            for (int n = 0; n < 16; ++n) {
                triggerserialI[p][t][n] = 0;
            }
        }
    }
    // In your constructor, you should add any child components, 
    const int buttonsizeTrig = 40;
    for (int i = 0; i < 16; ++i) {
        addAndMakeVisible(triggermultibutA[i]);

        triggermultibutA[i].setClickingTogglesState(true);
        triggermultibutA[i].setColour(juce::TextButton::buttonColourId, juce::Colours::black);
        triggermultibutA[i].setBounds(i * buttonsizeTrig, 0, buttonsizeTrig, 24);
    

                if (i == 0)
            triggermultibutA[i].setToggleState(true, juce::dontSendNotification);
        triggermultibutA[i].setColour(juce::TextButton::buttonColourId, juce::Colours::white);
      //  setTriggers(0);
        triggermultibutA[0].setColour(juce::TextButton::buttonColourId, juce::Colours::antiquewhite);
    triggermultibutA[4].setColour(juce::TextButton::buttonColourId, juce::Colours::antiquewhite);
    triggermultibutA[8].setColour(juce::TextButton::buttonColourId, juce::Colours::antiquewhite);
    triggermultibutA[12].setColour(juce::TextButton::buttonColourId, juce::Colours::antiquewhite);
    }



    //*******************************************paras************************************

    
    

        parasSerialCWave = new char* [100];
        parasSerialCWaveVolume = new char* [100];
        parasSerialCPitch = new char* [100];
        parasSerialCDelayT = new char* [100];
        parasSerialCDelayF = new char* [100];
                for (int s = 0; s < 10; ++s) {
            parasSerialCWave[s] = new char[100];
            parasSerialCWaveVolume[s] = new char[100];
            parasSerialCPitch[s] = new char[100];
            parasSerialCDelayT[s] = new char[100];
            parasSerialCDelayF[s] = new char[100];
            for (int n = 0; n < 100; ++n) {
                parasSerialCWave[s][n] = 0;
                parasSerialCWaveVolume[s][n] = 0;
                parasSerialCPitch[s][n] = 0;
                parasSerialCDelayT[s][n] = 0;
                parasSerialCDelayF[s][n] = 0;
            }
        }
     


  
   
   
 
    // initialise any special settings that your component needs.
}

void sequencer::init(AudioProcessorValueTreeState& valueTreeState,int n)
{

    
   //*****************************triggers*********************************
    for (int i = 0; i < 9; i++)
    {

    strcpy(triggerserialC[0][i], "1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,");

    strcpy(triggerserialC[1][i], "0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,");
    strcpy(triggerserialC[2][i], "0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,");
    strcpy(triggerserialC[3][i], "0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,");
    strcpy(triggerserialC[4][i], "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,");
    strcpy(parasSerialCWave[i], "01,02,12,02,30,10,30,03,40,01");
    strcpy(parasSerialCWaveVolume[i], "0.50,0.50,0.50,0.50,0.50,0.50,0.50,0.50,0.50,0.50,");
    strcpy(parasSerialCPitch[i], "2.00,2.00,2.00,2.00,2.00,2.00,2.00,2.00,2.00,2.00,");
    strcpy(parasSerialCDelayT[i], "0.50,0.50,0.50,0.50,0.50,0.50,0.50,0.50,0.50,0.50,");
    strcpy(parasSerialCDelayF[i], "0.50,0.50,0.50,0.50,0.50,0.50,0.50,0.50,0.50,0.50,");
   


    
        for (int s = 0; s < 16; s++)
        {
         

          valueTreeState.state.setProperty(triggerNames(i, n),var(triggerserialC[n][i]), nullptr);
          valueTreeState.state.setProperty(paraWaveNames(i,n), var(parasSerialCWave[n]), nullptr);
          valueTreeState.state.setProperty(paraWaveVolumeNames(i), var(parasSerialCWaveVolume[n]), nullptr);
          valueTreeState.state.setProperty(paraPitchNames(i), var(parasSerialCPitch[n]), nullptr);
          valueTreeState.state.setProperty(paraDelayTNames(i), var(parasSerialCDelayT[n]), nullptr);
          valueTreeState.state.setProperty(paraDelayFNames(i), var(parasSerialCDelayF[n]), nullptr);
       

        }
    }
 

    
   
    
    unSerialTriggers(valueTreeState, n,true);
    unSerialWaveParas(valueTreeState, n);
    unSerialWaveVolumeParas(valueTreeState, n);
    unSerialPitchParas(valueTreeState, n);
    unSerialDelayTParas(valueTreeState, n);
    unSerialDelayFParas(valueTreeState, n);
    
    getTriggers(0);
    getTriggers(1);
    getTriggers(2);
    getTriggers(3);
    getTriggers(4);
    getTriggers(5);
    getTriggers(6);
    


}
int rti[10][10][16];
int rti2[10][10][16];

void sequencer::initTrSet_1(AudioProcessorValueTreeState& valueTreeState,int s,int v)
{
        for (int p = 0; p < 9; p++) {
            if (v == 1) {
                valueTreeState.state.setProperty(triggerNames(p, s), var(triggersets.getTriggerDub()[s][p]), nullptr);
            }
            if (v == 2) {
                valueTreeState.state.setProperty(triggerNames(p, s), var(triggersets.getTriggerBreaks()[s][p]), nullptr);
            }
            if (v == 3) {
                valueTreeState.state.setProperty(triggerNames(p, s), var(triggersets.getTriggerHouse()[s][p]), nullptr);
            }
           
    }
        unSerialTriggers(valueTreeState, s, true);
        getTriggers(0);
        getTriggers(1);
        getTriggers(2);
        getTriggers(3);
        getTriggers(4);
        getTriggers(5);
        getTriggers(6);
    
}
void sequencer::setTriggers(int s)
{
    for (int i = 0; i < 16; i++) {
     
        rti[s][mPattern][i] = triggermultibutA[i].getToggleState();
      
    }


    sprintf(triggerserialC[s][mPattern], "%i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i"
        , rti[s][mPattern][0], rti[s][mPattern][1], rti[s][mPattern][2], rti[s][mPattern][3]
        , rti[s][mPattern][4], rti[s][mPattern][5], rti[s][mPattern][6], rti[s][mPattern][7]
        , rti[s][mPattern][8], rti[s][mPattern][9], rti[s][mPattern][10], rti[s][mPattern][11]
        , rti[s][mPattern][12], rti[s][mPattern][13], rti[s][mPattern][14], rti[s][mPattern][15]);
   
}
void sequencer::setPattern(int p,int s)
{
    mPattern = p;
    for (int t = 0; t < 16; t++)
    {

        triggermultibutA[t].setToggleState(rti[s][p][t], juce::dontSendNotification);
       
    }
     getTriggers(s);

     getTriggersColor(s);
}

int* sequencer::getTriggers(int s)
{
   
   return rti[s][mPattern];
}

void sequencer::setHighlight(int h)
{
    for (int i = 0; i < 16; i++) {
        triggermultibutA[i].setColour(juce::TextButton::buttonColourId, juce::Colours::white);
            if(i==h)
            triggermultibutA[i].setColour(juce::TextButton::buttonColourId, juce::Colours::antiquewhite);
    }
}

int** sequencer::getTriggersColor(int s)
{
    // memcpy(triggerserialI, rti, 16 * sizeof(int));
  
    return triggerserialI[s];
  
}


void sequencer::serialTriggers(AudioProcessorValueTreeState& valueTreeState,int s)
{
    for (int n = 0; n <= 9; n++) 
    {
      
        valueTreeState.state.setProperty(triggerNames(mPattern, s), var(triggerserialC[s][mPattern]), nullptr);
       // valueTreeState.state.setProperty(triggerNames(n, 1), var(triggerserialC[1][n]), nullptr);
    }
    memcpy(rti2, rti, 16 * sizeof(int));
  //  getTriggers(s);
}
char rt[10][100];

void sequencer::unSerialTriggers(AudioProcessorValueTreeState& valueTreeState, int s,bool on)
{
  
        for (int n = 0; n <= 9; n++) {


            Striggers[n].referTo(valueTreeState.state.getPropertyAsValue(triggerNames(n, s), nullptr, true));


            for (int i = 0; i <= 30; i += 2) {


                rti[s][n][i / 2] = Striggers[n].getValue().toString().substring(i, i + 1).getIntValue();
                strcpy(rt[n], Striggers[n].toString().toRawUTF8());

            }

        }
      

    for (int t = 0; t < 16; t++)
    {

        triggermultibutA[t].setToggleState(rti[s][mPattern][t], juce::dontSendNotification);
       
    }
    memcpy(triggerserialI, rti, 16 * sizeof(int));

   // unSerialWaveParas(valueTreeState,s);
  //  unSerialPitchParas(valueTreeState, s);
   // return 0;// Striggers[p].getValue().toString().substring(i, i + 1).getIntValue();
 
}
char *sequencer::tsC2()
{
    return rt[mPattern];
}
//******************************************************************************************************
//---------------------------------------------------------paras------------------------------------------
//*******************************************************************************************************


//---------------------------------------------   WaveNr   ----------------------------------------------
int mWaveNr[10][10];

void sequencer::setWaveNr(int w,int p,int s)
{
    mWaveNr[s][p] = w;
    
    
 sprintf(parasSerialCWave[s], "%.2i %.2i %.2i %.2i %.2i %.2i %.2i %.2i %.2i %.2i ",
        mWaveNr[s][0], mWaveNr[s][1], mWaveNr[s][2], mWaveNr[s][3], mWaveNr[s][4], mWaveNr[s][5],
        mWaveNr[s][6], mWaveNr[s][7], mWaveNr[s][8], mWaveNr[s][9]);
}


void sequencer::serialWaveParas(AudioProcessorValueTreeState& valueTreeState,int s)
{
    
        valueTreeState.state.setProperty(paraWaveNames(s,0), var(parasSerialCWave[s]), nullptr);
    
}

char outWsC[100] = {  };
void sequencer::unSerialWaveParas(AudioProcessorValueTreeState& valueTreeState, int s)
{
    
    for (int n = 0; n <= 10; n++) {
        SPStateParasW[n].referTo(valueTreeState.state.getPropertyAsValue(paraWaveNames(n,0), nullptr, true));


      for (int i = 0; i <= 27; i += 3) {
          mWaveNr[s][i / 3] = SPStateParasW[s].getValue().toString().substring(i, i + 2).getIntValue();
          strcpy(outWsC, SPStateParasW[0].toString().toRawUTF8());
    }
 }
 
}

const char* sequencer::getus()
{
   strcpy(outWsC, SPStateParasW[0].toString().toRawUTF8());
    return outWsC;
}

const int sequencer::getStateWave(int s)
{
    return mWaveNr[s][mPattern];
}
char* sequencer::waveValuessTc()
{
    return 0; 
}
double PitchWave[10][10] = { 2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0 };//---------------------------------audiopitch---------------
void sequencer::setPitchSt(double v, int p, int s)
{
    PitchWave[s][p] = v;
    
    sprintf(parasSerialCPitch[s], "%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f ",
        PitchWave[s][0], PitchWave[s][1], PitchWave[s][2], PitchWave[s][3], PitchWave[s][4], PitchWave[s][5],
        PitchWave[s][6], PitchWave[s][7], PitchWave[s][8], PitchWave[s][9]);
        
}

void sequencer::serialPitchParas(AudioProcessorValueTreeState& valueTreeState,  int s)
{
    valueTreeState.state.setProperty(paraPitchNames(s), var(parasSerialCPitch[s]), nullptr);
}

void sequencer::unSerialPitchParas(AudioProcessorValueTreeState& valueTreeState, int s)
{

    for (int n = 0; n <= 10; n++) {
        SPStateParasP[n].referTo(valueTreeState.state.getPropertyAsValue(paraPitchNames(n), nullptr, true));
        for (int i = 0; i <= 50; i += 5) {
            PitchWave[s][i / 5] = SPStateParasP[s].getValue().toString().substring(i, i + 4).getDoubleValue();
          //  strcpy(outWsC, SPStateParas[1].toString().toRawUTF8());
        }
    }
}

const double sequencer::getStatePitch(int s)
{
    return PitchWave[s][mPattern];
}

double WaveVolume[10][10] = { 0.7,0.7,0.7,0.7,0.7,0.7,0.7,0.7,0.7 };//---------------------------------audioVolume---------------
void sequencer::setWaveVolumeSt(double v, int p, int s)
{
    WaveVolume[s][p] = v;

    sprintf(parasSerialCWaveVolume[s], "%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f ",
       WaveVolume[s][0], WaveVolume[s][1], WaveVolume[s][2], WaveVolume[s][3], WaveVolume[s][4], WaveVolume[s][5],
        WaveVolume[s][6], WaveVolume[s][7], WaveVolume[s][8], WaveVolume[s][9]);
}
void sequencer::serialWaveVolumeParas(AudioProcessorValueTreeState& valueTreeState, int s)
{
    valueTreeState.state.setProperty(paraWaveVolumeNames(s), var(parasSerialCWaveVolume[s]), nullptr);

}
void sequencer::unSerialWaveVolumeParas(AudioProcessorValueTreeState& valueTreeState, int s)
{
    
    for (int n = 0; n <= 10; n++) {
        SPStateParasWV[n].referTo(valueTreeState.state.getPropertyAsValue(paraWaveVolumeNames(n), nullptr, true));
        for (int i = 0; i <= 50; i += 5) {
            WaveVolume[s][i / 5] = SPStateParasWV[s].getValue().toString().substring(i, i + 4).getDoubleValue();
            //  strcpy(outWsC, SPStateParas[1].toString().toRawUTF8());
        }
    }
    
}
const double sequencer::getStateWaveVolume(int s)
{
    return  WaveVolume[s][mPattern];
}

double DelayTime[10][10] = { 0 };//----------------------------------------------------------------delayTime-----------------

void sequencer::setDelayTSt(double v, int p, int s)
{
    DelayTime[s][mPattern] = v;
    sprintf(parasSerialCDelayT[s], "%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f ",
        DelayTime[s][0], DelayTime[s][1], DelayTime[s][2], DelayTime[s][3], DelayTime[s][4], DelayTime[s][5],
        DelayTime[s][6], DelayTime[s][7], DelayTime[s][8], DelayTime[s][9]);
}

void sequencer::serialDelayTParas(AudioProcessorValueTreeState& valueTreeState, int s)
{
    valueTreeState.state.setProperty(paraDelayTNames(s), var(parasSerialCDelayT[s]), nullptr);
}
void sequencer::unSerialDelayTParas(AudioProcessorValueTreeState& valueTreeState, int s)
{
    for (int n = 0; n <= 10; n++) {
        SPStateParasDT[n].referTo(valueTreeState.state.getPropertyAsValue(paraDelayTNames(n), nullptr, true));
        for (int i = 0; i <= 50; i += 5) {
            DelayTime[s][i / 5] = SPStateParasDT[s].getValue().toString().substring(i, i + 4).getDoubleValue();
          //  strcpy(outWsC, SPStateParas[2].toString().toRawUTF8());
        }
    }
}
const double sequencer::getStateDelayT(int s)
{
    return DelayTime[s][mPattern];
}

double DelayFeed[10][10] = { 0 };//----------------------------------------------------------------delayFeed-----------------
void sequencer::setDelayFSt(double v, int p, int s)
{
    DelayFeed[s][mPattern] = v;
    sprintf(parasSerialCDelayF[s], "%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f ",
        DelayFeed[s][0], DelayFeed[s][1], DelayFeed[s][2], DelayFeed[s][3], DelayFeed[s][4], DelayFeed[s][5],
        DelayFeed[s][6], DelayFeed[s][7], DelayFeed[s][8], DelayFeed[s][9]);
}
void sequencer::serialDelayFParas(AudioProcessorValueTreeState& valueTreeState, int s)
{
    valueTreeState.state.setProperty(paraDelayFNames(s), var(parasSerialCDelayF[s]), nullptr);
}
void sequencer::unSerialDelayFParas(AudioProcessorValueTreeState& valueTreeState, int s)
{
    for (int n = 0; n <= 10; n++) {
        SPStateParasDF[n].referTo(valueTreeState.state.getPropertyAsValue(paraDelayFNames(n), nullptr, true));
        for (int i = 0; i <= 50; i += 5) {
            DelayFeed[s][i / 5] = SPStateParasDF[s].getValue().toString().substring(i, i + 4).getDoubleValue();
            //  strcpy(outWsC, SPStateParas[2].toString().toRawUTF8());
        }
    }
}
const double sequencer::getStateDelayF(int s)
{
    return DelayFeed[s][mPattern];
}
void sequencer::resetParaState(AudioProcessorValueTreeState& valueTreeState,int s)
{

 
    for(int i=0;i<10;i++){
     mWaveNr[s][i] = getStateWave(s);
     WaveVolume[s][i] = getStateWaveVolume(s);
     PitchWave[s][i] = getStatePitch(s);
     DelayTime[s][i] = getStateDelayT(s);
     DelayFeed[s][i] = getStateDelayF(s);
    
    
    
    }
    
    sprintf(parasSerialCWave[s], "%.2i %.2i %.2i %.2i %.2i %.2i %.2i %.2i %.2i %.2i ",
        mWaveNr[s][0], mWaveNr[s][1], mWaveNr[s][2], mWaveNr[s][3], mWaveNr[s][4], mWaveNr[s][5],
        mWaveNr[s][6], mWaveNr[s][7], mWaveNr[s][8], mWaveNr[s][9]);
    valueTreeState.state.setProperty(paraWaveNames(s,0), var(parasSerialCWave[s]), nullptr);
    serialWaveParas(valueTreeState,s);

    sprintf(parasSerialCPitch[s], "%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f ",
        PitchWave[s][0], PitchWave[s][1], PitchWave[s][2], PitchWave[s][3], PitchWave[s][4], PitchWave[s][5],
        PitchWave[s][6], PitchWave[s][7], PitchWave[s][8], PitchWave[s][9]);
    valueTreeState.state.setProperty(paraPitchNames(s), var(parasSerialCPitch[s]), nullptr);
    serialPitchParas(valueTreeState, s);

    sprintf(parasSerialCWaveVolume[s], "%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f ",
        WaveVolume[s][0], WaveVolume[s][1], WaveVolume[s][2], WaveVolume[s][3], WaveVolume[s][4], WaveVolume[s][5],
        WaveVolume[s][6], WaveVolume[s][7], WaveVolume[s][8], WaveVolume[s][9]);
    valueTreeState.state.setProperty(paraWaveVolumeNames(s), var(parasSerialCWaveVolume[s]), nullptr);
    serialWaveVolumeParas(valueTreeState, s);
    sprintf(parasSerialCDelayT[s], "%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f ",
        DelayTime[s][0], DelayTime[s][1], DelayTime[s][2], DelayTime[s][3], DelayTime[s][4], DelayTime[s][5],
        DelayTime[s][6], DelayTime[s][7], DelayTime[s][8], DelayTime[s][9]);
    valueTreeState.state.setProperty(paraDelayTNames(s), var(parasSerialCDelayT[s]), nullptr);
    serialDelayTParas(valueTreeState, s);
    sprintf(parasSerialCDelayF[s], "%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f ",
        DelayFeed[s][0], DelayFeed[s][1], DelayFeed[s][2], DelayFeed[s][3], DelayFeed[s][4], DelayFeed[s][5],
        DelayFeed[s][6], DelayFeed[s][7], DelayFeed[s][8], DelayFeed[s][9]);
    valueTreeState.state.setProperty(paraDelayFNames(s), var(parasSerialCDelayF[s]), nullptr);
    serialDelayFParas(valueTreeState, s);
}