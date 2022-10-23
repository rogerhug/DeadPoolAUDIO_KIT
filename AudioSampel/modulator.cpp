/*
  ==============================================================================

    modulator.cpp
    Created: 23 Apr 2022 10:20:30am
    Author:  r7

  ==============================================================================
*/

#include <JuceHeader.h>
#include "modulator.h"

//==============================================================================
modulator::modulator(AudioProcessorValueTreeState& vts)
:lastValue(0.00f)
,valueTreeStateMod(vts)
, ParameterNr(0.00f)
, mDown(false)
, engineMode(0)
, KSlidePosModulator(0)
, KSliderPosModOut (0)
, mFormbut(0)
, Ktimebuts(50)
, mTimebut(2)

,KmodulatorOn(0)
,mCount(0)
,mBpm(120)

{
  
    steppValues = new int[STEPPERSIZE];
    stepperValu = new float[STEPPERSIZE];
    stepperValueMod = new float[STEPPERSIZE];
    ModOutValues = new int[STEPPERSIZE];


 
 

    for (int i = 0; i < STEPPERSIZE; i++) {
        steppValues[i] = sin(i / (double)STEPPERSIZE * double_Pi ) * 85;
        stepperValu[i] = sin(i / (double)STEPPERSIZE * double_Pi);
        ModOutValues[i] = 0;
       stepperValueMod[i] = 0;
    }
   
   

    startTimer(1);
    startTimerHz(30);
    stepValuesOut();
    stepAmpValuesOut();


    repaint();
}

modulator::~modulator()
{
}
int xf = 0;
int yf = 0;
bool tf = false;
inline int minmax100(int a) {
    int result = 0; result = a;
    if (result > 100) { result = 100; }
    if (result < 0) { result = 0; }
    return result;
}
inline double minmax1(double a) {
    double result = 0; result = a;
    if (result > 1) { result = 1; }
    if (result < 0) { result = 0; }
    return result;
   
} 

const int top = 0;
const int row = 18;
//-------------stepper---------
const int posStepsLeft= 0;
const int posStepsWidth = 128;
const int posstepSL = 8;
const int posStepsTop = 20;
const int posStepsHight = 80;
//------------timebuts
const int posTimeLeft = 0;
const int posTimeWidth = 100;
const int posTimeRowWidth = 25;
//------------form buts----
const int formbL = 140;
//-----------mod out slider
const int modSL = 190;


void modulator::mouseDown(const juce::MouseEvent& event)
{
   
    mDown = true;
    mouseDrag(event);
    
}

char modparasC[100] = { "" };
void modulator::mouseDrag(const MouseEvent& event)
{ 

     const int hightY = event.getPosition().getY();
     const int widthX = event.getPosition().getX();

     KSlidePosModulator = (float(widthX)/ posStepsWidth)*15;

        if (widthX < posStepsWidth+posstepSL && hightY > posStepsTop && hightY < posStepsTop +posStepsHight) {
          
            steppValues[KSlidePosModulator] = hightY - posStepsTop;
            stepperValu[KSlidePosModulator] = 1-((float(hightY) - posStepsTop) / posStepsHight) ;
       
            ParameterNr = 1;
            valueChanged(stepperValu[KSlidePosModulator]);
            stepValuesOut();
          repaint(0, 0, posStepsWidth +posStepsWidth+30, posStepsHight +30);
        }
        else
        if (widthX > posTimeLeft && widthX < posTimeLeft+(posTimeRowWidth * 5) && hightY > top && hightY< row) {
           ParameterNr = 3;
           if (widthX > posTimeLeft && widthX < posTimeLeft+posTimeRowWidth)
           mTimebut = 0;
           if (widthX > posTimeLeft+posTimeRowWidth && widthX < posTimeLeft + (posTimeRowWidth*2))
               mTimebut = 1;
           if (widthX > posTimeLeft + (posTimeRowWidth * 2) && widthX < posTimeLeft + (posTimeRowWidth * 3))
               mTimebut = 2;
           if (widthX > posTimeLeft + (posTimeRowWidth * 3) && widthX < posTimeLeft + (posTimeRowWidth * 4))
                mTimebut = 3;
           if (widthX > posTimeLeft + (posTimeRowWidth * 4) && widthX < posTimeLeft + (posTimeRowWidth * 5))
               mTimebut = 4;
           valueChanged(mTimebut);
           repaint(posTimeLeft, top, posTimeLeft + (posTimeRowWidth * 5)+20, row+20);
           
        }
        else
        if (widthX > formbL && widthX < formbL +30 && hightY > top && hightY < row*7) {
       
            if (hightY > top && hightY < row)
                mFormbut = 0;
            if (hightY > top +row && hightY < (row*2))
                mFormbut = 1;
            if (hightY > top + (row * 2) && hightY < (row * 3))
                mFormbut = 2;
            if (hightY > top + (row * 3) && hightY < (row * 4))
                mFormbut = 3;
            if (hightY > top + (row * 4) && hightY < (row * 5))
                mFormbut = 4;
            if (hightY > top + (row * 5) && hightY < (row * 6))
                mFormbut = 5;
            if (hightY > top + (row * 6) && hightY < (row * 7))
                mFormbut = 6;
            ParameterNr = 4;
        
            repaint(formbL, top, formbL+50,20+ row * 7);
            const int c = mFormbut;
            initCurve(c);
            repaint(0, 0, posStepsWidth + posStepsWidth + 30, posStepsHight + 30);
            valueChanged(mFormbut);
          //  stepValuesOut();
        }
        else
        if (widthX > modSL && widthX < modSL+80 && hightY > top && hightY < top+(row*7)) {
                 KSliderPosModOut = hightY / row;
                 ParameterNr = 2;
            
                ModOutValues[KSliderPosModOut] = widthX - (modSL+1);
                stepperValueMod[KSliderPosModOut] = float(ModOutValues[KSliderPosModOut]) * 0.01;
                valueChanged(stepperValueMod[KSliderPosModOut]);
                stepAmpValuesOut();
                repaint(modSL , top, 130, 140);

        }
        
        int nb = 0;
        for (int i = 0; i < 16; i++) {
            nb++;
            sprintf(&modparasC[nb - 1], "%d", stepperValu[i]);
        }
     
       
}
char lbt[20]{ "0" };
void modulator::paint(juce::Graphics& g)

{
 
    g.setColour(juce::Colours::white);

    sprintf(lbt, "p1 %i::p2 %i ", 0, mCount);

    g.drawRect(400, 0, getWidth(), getHeight(), 1);

    drawForm(g);
    drawButts(g);
    drawModOut(g);
   
   // drawTextOut(g);
    if (ParameterNr != 1)
        drawCount(g);
}

void modulator::mouseUp(const juce::MouseEvent& event)
{
    mDown = false;
    ParameterNr = -1;
  
}



void modulator::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

void modulator::timerCallback()
{ 
   
}

void modulator::drawForm(juce::Graphics& g)
{

    const int heightM = (posStepsHight  / 2);
    auto colorOn = juce::Colours::red;

    
  
       g.setColour(juce::Colours::white);

       for (int i = 0; i < STEPPERSIZE; i++) {
        
         
              
          g.setColour(juce::Colours::white);
           if (steppValues[i] < 40) {
               g.fillRect(i* posstepSL, posStepsTop+ steppValues[i], posstepSL-1,heightM- steppValues[i]);   //+
        
           }
           else {
               g.fillRect(i* posstepSL, posStepsTop+ heightM, posstepSL-1, steppValues[i]- heightM);
      
           }


       }



    
}

void modulator::drawModOut(juce::Graphics& g)
{
   
    g.setColour(juce::Colours::lightslategrey);
       g.fillRect(modSL  , 0, ModOutValues[0], row);
       g.fillRect(modSL, row, ModOutValues[1] , row);
       g.fillRect(modSL, (row * 2), ModOutValues[2] , row );
       g.fillRect(modSL, (row * 3), ModOutValues[3] , row);
       g.fillRect(modSL, (row * 4), ModOutValues[4] , row );
       /*
       if (engineMode > 0) {
           g.fillRect(modSL, (row * 5), ModOutValues[5], row);
           g.fillRect(modSL, (row * 6), ModOutValues[6], row);
             g.setColour(juce::Colours::white);
             for (int i = 0; i < 2; i++)
                 g.drawRect(modSL, top + (row * 5) +i * row, 80, row);
              g.drawText("WaveStart", modSL + 20, top + (row * 5), 60, row, juce::Justification::centred, true);
             g.drawText("WaveEnd", modSL + 20, top + (row * 6),  60, row, juce::Justification::centred, true);
       }
       */
       g.setColour(juce::Colours::white);
       for (int i = 0; i < 5; i++)
       g.drawRect(modSL, top  + i * row, 80, row);
      
    g.drawText("Pitch", modSL+10, top, 60, row, juce::Justification::centred, true);
    g.drawText("Cut", modSL + 10, top+row , 60, row, juce::Justification::centred, true);
    g.drawText("Vol", modSL + 10, top + (row*2), 60, row, juce::Justification::centred, true);
    g.drawText("DelayT", modSL + 10, top + (row * 3), 60, row, juce::Justification::centred, true);
    g.drawText("DelayF", modSL + 10, top + (row * 4), 60, row, juce::Justification::centred, true);


   //------------------tempo/Bpm----------------------
    /*
    g.setColour(juce::Colours::red);
    g.fillRect(5, 0, 95, 20);
    g.setColour(juce::Colours::white);
    g.drawRect(5, 0, 95, 20);
    g.fillRect(5+mBpm,0, 95 - mBpm, 19);
    g.setColour(juce::Colours::black);
    char bp[10] = { "" };
    sprintf(bp,"TimerBpm %i", mBpm*3);
    g.drawText(bp,5, 0, 95, 20,  juce::Justification::centred, true);

    */
}

void modulator::drawButts(juce::Graphics& g)
{
    
     g.setColour(juce::Colours::green);
     for (int i = 0; i < 5; i++) 
     g.drawRect(posTimeLeft+i* posTimeRowWidth,top, posTimeRowWidth, row);
     const int f = mTimebut * posTimeRowWidth;
     g.fillRect(posTimeLeft+(f), top, posTimeRowWidth, row);

     g.setColour(juce::Colours::white);
    g.drawText("1/4", posTimeLeft, top, posTimeRowWidth, row, juce::Justification::centred, true);
    g.drawText("1/2", posTimeLeft+ posTimeRowWidth, top, posTimeRowWidth, row, juce::Justification::centred, true);
    g.drawText("_1_", posTimeLeft+(posTimeRowWidth *2), top, posTimeRowWidth, row, juce::Justification::centred, true);
    g.drawText("1*2", posTimeLeft + (posTimeRowWidth * 3), top, posTimeRowWidth, row, juce::Justification::centred, true);
    g.drawText("1*4", posTimeLeft + (posTimeRowWidth * 4), top, posTimeRowWidth, row, juce::Justification::centred, true);
   
    const int fbutRW = 40;
    const int fb = top + (mFormbut * row);
    g.setColour(juce::Colours::green);
    for (int i = 0; i < 7; i++)
    g.drawRect(formbL, top+ i * row , fbutRW, row);
    g.fillRect(formbL, fb, fbutRW, row);

    g.setColour(juce::Colours::white);
    g.drawText("zero", formbL, top, fbutRW, row, juce::Justification::centred, true);
    g.drawText("sine", formbL, top+row , fbutRW, row, juce::Justification::centred, true);
    g.drawText("sawup", formbL, top+(row*2), fbutRW, row, juce::Justification::centred, true);
    g.drawText("sawdn", formbL, top + (row * 3), fbutRW, row, juce::Justification::centred, true);
    g.drawText("sqrt", formbL, top + (row * 4), fbutRW, row, juce::Justification::centred, true);
    g.drawText("rndm", formbL, top + (row * 5), fbutRW, row, juce::Justification::centred, true);
    g.drawText("rndm", formbL, top + (row * 6), fbutRW, row, juce::Justification::centred, true);


    //----------------Time mode butts----------------------------
    /*
    for (int i = 0; i < 4; i++)
        g.drawRect(110+ i * 45, 0 , 45, 19);
    g.setColour(juce::Colours::white);
    g.fillRect(110+ but_tm * 45, 0 , 45, 19);
    g.setColour(juce::Colours::black);
    g.drawText("Off", 110, 0, 45, 19, juce::Justification::centred, true);
    g.drawText("Int", 155, 0, 45, 19, juce::Justification::centred, true);
    g.drawText("VST", 200, 0, 45, 19, juce::Justification::centred, true);
    g.drawText("Midi", 245, 0, 45, 19, juce::Justification::centred, true);
    */
}

void modulator::countIn(int c, int on)
{

    mCount = c;
    if (on == 1 && ParameterNr != 1) {
     repaint((mCount * posstepSL), posStepsTop, 20, posStepsHight+20);
           
    }
        

}
void modulator::drawTextOut(juce::Graphics& g)
{
   
    char c1[50] = { "-" };

        sprintf(c1, "%f", mTimebut);
        g.setColour(juce::Colours::white);
        g.drawRect(100, 140, 30, 20);
        g.drawText(modparasC, 100, 140, 30, 20, juce::Justification::centred, true);



}

void modulator::drawCount(juce::Graphics& g)
{
    const int heightM = posStepsHight / 2;;
    auto colorOn = juce::Colours::red;
    g.setColour(juce::Colours::green);

    for (int i = 0; i < mCount+1; i++) {




        if (steppValues[i] <  posStepsHight / 2) {
           
            g.fillRect(i * posstepSL, posStepsTop+heightM + steppValues[i] - (posStepsHight / 2), posstepSL, 5);
        }
        else {
           
            g.fillRect(i * posstepSL, posStepsTop + steppValues[i]- 5, posstepSL-1, 5);
        }


    }

}


float values[16] = { 0,0,0,0,0,0,0,0,0,0 };
void modulator::initCurve(int i)
{
    for (int c = 0; c < STEPPERSIZE; c++) {
        switch (i) {
        case 0:
            steppValues[c] = posStepsHight/2;
            break;
        case 1:
            steppValues[c] = sin(c / (double)STEPPERSIZE * double_Pi) * posStepsHight;
            break;
        case 2:
            steppValues[c] = (c / (double)STEPPERSIZE) * posStepsHight;
            break;
        case 3:
            steppValues[c] = posStepsHight - (c / (double)STEPPERSIZE) * posStepsHight;
            break;
        case 4:
            steppValues[c / 2] = 0;
            steppValues[8+c / 2] = posStepsHight;
            break;
        case 5:
            steppValues[c / 4] =  posStepsHight / 4.5;
            steppValues[4 + c / 4] = posStepsHight/3;
            steppValues[8 + c / 4] = posStepsHight /1.5;
            steppValues[12 + c / 4] = posStepsHight-10;
            break;
        case 6:
            steppValues[c / 4] = posStepsHight-10;
            steppValues[4 + c / 4] = posStepsHight/1.5;
            steppValues[8 + c / 4] = posStepsHight/3.3;
            steppValues[12 + c / 4] = posStepsHight / 4;
         
            break;
           default:
            break;

        }
     values[c] = minmax1(double(steppValues[c]) / 100.0f);
     stepperValu[c] = minmax1(double(steppValues[c]) / 100.0f);
    }
    stepValuesOut();
    stepAmpValuesOut();
     
    repaint();
}

const float *modulator::stepValuesOut()
{
    
    return  stepperValu;
}

const float* modulator::stepAmpValuesOut()
{
    
    return stepperValueMod;
}
char serialStepValues[200] = { 0 };
float stepsValueIn[200] = { 0 };
String ModUname = { "Userial" };
void modulator::serialStepps(AudioProcessorValueTreeState& valueTreeState,String name)
{
    ModUname=name;
    float x = 6.66;
        sprintf(serialStepValues,
            //......................................steps.................................//..buts...//......aux....................
            "%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f "                                              
            , stepValuesOut()[0], stepValuesOut()[1], stepValuesOut()[2], stepValuesOut()[3]             
            , stepValuesOut()[4], stepValuesOut()[5], stepValuesOut()[6], stepValuesOut()[7]
            , stepValuesOut()[8], stepValuesOut()[9], stepValuesOut()[10], stepValuesOut()[11]
            , stepValuesOut()[12], stepValuesOut()[13], stepValuesOut()[14], stepValuesOut()[15]           
            , mTimebut, x                                                 
            , stepAmpValuesOut()[0], stepAmpValuesOut()[1], stepAmpValuesOut()[2], stepAmpValuesOut()[3]
            , stepAmpValuesOut()[4], stepAmpValuesOut()[5],x);

        valueTreeState.state.setProperty(name, var(serialStepValues), nullptr);
        SteppValuesSerial.setValue(var(serialStepValues));

}

void modulator::unSerialStepps(AudioProcessorValueTreeState& valueTreeState, String name)
{
   
    SteppValuesSerial.referTo(valueTreeState.state.getPropertyAsValue(name, nullptr, true));


        for (int y = 0; y <= 200; y += 5) {



            stepsValueIn[y / 5] = SteppValuesSerial.getValue().toString().substring(y, y + 4).getFloatValue();


        


    }
    for (int s = 0; s < 16; s++) {
        steppValues[s] = (stepsValueIn[s]* (posStepsHight+15)) ;
        stepperValu[s] = (stepsValueIn[s]);
    }
    mTimebut = stepsValueIn[16];
    mFormbut = 0;
    ModOutValues[0] = (stepsValueIn[18]*100);
    stepperValueMod[0] = stepsValueIn[18];
    ModOutValues[1] = (stepsValueIn[19]*100);
    stepperValueMod[1] = stepsValueIn[19];
    ModOutValues[2] = (stepsValueIn[20]*100);
    stepperValueMod[2] = stepsValueIn[20];
    ModOutValues[3] =  (stepsValueIn[21]*100);
    stepperValueMod[4] = stepsValueIn[22];
    ModOutValues[4] =  (stepsValueIn[22]*100);
    ModOutValues[5] = (stepsValueIn[23]*100);
    
    stepValuesOut();
    stepAmpValuesOut();
  
    repaint();
}

const char* modulator::GetModulatorC()
{
    return modparasC;
}



void modulator::valueChanged(float newValue)
{
   
  
        if (lastValue == newValue)
            return;
        lastValue = newValue;
    
    switch (GetParaNr()) {
    case 0:
     
        break;
    case 1:
        stepperValu[KSlidePosModulator] = newValue;
        break;
    case 2:
        stepperValueMod[KSliderPosModOut] = newValue;
        break;
    case 3:
        mTimebut = newValue;
        break;
    case 4:
        stepperValu[KSlidePosModulator] = newValue;
        break;
    default:
        break;
    }
    stepValuesOut();
    stepAmpValuesOut();
    if(engineMode==0)
    serialStepps(valueTreeStateMod, "sp1mod");
    if (engineMode == 1)
        serialStepps(valueTreeStateMod, "sp2mod");
    if (engineMode == 2)
        serialStepps(valueTreeStateMod, "sp3mod");
    if (engineMode == 3)
        serialStepps(valueTreeStateMod, "sp4mod");
    if (engineMode == 4)
        serialStepps(valueTreeStateMod, "sp5mod");
    if (engineMode == 5)
        serialStepps(valueTreeStateMod, "sp6mod");
    if (engineMode == 6)
        serialStepps(valueTreeStateMod, "sp7mod");

    if (onValueChanged != nullptr)
        onValueChanged();

}
