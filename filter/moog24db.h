/*
  ==============================================================================

    moog24db.h
    Created: 8 Jul 2022 9:06:18am
    Author:  lutz

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class moog24db  : public juce::Component
{
public:
    moog24db();
    ~moog24db() override;
        void init();
        void calc();
        float process(float x);
        float getCutoff();
        void setCutoff(float c);
        float getRes();
        void setRes(float r);
    protected:
        float cutoff;
        float res;
        float fs;
        float y1, y2, y3, y4;
        float oldx;
        float oldy1, oldy2, oldy3;
        float x;
        float r;
        float p;
        float k;

       
    };

