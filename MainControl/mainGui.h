/*
  ==============================================================================

    mainGui.h
    Created: 5 Oct 2022 7:05:52pm
    Author:  lutz

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include"mainController.h"
//==============================================================================
/*
*/
class mainGui  : public juce::Component
{
public:
    mainGui(AudioProcessorValueTreeState& vts);
    ~mainGui() override;
    ParasMainControll *mpcM;

    void mouseUp(const juce::MouseEvent& event) override;
    void mouseDown(const juce::MouseEvent& event) override;
    void mouseDrag(const MouseEvent& e)override;
    bool mouseOn() { return mDown; }
    void paint (juce::Graphics&) override;
    void drawbuts(juce::Graphics&);
    void drawSliders(juce::Graphics&);
    void resized() override;
    void initMainParas();

    Value MainStateParas;
    float* UstateParas;

    void serialParas(AudioProcessorValueTreeState& valueTreeState, String n);
    void unSerialParas(AudioProcessorValueTreeState& valueTreeState, String n);

    std::function<void()> onValueChanged;
    void valueChanged(float);

    const int GetParaNr() { return ParameterNr; }

private:
    std::atomic<float> lastValue{ 0.0f };
    int ParameterNr;
    bool mDown;
    AudioProcessorValueTreeState& valueTreeStateMain;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (mainGui)
};
