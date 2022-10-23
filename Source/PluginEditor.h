
#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include"customLook.h"
#include"../synth/showOscilator.h"
#include"../AudioSampel/showWave.h"


//==============================================================================

class NewProjectAudioProcessorEditor  : public AudioProcessorEditor
                                        ,private FilenameComponentListener
                                        ,private Timer
                                       

{
public:
    NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p);
    ~NewProjectAudioProcessorEditor() { }
 
    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void waveguiChanged(const double* p, int l)
    {
        guiWav.setIn(p, l);
    }
    void filenameComponentChanged(FilenameComponent* fileComponentThatHasChanged) override;
   
    void updateVst();
    void updateMidiCCParas() {}
    Label readoutLabel;
    Label readoutLabel2;
    Label readoutLabel3;


private:
    showOscilator guiOsc;
    showWave guiWav;
    NewProjectAudioProcessor& audioProcessor;
    std::unique_ptr<juce::FilenameComponent> fileComp;
   
    void addLookAndFeel(juce::LookAndFeel* laf, const juce::String& name) { }

    int Test;
    float Testf;
    float stpvl1[16];
    char setUs[200] = { "" };
    char setUsm[200] = { "" };
    void timerCallback() override;
    static String getSystemNameInfo()
    {
        String systemInfo;

        systemInfo
            << File::getSpecialLocation(File::commonDocumentsDirectory).getFullPathName();

        //   DBG (systemInfo);
        return systemInfo;
    }
   
    void initialise (const String& commandLine)
    {
        auto splash = new SplashScreen ("Welcome to my app!",
                                   ImageFileFormat::loadFrom (File ("/foobar/splash.jpg")),
                                   true);
        
        // now kick off your initialisation work on some kind of thread or task, and
       // launchBackgroundInitialisationThread();
        splash->setEnabled(false);
    }
     
                  // The number of rows of data we've got
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NewProjectAudioProcessorEditor)
};
