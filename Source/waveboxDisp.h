/*
  ==============================================================================

    waveboxDisp.h
    Created: 2 Sep 2022 6:20:05pm
    Author:  lutz

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class waveboxDisp  : public juce::Component
{
public:
    waveboxDisp();
    ~waveboxDisp() override;
    void setEngine(float e) { engineWb = e; repaint(); }
    void setFiles(Value* sf);
    void paint (juce::Graphics&) override;
    void resized() override;
    Value show[7];
private:
    float engineWb;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (waveboxDisp)
};
