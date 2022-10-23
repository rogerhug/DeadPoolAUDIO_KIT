/*
  ==============================================================================

    mainGui.cpp
    Created: 5 Oct 2022 7:05:52pm
    Author:  lutz

  ==============================================================================
*/

#include <JuceHeader.h>
#include "mainGui.h"

//==============================================================================
mainGui::mainGui(AudioProcessorValueTreeState& vts)
    :valueTreeStateMain(vts)
    , lastValue(0)
{
    ParameterNr = 0;
    mDown = false;
    mpcM = new ParasMainControll();
    UstateParas = new float[60];
    for (int i = 0; i < 60; i++) 
    UstateParas[i] = mpcM->getMainParas()[i];
    
}

mainGui::~mainGui()
{
}
//---------xY_datas----------------
const int top = 10;

//---------engineNr------
const int posEngNrL = 10;
const int posEngNrT = 260;
const int posEngNrW = 40;
const int posEngNrH = 50;

//----------timersource
const int posTimerInL = 330;
const int posTimerInT = top;
const int posTimerInW = 120;
//---------timerbpm---
const int posTimebpL = 600;
const int posTimebpT = top;
const int posTimebpW = 160;
//--------timerdiv-----
const int posTimeDivL = 300;
const int posTimeDivT = top+25;
const int posTimeDivW = 180;


//-------StartStop timer---
const int posStartStopL = 10;
const int posStartStopT = top+200;
const int posStartStopW = 100;

//-------sequenceNr-----
const int posSeqNrL = 590;
const int posSeqNrT = top+200;
const int posSeqNrW = 180;
//------sequence lenght--
const int posSeqLenghtL = 70;
const int posSeqLenghtT = top+330;
const int posSeqLenghtW = 700;

//-------masterGain
const int posMasterGainL = 290;
const int posMasterGainT = top+100;
const int posMasterGainW = 70;

//-------masterPitch
const int posMasterPitchL = 420;
const int posMasterPitchT = top+100;
const int posMasterPitchW = 70;



void mainGui::mouseUp(const juce::MouseEvent& event)
{
    mDown = false;
    ParameterNr = 0;
}

void mainGui::mouseDown(const juce::MouseEvent& event)
{
    mDown = true;

    const int hightY = event.getPosition().getY();
    const int widthX = event.getPosition().getX();

    //----------------engineNr_but----------------
    if (widthX > posEngNrL && widthX < posEngNrL + posEngNrW && hightY > posEngNrT && hightY < posEngNrT + posEngNrH) {
        ParameterNr = 1;
        mpcM->mEngineNb = ((float(hightY) - posEngNrT) / posEngNrH) *2;
        valueChanged(mpcM->mEngineNb);
        repaint(posEngNrL, posEngNrT, 700, 160);

    }
    //-----------------TimerIn_but-------------
    if (widthX > posTimerInL && widthX < posTimerInL + posTimerInW && hightY > posTimerInT && hightY < posTimerInT + 20) {
        ParameterNr = 2;
        mpcM->mTimeIn = ((float(widthX) - posTimerInL) / posTimerInW)*3 ;
        valueChanged(mpcM->mTimeIn);
        repaint(posTimerInL, posTimerInT, posTimerInW, 20);

    }
    //-----------------TimerDiv_but---------------
    if (widthX > posTimeDivL && widthX < posTimeDivL + posTimeDivW && hightY > posTimeDivT && hightY < posTimeDivT + 50) {
        ParameterNr = 3;
        mpcM->setTimeDivideSwitch((((float(hightY) - posTimeDivT) / 50) * 2) + 1);
        mpcM->setTimeDivide(((float(widthX) - posTimeDivL) / posTimeDivW), mpcM->mTime_divide_switch);
        valueChanged(mpcM->mTime_divide);
        repaint(posTimeDivL, posTimeDivT, posTimeDivW, 50);

    }
    //-----------------sequenceNr_but------------
    if (widthX > posSeqNrL && widthX < posSeqNrL + posSeqNrW && hightY > posSeqNrT && hightY < posSeqNrT + 20) {
        ParameterNr = 4;
        mpcM->mSeqenceNr = ((float(widthX) - posSeqNrL) / posSeqNrW)*3;
        valueChanged(mpcM->mSeqenceNr);
        repaint(posSeqNrL, posSeqNrT, posSeqNrW, 20);

    }

    //-----------------StartStop_but------------

    if (widthX > posStartStopL && widthX < posStartStopL + posStartStopW && hightY > posStartStopT && hightY < posStartStopT + 20) {
        ParameterNr = 5;
        mpcM->mStartStop = ((float(widthX) - posStartStopL) / posStartStopW) * 2;
        valueChanged(mpcM->mStartStop);
        repaint(posStartStopL, posStartStopT, posStartStopW, 20);

    }
}

void mainGui::mouseDrag(const MouseEvent& event)
{

    const int hightY = event.getPosition().getY();
    const int widthX = event.getPosition().getX();

    //--------------Timerbpm_slider--------------------
    if (widthX > posTimebpL && widthX < posTimebpL + posTimebpW && hightY > posTimebpT && hightY < posTimebpT + 20) {
        ParameterNr = 6;
        mpcM->mTimeBpm = ((float(widthX) - posTimebpL) / posTimebpW);
        valueChanged(mpcM->mTimeBpm);
        repaint(posTimebpL-60, posTimebpT, posTimebpW+70, 20);

    }

    //-------------SequencerLenght_slider------..........


    if (widthX > posSeqLenghtL && widthX < posSeqLenghtL + posSeqLenghtW && hightY > posSeqLenghtT && hightY < posSeqLenghtT + 20) {
        ParameterNr = 7;
        mpcM->mSequenceLenght = ((float(widthX) - posSeqLenghtL) / posSeqLenghtW);
        valueChanged(mpcM->mSequenceLenght);
        repaint(posSeqLenghtL-60, posSeqLenghtT, posSeqLenghtW+60 , 20);

    }
    //-----------------MasterGain----------------------------
    if (hightY > posMasterGainT && hightY < posMasterGainT + posMasterGainW && widthX > posMasterGainL && widthX < posMasterGainL + posMasterGainW) {
        ParameterNr = 8;
        mpcM->mMasterGain = 1 - ((float(hightY) - posMasterGainT) / posMasterGainW);
        valueChanged(mpcM->mMasterGain);
        repaint(posMasterGainL, posMasterGainT, posMasterGainW + 20, posMasterGainW + 20);

    }

    if (hightY > posMasterPitchT && hightY < posMasterPitchT + posMasterPitchW && widthX > posMasterPitchL && widthX < posMasterPitchL + posMasterPitchW) {
        ParameterNr = 9;
        mpcM->mMasterPitch = 1 - ((float(hightY) - posMasterPitchT) / posMasterPitchW);
        valueChanged(mpcM->mMasterPitch);
        repaint(posMasterPitchL, posMasterPitchT, posMasterPitchW + 20, posMasterPitchW + 20);

    }
}

void mainGui::paint (juce::Graphics& g)
{
    drawbuts(g);
    drawSliders(g);
}

void mainGui::drawbuts(juce::Graphics&g)
{

    //----------engine_buts------------

    g.setColour(Colours::lightgreen);
    g.fillRect(posEngNrL, posEngNrT, posEngNrW ,posEngNrH-10);
    const int embH = posEngNrW / 2;
    g.setColour(Colours::whitesmoke);
    const int emodbut = (posEngNrT)+(embH * int(mpcM->mEngineNb));
    g.fillRect(posEngNrL, emodbut, posEngNrW, embH);

    g.setColour(juce::Colours::black);
    
    g.drawText("Sp1", posEngNrL + 10, posEngNrT ,posEngNrW, 20, juce::dontSendNotification);
    g.drawText("Sp2", posEngNrL + 10, posEngNrT + embH, posEngNrW, 20, juce::dontSendNotification);
   


    //-------timerIn buts-------------------

 
    g.setColour(Colours::grey);
    g.fillRect(posTimerInL, posTimerInT, posTimerInW, 20);
    const int embHTi = posTimerInW / 3;
    g.setColour(Colours::whitesmoke);
    const int emodHtibut = (posTimerInL)+(embHTi * int(mpcM->mTimeIn));
    g.fillRect(emodHtibut, posTimerInT, embHTi, 20);

    g.setColour(juce::Colours::black);

    g.drawText("Int", posTimerInL + 10, posTimerInT, embHTi, 20, juce::dontSendNotification);
    g.drawText("VstS", posTimerInL + embHTi, posTimerInT,  embHTi,20, juce::dontSendNotification);
    g.drawText("VstP", posTimerInL + (embHTi*2), posTimerInT, embHTi,20, juce::dontSendNotification);
    g.setColour(juce::Colours::white);
   // g.drawText("TimeSource->",10, posTimerInT, 100, 20, juce::dontSendNotification);

    //--------------timerdiv-buts----------------------------------------

    g.setColour(juce::Colours::grey);
    const int rowT = 20;
    const int pw = posTimeDivW / 5;
    g.fillRect(posTimeDivL, posTimeDivT, posTimeDivW, rowT);
    g.fillRect(posTimeDivL, posTimeDivT + 30, posTimeDivW, rowT);
    g.setColour(juce::Colours::antiquewhite);
    const int but_onTmDiv = (mpcM->mTime_divide * 5);
    if (int(mpcM->mTime_divide_switch) == 1)
        g.fillRect(posTimeDivL + but_onTmDiv * pw, posTimeDivT, pw, rowT);
    else
        if (int(mpcM->mTime_divide_switch) == 2)
            g.fillRect(posTimeDivL + but_onTmDiv * pw, posTimeDivT + 30, pw, rowT);
    g.setColour(juce::Colours::white);
    for (int i = 0; i < 6; i++) {
        g.drawRect(posTimeDivL, posTimeDivT, i * pw, rowT);
        g.drawRect(posTimeDivL, posTimeDivT + 30, i * pw, rowT);
    }
    g.setColour(juce::Colours::black);
    g.drawText("4/1",  posTimeDivL + 4, posTimeDivT, pw, rowT, juce::dontSendNotification);
    g.drawText("2/1", posTimeDivL + pw, posTimeDivT, pw, rowT, juce::dontSendNotification);
    g.drawText("1/1",  posTimeDivL + pw * 2, posTimeDivT, pw, rowT, juce::dontSendNotification);
    g.drawText("1/2",  posTimeDivL + pw * 3, posTimeDivT, pw, rowT, juce::dontSendNotification);
    g.drawText("1/4",  posTimeDivL + pw * 4, posTimeDivT, pw, rowT, juce::dontSendNotification);

    g.drawText("1/8",  posTimeDivL + 4, posTimeDivT + 30, pw, rowT, juce::dontSendNotification);
    g.drawText("1/12",  posTimeDivL + pw, posTimeDivT + 30, pw, rowT, juce::dontSendNotification);
    g.drawText("1/16",  posTimeDivL + pw * 2, posTimeDivT + 30, pw, rowT, juce::dontSendNotification);
    g.drawText("1/24",  posTimeDivL + pw * 3, posTimeDivT + 30, pw, rowT, juce::dontSendNotification);
    g.drawText("1/32",  posTimeDivL + pw * 4, posTimeDivT + 30, pw, rowT, juce::dontSendNotification);
    //----------------Timer Start stop but-------------------

    g.setColour(Colours::grey);
    g.fillRect(posStartStopL, posStartStopT, posStartStopW, 20);
    const int embHTids = posStartStopW / 2;
    g.setColour(Colours::whitesmoke);
    const int emodHtidsbut = (posStartStopL)+(embHTids * int(mpcM->mStartStop));
    g.fillRect(emodHtidsbut, posStartStopT, embHTids, 20);

    g.setColour(juce::Colours::black);

    g.drawText("stop", posStartStopL +10, posStartStopT, embHTids, 20, juce::dontSendNotification);
    g.drawText("start", posStartStopL + embHTids+10, posStartStopT, embHTids, 20, juce::dontSendNotification);

    //------------SequencerNb but-----------------------

    g.setColour(Colours::grey);
    g.fillRect(posSeqNrL, posSeqNrT, posSeqNrW, 20);
    const int embHTids12 = posSeqNrW / 3;
    g.setColour(Colours::whitesmoke);
    const int emodHtids12but = (posSeqNrL)+(embHTids12 * int(mpcM->mSeqenceNr));
    g.fillRect(emodHtids12but, posSeqNrT, embHTids12, 20);

    g.setColour(juce::Colours::black);

    g.drawText("seq1", posSeqNrL, posSeqNrT, embHTids12, 20, juce::dontSendNotification);
    g.drawText("seq2", posSeqNrL + embHTids12, posSeqNrT, embHTids12, 20, juce::dontSendNotification);
    g.drawText("1+2", posSeqNrL + (embHTids12*2), posSeqNrT, embHTids12, 20, juce::dontSendNotification);

   

}

void mainGui::drawSliders(juce::Graphics&g)
{ 
    
    //------------------------------main master pitch gain----------------


    g.setFont(juce::Font("Consolas", 17.0f, juce::Font::bold));
    g.setColour(juce::Colours::white);
    int x = posMasterGainL;
    int y = posMasterGainT;
    int width = posMasterGainW;
    int height = posMasterGainW;
    float sliderPos = (mpcM->mMasterGain * 10);
    float rotaryStartAngle = 3.5;
    float rotaryEndAngle = 4.05;
    g.drawEllipse(x, y, width, height, 2);
    auto radius = (float)jmin(width / 2, height / 2) - 2.0f;
    auto centreX = (float)x + (float)width * 0.5f;
    auto centreY = (float)y + (float)height * 0.5f;
    auto rx = centreX - radius;
    auto ry = centreY - radius;
    auto rw = radius * 2.0f;
    auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    g.setColour(Colours::whitesmoke);
    Path filledArc;
    filledArc.addPieSegment(rx, ry, rw, rw, rotaryStartAngle, angle, 0.0);
    g.fillPath(filledArc);
    g.setColour(Colours::white);
    char dw[3] = "0";
    sprintf(dw, "%.2f", mpcM->mMasterGain);
    g.drawText("Gain", posMasterGainL - 10, posMasterGainT + posMasterGainW, 50, 20, juce::dontSendNotification);
    g.drawText(dw, posMasterGainL + 30, posMasterGainT + posMasterGainW, 40, 20, juce::dontSendNotification);


    int xp = posMasterPitchL;
    int yp = posMasterPitchT;
    float sliderPosP = (mpcM->mMasterPitch * 10);
    g.drawEllipse(xp, yp, width, height, 2);
    auto radiusP = (float)jmin((width) / 2, height / 2) - 2.0f;
    auto centreXP = (float)xp + (float)width * 0.5f;
    auto centreYP = (float)(yp)+(float)height * 0.5f;
    auto rxP = centreXP - radius;
    auto ryP = centreYP - radius;
    auto rwP = radius * 2.0f;
    auto angleP = rotaryStartAngle + sliderPosP * (rotaryEndAngle - rotaryStartAngle);
    g.setColour(Colours::whitesmoke);
    Path filledArcP;
    filledArcP.addPieSegment(rxP, ryP, rwP, rwP, rotaryStartAngle, angleP, 0.0);
    g.fillPath(filledArcP);

    g.setColour(Colours::white);
    g.drawText("rate", posMasterPitchL - 15, posMasterPitchT + posMasterPitchW, 40, 20, juce::dontSendNotification);
    char dwp[3] = "0";
    sprintf(dwp, "%.0f", mpcM->mMasterPitch* (mpcM->mSampelRate * 2));
    g.drawText(dwp, posMasterPitchL + 30, posMasterPitchT + posMasterPitchW, 70, 20, juce::dontSendNotification);

    //------------------------------timer bpm slider-------------------------------
    char sb[3] = "0";
    sprintf(sb, "%i", 1 + int(mpcM->mTimeBpm * 200));
    const int msbp = mpcM->mTimeBpm * posTimebpW;
    g.setColour(juce::Colours::whitesmoke);
    g.fillRect(posTimebpL, posTimebpT, posTimebpW,  20);
    g.setColour(juce::Colours::grey);
    g.drawRect(posTimebpL, posTimebpT, posTimebpW, 20, 2);
    g.fillRect(posTimebpL, posTimebpT, (msbp), 20);
    g.setColour(juce::Colours::white);
   
    g.drawRect(posTimebpL, posTimebpT, posTimebpW, 20);

    g.setColour(juce::Colours::whitesmoke);

    g.fillRect(posTimebpL - 45, posTimebpT + 1, 35, 20 - 2);
    g.setColour(juce::Colours::black);
   g.drawText("BP/Minute", posTimebpL + 20, posTimebpT, posSeqLenghtW, 20, juce::dontSendNotification);
    g.drawText(sb, posTimebpL - 40, posTimebpT, 30, 20, juce::dontSendNotification);



    //------------------------------sequenceLenght------------------------------

    char sl[3] = "0";
    sprintf(sl, "%i", 1 + int(mpcM->mSequenceLenght*31));
    const int msl = float(mpcM->mSequenceLenght) * posSeqLenghtW;
    g.setColour(juce::Colours::blue);
    g.drawRect(posSeqLenghtL, posSeqLenghtT, posSeqLenghtW, 20, 2);
    g.fillRect(posSeqLenghtL , posSeqLenghtT, (msl), 20);
    g.setColour(juce::Colours::white);
    g.drawText("Sequencelenght", posSeqLenghtL + 200, posSeqLenghtT, posSeqLenghtT, 20, juce::dontSendNotification);
    g.drawRect(posSeqLenghtL, posSeqLenghtT, posSeqLenghtW, 20);

    g.setColour(juce::Colours::blue);

    g.fillRect(posSeqLenghtL -62, posSeqLenghtT + 1, 40, 20 - 2);
    g.setColour(juce::Colours::black);

    g.drawText(sl, posSeqLenghtL - 55, posSeqLenghtT, 30,20, juce::dontSendNotification);



}

void mainGui::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

void mainGui::initMainParas()
{
}
String Usname = { "-" };
char serialMainParas[300] = { "-" };
void mainGui::serialParas(AudioProcessorValueTreeState& valueTreeState, String name)
{
  
    float x = 0.00;
    sprintf(serialMainParas,

        "%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f"
        , mpcM->mEngineNb, mpcM->mTimeIn, mpcM->mTime_divide_switch, mpcM->mTime_divide, mpcM->mTimeBpm, mpcM->mSeqenceNr, x
        , mpcM->mMasterGain, mpcM->mMasterPitch, mpcM->mSequenceLenght,
        x, x, x, x, x, x, x, x, x, x, x, x, x, x,x

    );

    valueTreeState.state.setProperty(name, var(serialMainParas), nullptr);
    MainStateParas.setValue(var(serialMainParas));
}

void mainGui::unSerialParas(AudioProcessorValueTreeState& valueTreeState, String name)
{
 
    MainStateParas.referTo(valueTreeState.state.getPropertyAsValue(name, nullptr, true));
    for (int i = 0; i <= 300; i += 5) {
        UstateParas[i / 5] = MainStateParas.getValue().toString().substring(i, i + 4).getFloatValue();
    }
    
     mpcM->setEngineNr(0);
     mpcM->setTimerIn(0);
   
    mpcM->setTimeDivideSwitch(UstateParas[2]);
    mpcM->setTimeDivide(UstateParas[3],mpcM->mTime_divide_switch);
    mpcM->getTimeDivAll();

    mpcM->setTimeBp(UstateParas[4]);



    mpcM->setSequenceNr(UstateParas[5]);
    //void  UstateMain[6];
    mpcM->setMasterGain(UstateParas[7]);
    mpcM->setmasterPitch(UstateParas[8]);
    mpcM->setSequenceLenght(UstateParas[9]);
    
    repaint();

}

void mainGui::valueChanged(float newValue)
{
    if (lastValue == newValue)
        return;
    lastValue = newValue;

    switch (GetParaNr()) {
    case 0:

        break;
    case 1:
        mpcM->setEngineNr(lastValue);
        break;
    case 2:
        mpcM->setTimerIn(lastValue);
        break;
    case 3:
        mpcM->setTimeDivide(lastValue,mpcM->mTime_divide_switch);
        break;
    case 4:
        mpcM->setSequenceNr(lastValue);
        break;
    case 5:
        mpcM->setStartStop(lastValue);
        break;
    case 6:
        mpcM->setTimeBp(lastValue);
        break;
    case 7:
        mpcM->setSequenceLenght(lastValue);
        break;
    case 8:
        mpcM->setMasterGain(lastValue);
       break;
    case 9:
        mpcM->setmasterPitch(lastValue);
        break;
    default:
        break;
    };
    if (onValueChanged != nullptr)
        onValueChanged();
}
