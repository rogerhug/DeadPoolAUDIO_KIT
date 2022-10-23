/*
  ==============================================================================

    TriggerGui.cpp
    Created: 27 Jun 2022 7:57:05pm
    Author:  lutz

  ==============================================================================
*/

#include <JuceHeader.h>
#include "TriggerGui.h"

//==============================================================================
TriggerGui::TriggerGui(AudioProcessorValueTreeState& vts)
    :lastValue(-1.0)
    , trpos1(0)
    , trpos2(0)
    , trpos3(0)
    , trpos4(0)
    , trpos5(0)
    , trpos6(0)
    , trpos7(0)
    , valueTreeStateTrigGui(vts)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    mDown = false;
    Ktrigger1 = new float[TRIGGERLENGHT + 2];
    Ktrigger2 = new float[TRIGGERLENGHT + 2];
    Ktrigger3 = new float[TRIGGERLENGHT + 2];
    Ktrigger4 = new float[TRIGGERLENGHT + 2];
    Ktrigger5 = new float[TRIGGERLENGHT + 2];
    Ktrigger6 = new float[TRIGGERLENGHT + 2];
    Ktrigger7 = new float[TRIGGERLENGHT + 2];
   for (int i = 0; i < TRIGGERLENGHT+2; i++) {
        Ktrigger1[i] = 0;
        Ktrigger2[i] = 0;
        Ktrigger3[i] = 0;
        Ktrigger4[i] = 0;
        Ktrigger5[i] = 0;
        Ktrigger6[i] = 0;
        Ktrigger7[i] = 0;



    }
   ParameterNr = -1;
   KposTrigger = 0;
   sqColor = 0;
   mPattern = 0;
   patternAB = 0;
   repaint();
}
inline int RangeInt(int s, int e, int v)
{
    int result = 0;
    result = v;
    if (result < s)
        result = s;
    if (result > e)
        result = e;
    return result;
}
inline float minMax1(float c)
{
    int result = 0;
    result = c;
    if (result < 0)
        result = 0;
    if (result > 1)
        result = 1;
    return result;
}
TriggerGui::~TriggerGui()
{
}
void TriggerGui::setColor(float c)
{

    sqColor = minMax1(c);
    repaint();
}
const int top=20;
const int posL = 20;
const int row = 22;
const int gridSizeW = row*31;
const int gridSizeH = 140;
int pos_1 = 0;
//------------------serial--------------

char serialSeqParas1[100] = { "-" };
char serialSeqParas2[100] = { "-" };
char serialSeqParas3[100] = { "-" };
char serialSeqParas4[100] = { "-" };
char serialSeqParas5[100] = { "-" };
char serialSeqParas6[100] = { "-" };
char serialSeqParas7[100] = { "-" };

void TriggerGui::mouseUp(const juce::MouseEvent& event)
{
    mDown = false;
    ParameterNr = -1;

}

void TriggerGui::mouseDown(const juce::MouseEvent& event)
{
    const int Psw = sqColor ;
    if (sqColor > 1)
        sqColor = 1;
  //  repaint(100, 20 * 6, 140, 30);//reader
    mDown = true;
    const int hightY = event.getPosition().getY();
    const int widthX = event.getPosition().getX();

   

            
        if ( hightY < top + row && widthX >posL && widthX < posL+gridSizeW+ row) {
            ParameterNr = 1;
            const int trpos1a = 1+(((float(widthX) - posL) / (gridSizeW+ row)) * 32) + (Psw * 32);
            p1t = trpos1a;
            if (event.mods.isLeftButtonDown() == true) {

                Ktrigger1[trpos1a] = 1;
               
               valueChanged(trpos1a);
            }
          
            repaint(posL,top, gridSizeW + 45, row+5);
          
        }
        else
        if (hightY >top+ row && hightY < top + row * 2 && widthX>posL && widthX < posL + gridSizeW + row) {
                ParameterNr = 2;
                const int trpos2a = 1 + (((float(widthX) - posL) / (gridSizeW+row)) * 32) + (Psw * 32);
                if (event.mods.isLeftButtonDown()) {
                    Ktrigger2[trpos2a] = 1;
                   valueChanged(trpos2a);
                }
                
               repaint(posL, top + row , gridSizeW+85, (row * 2));
            }
    /*

            else
                if (hightY > top + (row * 2) && hightY < top + row * 3 && widthX>posL && widthX < posL + gridSizeW + row) {
                    ParameterNr = 3; 
                    const int trpos3a = 1 + (((float(widthX) - posL) / (gridSizeW+ row)) * 32) + (Psw * 32);
                    if (event.mods.isLeftButtonDown() ) {
                        Ktrigger3[trpos3a] = 1;
                         valueChanged(trpos3a);
                    }
                   
                    repaint(posL, top + row*2, gridSizeW + 85, (row * 3) + 5);
                }
               
                    if (hightY > top + (row * 3) && hightY <top + row * 4 && widthX>posL && widthX < posL + gridSizeW + row) {
                        ParameterNr = 4;
                        const int trpos4a = 1 + (((float(widthX) - posL) / (gridSizeW+ row)) * 32) + (Psw * 32);
                        if (event.mods.isLeftButtonDown() == true) {
                            Ktrigger4[trpos4a] = 1;
                            valueChanged(trpos4a);
                        }
                         
                        repaint(posL, top + row * 3, gridSizeW + 25, (row * 4) + 5);
                    }
                    else
                        if (hightY > top +  (row * 4) && hightY <top + row * 5 && widthX>posL && widthX < posL + gridSizeW + row) {
                            ParameterNr = 5;
                            const int trpos5a = 1 + (((float(widthX) - posL) / (gridSizeW+ row)) * 32) + (Psw * 32);
                            if (event.mods.isLeftButtonDown() == true) {
                                Ktrigger5[trpos5a] = 1;
                              valueChanged(trpos5a);
                            }
                            
                            repaint(posL, top + row * 4, gridSizeW + 25, (row * 4) + 5);
                        }

                        else
                            if (hightY > top + (row * 5) && hightY <top + row * 6 && widthX>posL && widthX < posL + gridSizeW + row) {
                                ParameterNr = 6; 
                                const int trpos6a = 1 + (((float(widthX) - posL) / (gridSizeW+ row)) * 32) + (Psw * 32);
                                if (event.mods.isLeftButtonDown() == true) {
                                    Ktrigger6[trpos6a] = 1;
                                     valueChanged(trpos6a);
                                }
                              
                                repaint(posL, top + row * 5, gridSizeW + 25, (row * 6) + 5);
                            }
                            else
                                if (hightY > top + (row * 6) && hightY <top + row * 7 && widthX > posL && widthX < posL + gridSizeW + row) {
                                    ParameterNr = 7;
                                    const int trpos7a = 1 + (((float(widthX) - posL) / (gridSizeW+ row)) * 32) + (Psw * 32);
                                    if (event.mods.isLeftButtonDown() == true) {
                                        Ktrigger7[trpos7a] = 1;
                                         valueChanged(trpos7a);
                                    }
                                  
                                    repaint(posL, top + row * 6, gridSizeW + 25, (row * 7) + 5);
                                }
*/

                    triggersoutC();
}

void TriggerGui::mouseDrag(const MouseEvent& event)
{
    mDown = true;
    const int hightY = event.getPosition().getY();
    const int widthX = event.getPosition().getX();
    const int Psw = sqColor ;
    if (sqColor > 1)
        sqColor = 1;
    
    if (hightY > top && hightY < top + row && widthX>posL && widthX < posL + gridSizeW+ row) {
        ParameterNr = 1;
 
        const int trpos1a = 1 + (((float(widthX) - posL) / (gridSizeW+ row)) * 32) + (Psw * 32);
      
        if (event.mods.isRightButtonDown() == true) {

            Ktrigger1[trpos1a] = 0;

            valueChanged(trpos1a);
        }
      
        repaint(0, top , gridSizeW + 85, row + 25);
    }
    else
    
    if (hightY > top + row && hightY <top + row * 2 && widthX > posL && widthX < posL + gridSizeW + row) {
        ParameterNr = 2;
        const int trpos2a = 1 + (((float(widthX) - posL) / (gridSizeW+ row)) * 32) + (Psw * 32);

        if (event.mods.isRightButtonDown()) {
            Ktrigger2[trpos2a] = 0;
             valueChanged(trpos2a);
        }
       
        repaint(0, top + row, gridSizeW + 85, (row * 2) + 25);
    }
    /*
    else
        if (hightY > top + (row * 2) && hightY < top + row * 3 && widthX>posL && widthX < posL + gridSizeW + row) {
            ParameterNr = 3;
            const int trpos3a = 1 + (((float(widthX) - posL) / (gridSizeW+ row)) * 32) + (Psw * 32);
            if (event.mods.isRightButtonDown()) {
                Ktrigger3[trpos3a] = 0;
                 valueChanged(trpos3a);
            } 
           
            repaint(0, top + row * 2, gridSizeW + 85, (row * 3) + 5);
        }
        else
            if (hightY > top + (row * 3) && hightY <top + row * 4 && widthX>posL && widthX < posL + gridSizeW + row) {
                ParameterNr = 4;
                const int trpos4a = 1 + (((float(widthX) - posL) / (gridSizeW+ row)) * 32) + (Psw * 32);
               
                if (event.mods.isRightButtonDown()) {
                    Ktrigger4[trpos4a] = 0;
                     valueChanged(trpos4a);
                }
               
                repaint(0, top + row * 3, gridSizeW + 85, (row * 4) + 5);
            }
            else
                if (hightY > top + (row * 4) && hightY <top + row * 5 && widthX>posL && widthX < posL + gridSizeW + row) {
                    ParameterNr = 5;
                    const int trpos5a = 1 + (((float(widthX) - posL) / (gridSizeW+ row)) * 32) + (Psw * 32);

                    if (event.mods.isRightButtonDown()) {
                        Ktrigger5[trpos5a] = 0;
                        valueChanged(trpos5a);
                    }
                   
                    repaint(0, top + row * 4, gridSizeW + 85, (row * 5) + 5);
                }

                else
                    if (hightY > top + (row * 5) && hightY <top + row * 6 && widthX>posL && widthX < posL + gridSizeW + row) {
                        ParameterNr = 6;
                        const int trpos6a = 1 + (((float(widthX) - posL) / (gridSizeW+ row)) * 32) + (Psw * 32);
                        if (event.mods.isRightButtonDown()) {
                            Ktrigger6[trpos6a] = 0;
                            valueChanged(trpos6a);
                        }
                       
                        repaint(0, top + row * 5, gridSizeW + 85, (row * 6) + 5);
                    }
                    else
                        if (hightY > top + (row * 6) && hightY <top + row * 7 && widthX> posL && widthX < posL + gridSizeW + row) {
                            ParameterNr = 7;
                            const int trpos7a = 1 + (((float(widthX) - posL) / (gridSizeW+ row)) * 32) + (Psw * 32);
                            if (event.mods.isRightButtonDown()) {
                                Ktrigger7[trpos7a] = 0;
                                 valueChanged(trpos7a);
                            }
                           
                            repaint(0, top + row * 6, gridSizeW + 85, (row * 7) + 5);
                        }

*/
    int nb = 0;
    for (int i = 0; i < TRIGGERLENGHT; i++) {
        nb++;
      //  sprintf(&serialSeqParas1[nb - 1], "%.0f", Ktrigger1[i]);
    }
    triggersoutC();
    
 
   

}
void TriggerGui::paint (juce::Graphics& g)
{
   

    drawTriggerGrid(g);
    g.setColour(juce::Colours::blue);
    g.drawRect(0, 0, 835, 90, 10);
}
void TriggerGui::drawTriggerGrid(juce::Graphics& g)
{
    g.setColour(juce::Colours::black);
    g.fillAll();
    const int gridW = row;
    const int gridH = row;
    const int row1 = 20;
    const int csw = sqColor;
    if (sqColor > 1)
        sqColor = 1;
    auto colour1 = juce::Colours::silver;
    switch (csw) {
    case 0:
        colour1 = juce::Colours::silver;
        break;
    case 1:
        colour1 = juce::Colours::yellow;
        break;
    case 2:
        colour1 = juce::Colours::ghostwhite;
        break;
    default:
        break;
    }
    const int gridYWBG = double(gridH) * 1.9;
     g.setColour(juce::Colours::darkgrey);
     g.fillRect(posL, top , gridW*4, gridYWBG);
     g.setColour(juce::Colours::darkslategrey);
     g.fillRect(posL+gridW* 4, top , posL+gridW* 4,  gridYWBG);
     g.setColour(juce::Colours::darkgrey);
      g.fillRect(posL+gridW* 8, top, posL+gridW* 4,  gridYWBG);
     g.setColour(juce::Colours::darkslategrey);
     g.fillRect(posL+gridW* 12, top, posL+gridW* 4, gridYWBG);
     g.setColour(juce::Colours::darkgrey);
     g.fillRect(posL+gridW* 16, top, posL+gridW* 4,  gridYWBG);
     g.setColour(juce::Colours::darkslategrey);
     g.fillRect(posL+gridW* 20, top, posL+gridW* 4, gridYWBG);
     g.setColour(juce::Colours::darkgrey);
     g.fillRect(posL+gridW* 24, top, posL+gridW* 4,  gridYWBG);
     g.setColour(juce::Colours::darkslategrey);
     g.fillRect(posL+gridW* 28, top, posL+gridW* 3,  gridYWBG);

 




     
       if (csw == 0) {
          g.setColour(juce::Colours::black);  
           if (Ktrigger1[1] == 1) { g.fillRect(posL, top, gridW, gridH); }
           if (Ktrigger1[2] == 1) { g.fillRect(posL+gridW, top, gridW, gridH); }
           if (Ktrigger1[3] == 1) { g.fillRect(posL+gridW* 2, top, gridW, gridH); }
           if (Ktrigger1[4] == 1) { g.fillRect(posL+gridW* 3, top, gridW, gridH); }
           if (Ktrigger1[5] == 1) { g.fillRect(posL+gridW* 4, top, gridW, gridH); }
           if (Ktrigger1[6] == 1) { g.fillRect(posL+gridW* 5, top, gridW, gridH); }
           if (Ktrigger1[7] == 1) { g.fillRect(posL+gridW* 6, top, gridW, gridH); }
           if (Ktrigger1[8] == 1) { g.fillRect(posL+gridW* 7, top, gridW, gridH); }
           if (Ktrigger1[9] == 1) { g.fillRect(posL+gridW* 8, top, gridW, gridH); }
           if (Ktrigger1[10] == 1) { g.fillRect(posL+gridW* 9, top, gridW, gridH); }
           if (Ktrigger1[11] == 1) { g.fillRect(posL+gridW* 10, top, gridW, gridH); }
           if (Ktrigger1[12] == 1) { g.fillRect(posL+gridW* 11, top, gridW, gridH); }
           if (Ktrigger1[13] == 1) { g.fillRect(posL+gridW* 12, top, gridW, gridH); }
           if (Ktrigger1[14] == 1) { g.fillRect(posL+gridW* 13, top, gridW, gridH); }
           if (Ktrigger1[15] == 1) { g.fillRect(posL+gridW* 14, top, gridW, gridH); }
           if (Ktrigger1[16] == 1) { g.fillRect(posL+gridW* 15, top, gridW, gridH); }
           if (Ktrigger1[17] == 1) { g.fillRect(posL+gridW* 16, top, gridW, gridH); }
           if (Ktrigger1[18] == 1) { g.fillRect(posL+gridW* 17, top, gridW, gridH); }
           if (Ktrigger1[19] == 1) { g.fillRect(posL+gridW* 18, top, gridW, gridH); }
           if (Ktrigger1[20] == 1) { g.fillRect(posL+gridW* 19, top, gridW, gridH); }
           if (Ktrigger1[21] == 1) { g.fillRect(posL+gridW* 20, top, gridW, gridH); }
           if (Ktrigger1[22] == 1) { g.fillRect(posL+gridW* 21, top, gridW, gridH); }
           if (Ktrigger1[23] == 1) { g.fillRect(posL+gridW* 22, top, gridW, gridH); }
           if (Ktrigger1[24] == 1) { g.fillRect(posL+gridW* 23, top, gridW, gridH); }
           if (Ktrigger1[25] == 1) { g.fillRect(posL+gridW* 24, top, gridW, gridH); }
           if (Ktrigger1[26] == 1) { g.fillRect(posL+gridW* 25, top, gridW, gridH); }
           if (Ktrigger1[27] == 1) { g.fillRect(posL+gridW* 26, top, gridW, gridH); }
           if (Ktrigger1[28] == 1) { g.fillRect(posL+gridW* 27, top, gridW, gridH); }
           if (Ktrigger1[29] == 1) { g.fillRect(posL+gridW* 28, top, gridW, gridH); }
           if (Ktrigger1[30] == 1) { g.fillRect(posL+gridW* 29, top, gridW, gridH); }
           if (Ktrigger1[31] == 1) { g.fillRect(posL+gridW* 30, top, gridW, gridH); }
           if (Ktrigger1[32] == 1) { g.fillRect(posL+gridW* 31, top, gridW, gridH); }


           
       }
       if (csw == 1) {
           g.setColour(juce::Colours::black);
           if (Ktrigger1[33] == 1) { g.fillRect(posL, top, gridW, gridH); }
           if (Ktrigger1[34] == 1) { g.fillRect(posL+gridW, top, gridW, gridH); }
           if (Ktrigger1[35] == 1) { g.fillRect(posL+gridW* 2, top, gridW, gridH); }
           if (Ktrigger1[36] == 1) { g.fillRect(posL+gridW* 3, top, gridW, gridH); }
           if (Ktrigger1[37] == 1) { g.fillRect(posL+gridW* 4, top, gridW, gridH); }
           if (Ktrigger1[38] == 1) { g.fillRect(posL+gridW* 5, top, gridW, gridH); }
           if (Ktrigger1[39] == 1) { g.fillRect(posL+gridW* 6, top, gridW, gridH); }
           if (Ktrigger1[40] == 1) { g.fillRect(posL+gridW* 7, top, gridW, gridH); }
           if (Ktrigger1[41] == 1) { g.fillRect(posL+gridW* 8, top, gridW, gridH); }
           if (Ktrigger1[42] == 1) { g.fillRect(posL+gridW* 9, top, gridW, gridH); }
           if (Ktrigger1[43] == 1) { g.fillRect(posL+gridW* 10, top, gridW, gridH); }
           if (Ktrigger1[44] == 1) { g.fillRect(posL+gridW* 11, top, gridW, gridH); }
           if (Ktrigger1[45] == 1) { g.fillRect(posL+gridW* 12, top, gridW, gridH); }
           if (Ktrigger1[46] == 1) { g.fillRect(posL+gridW* 13, top, gridW, gridH); }
           if (Ktrigger1[47] == 1) { g.fillRect(posL+gridW* 14, top, gridW, gridH); }
           if (Ktrigger1[48] == 1) { g.fillRect(posL+gridW* 15, top, gridW, gridH); }
           if (Ktrigger1[49] == 1) { g.fillRect(posL+gridW* 16, top, gridW, gridH); }
           if (Ktrigger1[50] == 1) { g.fillRect(posL+gridW* 17, top, gridW, gridH); }
           if (Ktrigger1[51] == 1) { g.fillRect(posL+gridW* 18, top, gridW, gridH); }
           if (Ktrigger1[52] == 1) { g.fillRect(posL+gridW* 19, top, gridW, gridH); }
           if (Ktrigger1[53] == 1) { g.fillRect(posL+gridW* 20, top, gridW, gridH); }
           if (Ktrigger1[54] == 1) { g.fillRect(posL+gridW* 21, top, gridW, gridH); }
           if (Ktrigger1[55] == 1) { g.fillRect(posL+gridW* 22, top, gridW, gridH); }
           if (Ktrigger1[56] == 1) { g.fillRect(posL+gridW* 23, top, gridW, gridH); }
           if (Ktrigger1[57] == 1) { g.fillRect(posL+gridW* 24, top, gridW, gridH); }
           if (Ktrigger1[58] == 1) { g.fillRect(posL+gridW* 25, top, gridW, gridH); }
           if (Ktrigger1[59] == 1) { g.fillRect(posL+gridW* 26, top, gridW, gridH); }
           if (Ktrigger1[60] == 1) { g.fillRect(posL+gridW* 27, top, gridW, gridH); }
           if (Ktrigger1[61] == 1) { g.fillRect(posL+gridW* 28, top, gridW, gridH); }
           if (Ktrigger1[62] == 1) { g.fillRect(posL+gridW* 29, top, gridW, gridH); }
           if (Ktrigger1[63] == 1) { g.fillRect(posL+gridW* 30, top, gridW, gridH); }
           if (Ktrigger1[64] == 1) { g.fillRect(posL+gridW* 31, top, gridW, gridH); }
       }

if (csw == 0) {
           g.setColour(juce::Colours::black);
           
           if (Ktrigger2[1] == 1) { g.fillRect(posL, top + row1, gridW, gridH); }
           if (Ktrigger2[2] == 1) { g.fillRect(posL+gridW, top + row1, gridW, gridH); }
           if (Ktrigger2[3] == 1) { g.fillRect(posL+gridW* 2, top + row1, gridW, gridH); }
           if (Ktrigger2[4] == 1) { g.fillRect(posL+gridW* 3, top + row1, gridW, gridH); }
           if (Ktrigger2[5] == 1) { g.fillRect(posL+gridW* 4, top + row1, gridW, gridH); }
           if (Ktrigger2[6] == 1) { g.fillRect(posL+gridW* 5, top + row1, gridW, gridH); }
           if (Ktrigger2[7] == 1) { g.fillRect(posL+gridW* 6, top + row1, gridW, gridH); }
           if (Ktrigger2[8] == 1) { g.fillRect(posL+gridW* 7, top + row1, gridW, gridH); }
           if (Ktrigger2[9] == 1) { g.fillRect(posL+gridW* 8, top + row1, gridW, gridH); }
           if (Ktrigger2[10] == 1) { g.fillRect(posL+gridW* 9, top + row1, gridW, gridH); }
           if (Ktrigger2[11] == 1) { g.fillRect(posL+gridW* 10, top + row1, gridW, gridH); }
           if (Ktrigger2[12] == 1) { g.fillRect(posL+gridW* 11, top + row1, gridW, gridH); }
           if (Ktrigger2[13] == 1) { g.fillRect(posL+gridW* 12, top + row1, gridW, gridH); }
           if (Ktrigger2[14] == 1) { g.fillRect(posL+gridW* 13, top + row1, gridW, gridH); }
           if (Ktrigger2[15] == 1) { g.fillRect(posL+gridW* 14, top + row1, gridW, gridH); }
           if (Ktrigger2[16] == 1) { g.fillRect(posL+gridW* 15, top + row1, gridW, gridH); }
           if (Ktrigger2[17] == 1) { g.fillRect(posL+gridW* 16, top + row1, gridW, gridH); }
           if (Ktrigger2[18] == 1) { g.fillRect(posL+gridW* 17, top + row1, gridW, gridH); }
           if (Ktrigger2[19] == 1) { g.fillRect(posL+gridW* 18, top + row1, gridW, gridH); }
           if (Ktrigger2[20] == 1) { g.fillRect(posL+gridW* 19, top + row1, gridW, gridH); }
           if (Ktrigger2[21] == 1) { g.fillRect(posL+gridW* 20, top + row1, gridW, gridH); }
           if (Ktrigger2[22] == 1) { g.fillRect(posL+gridW* 21, top + row1, gridW, gridH); }
           if (Ktrigger2[23] == 1) { g.fillRect(posL+gridW* 22, top + row1, gridW, gridH); }
           if (Ktrigger2[24] == 1) { g.fillRect(posL+gridW* 23, top + row1, gridW, gridH); }
           if (Ktrigger2[25] == 1) { g.fillRect(posL+gridW* 24, top + row1, gridW, gridH); }
           if (Ktrigger2[26] == 1) { g.fillRect(posL+gridW* 25, top + row1, gridW, gridH); }
           if (Ktrigger2[27] == 1) { g.fillRect(posL+gridW* 26, top + row1, gridW, gridH); }
           if (Ktrigger2[28] == 1) { g.fillRect(posL+gridW* 27, top + row1, gridW, gridH); }
           if (Ktrigger2[29] == 1) { g.fillRect(posL+gridW* 28, top + row1, gridW, gridH); }
           if (Ktrigger2[30] == 1) { g.fillRect(posL+gridW* 29, top + row1, gridW, gridH); }
           if (Ktrigger2[31] == 1) { g.fillRect(posL+gridW* 30, top + row1, gridW, gridH); }
           if (Ktrigger2[32] == 1) { g.fillRect(posL+gridW* 31, top + row1, gridW, gridH); }
           
       }

       if (csw == 1) {
   
           if (Ktrigger2[33] == 1) { g.fillRect(posL, top + row1, gridW, gridH); }
           if (Ktrigger2[34] == 1) { g.fillRect(posL+gridW, top + row1, gridW, gridH); }
           if (Ktrigger2[35] == 1) { g.fillRect(posL+gridW* 2, top + row1, gridW, gridH); }
           if (Ktrigger2[36] == 1) { g.fillRect(posL+gridW* 3, top + row1, gridW, gridH); }
           if (Ktrigger2[37] == 1) { g.fillRect(posL+gridW* 4, top + row1, gridW, gridH); }
           if (Ktrigger2[38] == 1) { g.fillRect(posL+gridW* 5, top + row1, gridW, gridH); }
           if (Ktrigger2[39] == 1) { g.fillRect(posL+gridW* 6, top + row1, gridW, gridH); }
           if (Ktrigger2[40] == 1) { g.fillRect(posL+gridW* 7, top + row1, gridW, gridH); }
           if (Ktrigger2[41] == 1) { g.fillRect(posL+gridW* 8, top + row1, gridW, gridH); }
           if (Ktrigger2[41] == 1) { g.fillRect(posL+gridW* 8, top + row1, gridW, gridH); }
           if (Ktrigger2[42] == 1) { g.fillRect(posL+gridW* 9, top + row1, gridW, gridH); }
           if (Ktrigger2[43] == 1) { g.fillRect(posL+gridW* 10, top + row1, gridW, gridH); }
           if (Ktrigger2[44] == 1) { g.fillRect(posL+gridW* 11, top + row1, gridW, gridH); }
           if (Ktrigger2[45] == 1) { g.fillRect(posL+gridW* 12, top + row1, gridW, gridH); }
           if (Ktrigger2[46] == 1) { g.fillRect(posL+gridW* 13, top + row1, gridW, gridH); }
           if (Ktrigger2[47] == 1) { g.fillRect(posL+gridW* 14, top + row1, gridW, gridH); }
           if (Ktrigger2[48] == 1) { g.fillRect(posL+gridW* 15, top + row1, gridW, gridH); }
           if (Ktrigger2[49] == 1) { g.fillRect(posL+gridW* 16, top + row1, gridW, gridH); }
           if (Ktrigger2[50] == 1) { g.fillRect(posL+gridW* 17, top + row1, gridW, gridH); }
           if (Ktrigger2[51] == 1) { g.fillRect(posL+gridW* 18, top + row1, gridW, gridH); }
           if (Ktrigger2[52] == 1) { g.fillRect(posL+gridW* 19, top + row1, gridW, gridH); }
           if (Ktrigger2[53] == 1) { g.fillRect(posL+gridW* 20, top + row1, gridW, gridH); }
           if (Ktrigger2[54] == 1) { g.fillRect(posL+gridW* 21, top + row1, gridW, gridH); }
           if (Ktrigger2[55] == 1) { g.fillRect(posL+gridW* 22, top + row1, gridW, gridH); }
           if (Ktrigger2[56] == 1) { g.fillRect(posL+gridW* 23, top + row1, gridW, gridH); }
           if (Ktrigger2[57] == 1) { g.fillRect(posL+gridW* 24, top + row1, gridW, gridH); }
           if (Ktrigger2[58] == 1) { g.fillRect(posL+gridW* 25, top + row1, gridW, gridH); }
           if (Ktrigger2[59] == 1) { g.fillRect(posL+gridW* 26, top + row1, gridW, gridH); }
           if (Ktrigger2[60] == 1) { g.fillRect(posL+gridW* 27, top + row1, gridW, gridH); }
           if (Ktrigger2[61] == 1) { g.fillRect(posL+gridW* 28, top + row1, gridW, gridH); }
           if (Ktrigger2[62] == 1) { g.fillRect(posL+gridW* 29, top + row1, gridW, gridH); }
           if (Ktrigger2[63] == 1) { g.fillRect(posL+gridW* 30, top + row1, gridW, gridH); }
           if (Ktrigger2[64] == 1) { g.fillRect(posL+gridW* 31, top + row1, gridW, gridH); }
       }
       /*
      
       if (csw == 0) {
           if (Ktrigger3[1] == 1) { g.fillRect(posL, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[2] == 1) { g.fillRect(posL+gridW, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[3] == 1) { g.fillRect(posL+gridW* 2, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[4] == 1) { g.fillRect(posL+gridW* 3, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[5] == 1) { g.fillRect(posL+gridW* 4, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[6] == 1) { g.fillRect(posL+gridW* 5, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[7] == 1) { g.fillRect(posL+gridW* 6, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[8] == 1) { g.fillRect(posL+gridW* 7, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[9] == 1) { g.fillRect(posL+gridW* 8, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[10] == 1) { g.fillRect(posL+gridW* 9, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[11] == 1) { g.fillRect(posL+gridW* 10, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[12] == 1) { g.fillRect(posL+gridW* 11, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[13] == 1) { g.fillRect(posL+gridW* 12, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[14] == 1) { g.fillRect(posL+gridW* 13, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[15] == 1) { g.fillRect(posL+gridW* 14, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[16] == 1) { g.fillRect(posL+gridW* 15, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[17] == 1) { g.fillRect(posL+gridW* 16, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[18] == 1) { g.fillRect(posL+gridW* 17, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[19] == 1) { g.fillRect(posL+gridW* 18, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[20] == 1) { g.fillRect(posL+gridW* 19, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[21] == 1) { g.fillRect(posL+gridW* 20, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[22] == 1) { g.fillRect(posL+gridW* 21, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[23] == 1) { g.fillRect(posL+gridW* 22, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[24] == 1) { g.fillRect(posL+gridW* 23, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[25] == 1) { g.fillRect(posL+gridW* 24, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[26] == 1) { g.fillRect(posL+gridW* 25, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[27] == 1) { g.fillRect(posL+gridW* 26, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[28] == 1) { g.fillRect(posL+gridW* 27, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[29] == 1) { g.fillRect(posL+gridW* 28, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[30] == 1) { g.fillRect(posL+gridW* 29, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[31] == 1) { g.fillRect(posL+gridW* 30, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[32] == 1) { g.fillRect(posL+gridW* 31, top +row1 * 2, gridW, gridH); }
       }

       if (csw == 1) {
           if (Ktrigger3[33] == 1) { g.fillRect(posL, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[34] == 1) { g.fillRect(posL+gridW, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[35] == 1) { g.fillRect(posL+gridW* 2, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[36] == 1) { g.fillRect(posL+gridW* 3, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[37] == 1) { g.fillRect(posL+gridW* 4, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[38] == 1) { g.fillRect(posL+gridW* 5, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[39] == 1) { g.fillRect(posL+gridW* 6, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[40] == 1) { g.fillRect(posL+gridW* 7, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[41] == 1) { g.fillRect(posL+gridW* 8, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[42] == 1) { g.fillRect(posL+gridW* 9, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[43] == 1) { g.fillRect(posL+gridW* 10, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[44] == 1) { g.fillRect(posL+gridW* 11, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[45] == 1) { g.fillRect(posL+gridW* 12, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[46] == 1) { g.fillRect(posL+gridW* 13, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[47] == 1) { g.fillRect(posL+gridW* 14, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[48] == 1) { g.fillRect(posL+gridW* 15, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[49] == 1) { g.fillRect(posL+gridW* 16, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[50] == 1) { g.fillRect(posL+gridW* 17, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[51] == 1) { g.fillRect(posL+gridW* 18, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[52] == 1) { g.fillRect(posL+gridW* 19, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[53] == 1) { g.fillRect(posL+gridW* 20, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[54] == 1) { g.fillRect(posL+gridW* 21, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[55] == 1) { g.fillRect(posL+gridW* 22, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[56] == 1) { g.fillRect(posL+gridW* 23, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[57] == 1) { g.fillRect(posL+gridW* 24, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[58] == 1) { g.fillRect(posL+gridW* 25, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[59] == 1) { g.fillRect(posL+gridW* 26, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[60] == 1) { g.fillRect(posL+gridW* 27, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[61] == 1) { g.fillRect(posL+gridW* 28, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[62] == 1) { g.fillRect(posL+gridW* 29, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[63] == 1) { g.fillRect(posL+gridW* 30, top +row1 * 2, gridW, gridH); }
           if (Ktrigger3[64] == 1) { g.fillRect(posL+gridW* 31, top +row1 * 2, gridW, gridH); }
       }
       if (csw == 0) {
           if (Ktrigger4[1] == 1) { g.fillRect(posL, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[2] == 1) { g.fillRect(posL+gridW, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[3] == 1) { g.fillRect(posL+gridW* 2, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[4] == 1) { g.fillRect(posL+gridW* 3, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[5] == 1) { g.fillRect(posL+gridW* 4, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[6] == 1) { g.fillRect(posL+gridW* 5, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[7] == 1) { g.fillRect(posL+gridW* 6, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[8] == 1) { g.fillRect(posL+gridW* 7, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[9] == 1) { g.fillRect(posL+gridW* 8, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[10] == 1) { g.fillRect(posL+gridW* 9, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[11] == 1) { g.fillRect(posL+gridW* 10, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[12] == 1) { g.fillRect(posL+gridW* 11, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[13] == 1) { g.fillRect(posL+gridW* 12, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[14] == 1) { g.fillRect(posL+gridW* 13, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[15] == 1) { g.fillRect(posL+gridW* 14, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[16] == 1) { g.fillRect(posL+gridW* 15, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[17] == 1) { g.fillRect(posL+gridW* 16, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[18] == 1) { g.fillRect(posL+gridW* 17, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[19] == 1) { g.fillRect(posL+gridW* 18, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[20] == 1) { g.fillRect(posL+gridW* 19, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[21] == 1) { g.fillRect(posL+gridW* 20, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[22] == 1) { g.fillRect(posL+gridW* 21, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[23] == 1) { g.fillRect(posL+gridW* 22, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[24] == 1) { g.fillRect(posL+gridW* 23, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[25] == 1) { g.fillRect(posL+gridW* 24, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[26] == 1) { g.fillRect(posL+gridW* 25, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[27] == 1) { g.fillRect(posL+gridW* 26, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[28] == 1) { g.fillRect(posL+gridW* 27, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[29] == 1) { g.fillRect(posL+gridW* 28, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[30] == 1) { g.fillRect(posL+gridW* 29, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[31] == 1) { g.fillRect(posL+gridW* 30, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[32] == 1) { g.fillRect(posL+gridW* 31, top +row1 * 3, gridW, gridH); }
       }

       if (csw == 1) {
           if (Ktrigger4[33] == 1) { g.fillRect(posL, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[34] == 1) { g.fillRect(posL+gridW, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[35] == 1) { g.fillRect(posL+gridW* 2, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[36] == 1) { g.fillRect(posL+gridW* 3, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[37] == 1) { g.fillRect(posL+gridW* 4, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[38] == 1) { g.fillRect(posL+gridW* 5, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[39] == 1) { g.fillRect(posL+gridW* 6, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[40] == 1) { g.fillRect(posL+gridW* 7, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[41] == 1) { g.fillRect(posL+gridW* 8, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[42] == 1) { g.fillRect(posL+gridW* 9, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[43] == 1) { g.fillRect(posL+gridW* 10, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[44] == 1) { g.fillRect(posL+gridW* 11, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[45] == 1) { g.fillRect(posL+gridW* 12, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[46] == 1) { g.fillRect(posL+gridW* 13, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[47] == 1) { g.fillRect(posL+gridW* 14, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[48] == 1) { g.fillRect(posL+gridW* 15, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[49] == 1) { g.fillRect(posL+gridW* 16, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[50] == 1) { g.fillRect(posL+gridW* 17, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[51] == 1) { g.fillRect(posL+gridW* 18, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[52] == 1) { g.fillRect(posL+gridW* 19, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[53] == 1) { g.fillRect(posL+gridW* 20, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[54] == 1) { g.fillRect(posL+gridW* 21, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[55] == 1) { g.fillRect(posL+gridW* 22, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[56] == 1) { g.fillRect(posL+gridW* 23, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[57] == 1) { g.fillRect(posL+gridW* 24, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[58] == 1) { g.fillRect(posL+gridW* 25, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[59] == 1) { g.fillRect(posL+gridW* 26, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[60] == 1) { g.fillRect(posL+gridW* 27, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[61] == 1) { g.fillRect(posL+gridW* 28, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[62] == 1) { g.fillRect(posL+gridW* 29, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[63] == 1) { g.fillRect(posL+gridW* 30, top +row1 * 3, gridW, gridH); }
           if (Ktrigger4[64] == 1) { g.fillRect(posL+gridW* 31, top +row1 * 3, gridW, gridH); }
       }
       if (csw == 0) {
           if (Ktrigger5[1] == 1) { g.fillRect(posL, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[2] == 1) { g.fillRect(posL + gridW, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[3] == 1) { g.fillRect(posL+gridW* 2, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[4] == 1) { g.fillRect(posL+gridW* 3, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[5] == 1) { g.fillRect(posL+gridW* 4, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[6] == 1) { g.fillRect(posL+gridW* 5, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[7] == 1) { g.fillRect(posL+gridW* 6, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[8] == 1) { g.fillRect(posL+gridW* 7, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[9] == 1) { g.fillRect(posL+gridW* 8, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[10] == 1) { g.fillRect(posL+gridW* 9, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[11] == 1) { g.fillRect(posL+gridW* 10, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[12] == 1) { g.fillRect(posL+gridW* 11, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[13] == 1) { g.fillRect(posL+gridW* 12, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[14] == 1) { g.fillRect(posL+gridW* 13, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[15] == 1) { g.fillRect(posL+gridW* 14, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[16] == 1) { g.fillRect(posL+gridW* 15, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[17] == 1) { g.fillRect(posL+gridW* 16, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[18] == 1) { g.fillRect(posL+gridW* 17, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[19] == 1) { g.fillRect(posL+gridW* 18, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[20] == 1) { g.fillRect(posL+gridW* 19, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[21] == 1) { g.fillRect(posL+gridW* 20, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[22] == 1) { g.fillRect(posL+gridW* 21, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[23] == 1) { g.fillRect(posL+gridW* 22, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[24] == 1) { g.fillRect(posL+gridW* 23, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[25] == 1) { g.fillRect(posL+gridW* 24, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[26] == 1) { g.fillRect(posL+gridW* 25, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[27] == 1) { g.fillRect(posL+gridW* 26, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[28] == 1) { g.fillRect(posL+gridW* 27, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[29] == 1) { g.fillRect(posL+gridW* 28, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[30] == 1) { g.fillRect(posL+gridW* 29, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[31] == 1) { g.fillRect(posL+gridW* 30, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[32] == 1) { g.fillRect(posL+gridW* 31, top +row1 * 4, gridW, gridH); }
       }

       if (csw == 1) {
           if (Ktrigger5[33] == 1) { g.fillRect(posL , top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[34] == 1) { g.fillRect(posL + gridW, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[35] == 1) { g.fillRect(posL+gridW* 2, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[36] == 1) { g.fillRect(posL+gridW* 3, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[37] == 1) { g.fillRect(posL+gridW* 4, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[38] == 1) { g.fillRect(posL+gridW* 5, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[39] == 1) { g.fillRect(posL+gridW* 6, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[40] == 1) { g.fillRect(posL+gridW* 7, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[41] == 1) { g.fillRect(posL+gridW* 8, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[42] == 1) { g.fillRect(posL+gridW* 9, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[43] == 1) { g.fillRect(posL+gridW* 10, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[44] == 1) { g.fillRect(posL+gridW* 11, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[45] == 1) { g.fillRect(posL+gridW* 12, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[46] == 1) { g.fillRect(posL+gridW* 13, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[47] == 1) { g.fillRect(posL+gridW* 14, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[48] == 1) { g.fillRect(posL+gridW* 15, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[49] == 1) { g.fillRect(posL+gridW* 16, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[50] == 1) { g.fillRect(posL+gridW* 17, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[51] == 1) { g.fillRect(posL+gridW* 18, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[52] == 1) { g.fillRect(posL+gridW* 19, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[53] == 1) { g.fillRect(posL+gridW* 20, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[54] == 1) { g.fillRect(posL+gridW* 21, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[55] == 1) { g.fillRect(posL+gridW* 22, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[56] == 1) { g.fillRect(posL+gridW* 23, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[57] == 1) { g.fillRect(posL+gridW* 24, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[58] == 1) { g.fillRect(posL+gridW* 25, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[59] == 1) { g.fillRect(posL+gridW* 26, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[60] == 1) { g.fillRect(posL+gridW* 27, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[61] == 1) { g.fillRect(posL+gridW* 28, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[62] == 1) { g.fillRect(posL+gridW* 29, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[63] == 1) { g.fillRect(posL+gridW* 30, top +row1 * 4, gridW, gridH); }
           if (Ktrigger5[64] == 1) { g.fillRect(posL+gridW* 31, top +row1 * 4, gridW, gridH); }
       }
       if (csw == 0) {
           if (Ktrigger6[1] == 1) { g.fillRect(posL , top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[2] == 1) { g.fillRect(posL + gridW, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[3] == 1) { g.fillRect(posL+gridW* 2, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[4] == 1) { g.fillRect(posL+gridW* 3, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[5] == 1) { g.fillRect(posL+gridW* 4, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[6] == 1) { g.fillRect(posL+gridW* 5, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[7] == 1) { g.fillRect(posL+gridW* 6, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[8] == 1) { g.fillRect(posL+gridW* 7, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[9] == 1) { g.fillRect(posL+gridW* 8, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[10] == 1) { g.fillRect(posL+gridW* 9, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[11] == 1) { g.fillRect(posL+gridW* 10, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[12] == 1) { g.fillRect(posL+gridW* 11, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[13] == 1) { g.fillRect(posL+gridW* 12, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[14] == 1) { g.fillRect(posL+gridW* 13, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[15] == 1) { g.fillRect(posL+gridW* 14, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[16] == 1) { g.fillRect(posL+gridW* 15, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[17] == 1) { g.fillRect(posL+gridW* 16, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[18] == 1) { g.fillRect(posL+gridW* 17, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[19] == 1) { g.fillRect(posL+gridW* 18, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[20] == 1) { g.fillRect(posL+gridW* 19, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[21] == 1) { g.fillRect(posL+gridW* 20, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[22] == 1) { g.fillRect(posL+gridW* 21, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[23] == 1) { g.fillRect(posL+gridW* 22, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[24] == 1) { g.fillRect(posL+gridW* 23, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[25] == 1) { g.fillRect(posL+gridW* 24, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[26] == 1) { g.fillRect(posL+gridW* 25, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[27] == 1) { g.fillRect(posL+gridW* 26, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[28] == 1) { g.fillRect(posL+gridW* 27, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[29] == 1) { g.fillRect(posL+gridW* 28, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[30] == 1) { g.fillRect(posL+gridW* 29, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[31] == 1) { g.fillRect(posL+gridW* 30, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[32] == 1) { g.fillRect(posL+gridW* 31, top +row1 * 5, gridW, gridH); }
       }
       if (csw == 1) {
           if (Ktrigger6[33] == 1) { g.fillRect(posL , top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[34] == 1) { g.fillRect(posL + gridW, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[35] == 1) { g.fillRect(posL+gridW* 2, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[36] == 1) { g.fillRect(posL+gridW* 3, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[37] == 1) { g.fillRect(posL+gridW* 4, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[38] == 1) { g.fillRect(posL+gridW* 5, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[39] == 1) { g.fillRect(posL+gridW* 6, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[40] == 1) { g.fillRect(posL+gridW* 7, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[41] == 1) { g.fillRect(posL+gridW* 8, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[42] == 1) { g.fillRect(posL+gridW* 9, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[43] == 1) { g.fillRect(posL+gridW* 10, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[44] == 1) { g.fillRect(posL+gridW* 11, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[45] == 1) { g.fillRect(posL+gridW* 12, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[46] == 1) { g.fillRect(posL+gridW* 13, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[47] == 1) { g.fillRect(posL+gridW* 14, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[48] == 1) { g.fillRect(posL+gridW* 15, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[49] == 1) { g.fillRect(posL+gridW* 16, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[50] == 1) { g.fillRect(posL+gridW* 17, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[51] == 1) { g.fillRect(posL+gridW* 18, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[52] == 1) { g.fillRect(posL+gridW* 19, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[53] == 1) { g.fillRect(posL+gridW* 20, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[54] == 1) { g.fillRect(posL+gridW* 21, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[55] == 1) { g.fillRect(posL+gridW* 22, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[56] == 1) { g.fillRect(posL+gridW* 23, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[57] == 1) { g.fillRect(posL+gridW* 24, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[58] == 1) { g.fillRect(posL+gridW* 25, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[59] == 1) { g.fillRect(posL+gridW* 26, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[60] == 1) { g.fillRect(posL+gridW* 27, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[61] == 1) { g.fillRect(posL+gridW* 28, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[62] == 1) { g.fillRect(posL+gridW* 29, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[63] == 1) { g.fillRect(posL+gridW* 30, top +row1 * 5, gridW, gridH); }
           if (Ktrigger6[64] == 1) { g.fillRect(posL+gridW* 31, top +row1 * 5, gridW, gridH); }
       }

       if (csw == 0) {
           if (Ktrigger7[1] == 1) { g.fillRect(posL , top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[2] == 1) { g.fillRect(posL + gridW, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[3] == 1) { g.fillRect(posL+gridW* 2, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[4] == 1) { g.fillRect(posL+gridW* 3, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[5] == 1) { g.fillRect(posL+gridW* 4, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[6] == 1) { g.fillRect(posL+gridW* 5, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[7] == 1) { g.fillRect(posL+gridW* 6, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[8] == 1) { g.fillRect(posL+gridW* 7, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[9] == 1) { g.fillRect(posL+gridW* 8, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[10] == 1) { g.fillRect(posL+gridW* 9, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[11] == 1) { g.fillRect(posL+gridW* 10, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[12] == 1) { g.fillRect(posL+gridW* 11, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[13] == 1) { g.fillRect(posL+gridW* 12, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[14] == 1) { g.fillRect(posL+gridW* 13, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[15] == 1) { g.fillRect(posL+gridW* 14, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[16] == 1) { g.fillRect(posL+gridW* 15, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[17] == 1) { g.fillRect(posL+gridW* 16, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[18] == 1) { g.fillRect(posL+gridW* 17, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[19] == 1) { g.fillRect(posL+gridW* 18, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[20] == 1) { g.fillRect(posL+gridW* 19, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[21] == 1) { g.fillRect(posL+gridW* 20, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[22] == 1) { g.fillRect(posL+gridW* 21, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[23] == 1) { g.fillRect(posL+gridW* 22, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[24] == 1) { g.fillRect(posL+gridW* 23, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[25] == 1) { g.fillRect(posL+gridW* 24, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[26] == 1) { g.fillRect(posL+gridW* 25, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[27] == 1) { g.fillRect(posL+gridW* 26, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[28] == 1) { g.fillRect(posL+gridW* 27, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[29] == 1) { g.fillRect(posL+gridW* 28, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[30] == 1) { g.fillRect(posL+gridW* 29, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[31] == 1) { g.fillRect(posL+gridW* 30, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[32] == 1) { g.fillRect(posL+gridW* 31, top +row1 * 6, gridW, gridH); }
       }

       if (csw == 1) {
           if (Ktrigger7[33] == 1) { g.fillRect(posL , top + row1 * 6, gridW, gridH); }
           if (Ktrigger7[34] == 1) { g.fillRect(posL + gridW, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[35] == 1) { g.fillRect(posL+gridW* 2, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[36] == 1) { g.fillRect(posL+gridW* 3, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[37] == 1) { g.fillRect(posL+gridW* 4, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[38] == 1) { g.fillRect(posL+gridW* 5, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[39] == 1) { g.fillRect(posL+gridW* 6, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[40] == 1) { g.fillRect(posL+gridW* 7, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[41] == 1) { g.fillRect(posL+gridW* 8, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[42] == 1) { g.fillRect(posL+gridW* 9, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[43] == 1) { g.fillRect(posL+gridW* 10, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[44] == 1) { g.fillRect(posL+gridW* 11, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[45] == 1) { g.fillRect(posL+gridW* 12, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[46] == 1) { g.fillRect(posL+gridW* 13, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[47] == 1) { g.fillRect(posL+gridW* 14, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[48] == 1) { g.fillRect(posL+gridW* 15, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[49] == 1) { g.fillRect(posL+gridW* 16, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[50] == 1) { g.fillRect(posL+gridW* 17, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[51] == 1) { g.fillRect(posL+gridW* 18, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[52] == 1) { g.fillRect(posL+gridW* 19, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[53] == 1) { g.fillRect(posL+gridW* 20, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[54] == 1) { g.fillRect(posL+gridW* 21, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[55] == 1) { g.fillRect(posL+gridW* 22, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[56] == 1) { g.fillRect(posL+gridW* 23, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[57] == 1) { g.fillRect(posL+gridW* 24, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[58] == 1) { g.fillRect(posL+gridW* 25, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[59] == 1) { g.fillRect(posL+gridW* 26, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[60] == 1) { g.fillRect(posL+gridW* 27, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[61] == 1) { g.fillRect(posL+gridW* 28, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[62] == 1) { g.fillRect(posL+gridW* 29, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[63] == 1) { g.fillRect(posL+gridW* 30, top +row1 * 6, gridW, gridH); }
           if (Ktrigger7[64] == 1) { g.fillRect(posL + gridW * 31, top + row1 * 6, gridW, gridH); }
       }
       */
    g.setColour(colour1);
    for (int i = 0; i < 33; i++) {
        for (int y = 0; y < 3; y++) {
            g.drawRect(posL, top , i * row, y * row);
        }
    }
   

    char readout[50] = { "raedout" };
    sprintf(readout, "%d %f", mDown, Ktrigger1[trpos1]);
    g.setColour(juce::Colours::white);
 //   g.drawText(readout, 100, row1 * 6, 140, 30, juce::dontSendNotification);
  
}


void TriggerGui::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
String uname = { "-" };
void TriggerGui::serialParas(AudioProcessorValueTreeState& valueTreeState, String name)
{
    uname= name;
    int nb = 0;
    for (int i = 0; i < TRIGGERLENGHT; i++) {
                    nb++;


              sprintf(&serialSeqParas1[nb-1], "%.0f", minMax1(Ktrigger1[i]));
              sprintf(&serialSeqParas2[nb-1], "%.0f", minMax1(Ktrigger2[i]));
              sprintf(&serialSeqParas3[nb-1], "%.0f", minMax1(Ktrigger3[i]));
              sprintf(&serialSeqParas4[nb-1], "%.0f", minMax1(Ktrigger4[i]));
              sprintf(&serialSeqParas5[nb-1], "%.0f", minMax1(Ktrigger5[i]));
              sprintf(&serialSeqParas6[nb-1], "%.0f", minMax1(Ktrigger6[i]));
              sprintf(&serialSeqParas7[nb-1], "%.0f", minMax1(Ktrigger7[i]));
    }
   
    valueTreeState.state.setProperty(name + "tr1", var(serialSeqParas1), nullptr);
    KtrigAll[0].setValue(var(serialSeqParas1));
    valueTreeState.state.setProperty(name + "tr2", var(serialSeqParas2), nullptr);
    KtrigAll[1].setValue(var(serialSeqParas2));
    valueTreeState.state.setProperty(name + "tr3", var(serialSeqParas3), nullptr);
    KtrigAll[2].setValue(var(serialSeqParas3));
    valueTreeState.state.setProperty(name + "tr4", var(serialSeqParas4), nullptr);
    KtrigAll[3].setValue(var(serialSeqParas4));
    valueTreeState.state.setProperty(name + "tr5", var(serialSeqParas5), nullptr);
    KtrigAll[4].setValue(var(serialSeqParas5));
    valueTreeState.state.setProperty(name + "tr6", var(serialSeqParas6), nullptr);
    KtrigAll[5].setValue(var(serialSeqParas6));
    valueTreeState.state.setProperty(name + "tr7", var(serialSeqParas7), nullptr);
    KtrigAll[6].setValue(var(serialSeqParas7));
    triggersoutC();
    GetTrigAllV();
   
}

void TriggerGui::unSerialParas(AudioProcessorValueTreeState& valueTreeState)
{

    SeqStateParas1.referTo(valueTreeState.state.getPropertyAsValue(uname+"tr1", nullptr, true));
    SeqStateParas2.referTo(valueTreeState.state.getPropertyAsValue(uname + "tr2", nullptr, true));
    SeqStateParas3.referTo(valueTreeState.state.getPropertyAsValue(uname + "tr3", nullptr, true));
    SeqStateParas4.referTo(valueTreeState.state.getPropertyAsValue(uname + "tr4", nullptr, true));
    SeqStateParas5.referTo(valueTreeState.state.getPropertyAsValue(uname + "tr5", nullptr, true));
    SeqStateParas6.referTo(valueTreeState.state.getPropertyAsValue(uname + "tr6", nullptr, true));
    SeqStateParas7.referTo(valueTreeState.state.getPropertyAsValue(uname + "tr7", nullptr, true));

    
    for (int i = 0; i <= TRIGGERLENGHT-1; i +=1) {
        Ktrigger1[i] = SeqStateParas1.getValue().toString().substring(i, i + 1 ).getFloatValue();
        Ktrigger2[i] = SeqStateParas2.getValue().toString().substring(i, i + 1).getFloatValue();
        Ktrigger3[i] = SeqStateParas3.getValue().toString().substring(i, i + 1).getFloatValue();
        Ktrigger4[i] = SeqStateParas4.getValue().toString().substring(i, i + 1).getFloatValue();
        Ktrigger5[i] = SeqStateParas5.getValue().toString().substring(i, i + 1).getFloatValue();
        Ktrigger6[i] = SeqStateParas6.getValue().toString().substring(i, i + 1).getFloatValue();
        Ktrigger7[i] = SeqStateParas7.getValue().toString().substring(i, i + 1).getFloatValue();
        
    }
    repaint();
    getTrigger1();
    getTrigger2();
    getTrigger3();
    getTrigger4();
    getTrigger5();
    getTrigger6();
    getTrigger7();
    triggersoutC();
}

void TriggerGui::XmlTriggersIn(float** in)
{
    for (int i = 0; i <= TRIGGERLENGHT - 1; i ++) {
        Ktrigger1[i] = in[0][i];
        Ktrigger2[i] = in[1][i];
        Ktrigger3[i] = in[2][i];
        Ktrigger4[i] = in[3][i];
        Ktrigger5[i] = in[4][i];
        Ktrigger6[i] = in[5][i];
        Ktrigger7[i] = in[6][i];
    }
    repaint();
    getTrigger1();
    getTrigger2();
    getTrigger3();
    getTrigger4();
    getTrigger5();
    getTrigger6();
    getTrigger7();
    triggersoutC();
}

const char* TriggerGui::triggersoutC()
{
    return serialSeqParas1;
}

void TriggerGui::valueChanged(float newValue)
{
    if (lastValue == newValue)
        return;
    lastValue = newValue;

    switch (GetParaNr()) {
    case 0:
        break;
    case 1:
       Ktrigger1[trpos1] = lastValue;
       triggersoutC();

       break;
    case 2:
        Ktrigger2[trpos2] =lastValue;
        break;
    case 3:
        Ktrigger3[trpos3] = lastValue;
        break;
    case 4:
        Ktrigger4[trpos4] = lastValue;
        break;
    case 5:
        Ktrigger5[trpos5] = lastValue;
        break;
    case 6:
        Ktrigger6[trpos6] = lastValue;
        break;
    case 7:
        Ktrigger7[trpos7] = lastValue;
        break;
    default:
        break;
    }

    if (onValueChanged != nullptr)
        onValueChanged();



}
