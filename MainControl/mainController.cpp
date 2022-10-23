/*
  ==============================================================================

    mainController.cpp
    Created: 5 Oct 2022 7:09:49pm
    Author:  Roger Hug

  ==============================================================================
*/

#include "mainController.h"

ParasMainControll::ParasMainControll()
    :mEngineNb(0)
    ,mTimeIn(0)
    , mTimeBpm(0.6)
    ,mTime_divide(0.4)
    ,mTime_divide_switch(2)
    ,mStartStop(0)
    ,mSeqenceNr(0)
    ,mSequenceLenght(1)

    ,mMasterPitch(0.5)
    ,mMasterGain(0.5)

   , mSampelRate(44100)
{
    
    
    MainParasBus = new float[20];
    for (int i = 0; i < 20; i++)
        MainParasBus[i] = 0;

    getMainParas();
}

const int ParasMainControll::getTimeDivAll()
{
    int shift = 0;
    if (int(mTime_divide_switch) == 1)
        shift = 0;
    if (int(mTime_divide_switch) == 2)
        shift = 5;
    const int Tm = (mTime_divide * 5) + shift;
    return Tm;
}

const float* ParasMainControll::getMainParas()
{
    MainParasBus[0] = mEngineNb;
    MainParasBus[1] = mTimeIn;
    MainParasBus[2] = mTimeBpm;
    MainParasBus[3] = mTime_divide;
    MainParasBus[4] = mSeqenceNr;
    MainParasBus[5] = mSequenceLenght;

    MainParasBus[6] = mMasterPitch;
    MainParasBus[7] = mMasterGain;


    
    return MainParasBus;
}

