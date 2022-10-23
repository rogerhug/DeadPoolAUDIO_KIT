/*
  ==============================================================================

    echoController.cpp
    Created: 21 Oct 2022 10:28:41pm
    Author:  roger hug

  ==============================================================================
*/

#include "echoController.h"

ParasEchoControll::ParasEchoControll()
 :mode(0)
,dTime(0)
,dTimeM(0)
,dTimeMod(0)
,dLevel(0)
,dLevelM(0)
,dLevelMod(0)
,dFeed(0)
,dFeedM(0)
,dFeedMod(0)
,dMix(0)
,dMixM(0)
,dMix_t(0)
,dMixMod(0)
,dStepperMix(0)
{



}

const float ParasEchoControll::delaySync(float t)
{
 
    const int sync = t * 6;
    float time;
    switch (sync)
    {
    case 0:
        time = 0.125;
     break;
    case 1:
        time = 0.25;
        break;
    case 2:
        time = 0.5;
        break;
    case 3:
        time = 0.75;
        break;
    case 4:
        time = 1;
        break;
    case 5:
        time = 1.5;
        break;
    case 6:
        time = 2;
        break;
    default:
        break;
    }
    dTime = time;
    getDelayTime();
    return time;
}
