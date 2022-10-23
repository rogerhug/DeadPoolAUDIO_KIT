/*
  ==============================================================================

    mixerGui.cpp
    Created: 9 Sep 2022 10:14:59am
    Author:  lutz

  ==============================================================================
*/

#include <JuceHeader.h>
#include "mixerGui.h"

//==============================================================================
mixerGui::mixerGui()
    :lastValue(0)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    mDown = false;
    ParameterNr = -1;
    mHidemenu = 0;
    ParaSection = 0;

    repaint();
}

mixerGui::~mixerGui()
{
}

void mixerGui::mouseUp(const juce::MouseEvent& event)
{
    mDown = false;
}
//-----------gui dat-------

const int posmenuL = 7;
const int posmenuW = 150;

const int top = 0;
const int volSlidtop = 50;
const int volSlidT = 100;
const int volSlidL = 12;
const int posSW = 25;








void mixerGui::mouseDown(const juce::MouseEvent& event)
{
    mDown = true;
    const int hightY = event.getPosition().getY();
    const int widthX = event.getPosition().getX();
    if (hightY < 20 && widthX > posmenuL && widthX < posmenuL+posmenuW+30 ) {
        ParameterNr = 8;
        mHidemenu = ((float(widthX)-posmenuL) / (posmenuW+30)*4)+0.5 ;
        valueChanged(mHidemenu);
    }

    repaint();

}
int volumeMix[8] = { 70,70,70,70,70,70,70 };
int hertzMix[8] = { 50,50,50,50,50,50,50 };
int WaveNrMix[8] = { 1,1,1,1,1,1,1 };
int DelayMix[8] = { 0,0,0,0,0,0,0 };
int GateMix[8] = { 1,1,1,1,1,1,1,1 };

void mixerGui::mouseDrag(const MouseEvent& event)
{
    const int hightY = event.getPosition().getY();
    const int widthX = event.getPosition().getX();
    const int mHm = mHidemenu;
    if (mHm == 0) {
        if (hightY > volSlidtop && hightY < volSlidtop + volSlidT && widthX < volSlidL + posSW) {
            ParameterNr = 1;
            ParaSection = 1;
            volumeMix[0] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(volumeMix[0] * 0.01)));
            repaint(volSlidL, volSlidtop, posSW, 120);

        }

        if (hightY > volSlidtop && hightY < volSlidtop + volSlidT && widthX > volSlidL + posSW && widthX < volSlidL + (posSW*2)) {
            ParameterNr = 2;
            ParaSection = 2;
            volumeMix[1] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(volumeMix[1] * 0.01)));
            repaint(volSlidL + (posSW ), volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY <volSlidtop + volSlidT && widthX > volSlidL + (posSW * 2) && widthX < volSlidL + (posSW * 3)) {
            ParameterNr = 3;
            ParaSection = 3;
            volumeMix[2] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(volumeMix[2] * 0.01)));
            repaint(volSlidL + (posSW * 2), volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY <volSlidtop + volSlidT && widthX > volSlidL + (posSW * 3) && widthX < volSlidL + (posSW * 4)) {
            ParameterNr = 4;
            ParaSection = 4;
            volumeMix[3] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(volumeMix[3] * 0.01)));
            repaint(volSlidL + (posSW * 3), volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY <volSlidtop + volSlidT && widthX > volSlidL + (posSW * 4) && widthX < volSlidL + (posSW * 5)) {
            ParameterNr = 5;
            ParaSection = 5;
            volumeMix[4] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(volumeMix[4] * 0.01)));
            repaint(volSlidL + (posSW * 4), volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY <volSlidtop + volSlidT && widthX > volSlidL + (posSW * 5) && widthX < volSlidL + (posSW * 6)) {
            ParameterNr = 6;
            ParaSection = 6;
            volumeMix[5] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(volumeMix[5] * 0.01)));
            repaint(volSlidL + (posSW * 5), volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY <volSlidtop + volSlidT && widthX > volSlidL + (posSW * 6) && widthX < volSlidL + (posSW * 7)) {
            ParameterNr = 7;
            ParaSection = 7;
            volumeMix[6] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(volumeMix[6] * 0.01)));
            repaint(volSlidL + (posSW * 6), volSlidtop, posSW+10, 120);

        }
    }
    if (mHm == 1) {
        if (hightY > volSlidtop && hightY < volSlidtop + volSlidT && widthX < volSlidL + (posSW )) {
            ParameterNr = 10;
            ParaSection = 1;
            hertzMix[0] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(hertzMix[0] * 0.01)));
            repaint(volSlidL, volSlidtop, (posSW +10), 120);

        }

        if (hightY > volSlidtop && hightY < volSlidtop + volSlidT && widthX > volSlidL + (posSW ) && widthX < volSlidL + (posSW * 2)) {
            ParameterNr = 11;
            ParaSection = 2;
            hertzMix[1] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(hertzMix[1] * 0.01)));
            repaint(volSlidL + (posSW ), volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY <volSlidtop + volSlidT && widthX > volSlidL + (posSW * 2) && widthX < volSlidL + (posSW * 3)) {
            ParameterNr = 12;
            ParaSection = 3;
            hertzMix[2] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(hertzMix[2] * 0.01)));
            repaint(volSlidL + (posSW * 2), volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY <volSlidtop + volSlidT && widthX > volSlidL + (posSW * 3) && widthX < volSlidL + (posSW * 4)) {
            ParameterNr = 13;
            ParaSection = 4;
            hertzMix[3] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(hertzMix[3] * 0.01)));
            repaint(volSlidL + (posSW * 3), volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY <volSlidtop + volSlidT && widthX > volSlidL + (posSW * 4) && widthX < volSlidL + (posSW * 5)) {
            ParameterNr = 14;
            ParaSection = 5;
            hertzMix[4] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(hertzMix[4] * 0.01)));
            repaint(volSlidL + (posSW * 4), volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY <volSlidtop + volSlidT && widthX > volSlidL + (posSW * 5) && widthX < volSlidL + (posSW * 6)) {
            ParameterNr = 15;
            ParaSection = 6;
            hertzMix[5] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(hertzMix[5] * 0.01)));
            repaint(volSlidL + (posSW * 5), volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY <volSlidtop + volSlidT && widthX > volSlidL + (posSW * 6) && widthX < volSlidL + (posSW * 7)) {
            ParameterNr = 16;
            ParaSection = 7;
            hertzMix[6] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(hertzMix[6] * 0.01)));
            repaint(volSlidL + (posSW * 6), volSlidtop, posSW+10, 120);

        }
    }

    if (mHm == 2) {
        if (hightY > volSlidtop && hightY < volSlidtop + volSlidT && widthX < volSlidL + (posSW )) {
            ParameterNr = 17;
            ParaSection = 1;
            WaveNrMix[0] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(WaveNrMix[0] * 0.01) * 64));
            repaint(volSlidL, volSlidtop, (posSW + 10), 120);

        }

        if (hightY > volSlidtop && hightY < volSlidtop + volSlidT && widthX > volSlidL + (posSW) && widthX < volSlidL + (posSW * 2)) {
            ParameterNr = 18;
            ParaSection = 2;
            WaveNrMix[1] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(WaveNrMix[1] * 0.01) * 64));
            repaint(volSlidL + (posSW ), volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY <volSlidtop + volSlidT && widthX > volSlidL + (posSW * 2) && widthX < volSlidL + (posSW * 3)) {
            ParameterNr = 19;
            ParaSection = 3;
            WaveNrMix[2] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(WaveNrMix[2] * 0.01) * 64));
            repaint(volSlidL + (posSW * 2), volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY <volSlidtop + volSlidT && widthX > volSlidL + (posSW * 3) && widthX < volSlidL + (posSW * 4)) {
            ParameterNr = 20;
            ParaSection = 4;
            WaveNrMix[3] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(WaveNrMix[3] * 0.01) * 64));
            repaint(volSlidL + (posSW * 3), volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY <volSlidtop + volSlidT && widthX > volSlidL + (posSW * 4) && widthX < volSlidL + (posSW * 5)) {
            ParameterNr = 21;
            ParaSection = 5;
            WaveNrMix[4] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(WaveNrMix[4] * 0.01) * 64));
            repaint(volSlidL + (posSW * 4), volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY <volSlidtop + volSlidT && widthX > volSlidL + (posSW * 5) && widthX < volSlidL + (posSW * 6)) {
            ParameterNr = 22;
            ParaSection = 6;
            WaveNrMix[5] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(WaveNrMix[5] * 0.01) * 64));
            repaint(volSlidL + (posSW * 5), volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY <volSlidtop + volSlidT && widthX > volSlidL + (posSW * 6) && widthX < volSlidL + (posSW * 7)) {
            ParameterNr = 23;
            ParaSection = 7;
            WaveNrMix[6] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(WaveNrMix[6] * 0.01)*64));
            repaint(volSlidL + (posSW * 6), volSlidtop, posSW+10, 120);

        }
    }
    if (mHm == 3) {
        if (hightY > volSlidtop && hightY < volSlidtop + volSlidT && widthX < volSlidL + (posSW )) {
            ParameterNr = 24;
            ParaSection = 1;
            DelayMix[0] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(DelayMix[0] * 0.01) ));
            repaint(volSlidL, volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY < volSlidtop + volSlidT && widthX > volSlidL + (posSW ) && widthX < volSlidL + (posSW * 2)) {
            ParameterNr = 25;
            ParaSection = 2;
            DelayMix[1] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(DelayMix[1] * 0.01) ));
            repaint(volSlidL + (posSW ), volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY <volSlidtop + volSlidT && widthX > volSlidL + (posSW * 2) && widthX < volSlidL + (posSW * 3)) {
            ParameterNr = 26;
            ParaSection = 3;
            DelayMix[2] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(DelayMix[2] * 0.01) ));
            repaint(volSlidL + (posSW * 2), volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY <volSlidtop + volSlidT && widthX > volSlidL + (posSW * 3) && widthX < volSlidL + (posSW * 4)) {
            ParameterNr = 27;
            ParaSection = 4;
            DelayMix[3] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(DelayMix[3] * 0.01) ));
            repaint(volSlidL + (posSW * 3), volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY <volSlidtop + volSlidT && widthX > volSlidL + (posSW * 4) && widthX < volSlidL + (posSW * 5)) {
            ParameterNr = 28;
            ParaSection = 5;
            DelayMix[4] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(DelayMix[4] * 0.01) ));
            repaint(volSlidL + (posSW * 4), volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY <volSlidtop + volSlidT && widthX > volSlidL + (posSW * 5) && widthX < volSlidL + (posSW * 6)) {
            ParameterNr = 29;
            ParaSection = 6;
            DelayMix[5] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(DelayMix[5] * 0.01) ));
            repaint(volSlidL + (posSW * 5), volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY <volSlidtop + volSlidT && widthX > volSlidL + (posSW * 6) && widthX < volSlidL + (posSW * 7)) {
            ParameterNr = posSW+10;
            ParaSection = 7;
            DelayMix[6] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(DelayMix[6] * 0.01) ));
            repaint(volSlidL + (posSW * 6), volSlidtop, posSW+10, 120);

        }
    }
    if (mHm == 4) {
        if (hightY > volSlidtop && hightY < volSlidtop + volSlidT && widthX < volSlidL + (posSW )) {
            ParameterNr = 31;
            ParaSection = 1;
            GateMix[0] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(GateMix[0] * 0.01) ));
            repaint(volSlidL, volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY < volSlidtop + volSlidT && widthX > volSlidL + (posSW ) && widthX < volSlidL + (posSW * 2)) {
            ParameterNr = 32;
            ParaSection = 2;
            GateMix[1] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(GateMix[1] * 0.01) ));
            repaint(volSlidL + (posSW), volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY <volSlidtop + volSlidT && widthX > volSlidL + (posSW * 2) && widthX < volSlidL + (posSW * 3)) {
            ParameterNr = 33;
            ParaSection = 3;
            GateMix[2] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(GateMix[2] * 0.01) ));
            repaint(volSlidL + (posSW * 2), volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY <volSlidtop + volSlidT && widthX > volSlidL + (posSW * 3) && widthX < volSlidL + (posSW * 4)) {
            ParameterNr = 34;
            ParaSection = 4;
            GateMix[3] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(GateMix[3] * 0.01) ));
            repaint(volSlidL + (posSW * 3), volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY <volSlidtop + volSlidT && widthX > volSlidL + (posSW * 4) && widthX < volSlidL + (posSW * 5)) {
            ParameterNr = 35;
            ParaSection = 5;
            GateMix[4] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(GateMix[4] * 0.01) ));
            repaint(volSlidL + (posSW * 4), volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY <volSlidtop + volSlidT && widthX > volSlidL + (posSW * 5) && widthX < volSlidL + (posSW * 6)) {
            ParameterNr = 36;
            ParaSection = 6;
            GateMix[5] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(GateMix[5] * 0.01) ));
            repaint(volSlidL + (posSW * 5), volSlidtop, posSW+10, 120);

        }

        if (hightY > volSlidtop && hightY <volSlidtop + volSlidT && widthX > volSlidL + (posSW * 6) && widthX < volSlidL + (posSW * 7)) {
            ParameterNr = 37;
            ParaSection = 7;
            GateMix[6] = volSlidT - (hightY - volSlidtop);
            valueChanged((float(GateMix[6] * 0.01) ));
            repaint(volSlidL + (posSW * 6), volSlidtop, posSW+10, 120);

        }
    }
    else
        ParaSection = 0;



    
       
    GetParaNr();
}

void mixerGui::paint (juce::Graphics& g)
{
   

   // g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background
    g.setColour (juce::Colours::white);
    g.drawRect(getLocalBounds(), 2);
   
    g.setFont (14.0f);
 //   g.drawText ("mixer",100,0,100,20,
 //               juce::Justification::centred, true);   // draw some placeholder text

    drawSliders(g);
    drawButts(g);
}

void mixerGui::drawButts(juce::Graphics&g)
{

    

    g.setColour(juce::Colours::grey);
    const int nbM = mHidemenu;
    const int NbW = posmenuW / 4;

   g.fillRect(posmenuL , 5, NbW*5, 20);
   g.setColour(juce::Colours::whitesmoke);
    for (int i = 0; i < 5; i++) {

        g.setColour(juce::Colours::whitesmoke);
        g.fillRect(posmenuL+ (nbM * NbW),5 , NbW, 20);   //+
        g.setColour(juce::Colours::white);
        g.drawRect(posmenuL + (i * NbW), 5, NbW, 20);

    }
    g.setColour(juce::Colours::black);
    g.drawText("Gain", posmenuL, 5, NbW, 20,
        juce::Justification::centred, true);
    g.drawText("Tune", posmenuL+ NbW,5, NbW, 20,
        juce::Justification::centred, true);
    g.drawText("Wave", posmenuL + NbW*2, 5, NbW, 20,
        juce::Justification::centred, true);
    g.drawText("Dlay", posmenuL + NbW*3, 5, NbW, 20,
        juce::Justification::centred, true);
    g.drawText("Gate", posmenuL + NbW*4, 5, NbW, 20,
        juce::Justification::centred, true);

}

void mixerGui::drawSliders(juce::Graphics& g)
{
    const int mH = mHidemenu;
    g.setColour(juce::Colours::white);
    if (mH == 0) {
        for (int i = 0; i < 7; i++) {

            g.setColour(juce::Colours::red);
            g.fillRect(volSlidL + (i * posSW ), volSlidtop, posSW, volSlidT);
            g.setColour(juce::Colours::black);
            g.fillRect(volSlidL + (i * posSW), volSlidtop, posSW, volSlidT - (volumeMix[i]));   //+
            g.setColour(juce::Colours::white);
            g.drawRect(volSlidL + (i * posSW), volSlidtop, posSW, volSlidT);

        }
    }
    if (mH == 1) {

        for (int i = 0; i < 7; i++) {

            g.setColour(juce::Colours::seagreen);
            g.fillRect(volSlidL + (i * posSW), volSlidtop, posSW, volSlidT);
            g.setColour(juce::Colours::black);
            g.fillRect(volSlidL + (i * posSW), volSlidtop, posSW, volSlidT - (hertzMix[i]));   //+
            g.setColour(juce::Colours::white);
            g.drawRect(volSlidL + (i * posSW), volSlidtop, posSW, volSlidT);

        }
    }

    if (mH == 2) {

        for (int i = 0; i < 7; i++) {

            g.setColour(juce::Colours::yellow);
            g.fillRect(volSlidL + (i * posSW), volSlidtop, posSW, volSlidT);
            g.setColour(juce::Colours::black);
            g.fillRect(volSlidL + (i * posSW), volSlidtop, posSW, volSlidT - (WaveNrMix[i]));   //+
            g.setColour(juce::Colours::white);
            g.drawRect(volSlidL + (i * posSW), volSlidtop, posSW, volSlidT);

        }
    }
    if (mH == 3) {

        for (int i = 0; i < 7; i++) {

            g.setColour(juce::Colours::green);
            g.fillRect(volSlidL + (i * posSW), volSlidtop, posSW, volSlidT);
            g.setColour(juce::Colours::black);
            g.fillRect(volSlidL + (i * posSW), volSlidtop, posSW, volSlidT - (DelayMix[i]));   //+
            g.setColour(juce::Colours::white);
            g.drawRect(volSlidL + (i * posSW), volSlidtop, posSW, volSlidT);

        }
    }
    if (mH == 4) {

        for (int i = 0; i < 7; i++) {

            g.setColour(juce::Colours::blueviolet);
            g.fillRect(volSlidL + (i * posSW), volSlidtop, posSW, volSlidT);
            g.setColour(juce::Colours::black);
            g.fillRect(volSlidL + (i * posSW), volSlidtop, posSW, volSlidT - (GateMix[i]));   //+
            g.setColour(juce::Colours::white);
            g.drawRect(volSlidL + (i * posSW), volSlidtop, posSW, volSlidT);

        }
    }

   

   
}

void mixerGui::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

void mixerGui::inputValues(ParasSamplerControll& mp,int e)
{
    if(e==0)
    mp1 = mp;
    if (e == 1)
    mp2 = mp;
    if (e == 2)
    mp3 = mp;
    if (e == 3)
    mp4 = mp;
    if (e == 4)
    mp5 = mp;
    if (e == 5)
    mp6 = mp;
    if (e == 6)
    mp7 = mp;
   
    volumeMix[0] = mp1.mVolume*100;
    volumeMix[1] = mp2.mVolume*100;
    volumeMix[2] = mp3.mVolume*100;
    volumeMix[3] = mp4.mVolume*100;
    volumeMix[4] = mp5.mVolume * 100;
    volumeMix[5] = mp6.mVolume * 100;
    volumeMix[6] = mp7.mVolume * 100;
    
    hertzMix[0] = mp1.mWaveHertz * 100;
    hertzMix[1] = mp2.mWaveHertz * 100;
    hertzMix[2] = mp3.mWaveHertz * 100;
    hertzMix[3] = mp4.mWaveHertz * 100;
    hertzMix[4] = mp5.mWaveHertz * 100;
    hertzMix[5] = mp6.mWaveHertz * 100;
    hertzMix[6] = mp7.mWaveHertz * 100;
    

    WaveNrMix[0] = mp1.mWaveNumbr;
    WaveNrMix[1] = mp2.mWaveNumbr;
    WaveNrMix[2] = mp3.mWaveNumbr;
    WaveNrMix[3] = mp4.mWaveNumbr;
    WaveNrMix[4] = mp5.mWaveNumbr;
    WaveNrMix[5] = mp6.mWaveNumbr;
    WaveNrMix[6] = mp7.mWaveNumbr;

    DelayMix[0] = mp1.mDlWet*100;
    DelayMix[1] = mp2.mDlWet * 100;
    DelayMix[2] = mp3.mDlWet * 100;
    DelayMix[3] = mp4.mDlWet * 100;
    DelayMix[4] = mp5.mDlWet * 100;
    DelayMix[5] = mp6.mDlWet * 100;
    DelayMix[6] = mp7.mDlWet * 100;

    GateMix[0] = mp1.mGate * 100;
    GateMix[1] = mp2.mGate * 100;
    GateMix[2] = mp3.mGate * 100;
    GateMix[3] = mp4.mGate * 100;
    GateMix[4] = mp5.mGate * 100;
    GateMix[5] = mp6.mGate * 100;
    GateMix[6] = mp7.mGate * 100;
 
    repaint();
}


void mixerGui::valueChanged(float newValue)
{
    if (lastValue == newValue)
        return;
    lastValue = newValue;

    switch (GetParaNr()) {
    case 0:
        break;
        case 1:
            mp1.setVolume(lastValue);
            mp1.setVolume_t(lastValue);
           break;
        case 2:
            mp2.setVolume(lastValue);
            mp2.setVolume_t(lastValue);
            break;
        case 3:
            mp3.setVolume(lastValue);
            mp3.setVolume_t(lastValue);
            break;
        case 4:
            mp4.setVolume(lastValue);
            mp4.setVolume_t(lastValue);
            break;
        case 5:
            mp5.setVolume(lastValue);
            mp5.setVolume_t(lastValue);
            break;
        case 6:
            mp6.setVolume(lastValue);
            mp6.setVolume_t(lastValue);
            break;
        case 7:
            mp7.setVolume(lastValue);
            mp7.setVolume_t(lastValue);
            break;
        case 8:
           // mHidemenu=lastValue;
            mp1.setMixer(lastValue);
            mp2.setMixer(lastValue);
            mp3.setMixer(lastValue);
            mp4.setMixer(lastValue);
            mp5.setMixer(lastValue);
            mp6.setMixer(lastValue);
            mp7.setMixer(lastValue);
            break;
        case 10:
            mp1.setWaveFileHertz(lastValue);
            mp1.setPitch_t(lastValue);
            mp1.setSynthHertz(lastValue);
            break;
        case 11:
            mp2.setWaveFileHertz(lastValue);
            mp2.setSynthHertz(lastValue);
            mp2.setPitch_t(lastValue);
            break;
        case 12:
            mp3.setWaveFileHertz(lastValue);
            mp3.setSynthHertz(lastValue);
            mp3.setPitch_t(lastValue);
            break;
        case 13:
            mp4.setWaveFileHertz(lastValue);
            mp4.setSynthHertz(lastValue);
            mp4.setPitch_t(lastValue);
            break;
        case 14:
            mp5.setWaveFileHertz(lastValue);
            mp5.setSynthHertz(lastValue);
            mp5.setPitch_t(lastValue);
            break;
        case 15:
            mp6.setWaveFileHertz(lastValue);
            mp6.setSynthHertz(lastValue);
            mp6.setPitch_t(lastValue);
            break;
        case 16:
            mp7.setWaveFileHertz(lastValue);
            mp7.setSynthHertz(lastValue);
            mp7.setPitch_t(lastValue);
            break;
        case 17:
            mp1.setWaveNumr(lastValue);
            break;
        case 18:
            mp2.setWaveNumr(lastValue);
            break;
        case 19:
            mp3.setWaveNumr(lastValue);
            break;
        case 20:
            mp4.setWaveNumr(lastValue);
            break;
        case 21:
            mp5.setWaveNumr(lastValue);
            break;
        case 22:
            mp6.setWaveNumr(lastValue);
            break;
        case 23:
            mp7.setWaveNumr(lastValue);
            break;
        case 24:
            mp1.setDelayMix(lastValue);
            break;
        case 25:
            mp2.setDelayMix(lastValue);
            break;
        case 26:
            mp3.setDelayMix(lastValue);
            break;
        case 27:
            mp4.setDelayMix(lastValue);
            break;
        case 28:
            mp5.setDelayMix(lastValue);
            break;
        case 29:
            mp6.setDelayMix(lastValue);
            break;
        case 30:
            mp7.setDelayMix(lastValue);
            break;
        case 31:
            mp1.setGate(lastValue);
            break;
        case 32:
            mp2.setGate(lastValue);
            break;
        case 33:
            mp3.setGate(lastValue);
            break;
        case 34:
            mp4.setGate(lastValue);
            break;
        case 35:
            mp5.setGate(lastValue);
            break;
        case 36:
            mp6.setGate(lastValue);
            break;
        case 37:
            mp7.setGate(lastValue);
            break;
        case 40:
           
            mp1.setVolumeAll(lastValue,0);
            mp2.setVolumeAll(lastValue, 1);
            mp3.setVolumeAll(lastValue, 2);
            mp4.setVolumeAll(lastValue, 3);
            mp5.setVolumeAll(lastValue, 4);
            mp6.setVolumeAll(lastValue, 5);
            mp7.setVolumeAll(lastValue, 6);
           
            break;
        case 41:
            mp1.setPitchAll(lastValue, 0);
            mp2.setPitchAll(lastValue, 1);
            mp3.setPitchAll(lastValue, 2);
            mp4.setPitchAll(lastValue, 3);
            mp5.setPitchAll(lastValue, 4);
            mp6.setPitchAll(lastValue, 5);
            mp7.setPitchAll(lastValue, 6);
               
            break;
        case 42:
            break;
        case 43:
            break;
        case 44:
            break;
    default:
        break;
    }
   
    if (onValueChanged != nullptr)
        onValueChanged();
}
