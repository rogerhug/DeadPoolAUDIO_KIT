/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor(NewProjectAudioProcessor& p)
    : AudioProcessorEditor(&p)
    , audioProcessor(p)

{
    Test = 0;
    Testf = 0;




    addAndMakeVisible(readoutLabel);
    readoutLabel.setBounds(300, 630, 400, 40);
    addAndMakeVisible(readoutLabel2);
    readoutLabel2.setBounds(300, 600, 400, 40);

    auto* hyperlink1 = (new HyperlinkButton("www.hebeisen.soft/DeadPoolAudio_kit",
        { "https://github.com/rogerhug" }));

    addAndMakeVisible(hyperlink1);
    hyperlink1->setBounds(20, 620, 250, 22);

    addAndMakeVisible(guiOsc);
    addAndMakeVisible(guiWav);

    //************************Main******************************************


    addAndMakeVisible(audioProcessor.mainG);
    audioProcessor.mainG.serialParas(audioProcessor.valueTreeState, "Mainparas");
    audioProcessor.mainG.mpcM->setEngineNr(0);
    guiOsc.setVisible(audioProcessor.spg1.mpc->getOscilatorHide());
    guiWav.setVisible(audioProcessor.spg1.mpc->getWaveFileHide());
    audioProcessor.mainG.onValueChanged = [this] {

        switch (audioProcessor.mainG.GetParaNr()) {

        case 0: break;
        case 1:
        audioProcessor.spg1.setVisible(audioProcessor.mainG.mpcM->getEngineHide()[0]);
        audioProcessor.spg2.setVisible(audioProcessor.mainG.mpcM->getEngineHide()[1]);
        
              if (audioProcessor.mainG.mpcM->getEngineHide()[0] == true) {
                guiOsc.setVisible(audioProcessor.spg1.mpc->getOscilatorHide());
                guiOsc.formIn(audioProcessor.spg1.sampelout.oscillator.getForm(audioProcessor.spg1.mpc->mSynthWaveForm));
                guiWav.setVisible(audioProcessor.spg1.mpc->getWaveFileHide());
                guiWav.setIn(audioProcessor.spg1.bin.getSample(), audioProcessor.spg1.bin.getSampleLength() );


            }
              else
            if (audioProcessor.mainG.mpcM->getEngineHide()[1] == true) {

                guiOsc.setVisible(audioProcessor.spg2.mpc->getOscilatorHide());
               guiOsc.formIn(audioProcessor.spg2.sampelout.oscillator.getForm(audioProcessor.spg2.mpc->mSynthWaveForm));
                guiWav.setVisible(audioProcessor.spg2.mpc->getWaveFileHide());
              guiWav.setIn(audioProcessor.spg2.bin.getSample(), audioProcessor.spg2.bin.getSampleLength() );

            }

                
            break;
        case 2:
            audioProcessor.Ptime.setTimeSource(audioProcessor.mainG.mpcM->mTimeIn);
            audioProcessor.Ptime.setTimes(audioProcessor.mainG.mpcM->getTimeDivAll());
            break;
        case 3:
          audioProcessor.Ptime.setTimes(audioProcessor.mainG.mpcM->getTimeDivAll());
            break;
        case 4:
            audioProcessor.Ptime.setStepChange(audioProcessor.mainG.mpcM->mSeqenceNr);
            audioProcessor.trg.setAB(int(audioProcessor.mainG.mpcM->mSeqenceNr));
            audioProcessor.Ptime.trigger1In(audioProcessor.trg.getTrigger1(), audioProcessor.mainG.mpcM->mSeqenceNr);
            audioProcessor.Ptime.trigger2In(audioProcessor.trg.getTrigger2(), audioProcessor.mainG.mpcM->mSeqenceNr);
            break;
        case 5:
            audioProcessor.mainG.mpcM->mStartStop;
            break;
        case 6:
            audioProcessor.Ptime.setBpm(int(audioProcessor.mainG.mpcM->mTimeBpm * 200));
            break;
        case 7:
            audioProcessor.Ptime.setSequenceLenght(audioProcessor.mainG.mpcM->mSequenceLenght);
            break;
        case 8:
            audioProcessor.setMasterGain(audioProcessor.mainG.mpcM->mMasterGain);
            break;
        case 9:
            audioProcessor.mainG.mpcM->mMasterPitch;
            audioProcessor.spg1.mpc->setPitchAll(audioProcessor.mainG.mpcM->mMasterPitch, 0);
            audioProcessor.spg1.sampelout.parasIn(*audioProcessor.spg1.mpc);
            audioProcessor.spg2.mpc->setPitchAll(audioProcessor.mainG.mpcM->mMasterPitch, 1);
            audioProcessor.spg2.sampelout.parasIn(*audioProcessor.spg2.mpc);
            break;
        default:
            break;
        }
        audioProcessor.mainG.serialParas(audioProcessor.valueTreeState, "Mainparas");
    };
    
    addAndMakeVisible(audioProcessor.trg);


    //*******************************************************************************
    //--------------------------------SeQuencer -------------------------------------
    //******************************************************************************

    audioProcessor.trg.serialParas(audioProcessor.valueTreeState, "sp");

    audioProcessor.trg.onValueChanged = [this] {

        switch (audioProcessor.trg.GetparamNr()) {

        case 0:
            break;
        case 1:
              audioProcessor.Ptime.trigger1In(audioProcessor.trg.getTrigger1(), (audioProcessor.mainG.mpcM->mSeqenceNr));
              break;
        case 2:
            audioProcessor.Ptime.trigger2In(audioProcessor.trg.getTrigger2(), (audioProcessor.mainG.mpcM->mSeqenceNr));
            break;
        
        default:
            break;


        }
        audioProcessor.trg.serialParas(audioProcessor.valueTreeState, "sp");
    };



    //************************************************************* *************** 
   //-------------------Sampler1 Paras ------------------------------------
   //*****************************************************************   *********************
    

   
    addAndMakeVisible(audioProcessor.spg1);
    audioProcessor.spg1.setEngine(0);
      audioProcessor.spg1.mpc->setEngineNumber(0);
    //init---Refresh-gui----
    audioProcessor.spg1.initGui();

    audioProcessor.spg1.onValueChanged = [this] {
 
        if (audioProcessor.spg1.GetParaNr() == 1) {
            guiOsc.setVisible(audioProcessor.spg1.mpc->getOscilatorHide());
            guiWav.setVisible(audioProcessor.spg1.mpc->getWaveFileHide());
         
        }
        if (audioProcessor.spg1.GetParaNr() == 3)
           guiWav.setIn(audioProcessor.spg1.bin.getSample(), audioProcessor.spg1.bin.getSampleLength());
        if (audioProcessor.spg1.GetParaNr() == 6)
            audioProcessor.Ptime.setGate(audioProcessor.spg1.mpc->mGate, 0, audioProcessor.spg1.mpc->mSamplePlayMode);
        if (audioProcessor.spg1.GetParaNr() == 19)
            guiOsc.formIn(audioProcessor.spg1.sampelout.oscillator.getForm(audioProcessor.spg1.mpc->mSynthWaveForm));
        if (audioProcessor.spg1.GetParaNr() == 25)
            audioProcessor.Ptime.setDivides(audioProcessor.spg1.GetTimes(), 0);

        audioProcessor.spg1.GetParas();

        audioProcessor.spg1.serialParas(audioProcessor.valueTreeState, "sp1Paras");

    };

    //-------------------------------------sp1 modulator---------


    audioProcessor.spg1.mod1.onValueChanged = [this] {
        audioProcessor.spg1.ModulatorParasUpdate();

        if (audioProcessor.spg1.mod1.GetParaNbr() == 3)
            audioProcessor.Ptime.setModulatorDiv(audioProcessor.spg1.mod1.mTimebut, 0);

    };

    //***************************************sp2paras***********************************
    //*********************************************************************************

    addAndMakeVisible(audioProcessor.spg2);
    audioProcessor.spg2.setEngine(1);
    audioProcessor.spg2.mpc->setEngineNumber(1);
    audioProcessor.spg2.setVisible(false);
    //init---Refresh-gui----
    audioProcessor.spg2.initGui();
   
    audioProcessor.spg2.onValueChanged = [this] {
   
        if (audioProcessor.spg2.GetParaNr() == 1 ) {
            guiOsc.setVisible(audioProcessor.spg2.mpc->getOscilatorHide());
            guiWav.setVisible(audioProcessor.spg2.mpc->getWaveFileHide());
           
        }
       if (audioProcessor.spg2.GetParaNr() == 3) 
           guiWav.setIn(audioProcessor.spg2.bin.getSample(), audioProcessor.spg2.bin.getSampleLength());

        if (audioProcessor.spg2.GetParaNr() == 6)
          audioProcessor.Ptime.setGate(audioProcessor.spg2.mpc->mGate, 1, audioProcessor.spg2.mpc->mSamplePlayMode);
          if (audioProcessor.spg2.GetParaNr() == 19)
          guiOsc.formIn(audioProcessor.spg2.sampelout.oscillator.getForm(audioProcessor.spg2.mpc->mSynthWaveForm));
          if (audioProcessor.spg2.GetParaNr() == 25)
            audioProcessor.Ptime.setDivides(audioProcessor.spg2.GetTimes(), 1);

        audioProcessor.spg2.GetParas();

        audioProcessor.spg2.serialParas(audioProcessor.valueTreeState, "sp2Paras");

    };

    //-------------------------------------sp1 modulator---------


    audioProcessor.spg2.mod1.onValueChanged = [this] {
        audioProcessor.spg2.ModulatorParasUpdate();

        if (audioProcessor.spg2.mod1.GetParaNbr() == 3)
            audioProcessor.Ptime.setModulatorDiv(audioProcessor.spg2.mod1.mTimebut, 1);

    };

    //************************************************************* *************** 
   //-------------------
   //************************
    auto* mlaf = new CustomLookAndFeel();
    addLookAndFeel(mlaf, "Custom Look And Feel");
    mlaf->setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::red);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    fileComp.reset(new juce::FilenameComponent("fileComp",
        {},                       // current file
        false,                    // can edit file name,
        false,                    // is directory,
        false,                    // is for saving,
        {},                       // browser wildcard suffix,
        {},                       // enforced suffix,
        "Select file to open"));  // text when nothing selected
    addAndMakeVisible(fileComp.get());
    fileComp->addListener(this);
    // fileComp.get()->setLookAndFeel(mlaf);
    fileComp.get()->setBrowseButtonText("Load or DROP .wav");
    fileComp.get()->setExplicitFocusOrder(1);


    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.





    addAndMakeVisible(readoutLabel3);
    readoutLabel3.setBounds(120, 210, 450, 20);
    readoutLabel3.setFont(juce::Font("Consolas", 17.0f, juce::Font::bold));
        
    timerCallback();
    startTimer(1);
    startTimerHz(30);


 
    addAndMakeVisible(audioProcessor.BrowserVstPreset);
    audioProcessor.BrowserVstPreset.Vst3SetSave->addListener(this);
   
  
    setSize (800, 670);
}


//==============================================================================
void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{

    g.setFont(juce::Font("Consolas", 14.0f, juce::Font::bold));
    g.fillAll(juce::Colours::black);

}

void NewProjectAudioProcessorEditor::resized()
{  

    audioProcessor.mainG.setBounds(getLocalBounds());
    fileComp.get()->setBounds(580,50,180,40);

  
    audioProcessor.BrowserVstPreset.setBounds(10, 5, 250, 175);

    audioProcessor.trg.setBounds(50, 240, 730, 92);

    guiOsc.setBounds(590, 95, 180, 110);
    guiWav.setBounds(590, 95, 180, 110);
    audioProcessor.spg1.setBounds(50, 370, 710, 190);


    audioProcessor.spg2.setBounds(50, 370, 710, 190);


}
Value filesW;
void NewProjectAudioProcessorEditor::filenameComponentChanged(FilenameComponent* fileComponentThatHasChanged)
{ 
    
    
    //******************************Presets******************************
    //********************************************************************


    auto* fP = audioProcessor.BrowserVstPreset.Vst3SetSave.get();

    juce::ValueTree OutValueTreeP{ "DeadPoolAudio_V3" };
    if (fileComponentThatHasChanged == fP)
    {
        //-------------------Paras->toxml-----------------------------------
        //-----------------------Main-------

        OutValueTreeP.setProperty("MainParas", audioProcessor.mainG.MainStateParas, nullptr);

        //-----------------------sp1-------
        OutValueTreeP.setProperty("sp1Paras", audioProcessor.spg1.SPStateParas, nullptr);
        OutValueTreeP.setProperty("sp1ParasAdsr", audioProcessor.spg1.SPAdsrParas, nullptr);
        OutValueTreeP.setProperty("sptr1", audioProcessor.trg.GetTrigAllV()[0], nullptr);
        OutValueTreeP.setProperty("sp1mod", audioProcessor.spg1.mod1.SteppValuesSerial, nullptr);
        for(int i=0;i<63;i++)
        OutValueTreeP.setProperty(audioProcessor.spg1.urls.Sp1SetNames()[i], audioProcessor.spg1.urls.getUrl1V()[i], nullptr);

        //-----------------------sp2-------
        OutValueTreeP.setProperty("sp2Paras", audioProcessor.spg2.SPStateParas, nullptr);
        OutValueTreeP.setProperty("sp2ParasAdsr", audioProcessor.spg2.SPAdsrParas, nullptr);
        OutValueTreeP.setProperty("sptr2", audioProcessor.trg.GetTrigAllV()[1], nullptr);
        OutValueTreeP.setProperty("sp2mod", audioProcessor.spg2.mod1.SteppValuesSerial, nullptr);
        for (int i = 0; i < 63; i++)
            OutValueTreeP.setProperty(audioProcessor.spg2.urls.Sp2SetNames()[i], audioProcessor.spg2.urls.getUrl2V()[i], nullptr);



        File fileP(fP->getLocationToBrowse());

        if (auto xml = OutValueTreeP.createXml()) {

            xml->writeTo(fileP);


        }

        juce::FileOutputStream outstream(fileP);
        OutValueTreeP.getProperty("DeadPoolAudio_kit").writeToStream(outstream);


    }



  
//================================================================================================
//==================================sampels=======================================================

    
    const int engine = audioProcessor.mainG.mpcM->mEngineNb;

         auto*f= fileComp.get();
         char dbt[512] = { "" };
         if(fileComponentThatHasChanged == f)
        {
        // strcpy(dbt,f->getRecentlyUsedFilenames()[0].getCharPointer());;
        //-------------------Sampels--------------------------------
 
         
        if(engine ==0){
            const int nr = audioProcessor.spg1.mpc->mWaveNumbr*63;
           audioProcessor.spg1.urls.serial1(audioProcessor.valueTreeState, f->getLocationToBrowse(), nr,0);
           audioProcessor.spg1.bin.loadWaveFile(f->getLocationToBrowse().getFullPathName().toRawUTF8(), 1);
           audioProcessor.spg1.sampelout.loadfile(audioProcessor.spg1.bin.getSampleLength(), audioProcessor.spg1.bin.getSample());
           audioProcessor.spg1.setfile(f->getLocationToBrowse().getFullPathName());
           guiWav.setIn(audioProcessor.spg1.bin.getSample(), audioProcessor.spg1.bin.getSampleLength());
        }
        if (engine == 1) {
            const int nr2 = audioProcessor.spg2.mpc->mWaveNumbr*63;
            audioProcessor.spg2.urls.serial1(audioProcessor.valueTreeState, f->getLocationToBrowse().getFullPathName(), nr2, 1);
            audioProcessor.spg2.bin.loadWaveFile(f->getLocationToBrowse().getFullPathName().toRawUTF8(), 1);
            audioProcessor.spg2.sampelout.loadfile(audioProcessor.spg2.bin.getSampleLength(), audioProcessor.spg2.bin.getSample());
            audioProcessor.spg2.setfile(f->getLocationToBrowse().getFullPathName());
            guiWav.setIn(audioProcessor.spg2.bin.getSample(), audioProcessor.spg2.bin.getSampleLength());
        }

    
    
       }
       
}



char dbtx[70] = { "-" };
char dbtx2[70] = { "-" };
char dbt[70] = { "-" };
 int nb = 0;
 void NewProjectAudioProcessorEditor::timerCallback() {
     /*

     for (int i = 0; i < 32; i++) {
         //   nb++;
        //    sprintf(&setUs[nb - 1], "%i", audioProcessor.sp1.mp.getSeqTrigger()[i]);
     }



     if (audioProcessor.midiCCupdate > 0) { updateMidiCCParas(); }
     //for (int k = 0; k < 32; k++)
      // sprintf(dbt,"%s" ,audioProcessor.mainG.trg.triggersoutC());
     for (int i = 0; i < 64; i++) {
         nb++;


         // sprintf(&dbtx2[i], "%.0f", menusXml.getXmlIn()[i]);
         sprintf(&dbtx[i], "%.0f", audioProcessor.mainG.trg.getTrigger4()[i]);



         //  sprintf(&dbtx2[i], "%.0f", audioProcessor.Ptime.getTrigger1()[i]);


     }
  */
     
    
     sprintf(dbt, "|countSp: %.2i|BlockSize:: %i| SampelRate::%.2f | tesvalue::%f",
         audioProcessor.Ptime.getHtimeAll(0)[0]
           , audioProcessor.getBlockSize()
         , audioProcessor.getSampleRate()
        , audioProcessor.mainG.mpcM->mMasterPitch

     );

    // readoutLabel.setText(fileComp.get()->getComponentID().toRawUTF8(), juce::dontSendNotification);
    //  readoutLabel2.setText(audioProcessor.mainG.trg.triggersoutC(), juce::dontSendNotification);
     readoutLabel3.setText(dbt, juce::dontSendNotification);
   

     //---------------------------------triggerstepper---------------------------------------------
     if (int(audioProcessor.mainG.mpcM->mSeqenceNr) == 2) {
         if (audioProcessor.Ptime.changeStepGui() == true)
         {
             audioProcessor.trg.setAB(audioProcessor.Ptime.GetStepSequence());
         }
     }
    
     if (audioProcessor.BrowserVstPreset.updateVst3Sets == true)
     {

         updateVst();
     }

 }

void NewProjectAudioProcessorEditor::updateVst()
{
   // guiWav.setIn(audioProcessor.spg1.mpc->getInitWave(),44100);

    audioProcessor.valueTreeState.replaceState(audioProcessor.BrowserVstPreset.valueTreeStateP.state);
    //-------------------main--------------------------------------------------------------
    
    audioProcessor.mainG.unSerialParas(audioProcessor.BrowserVstPreset.valueTreeStateP, "MainParas");
    //---------------------time------------------------------
    audioProcessor.Ptime.setStepChange(audioProcessor.mainG.mpcM->mSeqenceNr);
    audioProcessor.Ptime.setTimeSource(int(audioProcessor.mainG.mpcM->mTimeIn));
    audioProcessor.Ptime.setTimes(audioProcessor.mainG.mpcM->getTimeDivAll());
    audioProcessor.Ptime.setBpm(audioProcessor.mainG.mpcM->getTimerBpm());
    //--------------------triggers-----------------------------------------
    audioProcessor.trg.unSerialParas(audioProcessor.valueTreeState);//-----seq

   //----------------------sp1---------------------------------------------------------------
    audioProcessor.spg1.unSerialParas(audioProcessor.BrowserVstPreset.valueTreeStateP,"sp1Paras");     //-----guiSp
    audioProcessor.Ptime.setGate(audioProcessor.spg1.mpc->mGate, 0, audioProcessor.spg1.mpc->mSamplePlayMode);
    audioProcessor.Ptime.trigger1In(audioProcessor.trg.getTrigger1(), int(audioProcessor.mainG.mpcM->mSeqenceNr));
    audioProcessor.spg1.mod1.unSerialStepps(audioProcessor.valueTreeState,"sp1mod");//----modSp
    audioProcessor.spg1.mpc->setInputSteps(audioProcessor.spg1.mod1.stepValuesOut());
    audioProcessor.spg1.mpc->setInputstepAmps(audioProcessor.spg1.mod1.stepAmpValuesOut());
   // audioProcessor.Ptime.setModulatorDiv(audioProcessor.spg1.mod1.mTimebut, 0);
    audioProcessor.spg1.sampelout.parasIn(*audioProcessor.spg1.mpc);
   
    //----------------------sp2---------------------------------------------------------------
    audioProcessor.spg2.unSerialParas(audioProcessor.BrowserVstPreset.valueTreeStateP, "sp2Paras");     //-----guiSp
    audioProcessor.Ptime.setGate(audioProcessor.spg2.mpc->mGate, 1, audioProcessor.spg2.mpc->mSamplePlayMode);
    audioProcessor.Ptime.trigger2In(audioProcessor.trg.getTrigger2(), int(audioProcessor.mainG.mpcM->mSeqenceNr));
    audioProcessor.spg2.mod1.unSerialStepps(audioProcessor.valueTreeState, "sp2mod");//----modSp
    audioProcessor.spg2.mpc->setInputSteps(audioProcessor.spg2.mod1.stepValuesOut());
    audioProcessor.spg2.mpc->setInputstepAmps(audioProcessor.spg2.mod1.stepAmpValuesOut());
  //  audioProcessor.Ptime.setModulatorDiv(audioProcessor.spg2.mod1.mTimebut, 1);
    audioProcessor.spg2.sampelout.parasIn(*audioProcessor.spg2.mpc);

 
    //-------------------------guiwave-------------------------------------
    if(int(audioProcessor.mainG.mpcM->mEngineNb)==0 && int(audioProcessor.spg1.mpc->mEngineMode)==1)
    guiWav.setIn(audioProcessor.spg1.bin.getSample(), audioProcessor.spg1.bin.getSampleLength()/2);
    if (int(audioProcessor.mainG.mpcM->mEngineNb) == 1 && int(audioProcessor.spg2.mpc->mEngineMode==1) == 1)
    guiWav.setIn(audioProcessor.spg2.bin.getSample(), audioProcessor.spg2.bin.getSampleLength()/2);
    
    audioProcessor.BrowserVstPreset.updateVst3Sets = false;
}








