/*
  ==============================================================================

    mainController.h
    Created: 5 Oct 2022 7:09:49pm
    Author:  Roger Hug

  ==============================================================================
*/

#pragma once
struct ParasMainControll
{
    float mEngineNb;
    float mTimeIn;
    float mTimeBpm;
    float mTime_divide;
    float mTime_divide_switch;
    float mStartStop;
    float mSeqenceNr;
    float mSequenceLenght;

    float mMasterPitch;
    float mMasterGain;

    float mSampelRate;
    ParasMainControll();

    void setSampelRate(float v) { mSampelRate = v; }

    void setEngineNr(float v) {  mEngineNb = v; getEngineHide();  }
    void setTimerIn(float v)  { mTimeIn = v;    }
    void setTimeBp(float v)   { mTimeBpm = v; getTimerBpm(); }
    const int getTimerBpm()   { return  mTimeBpm * 200;  }
    void setTimeDivide(float v,float sw) { mTime_divide = v; }
    void setTimeDivideSwitch(float v) { mTime_divide_switch = v; }
    const int getTimeDivAll();

    void setStartStop(float v) { mStartStop = v; }

    void setSequenceNr(float v) { mSeqenceNr = v; }
    void setSequenceLenght(float v) { mSequenceLenght = v; }

    void setmasterPitch(float v) { mMasterPitch = v; }
    void setMasterGain(float v) { mMasterGain = v; }
    bool eNrHide[8] = { false,false, false, false, false, false, false,false };
    const bool *getEngineHide()
    {
        for (int i = 0; i < 7; i++) {
            if(i==int(mEngineNb))
                eNrHide[int(mEngineNb)] = true;
            else
            eNrHide[i] = false;
             }
        return eNrHide;
    }

    const float* getMainParas();
private:
    float* MainParasBus;

};
