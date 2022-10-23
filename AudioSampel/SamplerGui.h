/*
  ==============================================================================

    SamplerGui.h
    Created: 22 Jun 2022 4:37:37pm
    Author:  roger hug

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include"modulator.h"
#include"SamplerController.h"
#include"playSampelFile.h"
#include"../binaryFiles/binary.h"
#include"../binaryFiles/audioUrlFiles.h"

//==============================================================================

class SamplerGui  : public juce::Component
                                
{
public:
    SamplerGui(AudioProcessorValueTreeState& vts);
    ~SamplerGui() override; 
    
    ParasSamplerControll *mpc;
    AudioSample sampelout;
    binaryFiles bin;
    PluginWaves urls;
    modulator mod1;

    void setEngine(const int e) { engineNb = e; Spcolor(e); mpc->setEngineNumber(e); }
    void Spcolor(int c) { Kcolor = c; repaint(); }
    void mouseUp(const juce::MouseEvent& event) override;
    void mouseDown(const juce::MouseEvent& event) override;
    void mouseDrag(const MouseEvent& e)override;
    bool mouseOn() { return mDown; }
    void resized() override;
    void paint (juce::Graphics&) override;
    void drawButts(juce::Graphics& g);
    void drawSliders(juce::Graphics& g);
    void setfile(String s)
    {
        mpc->AudioFile=s;
        repaint(0, 0, 600, 30);
   }
    int test;
    void initGui();

    Value SPStateParas;
    float *UstateParas;

    Value SPAdsrParas;
    float* busEnvelopes;

    void updateMixer(ParasSamplerControll& mpm,int n,int sp);

    void serialParas(AudioProcessorValueTreeState& valueTreeState, String n);
    void unSerialParas(AudioProcessorValueTreeState& valueTreeState,String n);

    const int GetTimes() { return mTimes; }
    const float* GetParas();
    float* GetAdsrParas() { return busEnvelopes;  }
    bool getOscVisible();

    std::function<void()> onValueChanged;
    void valueChanged(float) ;
  
    const int GetParaNr() { return ParameterNr; }
    bool GetMouseDown() { return mDown; }

   

    void loadSample(File f)
    {
    
      bin.loadWaveFile(urls.getUrlNb(engineNb)[mpc->getWaveNr()].toString().toRawUTF8(), 1);

      mpc->setWaveSize(bin.getSampleLength());
      sampelout.setWaveSize(bin.getSampleLength());
      sampelout.loadfile(bin.getSampleLength(), bin.getSample());
      sampelout.parasIn(*mpc);
          }

 void ModulatorParasUpdate()
    {

       // for (int i = 0; i < 16; i++)
      //  mpc->Modsteps[i] = mod1.stepValuesOut()[i];
        mpc->setInputSteps(mod1.stepValuesOut());
        for (int i = 0; i < 16; i++)
      mpc->ModstepsAmp[i] = mod1.stepAmpValuesOut()[i];
        mpc->setInputstepAmps(mod1.stepAmpValuesOut());

        mod1.mFormbut;
        for (int i = 0; i < 16; i++)
        mpc->Modsteps[i] = mod1.stepValuesOut()[i];
    }

 void UrlUpdateFiles()
 {
     for (int i = 0; i < 7; i++)
     urls.getUrlNb(i);

 }
private:

    std::atomic<float> lastValue{ 0.0f };
   
    int ParameterNr;
    bool mDown;
    int engineNb;
    int kenvSLiderNr;
    int Ktimes;
    int Kcolor;
    float mMemoryValue;
    float* modulatorStepParas;
    float* modulatorparas;
    float mTimes;
    AudioProcessorValueTreeState& valueTreeStateGui;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SamplerGui)
};
