/*
  ==============================================================================

    showOscilator.h
    Created: 19 Aug 2022 3:32:16pm
    Author:  Roger Hug

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class showOscilator  : public juce::Component
{
public:
    showOscilator();
    ~showOscilator() override;

    void formIn(const double* in)
    {
        memset(sine1, 0, 512 * sizeof(double));
        memcpy(sine1, in, 512 * sizeof(double));
   
        repaint();
    }

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    double* sine1;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (showOscilator)
};
