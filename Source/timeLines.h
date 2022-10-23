/*
  ==============================================================================

    timeLines.h
    Created: 16 Feb 2022 2:26:57pm
    Author:  r7

  ==============================================================================
*/

#pragma once


template< typename precision = long double, typename ratio = std::milli >
class TimerX final
{
public:
    //---------------- aliases ----------------
    using timeDuration_t = std::chrono::duration<precision, ratio>;
    using timePoint_t = std::chrono::time_point<std::chrono::system_clock, timeDuration_t>;
    using this_type = TimerX< precision, ratio >;

    inline void Start()  { m_start = std::chrono::system_clock::now(); }
    inline void End()   {  m_end = std::chrono::system_clock::now();   }
    void CalcDuration() {  m_duration = std::max(m_start, m_end) - std::min(m_start, m_end);  }

    timeDuration_t const& GetDuration() const
    {
        return m_duration;
    }
    void Zero()
    {
        m_start = std::chrono::system_clock::now();
        m_end = std::chrono::system_clock::now();
        m_duration = std::max(m_start, m_end) - std::min(m_start, m_end);

    }
    //--------------------------------
    /* TestLatency( i_count )
        Tests the latency / error of the timer class.

        NOTE: this number is how inaccurate your timings can be.
    */

    
    
    static timeDuration_t TestLatency512(size_t const i_count = 512)
      
    {
      
        this_type t;
        timeDuration_t tSum = timeDuration_t::duration::zero();
        for (size_t i = 0; i < i_count; ++i)
        {
            t.Start();
            t.End();
            t.CalcDuration();
            tSum += t.GetDuration();
        }
        return tSum / i_count;
    }
   

private:
    //---------------- private member data ----------------
    timePoint_t     m_start;
    timePoint_t     m_end;
    timeDuration_t  m_duration;

};

using Timer_t = TimerX<>;

#include <JuceHeader.h>
#include <chrono>

constexpr auto SEQSIZE = 32;


//==============================================================================
/*
*/
class timeLines
{
public:
    timeLines();
    ~timeLines();

    void setAllParaSiN(float* in)
    {

    }

    void setTimeSource(int s) { KtimeSourceSw = s; }
    void setBpm(int bp) { bPm = bp; }
    int getBpm() { return bPm; }
    void setTimes(int t); 
    int dividers[10] = { 10,10,10,10,10,10,10,10,10 };
    double fixdivision[10] = { 1,1,1,1,1,1,1 };
    void setGate(float g,int n,int m) {
        
        if (m < 1) {
           
            float pin1 = 0.17;// / 120 * double(bPm);
            float pin2 = 0.37;// / 120 * double(bPm);
                if (dividers[n] > 10)
                    mGate[n] = pin1;
                else
                    mGate[n] = pin2;
            
        }
        else
        
        mGate[n] = g;
    
    
    }
    void setSequenceLenght(float sqlenght) { seqlenght = sqlenght; }
    void setDivides(int d, int n); 
    void setModulatorDiv(float d,float n);
    void division(int n);
    //--------timersync----


    //-------timer-chrono
    TimerX<double> tm1;
    void timerChrono(AudioPlayHead* playhead,int nFrames,float on);
    float gettest() { return test; }
    //------vst-PPQ time------
    void prepare(int sr, int size);
    const double getPpqPerSample(); 
    void processTimeHost(AudioPlayHead* playhead, int nFrames,int selectSp);

    //------vst PPQ sampels--------
    double ppqqq;
    void prosessTimeSampels(AudioPlayHead* playhead, int nFrames, int selectSp);
    double getPpqIn() { return ppqqq; }
    //-----triggerinputs 

    void trigger1In(const float* tr, float a);
    void trigger2In(const float* tr, float a);
    void trigger3In(const float* tr, float a);
    void trigger4In(const float* tr, float a);
    void trigger5In(const float* tr, float a);
    void trigger6In(const float* tr, float a);
    void trigger7In(const float* tr, float a);
    void setStepChange(float s) { stepChangeN = s; }
    const int GetStepSequence() { return stepSq; }
    bool changeStepGui() {
        if (int(stepChangeN) == 2)
        {
            if (getHtime1()[0] == 0 && getHtime1()[2] < 500)
                return true;
        }
        else
            return false;

    }
    int stepSq;
    const float* getTrigger1()
    {
        return triggers1;
    }
    //-----Outputs------
    const int *getHtime1();
    const int* getHtime2();
    const int* getHtime3();
    const int* getHtime4();
    const int* getHtime5();
    const int* getHtime6();
    const int* getHtime7();
    const int* getHtimeAll(int m);
 int Blocksize;
    int Sampelrate;
    int dataint;
    float datafloat;
    float xt = 0;
    int gateSource;
private:
    float test;
    float *mModulatorDiv;
    int KtimeSourceSw;
    float stepChangeN;
    int stepChange;
   
    int bPm;
    float *mGate;
    int triggerAB; 
    float seqlenght;
    float* triggers1;
    float* triggers2;
    float* triggers3;
    float* triggers4;
    float* triggers5;
    float* triggers6;
    float* triggers7;
  
  

    std::atomic<double> currentPositionPpq = { 0.00 };
    std::atomic<double> IcurrentPositionCr = { 0.00 };


    std::atomic<double> IcurrentPositionS1 = { 0.00 };
    std::atomic<double> IcurrentPositionS2 = { 0.00 };
    std::atomic<double> IcurrentPositionS3 = { 0.00 };
    std::atomic<double> IcurrentPositionS4 = { 0.00 };
    std::atomic<double> IcurrentPositionS5 = { 0.00 };
    std::atomic<double> IcurrentPositionS6 = { 0.00 };
    std::atomic<double> IcurrentPositionS7 = { 0.00 };


    double SampelsInMinute;
    AudioPlayHead::CurrentPositionInfo info;
    std::vector<double> ppqPositions;
    std::vector<double> TimeSampelsPositions;
    std::vector<double> PositionsCr;
  
   

  
  //  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK _DETECTOR (timeLines)
};
