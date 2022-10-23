/*
  ==============================================================================

    TriggerGui.h
    Created: 27 Jun 2022 7:57:05pm
    Author:  roger hug

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
constexpr auto TRIGGERLENGHT = 64;
//==============================================================================
/*
*/



class TriggerGui  : public juce::Component
{
public:
    TriggerGui(AudioProcessorValueTreeState& vts);
    ~TriggerGui() override;
    void setColor(float c);
    void setAB(int c)
    {
        if (c > 1)
            c = 1;
        sqColor = c;
        repaint();

    }
    void setPattern(float p) { mPattern = p; repaint(); }
    void mouseUp(const juce::MouseEvent& event) override;
    void mouseDown(const juce::MouseEvent& event) override;
    void mouseDrag(const MouseEvent& e)override;
    bool mouseOn() { return mDown; }
    void drawTriggerGrid(juce::Graphics& g);
    void paint (juce::Graphics&) override;
    void resized() override;
    const int GetparamNr()  { return ParameterNr; }
    const float* getTrigger1() { return Ktrigger1; }
    const float* getTrigger2() { return Ktrigger2; }
    const float* getTrigger3() { return Ktrigger3; }
    const float* getTrigger4() { return Ktrigger4; }
    const float* getTrigger5() { return Ktrigger5; }
    const float* getTrigger6() { return Ktrigger6; }
    const float* getTrigger7() { return Ktrigger7; }

    
    void serialParas(AudioProcessorValueTreeState& valueTreeState,String name);
    void unSerialParas(AudioProcessorValueTreeState& valueTreeState);

    void XmlTriggersIn(float **in);



    const char* triggersoutC();
    bool mDown;
    Value SeqStateParas1;
    float* Ktrigger1;;
    Value SeqStateParas2;
    float *Ktrigger2;
    Value SeqStateParas3;
    float* Ktrigger3;
    Value SeqStateParas4;
    float* Ktrigger4;
    Value SeqStateParas5;
    float* Ktrigger5;
    Value SeqStateParas6;
    float* Ktrigger6;
    Value SeqStateParas7;
    float* Ktrigger7;

    Value KtrigAll[7];
    Value* GetTrigAllV(){ return KtrigAll;  }
    std::function<void()> onValueChanged;
    void valueChanged(float newValue);
    const int GetParaNr() { return ParameterNr; }
    int p1t;
private:
    AudioProcessorValueTreeState& valueTreeStateTrigGui;
    std::atomic<float> lastValue{ 0.0f };
    int ParameterNr;
    int KposTrigger;
    float sqColor;
    float mPattern;

    int patternAB;

    std::atomic<int> trpos1{ 0 };
    std::atomic<int> trpos2{ 0 };
    std::atomic<int> trpos3{ 0 };
    std::atomic<int> trpos4{ 0 };
    std::atomic<int> trpos5{ 0 };
    std::atomic<int> trpos6{ 0 };
    std::atomic<int> trpos7{ 0 };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TriggerGui)
};
