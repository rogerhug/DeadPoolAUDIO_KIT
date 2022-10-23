/*
  ==============================================================================

    mixerGui.h
    Created: 9 Sep 2022 10:14:59am
    Author:  lutz

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include"SamplerController.h"

//==============================================================================
/*
*/
class mixerGui  : public juce::Component
{
public:
    mixerGui();
    ~mixerGui() override;
    void mouseUp(const juce::MouseEvent& event) override;
    void mouseDown(const juce::MouseEvent& event) override;
    void mouseDrag(const MouseEvent& e)override;
    bool mouseOn() { return mDown; }
    void paint (juce::Graphics&) override;
    void drawButts(juce::Graphics&) ;
    void drawSliders(juce::Graphics&);
    void resized() override;
    void inputValues(ParasSamplerControll& mp,int e);
    void setHideControll(float h){}
    bool mDown;
    std::function<void()> onValueChanged;
    void valueChanged(float);
    const int GetParaNr() { return ParameterNr; }
    const int GetParaSelect() { return ParaSection; }
    const int GetMenu() { return mHidemenu; }
    ParasSamplerControll mp1;
    ParasSamplerControll mp2;
    ParasSamplerControll mp3;
    ParasSamplerControll mp4;
    ParasSamplerControll mp5;
    ParasSamplerControll mp6;
    ParasSamplerControll mp7;
   
    void repaintMix(bool m) { if (m == true)repaint(); }
 
float mHidemenu;
private:
    int ParameterNr;
    int ParaSection;
    std::atomic<float> lastValue{ -1.0f };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (mixerGui)
};
