/*
  ==============================================================================

    showWave.cpp
    Created: 9 Oct 2022 1:14:29pm
    Author:  Roger Hug

  ==============================================================================
*/

#include <JuceHeader.h>
#include "showWave.h"

//==============================================================================
showWave::showWave()

{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    int wavelenght = 44100;
    init = new double[wavelenght];
    for (int i = 0; i < wavelenght; i++)
        init[i] = 1 - (i / double(wavelenght));

}

showWave::~showWave()
{
    
      
}

void showWave::paint (juce::Graphics& g)
{
    auto centreY = (float)getHeight() / 2.0f;
    g.setColour(Colours::white);
    // Draw a representative  wave.
    Path wavePath;
    wavePath.startNewSubPath(0, centreY);

       int y = 0;
        for (auto x = 1.0f; x < (float)getWidth(); ++x,y+=128 )
            wavePath.lineTo(x, centreY + init[int(y)] * (float)getHeight() * 2.0f
                * std::sin(y * wavelenght * 0.0001f));
    
    g.setColour(getLookAndFeel().findColour(Slider::thumbColourId));
    g.strokePath(wavePath, PathStrokeType(2.0f));
}

void showWave::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
