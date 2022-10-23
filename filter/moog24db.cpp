/*
  ==============================================================================

    moog24db.cpp
    Created: 8 Jul 2022 9:06:18am
    Author:  lutz

  ==============================================================================
*/

#include <JuceHeader.h>
#include "moog24db.h"
#include "../JuceLibraryCode/JuceHeader.h"    // only for double_Pi constant
//==============================================================================
moog24db::moog24db()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    fs = 44100.0;
    init();
    cutoff = 22050;
    res = 0.1;
}

moog24db::~moog24db()
{
}

void moog24db::init()
{
    // initialize values
    y1 = y2 = y3 = y4 = oldx = oldy1 = oldy2 = oldy3 = 0;
    calc();
}

void moog24db::calc()
{
    float f = (cutoff + cutoff) / fs; //[0 - 1]
    p = f * (1.8f - 0.8f * f);
    k = p + p - 1.f;

    float t = (1.f - p) * 1.386249f;
    float t2 = 12.f + t * t;
    r = res * (t2 + 6.f * t) / (t2 - 6.f * t);
}

float moog24db::process(float input)
{
    // process input
    x = input - r * y4;

    //Four cascaded onepole filters (bilinear transform)
    y1 = x * p + oldx * p - k * y1;
    y2 = y1 * p + oldy1 * p - k * y2;
    y3 = y2 * p + oldy2 * p - k * y3;
    y4 = y3 * p + oldy3 * p - k * y4;

    //Clipper band limited sigmoid
    y4 -= (y4 * y4 * y4) / 6.f;

    oldx = x; oldy1 = y1; oldy2 = y2; oldy3 = y3;
    return y4;
}


float moog24db::getCutoff()
{
    return cutoff;
}

void moog24db::setCutoff(float c)
{
    cutoff = c*22000; calc();
}

float moog24db::getRes()
{
    return res;
}

void moog24db::setRes(float r)
{
    res = r; calc();
}

