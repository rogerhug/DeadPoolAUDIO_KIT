/*
  ==============================================================================

    modulator.h
    Created: 23 Apr 2022 10:20:30am
    Author:  roger hug

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <functional>

#define STEPPERSIZE 16
//==============================================================================
/*
*/

class modulator  : public juce::Component
                   ,private Timer
                 
{
public:    
   
   
    modulator(AudioProcessorValueTreeState& vts);
    ~modulator() override;
    void paint(juce::Graphics& g)override;
    void mouseUp(const juce::MouseEvent& event) override;
    void mouseDown(const juce::MouseEvent& event) override;
    void mouseDrag(const MouseEvent& e)override;

    void resized() override;
    void timerCallback()override;
 
    void drawForm(juce::Graphics& g);
    void drawModOut(juce::Graphics& g);

    void drawButts(juce::Graphics& g);
    void countIn(int c, int on);
    void drawTextOut(juce::Graphics& g);
    void drawCount(juce::Graphics& g);
    void initCurve(int i);
    void setEngine(float e) { engineMode = e; repaint(190, 70, 120, 60); }

    float mTimebut;
    float mFormbut;

    int* steppValues;
    int* ModOutValues;
    bool mDown;

    Value SteppValuesSerial;
 

    const float *stepValuesOut();
    const float* stepAmpValuesOut();
    const float getTimerBpmvalue() { return mBpm * 4; }
    void serialStepps(AudioProcessorValueTreeState& valueTreeState,String name);
    void unSerialStepps(AudioProcessorValueTreeState& valueTreeState,String name);
    const int GetParaNbr() { return ParameterNr; }
    const char *GetModulatorC();
 
    float *stepperValu;
    float *stepperValueMod;
    std::function<void()> onValueChanged;
    void valueChanged(float newValue);
    const int GetParaNr() { return ParameterNr; }

    float* getStepOutValues() {
        return  stepperValu;
    }
    float* getStepOutValuesAmp() {
      return  stepperValueMod;
    }
private: 
    std::atomic<float> lastValue{ 0.00f };
    int KSlidePosModulator;
    int KSliderPosModOut;
    float engineMode;
    int ParameterNr;
    int Ktimebuts;
    int KmodulatorOn;
    int mCount;
    int mBpm;
    AudioProcessorValueTreeState& valueTreeStateMod;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (modulator)
};
