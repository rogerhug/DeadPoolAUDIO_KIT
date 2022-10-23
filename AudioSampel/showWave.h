/*
  ==============================================================================

    showWave.h
    Created: 9 Oct 2022 1:14:29pm
    Author:  Roger Hug

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class showWave  : public juce::Component
               
{
public:
    showWave();
    ~showWave() override;


    int wavelenght;
    void setIn(const double* in,const int lenght) {
        memset(init, 0, 44100 * sizeof(double));
        memcpy(init, in,lenght * sizeof(double));
      wavelenght = lenght;
      repaint();
    }
    void paint (juce::Graphics&) override;
    void resized() override;


private:
    double* init;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (showWave)
};
