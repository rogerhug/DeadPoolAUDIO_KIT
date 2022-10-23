/*
  ==============================================================================

    showOscilator.cpp
    Created: 19 Aug 2022 3:32:16pm
    Author: Roger Hug

  ==============================================================================
*/

#include <JuceHeader.h>
#include "showOscilator.h"

//==============================================================================
showOscilator::showOscilator()
{

    sine1 = new double[1024];
  
    for (int i = 0; i < 512; i++)
    {
        sine1[i] = sin(i / (double)512 * 12 * double_Pi);
    }
}

showOscilator::~showOscilator()
{
}


void showOscilator::paint (juce::Graphics& g)
{



    auto centreY = (float)getHeight() / 2.0f;

    // Draw a representative Tabel.
    Path tabelPath;
    tabelPath.startNewSubPath(0, centreY);

 
    for (auto x = 1.0f; x < (float)getWidth(); ++x)
        tabelPath.lineTo(x, centreY + (sine1[int(x)*2] *0.5)* (float)getHeight()/8
            * (float(x) * 256 * 0.0001f));

    g.setColour(getLookAndFeel().findColour(Slider::thumbColourId));
    g.strokePath(tabelPath, PathStrokeType(2.0f));

}

void showOscilator::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
