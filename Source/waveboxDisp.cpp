/*
  ==============================================================================

    waveboxDisp.cpp
    Created: 2 Sep 2022 6:20:05pm
    Author:  lutz

  ==============================================================================
*/

#include <JuceHeader.h>
#include "waveboxDisp.h"

//==============================================================================
waveboxDisp::waveboxDisp()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    engineWb = 0;
}

waveboxDisp::~waveboxDisp()
{
}

void waveboxDisp::setFiles(Value* sf)
{
    for (int i = 0; i < 7; i++)
    show[i].setValue(sf[i]);
    repaint();
}

void waveboxDisp::paint (juce::Graphics& g)
{

    g.fillAll (juce::Colours::black);   // clear the background
    g.setColour(juce::Colours::white);
    const int Kcolor = engineWb;
   
    g.setFont(juce::Font("Consolas", 13.0f, juce::Font::bold));

    for (int i = 0; i < 7; i++)
        g.drawRect(10,20+( i * 20), getWidth()-20, 20);
    g.setColour(juce::Colours::darkblue.withLightness(0.45));
    g.fillRect(12, 21 + (Kcolor * 20), getWidth() - 26, 17);
   
    g.setColour(juce::Colours::whitesmoke);
    g.drawRect (getLocalBounds(), 5);   // draw an outline around the component
    const int subt = 25;
    g.setColour (juce::Colours::white);
    g.setFont(18.0f);
    g.drawText("currentFiles", 10, 0, 200, 20,
        juce::Justification::centred, true);
    g.setFont (14.0f);
    g.setColour(juce::Colours::white);
    g.drawText (show[0].toString().getLastCharacters(subt).toRawUTF8(), 10,20,200,20,
                juce::Justification::centred, true);  
    g.drawText(show[1].toString().getLastCharacters(subt).toRawUTF8(), 10, 40, 200, 20,
        juce::Justification::centred, true);
    g.drawText(show[2].toString().getLastCharacters(subt).toRawUTF8(), 10, 60, 200, 20,
        juce::Justification::centred, true);
    g.drawText(show[3].toString().getLastCharacters(subt).toRawUTF8(), 10, 80, 200, 20,
            juce::Justification::centred, true);
    g.drawText(show[4].toString().getLastCharacters(subt).toRawUTF8(), 10, 100, 200, 20,
        juce::Justification::centred, true);
    g.drawText(show[5].toString().getLastCharacters(subt).toRawUTF8(), 10, 120, 200, 20,
        juce::Justification::centred, true);
    g.drawText(show[6].toString().getLastCharacters(subt).toRawUTF8(), 10, 140, 200, 20,
        juce::Justification::centred, true);
}

void waveboxDisp::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
