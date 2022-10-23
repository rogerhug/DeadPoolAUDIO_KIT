/*
  ==============================================================================

    echoController.h
    Created: 21 Oct 2022 10:28:41pm
    Author:  roger hug

  ==============================================================================
*/

#pragma once
struct ParasEchoControll
{

    float mode;
    float dTime;
    float dTimeM;
    float dTimeMod;
    float dLevel;
    float dLevelM;
    float dLevelMod;
    float dFeed;
    float dFeedM;
    float dFeedMod;
    float dMix;
    float dMixM;
    float dMix_t;
    float dMixMod;

    float dStepperMix;

    ParasEchoControll();

    inline float minmaxDelay(float a) {
        float result = 0; result = a;
        if (result > 0.999) { result = 0.999; }
        if (result < 0.0) { result = 0.0; }
        return result;
    }

    void setDelayMode(float m) { mode = m; getDelayMode(); }
    void setDelayTime(float t) { dTime = (t); dTimeM = (t); }
    void setDelayTimeMod(float tm) { dTimeMod = (tm); }
    void setDelayLevel(float l) { dLevel = (l); dLevelM = (l); }
    void setDelayLevelMod(float lm) { dLevelMod = (lm); }
    void setDelayFeed(float f) { dFeed = f; dFeedM = f; }
    void setDelayFeedMod(float fm) { dFeedMod = fm; }
    void setDelayMix(float m) { dMix = m; dMix_t = m; getDelayMix(); }
    const float getDelayMix() { return dMix; }
    void setDelayMixMod(float md) { dMixMod = md; }

    const float delaySync(float t);
    

    void setDelayMixStepper(float ms) {
        dStepperMix = ms;
        dMix *= ms;

    }

    void delayStepper(float in) {


        const float y = in;

        dMix = minmaxDelay(dMix_t * y);

    }

    const float getDelayTime() { return dTime; }
    const float getDelayFeed() { return dFeed; }
    const float getDelayLevel() { return dLevel; }
    const int getDelayMode() { return mode; }
    //--------main-modulation-------------


    //----parameterModulation------
    void lfoMod(float p)
    {
        float mixphase = 1 - (p * dMixMod);

        if (dTimeMod > 0.1) { dTime = dTimeM * 1 - (p * dTimeMod); }
        else { dTime = dTimeM; }
        if (dLevelMod > 0.1) { dLevel = dLevelM * 1 - (p * dLevelMod); }
        else { dLevel = dLevelM; }
        if (dFeedMod > 0.1) { dFeed = dFeedM * 1 - (p * dFeedMod); }
        else { dFeed = dFeedM; }


        if (dMixMod > 0.1) { dMix = dMix_t * mixphase; }
        else { dMix = dMix; }



    }
private:

};

