/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once


#include <JuceHeader.h>


#include"timeLines.h"
#include"../MainControl/mainGui.h"
#include"../MainControl/TriggerGui.h"
#include"../binaryFiles/binary.h"
#include"../AudioSampel/SamplerGui.h"
#include"filebrowser.h"
#include"../filter/moog24db.h"


class CParamSmoothP
{
public:
    CParamSmoothP() { a = 0.99; b = 1. - a; z = 0.; };
    ~CParamSmoothP() {};
    inline double Process(double in) { z = (in * b) + (z * a); return z; }
private:
    double a, b, z;
};

constexpr auto SP_BUFFERS = 2048;
//==============================================================================
/**
*/
class NewProjectAudioProcessor  : public juce::AudioProcessor
   
{
public:
    //==============================================================================
    NewProjectAudioProcessor();
    ~NewProjectAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    

    filebrowserVst3Sets BrowserVstPreset;

    mainGui mainG;
    TriggerGui trg;

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
 
    void updateCurrentTimeInfoFromHost();
    int setMidiCC(int i) { return i; }
    void midiCC_(juce::MidiBuffer&);
    void setMasterGain(float v) { masterGain = v; }
    
  
    timeLines Ptime;

    SamplerGui spg1;
    float*buff1;

    SamplerGui spg2;
    float* buff2;

    float* buffMix;

   moog24db moogM;
   float filterMode;

   void updateFilter()
   {
       moogM.setCutoff(0.9);
       moogM.setRes(0.1);
 
   }


    UndoManager undoManager;
    AudioProcessorValueTreeState valueTreeState;
    AudioPlayHead::CurrentPositionInfo lastPosInfo;
     float test = 0;
   
private:
    float masterGain;
    bool ApVst;
    std::atomic<float> mStepPos;
    CParamSmoothP smLevel;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NewProjectAudioProcessor)
};
