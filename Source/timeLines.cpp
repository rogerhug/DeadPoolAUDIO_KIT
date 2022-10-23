/*
  ==============================================================================

    timeLines.cpp
    Created: 16 Feb 2022 2:26:57pm
    Author:  r7

  ==============================================================================
*/

#include <JuceHeader.h>
#include "timeLines.h"

//==============================================================================
timeLines::timeLines()

    :IcurrentPositionCr(0.00)
    , currentPositionPpq(0.00)
    , IcurrentPositionS1(0.00)
    , IcurrentPositionS2(0.00)
    , IcurrentPositionS3(0.00)
    , IcurrentPositionS4(0.00)
    , IcurrentPositionS5(0.00)
    , IcurrentPositionS6(0.00)
    , IcurrentPositionS7(0.00)
    , seqlenght(SEQSIZE)
    , Blocksize(512)
    , bPm(120)
    , Sampelrate(44100)
    , triggerAB(0)

   
{
    gateSource = 10;
    KtimeSourceSw = 0;
    mGate = new float[10];
    mModulatorDiv = new float[10];
    for (int i = 0; i < 10; i++) {
        mModulatorDiv[i] = 2;
        mGate[i] = 250;
    }
    triggers1 = new float[66];
    triggers2 = new float[66];
    triggers3 = new float[66];
    triggers4 = new float[66];
    triggers5 = new float[66];
    triggers6 = new float[66];
    triggers7 = new float[66];

    for (int i = 0; i < 66; i++) {
        triggers1[i] = 0;
        triggers2[i] = 0;
        triggers3[i] = 0;
        triggers4[i] = 0;
        triggers5[i] = 0;
        triggers6[i] = 0;
        triggers7[i] = 0;
      
    }
    for (int i = 0; i < 7; i++)
        setDivides(10, i);

    stepChangeN = 0;
    stepSq = 0;
    stepChange = 0;
}

timeLines::~timeLines()
{
}

void timeLines::setTimes(int t)
{
 
    for (int i = 0; i < 10; ++i) {
        dividers[i] = t+3;
        division(i);
    }
}

void timeLines::setDivides(int d, int n)
{
    dividers[n] = d; division(n);
}

void timeLines::setModulatorDiv(float d,float n)
{
    const int nr = n;
    if (d == 0) { mModulatorDiv[nr] = 0.25; }
    if (d == 1) { mModulatorDiv[nr] = 0.5; }
    if (d == 2) { mModulatorDiv[nr] = 1; }
    if (d == 3) { mModulatorDiv[nr] = 2; }
    if (d == 4) { mModulatorDiv[nr] = 4; }
}

int timeOuts1[7] = { 0,0,0,0,0,0 };
int timeOuts2[6] = { 0,0,0,0,0,0 };
int timeOuts3[6] = { 0,0,0,0,0,0 };
int timeOuts4[6] = { 0,0,0,0,0,0 };
int timeOuts5[6] = { 0,0,0,0,0,0 };
int timeOuts6[6] = { 0,0,0,0,0,0 };
int timeOuts7[6] = { 0,0,0,0,0,0 };




void timeLines::prepare(int sr, int size)
{
    tm1.Zero();
    Blocksize = size;
    Sampelrate = sr;
    SampelsInMinute = (double(sr) * 60);
    ppqPositions.resize(size);
    IcurrentPositionCr = 0;
    PositionsCr.resize(size);
}

const double timeLines::getPpqPerSample()
{
    auto SampelsPerBeat = SampelsInMinute / info.bpm;
    return 1 / SampelsPerBeat;
}
inline int minSq(int i)
{
    if (i < 1)
        i = 1;
    return i;
}
void timeLines::processTimeHost(AudioPlayHead* playhead, int nFrames,int selectSp)
{
    if (KtimeSourceSw == 2) {
        tm1.End();
        const int size = seqlenght;

        if (playhead != nullptr)
            playhead->getCurrentPosition(info);

        auto ppqPerSample = getPpqPerSample();
        double offset = 0.0;

        if (info.isPlaying > 0) {


             

            for (int sample = 0; sample < nFrames; ++sample)
            {
                const int latence = double(2010) / info.bpm * 120;;
                ppqPositions[sample] = info.ppqPosition + offset;
                offset += ppqPerSample;
                const double pos = ppqPositions[sample] + (double(Blocksize) / 1000);
             
                currentPositionPpq = pos+latence;




            }


            //--------------------------stepTime-----------------------AB--sequence--

           
            if (int(stepChangeN) == 2)
            {   const int triggCh = int(fmod((IcurrentPositionS1 / size), 2));//stepcount
                stepSq = triggCh;
                triggerAB = 32 * triggCh;
            }



            //---------------------------time1----------------------------------
            timeOuts1[0] = (fmod(currentPositionPpq * fixdivision[0],minSq(size)));
            timeOuts1[2] = fmod(currentPositionPpq * fixdivision[0], 1.0) * 960.0 + 0.5;
            timeOuts1[3] = (fmod(currentPositionPpq * mModulatorDiv[0], minSq(size/2)));
            timeOuts1[4] = (fmod(currentPositionPpq * fixdivision[0], 4));
            if (timeOuts1[2] < (mGate[0] * 960) && triggers1[timeOuts1[0] + 1 + triggerAB] == true)
            {
                timeOuts1[1] = 1;                                     //triggerOn
            }
            else { timeOuts1[1] = 0; }

            //---------------------------time2----------------------------------
            timeOuts2[0] = (fmod(currentPositionPpq * fixdivision[1], minSq(size)));
            timeOuts2[2] = fmod(currentPositionPpq * fixdivision[1], 1.0) * 960.0 + 0.5;
            timeOuts2[3] = (fmod(currentPositionPpq * mModulatorDiv[1], minSq(size/2)));
            timeOuts2[4] = (fmod(currentPositionPpq * fixdivision[1], 4));
            if (timeOuts2[2] < (mGate[1] * 960) && triggers2[timeOuts2[0] + 1 + triggerAB] == true)
            {
                timeOuts2[1] = 1;                                     //triggerOn
            }
            else { timeOuts2[1] = 0; }

            //---------------------------time3----------------------------------
            timeOuts3[0] = (fmod(currentPositionPpq * fixdivision[2], minSq(size)));
            timeOuts3[2] = fmod(currentPositionPpq * fixdivision[2], 1.0) * 960.0 + 0.5;
            timeOuts3[3] = (fmod(currentPositionPpq * mModulatorDiv[2], minSq(size/2)));
            timeOuts3[4] = (fmod(currentPositionPpq * fixdivision[2], 4));
            if (timeOuts3[2] < (mGate[2] * 960) && triggers3[timeOuts3[0] + 1 + triggerAB] == true)
            {
                timeOuts3[1] = 1;                                     //triggerOn
            }
            else { timeOuts3[1] = 0; }

            //---------------------------time4----------------------------------
            timeOuts4[0] = (fmod(currentPositionPpq * fixdivision[3], minSq(size)));
            timeOuts4[2] = fmod(currentPositionPpq * fixdivision[3], 1.0) * 960.0 + 0.5;
            timeOuts4[3] = (fmod(currentPositionPpq * mModulatorDiv[3], minSq(size/2)));
            timeOuts4[4] = (fmod(currentPositionPpq * fixdivision[3], 4));
            if (timeOuts4[2] < (mGate[3] * 960) && triggers4[timeOuts4[0] + 1 + triggerAB] == true)
            {
                timeOuts4[1] = 1;                                     //triggerOn
            }
            else { timeOuts4[1] = 0; }

            //---------------------------time5----------------------------------
            timeOuts5[0] = (fmod(currentPositionPpq * fixdivision[4], minSq(size)));
            timeOuts5[2] = fmod(currentPositionPpq * fixdivision[4], 1.0) * 960.0 + 0.5;
            timeOuts5[3] = (fmod(currentPositionPpq * mModulatorDiv[4], minSq(size/2)));
            timeOuts5[4] = (fmod(currentPositionPpq * fixdivision[4], 4));
            if (timeOuts5[2] < (mGate[4] * 960) && triggers5[timeOuts5[0] + 1 + triggerAB] == true)
            {
                timeOuts5[1] = 1;                                     //triggerOn
            }
            else { timeOuts5[1] = 0; }

            //---------------------------time6----------------------------------
            timeOuts6[0] = (fmod(currentPositionPpq * fixdivision[5], minSq(size)));
            timeOuts6[2] = fmod(currentPositionPpq * fixdivision[5], 1.0) * 960.0 + 0.5;
            timeOuts6[3] = (fmod(currentPositionPpq * mModulatorDiv[5], minSq(size/2)));
            timeOuts6[4] = (fmod(currentPositionPpq * fixdivision[5], 4));
            if (timeOuts6[2] < (mGate[5] * 960) && triggers6[timeOuts6[0] + 1 + triggerAB] == true)
            {
                timeOuts6[1] = 1;                                     //triggerOn
            }
            else { timeOuts6[1] = 0; }

            //---------------------------time7----------------------------------
            timeOuts7[0] = (fmod(currentPositionPpq * fixdivision[6], minSq(size)));
            timeOuts7[2] = fmod(currentPositionPpq * fixdivision[6], 1.0) * 960.0 + 0.5;
            timeOuts7[3] = (fmod(currentPositionPpq * mModulatorDiv[6], minSq(size/2)));
            timeOuts7[4] = (fmod(currentPositionPpq * fixdivision[6], 4));
            if (timeOuts7[2] < (mGate[6] * 960) && triggers7[timeOuts7[0] + 1 + triggerAB] == true)
            {
                timeOuts7[1] = 1;                                     //triggerOn
            }
            else { timeOuts7[1] = 0; }




        }
    }
    
}
int scount1 = 0;
double rateS[10] = { 0,0,0,0,0,0,0 };
float buf1[2048]; int trdef = 0;
void timeLines::prosessTimeSampels(AudioPlayHead* playhead, int sampel_t, int nFrames)
{
    if (KtimeSourceSw == 1) {

        tm1.End();
    int samplePos = (sampel_t);
        if (playhead != nullptr)
            playhead->getCurrentPosition(info);
        float beats = 0;


        double offset = ((double)Blocksize/2) * 1000 / Sampelrate;

        const int kBeatDiv = 4;
        const int kBeatDiv32 = ((32));
        const int size = seqlenght;
    
        int samplesPerBeat0 =  (Sampelrate) * 60.0 / info.bpm* fixdivision[0];
        int samplesPerBeat1 = (Sampelrate) * 60.0 / info.bpm * fixdivision[1];
        int samplesPerBeat2 = (Sampelrate) * 60.0 / info.bpm * fixdivision[2];
        int samplesPerBeat3 = (Sampelrate) * 60.0 / info.bpm * fixdivision[3];
        int samplesPerBeat4 = (Sampelrate) * 60.0 / info.bpm * fixdivision[4];
        int samplesPerBeat5 = (Sampelrate) * 60.0 / info.bpm * fixdivision[5];
        int samplesPerBeat6 = (Sampelrate) * 60.0 / info.bpm * fixdivision[6];
        
        
        if (info.isPlaying > 0) {


            for (int s = 0; s < nFrames; s++)
                  {

               ppqPositions[s] = (samplePos + s) ;
               const int latence = double(2010) / info.bpm * 120;;
               const double pos = (ppqPositions[s] - offset) +latence;
                 xt = double(pos);
                  
                
                 
                int mod0 = (int(pos) % ((samplesPerBeat0) * kBeatDiv32));
                IcurrentPositionS1 = ((mod0) / ((samplesPerBeat0) / kBeatDiv32));
                rateS[0] = (double)(mod0 ) / ((samplesPerBeat0/ kBeatDiv32));
                timeOuts1[6] = samplesPerBeat0;

                int mod1 = (int(pos) % (samplesPerBeat1 * kBeatDiv32));
                IcurrentPositionS2 = mod1 / (samplesPerBeat1 / kBeatDiv32);
                rateS[1] = (double)mod1 / (samplesPerBeat1 / kBeatDiv32);

                int mod2 = (int(pos) % (samplesPerBeat2 * kBeatDiv32));
                IcurrentPositionS3 = mod2 / (samplesPerBeat2 / kBeatDiv32);
                rateS[2] = (double)mod2 / (samplesPerBeat2 / kBeatDiv32);

                int mod3 = int(pos) % (samplesPerBeat3 * kBeatDiv32);
                IcurrentPositionS4 = mod3 / (samplesPerBeat3 / kBeatDiv32);
                rateS[3] = (double)mod3 / (samplesPerBeat3 / kBeatDiv32);

                int mod4 = int(pos) % (samplesPerBeat4 * kBeatDiv32);
                IcurrentPositionS5 = mod4 / (samplesPerBeat4 / kBeatDiv32);
                rateS[4] = (double)mod4 / (samplesPerBeat4 / kBeatDiv32);

                int mod5 = int(pos) % (samplesPerBeat5 * kBeatDiv32);
                IcurrentPositionS6 = mod5 / (samplesPerBeat5 / kBeatDiv32);
                rateS[5] = (double)mod5 / (samplesPerBeat5 / kBeatDiv32);

                int mod6 = int(pos) % (samplesPerBeat6 * kBeatDiv32);
                IcurrentPositionS7 = mod6 / (samplesPerBeat6 / kBeatDiv32);
                rateS[6] = (double)mod6 / (samplesPerBeat6 / kBeatDiv32);


            }
            const int polyN = 4;
            
            
            //--------------------------stepTime-----------------------AB--sequence--

          
             if (int(stepChangeN) == 2)
                {
                const int triggCh= int(fmod((IcurrentPositionS1 / size), 2));//stepcount
                stepSq = triggCh;

                triggerAB =32* triggCh;
                changeStepGui();
                }

           //-----------------------------time1------------------------------------
            
            timeOuts1[0] = (int(IcurrentPositionS1) % minSq(size));          // count
            timeOuts1[2] = int(fmod((rateS[0]), 1.0) * 960.0 + 0.5);   //rate
            timeOuts1[3] = (int((IcurrentPositionS1)* mModulatorDiv[0]) % minSq(size/2));    //modCount
            timeOuts1[4] = int(fmod((IcurrentPositionS1), polyN));        //voicecount
          
  
           
            

            timeOuts1[5] = trdef;

            if (timeOuts1[2] < (mGate[0] * 960) && triggers1[timeOuts1[0] + 1 + triggerAB] == true)
            {
                timeOuts1[1] = 1;                                     //triggerOn
            }
            else { timeOuts1[1] = 0; }

            //---------------------------time2----------------------------------------------


            timeOuts2[0] = (int(IcurrentPositionS2) % minSq(size));          // count
            timeOuts2[2] = int(fmod((rateS[1]), 1.0) * 960.0 + 0.5);   //rate
            timeOuts2[3] = (int(IcurrentPositionS2* mModulatorDiv[1]) % (minSq(size/2)));    //modCount
            timeOuts2[4] = int(fmod(IcurrentPositionS2, polyN));        //voicecount

            if (timeOuts2[2] < (mGate[1] * 960) && triggers2[timeOuts2[0] + 1 + triggerAB] == true)
            {
                timeOuts2[1] = 1;                                     //triggerOn
            }
            else { timeOuts2[1] = 0; }

            //---------------------------time3----------------------------------------------


            timeOuts3[0] = (int(IcurrentPositionS3) % minSq(size));          // count
            timeOuts3[2] = int(fmod((rateS[2]), 1.0) * 960.0 + 0.5);   //rate
            timeOuts3[3] = (int(IcurrentPositionS3 *mModulatorDiv[2]) % (minSq(size/2)));    //modCount
            timeOuts3[4] = int(fmod(IcurrentPositionS3, polyN));        //voicecount

            if (timeOuts3[2] < (mGate[2] * 960) && triggers3[timeOuts3[0] + 1 + triggerAB] == true)
            {
                timeOuts3[1] = 1;                                     //triggerOn
            }
            else { timeOuts3[1] = 0; }
            //---------------------------time4----------------------------------------------


            timeOuts4[0] = (int(IcurrentPositionS4) % minSq(size));          // count
            timeOuts4[2] = int(fmod((rateS[3]), 1.0) * 960.0 + 0.5);   //rate
            timeOuts4[3] = (int(IcurrentPositionS4* mModulatorDiv[3]) % (minSq(size/2)));    //modCount
            timeOuts4[4] = int(fmod(IcurrentPositionS4, polyN));        //voicecount

            if (timeOuts4[2] < (mGate[3] * 960) && triggers4[timeOuts4[0] + 1 + triggerAB] == true)
            {
                timeOuts4[1] = 1;                                     //triggerOn
            }
            else { timeOuts4[1] = 0; }

            //---------------------------time5----------------------------------------------


            timeOuts5[0] = (int(IcurrentPositionS5) % minSq(size));          // count
            timeOuts5[2] = int(fmod((rateS[4]), 1.0) * 960.0 + 0.5);   //rate
            timeOuts5[3] = (int(IcurrentPositionS5* mModulatorDiv[4]) % (minSq(size/2)));    //modCount
            timeOuts5[4] = int(fmod(IcurrentPositionS5, polyN));        //voicecount

            if (timeOuts5[2] < (mGate[4] * 960) && triggers5[timeOuts5[0] + 1 + triggerAB] == true)
            {
                timeOuts5[1] = 1;                                     //triggerOn
            }
            else { timeOuts5[1] = 0; }

            //---------------------------time6----------------------------------------------


            timeOuts6[0] = (int(IcurrentPositionS6) % minSq(size));          // count
            timeOuts6[2] = int(fmod((rateS[5]), 1.0) * 960.0 + 0.5);   //rate
            timeOuts6[3] = (int(IcurrentPositionS6* mModulatorDiv[5]) % (minSq(size/2)));    //modCount
            timeOuts6[4] = int(fmod(IcurrentPositionS6, polyN));        //voicecount

            if (timeOuts6[2] < (mGate[5] * 960) && triggers6[timeOuts6[0] + 1 + triggerAB] == true)
            {
                timeOuts6[1] = 1;                                     //triggerOn
            }
            else { timeOuts6[1] = 0; }

            //---------------------------time7----------------------------------------------


            timeOuts7[0] = (int(IcurrentPositionS7) % minSq(size));          // count
            timeOuts7[2] = int(fmod((rateS[6]), 1.0) * 960.0 + 0.5);   //rate
            timeOuts7[3] = (int(IcurrentPositionS7* mModulatorDiv[6]) % (minSq(size/2)));    //modCount
            timeOuts7[4] = int(fmod(IcurrentPositionS7, polyN));        //voicecount

            if (timeOuts7[2] < (mGate[6] * 960) && triggers7[timeOuts7[0] + 1 + triggerAB] == true)
            {
                timeOuts7[1] = 1;                                     //triggerOn
            }
            else { timeOuts7[1] = 0; }



        }

    }
}

void timeLines::trigger1In(const float* tr, float a)
{

    const int sw = a;
    if (sw == 0)
        triggerAB = 0;
    if (sw == 1)
        triggerAB = 32;
    if (sw == 3) {


    }


    memcpy(triggers1, tr, 66 * sizeof(float));
}

void timeLines::trigger2In(const float* tr, float a)
{
    if (a == 0)
        triggerAB = 0;
    if (a == 1)
        triggerAB = 32;

    memcpy(triggers2, tr, 66 * sizeof(float));
}

void timeLines::trigger3In(const float* tr, float a)
{
    if (a == 0)
        triggerAB = 0;
    if (a == 1)
        triggerAB = 32;

    memcpy(triggers3, tr, 66 * sizeof(float));
}

void timeLines::trigger4In(const float* tr, float a)
{
    if (a == 0)
        triggerAB = 0;
    if (a == 1)
        triggerAB = 32;

    memcpy(triggers4, tr, 66 * sizeof(float));
}

void timeLines::trigger5In(const float* tr, float a)
{
    if (a == 0)
        triggerAB = 0;
    if (a == 1)
        triggerAB = 32;

    memcpy(triggers5, tr, 66 * sizeof(float));
}

void timeLines::trigger6In(const float* tr, float a)
{
    if (a == 0)
        triggerAB = 0;
    if (a == 1)
        triggerAB = 32;

    memcpy(triggers6, tr, 66 * sizeof(float));
}

void timeLines::trigger7In(const float* tr, float a)
{
    if (a == 0)
        triggerAB = 0;
    if (a == 1)
        triggerAB = 32;

    memcpy(triggers7, tr, 66 * sizeof(float));
}


void timeLines::division(int n)
{
    gateSource = n;
  
    if (KtimeSourceSw == 2) {

        if (dividers[n] == 0) { fixdivision[n] = 0.0125; }          // Vst3 ppq dividers
        if (dividers[n] == 1) { fixdivision[n] = 0.025; }
        if (dividers[n] == 2) { fixdivision[n] = 0.05; }
        if (dividers[n] == 3) { fixdivision[n] = 0.125; }
        if (dividers[n] == 4) { fixdivision[n] = 0.25; }
        if (dividers[n] == 5) { fixdivision[n] = 0.5; }
        if (dividers[n] == 6) { fixdivision[n] = 1; }                  //1/4
        if (dividers[n] == 7) { fixdivision[n] = 1.5; }
        if (dividers[n] == 8) { fixdivision[n] = 2; }                  //1/8
        if (dividers[n] == 9) { fixdivision[n] = 3; }
        if (dividers[n] == 10) { fixdivision[n] = 4; }                 //1/16
        if (dividers[n] == 11 ){ fixdivision[n] = 6; }
        if (dividers[n] == 12) { fixdivision[n] = 8; }                 //1/32
        if (dividers[n] == 13) { fixdivision[n] = 12; }
        if (dividers[n] == 14) { fixdivision[n] = 16; }
        if (dividers[n] == 15) { fixdivision[n] = 24; }
    }
    if (KtimeSourceSw == 0) {                                   // chrono dividers

        if (dividers[n] == 0) { fixdivision[n] = 0.6666666/32; }         // 4/1
        if (dividers[n] == 1) { fixdivision[n] = 0.6666666/24; }         // 3/1
        if (dividers[n] == 2) { fixdivision[n] = 0.6666666/16; }         // 2/1 
        if (dividers[n] == 3) { fixdivision[n] = 0.6666666/12; }         // 1/1
        if (dividers[n] == 4) { fixdivision[n] = 0.6666666/8; }          // 1/2
        if (dividers[n] == 5) { fixdivision[n] = 0.6666666/6; }          // 1/3
        if (dividers[n] == 6) { fixdivision[n] = 0.6666666 /4; }         // 1/4
        if (dividers[n] == 7) { fixdivision[n] = 0.6666666/3; }          // 1/6
        if (dividers[n] == 8) { fixdivision[n] = 0.6666666/2;}           // 1/8
        if (dividers[n] == 9) { fixdivision[n] =  0.66666/1.5; }          //1/12
        if (dividers[n] == 10) { fixdivision[n] = 0.66666; }              //1/16
        if (dividers[n] == 11) { fixdivision[n] = 0.66666 * 1.5; }        //1/24
        if (dividers[n] == 12) { fixdivision[n] = 0.66666 * 2; }          //1/32
        if (dividers[n] == 13) { fixdivision[n] = 0.66666 *3; }           //1/48
        if (dividers[n] == 14) { fixdivision[n] = 0.66666 * 4; }          //1/64
        if (dividers[n] == 15) { fixdivision[n] = 0.66666 * 6; }          //1/96

    }
    if (KtimeSourceSw == 1) {

        if (dividers[n] == 0) { fixdivision[n] = 192; }// Vst3 sampelTime dividers
        if (dividers[n] == 1) { fixdivision[n] = 192; }
        if (dividers[n] == 2) { fixdivision[n] = 128; }
        if (dividers[n] == 3) { fixdivision[n] = 96; }
        if (dividers[n] == 4) { fixdivision[n] = 64; }
        if (dividers[n] == 5) { fixdivision[n] = 48; }
        if (dividers[n] == 6) { fixdivision[n] = 32; }
        if (dividers[n] == 7) { fixdivision[n] = 24; }
        if (dividers[n] == 8) { fixdivision[n] = 16; }
        if (dividers[n] == 9) { fixdivision[n] = 12; }
        if (dividers[n] == 10) { fixdivision[n] = 8; }             //1/16
        if (dividers[n] == 11) { fixdivision[n] = 6; }
        if (dividers[n] == 12) { fixdivision[n] = 4; }
        if (dividers[n] == 13) { fixdivision[n] = 3; }
        if (dividers[n] == 14) { fixdivision[n] = 2; }
        if (dividers[n] == 15) { fixdivision[n] = 1; }
    }
   
}

void timeLines::timerChrono(AudioPlayHead* playhead,int nFrames,float on)
{
    datafloat = tm1.GetDuration().count();
    if (playhead != nullptr)
        playhead->getCurrentPosition(info);

    const int onI = on;

   // if (info.isPlaying == true) {   //vst   
        if (onI >0) {   //app 
     //   if (KtimeSourceSw == 0) {// vst
            if (onI > 0) {//app

            const int size = seqlenght;

            tm1.Start();

            tm1.CalcDuration();



            //--Time ++--------------------------------


            const float offsetC = tm1.TestLatency512().count() / 512 * Blocksize;

            for (int s = 0; s < nFrames; s++) {
                const int clock96 = 64;
          //      PositionsCr[s]= (((tm1.GetDuration().count()) * 0.01) / 100) * info.bpm;//-----------vst
                ppqPositions[s] = ((PositionsCr[s]+(double(Blocksize)/112)) + offsetC);

                const double pos = ppqPositions[s];

            //    IcurrentPositionCr = (pos);//-----------vst
                IcurrentPositionCr = ((tm1.GetDuration().count() * 0.01) / 100) * bPm;     //-----------aPP

                IcurrentPositionS1 = int((IcurrentPositionCr + offsetC) * fixdivision[0]) % clock96; ;
                const int rate1 = fmod((IcurrentPositionCr + offsetC) * fixdivision[0], 1.0) * 960;
                const double t1m = (IcurrentPositionS1 * mModulatorDiv[0]);

                IcurrentPositionS2 = int((IcurrentPositionCr + offsetC) * fixdivision[1]) % clock96;
                const int rate2 = fmod((IcurrentPositionCr + offsetC) * fixdivision[1], 1.0) * 960;
                const double t2m = IcurrentPositionS2 * mModulatorDiv[1];

                IcurrentPositionS3 = int((IcurrentPositionCr + offsetC) * fixdivision[2]) % clock96;
                const int rate3 = fmod((IcurrentPositionCr + offsetC) * fixdivision[2], 1.0) * 960;
                const double t3m = IcurrentPositionS3 * mModulatorDiv[2];

                IcurrentPositionS4 = int((IcurrentPositionCr + offsetC) * fixdivision[3]) % clock96;
                const int rate4 = fmod((IcurrentPositionCr + offsetC) * fixdivision[3], 1.0) * 960;
                const double t4m = IcurrentPositionS4 * mModulatorDiv[3];

                IcurrentPositionS5 = int((IcurrentPositionCr + offsetC) * fixdivision[4]) % clock96;
                const int rate5 = fmod((IcurrentPositionCr + offsetC) * fixdivision[4], 1.0) * 960;
                const double t5m = IcurrentPositionS5 * mModulatorDiv[4];

                IcurrentPositionS6 = int((IcurrentPositionCr + offsetC) * fixdivision[5]) % clock96;
                const int rate6 = fmod((IcurrentPositionCr + offsetC) * fixdivision[5], 1.0) * 960;
                const double t6m = IcurrentPositionS6 * mModulatorDiv[5];


                IcurrentPositionS7 = int((IcurrentPositionCr + offsetC) * fixdivision[6]) % clock96;
                const int rate7 = fmod((IcurrentPositionCr + offsetC) * fixdivision[6], 1.0) * 960;
                const double t7m = IcurrentPositionS7 * mModulatorDiv[6];


           
                const int polyN = 4;

                //--------------------------stepTime-----------------------AB--sequence--

               
                if (int(stepChangeN) == 2)
                {
                    const int triggCh = int(fmod((IcurrentPositionS1 / size), 2));//stepcount
                    stepSq = triggCh;
                    triggerAB = 32 * triggCh;
                }


                    //-----------------------------time 1------------------------------------------

            timeOuts1[0] = (int(IcurrentPositionS1) % minSq(size));            //  count
           // test = rate1;
            timeOuts1[2] = rate1;
            timeOuts1[3] = int(fmod(t1m, minSq(size/ 2) ));                      //----mod
            timeOuts1[4] = int(fmod(IcurrentPositionS1, polyN));             // voice size

            if (timeOuts1[2] < (mGate[0] * 960) && triggers1[timeOuts1[0] + 1 + triggerAB] == true)
            {
                timeOuts1[1] = 1;
            }
            else { timeOuts1[1] = 0; }                               //trigger
            
             //-----------------------------time 2------------------------------------------

            timeOuts2[0] = int(IcurrentPositionS2 ) % minSq(size );        //  count
            timeOuts2[2] = rate2;
            timeOuts2[3] = int(fmod(t2m, minSq(size / 2)));
            timeOuts2[4] = int(fmod(IcurrentPositionS2, polyN));                        // voice size

            if (timeOuts2[2] < (mGate[1] * 960) && triggers2[timeOuts2[0] + 1 + triggerAB] == true)
            {
                timeOuts2[1] = 1;
            }
            else { timeOuts2[1] = 0; }                               //trigger


 
              //-----------------------------time 3------------------------------------------

            timeOuts3[0] = int(IcurrentPositionS3) % minSq(size);       //  count
            timeOuts3[2] = rate3;
            timeOuts3[3] = int(fmod(t3m, minSq(size/2)));
            timeOuts3[4] = int(fmod(IcurrentPositionS3, polyN));                        // voice size

            if (timeOuts3[2] < (mGate[2] * 960) && triggers3[timeOuts3[0] + 1 + triggerAB] == true)
            {
                timeOuts3[1] = 1;
            }
            else { timeOuts3[1] = 0; }     //trigger
            test = (mGate[3]) * 960;
             //-----------------------------time 4------------------------------------------

            timeOuts4[0] = int(IcurrentPositionS4) % minSq(size);        //  count
            timeOuts4[2] = rate4;
            timeOuts4[3] = int(fmod(t4m, minSq(size/2)));
            timeOuts4[4] = int(fmod(IcurrentPositionS4, polyN));                        // voice size

            if (timeOuts4[2] < (mGate[3] * 960) && triggers4[timeOuts4[0] + 1 + triggerAB] == true)
            {
                timeOuts4[1] = 1;
            }
            else { timeOuts4[1] = 0; }     //trigger
            
             //-----------------------------time 5------------------------------------------

            timeOuts5[0] = int(IcurrentPositionS5) % minSq(size);        //  count
            timeOuts5[2] = rate5;
            timeOuts5[3] = int(fmod(t5m, minSq(size/2)));
            timeOuts5[4] = int(fmod(IcurrentPositionS5, polyN));                        // voice size

            if (timeOuts5[2] < (mGate[4] * 960) && triggers5[timeOuts5[0] + 1 + triggerAB] == true)
            {
                timeOuts5[1] = 1;
            }
            else { timeOuts5[1] = 0; }     //trigger

            //-----------------------------time 6------------------------------------------

            timeOuts6[0] = int(IcurrentPositionS6 ) % minSq(size);      //  count
            timeOuts6[2] = rate6;
            timeOuts6[3] = int(fmod(t6m, minSq(size/2)));
            timeOuts6[4] = int(fmod(IcurrentPositionS6, polyN));                        // voice size

            if (timeOuts6[2] < (mGate[5] * 960) && triggers6[timeOuts6[0] + 1 + triggerAB] == true)
            {
                timeOuts6[1] = 1;
            }
            else { timeOuts6[1] = 0; }     //trigger
            
            
            //-----------------------------time 7------------------------------------------

            timeOuts7[0] = int(IcurrentPositionS7 ) % minSq(size);       //  count
            timeOuts7[2] = rate7;
            timeOuts7[3] = int(fmod(t7m, minSq(size/2)));
            timeOuts7[4] = int(fmod(IcurrentPositionS7, polyN));                        // voice size

            if (timeOuts7[2] < (mGate[6] * 960) && triggers7[timeOuts7[0] + 1 + triggerAB] == true)
            {
                timeOuts7[1] = 1;
            }
            else { timeOuts7[1] = 0; }     //trigger

          
            //-------end-------
        }
 }
    }
  //  if (info.ppqLoopEnd - info.ppqPosition == 0) {
   //     tm1.Zero();

     //   if (info.isPlaying == 0 || KtimeSourceSw == 1) { tm1.End(); tm1.Zero();
     //   }

  //  }

    
}





const int *timeLines::getHtime1()
{
    return timeOuts1;
}

const int* timeLines::getHtime2()
{
    return timeOuts2;
}

const int* timeLines::getHtime3()
{
    return timeOuts3;
}

const int* timeLines::getHtime4()
{
    return timeOuts4;
}

const int* timeLines::getHtime5()
{
    return timeOuts5;
}

const int* timeLines::getHtime6()
{
    return timeOuts6;
}

const int* timeLines::getHtime7()
{
    return timeOuts7;
}

const int* timeLines::getHtimeAll(int m)

{
    switch (m) {
    case 0:
        return timeOuts1;
        break;
    case 1:
        return timeOuts2;
        break;
    case 2:
        return timeOuts3;
        break;
    case 3:
        return timeOuts4;
        break;
    case 4:
        return timeOuts5;
        break;
    case 5:
        return timeOuts6;
        break;
    case 6:
        return timeOuts7;
        break;
    case 7:
        break;
    default:
        break;

    }
    return nullptr;
}




