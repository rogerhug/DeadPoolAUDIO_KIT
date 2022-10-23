/*
  ==============================================================================

    filebrowser.cpp
    Created: 28 Jul 2022 1:53:07pm
    Author:  roger hug

  ==============================================================================
*/

#include <JuceHeader.h>
#include "filebrowser.h"




//==============================================================================
filebrowserTriggers::filebrowserTriggers()

{
    auto* mlaf = new CustomLookAndFeel();
    addLookAndFeel(mlaf, "Custom Look And Feel");
    mlaf->setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::mediumseagreen);
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    setOpaque(true);

 
        File f = { getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Triggers" };//  just route to order/C://users..
        triggerList.setDirectory(f, true, true);

        directoryThread.startThread(1);

        fileTreeTriggers.setTitle("Files");
        fileTreeTriggers.addListener(this);
        fileTreeTriggers.setColour(TreeView::backgroundColourId, Colours::black);
        addAndMakeVisible(fileTreeTriggers);

        updateTriggers = false;

        TriggersXmlIn = new float* [66];
        for (int i = 0; i < 10; i++) {
            TriggersXmlIn[i] = new float[66];
            for (int k = 0; k < 66; k++)
                TriggersXmlIn[i][k] = 0.0;

        }


        TriggerSave.reset(new juce::FilenameComponent("fileComp",
            {},                            // current file
            true,                        // can edit file name,
            false,                        // is directory,
            true,                          // is for saving,
            { "trg" },                       // browser wildcard suffix,
            { "trg" },                       // enforced suffix,
            "-"));  // text when nothing selected
        addAndMakeVisible(TriggerSave.get());
        TriggerSave.get()->setBrowseButtonText("Save");
        TriggerSave.get()->setDefaultBrowseTarget(f);
        TriggerSave.get()->setVisible(true);
      //  TriggerSave.get()->setLookAndFeel(mlaf);
       

 
    
    /*

    textContent.reset(new juce::TextEditor());
    addAndMakeVisible(textContent.get());
    textContent->setMultiLine(true);
    textContent->setReadOnly(true);
    textContent->setCaretVisible(true);
    textContent->getLineSpacing();
    */
}

filebrowserTriggers::~filebrowserTriggers()
{
    fileTreeTriggers.removeListener(this);
   

}

void filebrowserTriggers::paint (juce::Graphics& g)
{

    juce::Rectangle<float> area(0, 0, getWidth(), getHeight());
    g.setColour(juce::Colours::blue);
    g.drawRect(area,  50);
    g.setColour(juce::Colours::white);
   
    g.setFont(juce::Font("Aharoni", 20.0f, juce::Font::bold));
    g.drawText("TRIGGERS", 20, getHeight() - 20, getWidth() - 40, 20, juce::dontSendNotification);
}

void filebrowserTriggers::resized()
{
   
        TriggerSave.get()->setBounds(120,getHeight() - 25, 50, 20);
        fileTreeTriggers.setBounds(0, 0,  getWidth()-20,getHeight()-35);

    
    
  //  textContent->setBounds(200, 0, 200, 150);
}

void filebrowserTriggers::parsetriggers()
{
    auto selectedFile = fileTreeTriggers.getSelectedFile();
    selectedFile.getFileName();


    juce::ValueTree InValueTree{ "triggersIn" };
    juce::File InFile(selectedFile);
   // readFile(selectedFile);
  
    juce::FileInputStream in(InFile);
   
    // reading
    if (auto xml = juce::XmlDocument::parse(InFile))
        InValueTree = juce::ValueTree::fromXml(*xml);

 

   trin1.referTo(InValueTree.getPropertyAsValue("trig1", nullptr, true));
   trin2.referTo(InValueTree.getPropertyAsValue("trig2", nullptr, true));
   trin3.referTo(InValueTree.getPropertyAsValue("trig3", nullptr, true));
   trin4.referTo(InValueTree.getPropertyAsValue("trig4", nullptr, true));
   trin5.referTo(InValueTree.getPropertyAsValue("trig5", nullptr, true));
   trin6.referTo(InValueTree.getPropertyAsValue("trig6", nullptr, true));
   trin7.referTo(InValueTree.getPropertyAsValue("trig7", nullptr, true));
   for (int i = 0; i <= 64 ; i += 1) {
       TriggersXmlIn[0][i] = trin1.getValue().toString().substring(i, i + 1).getFloatValue();
       TriggersXmlIn[1][i] = trin2.getValue().toString().substring(i, i + 1).getFloatValue();
       TriggersXmlIn[2][i] = trin3.getValue().toString().substring(i, i + 1).getFloatValue();
       TriggersXmlIn[3][i] = trin4.getValue().toString().substring(i, i + 1).getFloatValue();
       TriggersXmlIn[4][i] = trin5.getValue().toString().substring(i, i + 1).getFloatValue();
       TriggersXmlIn[5][i] = trin6.getValue().toString().substring(i, i + 1).getFloatValue();
       TriggersXmlIn[6][i] = trin7.getValue().toString().substring(i, i + 1).getFloatValue();
   }

  
      
   getXmlIn();
  

}


 float** filebrowserTriggers::getXmlIn()
{
    return TriggersXmlIn;
   
}

 Value* filebrowserTriggers::getXmTriggersets()
 {
     return nullptr;
 }

/*
void filebrowser7::filenameComponentChanged(FilenameComponent* fileComponentThatHasChanged)
{

}
*/

 filebrowserWaveSets::filebrowserWaveSets()
     //:thumbnailCache(5)
     //,curve(512, formatManager, thumbnailCache)
    
 {
     updateWaveSets = false;
     auto* mlaf = new CustomLookAndFeel();
     addLookAndFeel(mlaf, "Custom Look And Feel");
     mlaf->setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::mediumseagreen);
     // In your constructor, you should add any child components, and
     // initialise any special settings that your component needs.
     setOpaque(true);


    
     File fw = { getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_WaveSets" };//  just route to order/C://users..
     WaveSetList.setDirectory(fw, true, true);

     directoryThread.startThread(1);

     fileTreeWaves.setTitle("Files");
     fileTreeWaves.addListener(this);
     fileTreeWaves.setColour(TreeView::backgroundColourId, Colours::black);
     addAndMakeVisible(fileTreeWaves);





     WaveSetSave.reset(new juce::FilenameComponent("fileComp",
         {},                            // current file
         false,                        // can edit file name,
         false,                        // is directory,
         true,                          // is for saving,
         { "ww" },                       // browser wildcard suffix,
         { "ww" },                       // enforced suffix,
         "-"));  // text when nothing selected
     addAndMakeVisible(WaveSetSave.get());
     WaveSetSave.get()->setBrowseButtonText("Save");
     WaveSetSave.get()->setDefaultBrowseTarget(fw);
     WaveSetSave.get()->setVisible(true);
    // WaveSetSave.get()->setLookAndFeel(mlaf);

   //  addAndMakeVisible(curve);


     /*
     textContent.reset(new juce::TextEditor());
     addAndMakeVisible(textContent.get());
     textContent->setMultiLine(true);
     textContent->setReadOnly(true);
     textContent->setCaretVisible(true);
     textContent->getLineSpacing();
     textContent->setLookAndFeel(mlaf);

     juce::String infoText;
     infoText << "This simple application takes some text input from the user, ";
     infoText << "converts it to uppercase, and displays this in another label. ";
     infoText << "The application demonstrates a number of useful features of the Label class.";
     textContent->setText(infoText, juce::dontSendNotification);
     textContent->setColour(juce::Label::backgroundColourId, juce::Colours::darkblue);
 */

     
 }

 filebrowserWaveSets::~filebrowserWaveSets()
 {
    
     fileTreeWaves.removeListener(this);

 }

 void filebrowserWaveSets::fileIn(File f, const int nUmber)
 {
  
    
     
 }

inline bool hideB(float m)
 {
    
     if(m>0)
     return true; 
     else
     return false;
 }

 void filebrowserWaveSets::hideMode(float m)
 {
   
     if (m > 0) {
         WaveSetSave.get()->setVisible(true);
        // textContent->setVisible(true);
         fileTreeWaves.setVisible(true);
    
     }
     if (m < 1) {
         WaveSetSave.get()->setVisible(false);
       //  textContent->setVisible(false);
     
         fileTreeWaves.setVisible(false);
     }
     
 }

 void filebrowserWaveSets::paint(juce::Graphics& g)
 { 
     
 
     juce::Rectangle<float> area(0, 0, getWidth(), getHeight());
     g.setColour(juce::Colours::red);
     g.drawRect(area, 50);
     g.setColour(juce::Colours::white);
      g.setFont(juce::Font("Aharoni", 20.0f, juce::Font::bold));
     g.drawText("WAVESETS", 30, getHeight() - 20, getWidth() - 60, 20, juce::dontSendNotification);

 }

 void filebrowserWaveSets::resized()
 {



     WaveSetSave.get()->setBounds(140, getHeight() - 25, 50, 20);
     fileTreeWaves.setBounds(10, 0, getWidth() - 20, getHeight() - 35);
   //  curve.setBounds(200, 0, 200, 150);

     //  textContent->setBounds(220, 0, 200, 150);
 }



 void filebrowserWaveSets::SaveWaveSets()
 {

     auto selectedFile = fileTreeWaves.getSelectedFile();
     selectedFile.getFileName();


     juce::ValueTree InValueTree{ "WaveSets" };
     juce::File InFile(selectedFile);
     // readFile(selectedFile);

     juce::FileInputStream in(InFile);


     // reading
     if (auto xml = juce::XmlDocument::parse(InFile))
         InValueTree = juce::ValueTree::fromXml(*xml);
  
    // curve.setFile(InFile);
   
       
         outStr[0].referTo(InValueTree.getPropertyAsValue("Wave1", nullptr, true));
         outStr[1].referTo(InValueTree.getPropertyAsValue("Wave2", nullptr, true));
         outStr[2].referTo(InValueTree.getPropertyAsValue("Wave3", nullptr, true));
         outStr[3].referTo(InValueTree.getPropertyAsValue("Wave4", nullptr, true));
         outStr[4].referTo(InValueTree.getPropertyAsValue("Wave5", nullptr, true));
         outStr[5].referTo(InValueTree.getPropertyAsValue("Wave6", nullptr, true));
         outStr[6].referTo(InValueTree.getPropertyAsValue("Wave7", nullptr, true));

  

         getXmlWavesets();
   
 }


 void filebrowserWaveSets::serialWaveSets(AudioProcessorValueTreeState& valueTreeState, File fileAudio, const int nUmb)
 {
     switch (nUmb) {
     case 0:
         valueTreeState.state.setProperty("Wave1", var(fileAudio.getFullPathName().toRawUTF8()), nullptr);
         break;
     case 1:
         valueTreeState.state.setProperty("Wave2", var(fileAudio.getFullPathName().toRawUTF8()), nullptr);
         break;
     case 3:
         valueTreeState.state.setProperty("Wave3", var(fileAudio.getFullPathName().toRawUTF8()), nullptr);
         break;
     case 4:
         valueTreeState.state.setProperty("Wave4", var(fileAudio.getFullPathName().toRawUTF8()), nullptr);
         break;
     case 5:
         valueTreeState.state.setProperty("Wave5", var(fileAudio.getFullPathName().toRawUTF8()), nullptr);
         break;
     case 6:
         valueTreeState.state.setProperty("Wave6", var(fileAudio.getFullPathName().toRawUTF8()), nullptr);
         break;
     case 7:
         valueTreeState.state.setProperty("Wave7", var(fileAudio.getFullPathName().toRawUTF8()), nullptr);
         break;

     }

 }

 void filebrowserWaveSets::setFileIn(Value t, int n)
 {
     outStr[n].setValue(t);
     getXmlWavesets();
  
 }

 Value* filebrowserWaveSets::getXmlWavesets()
 {

     return  outStr;
 }
 /*
 void filebrowser7::filenameComponentChanged(FilenameComponent* fileComponentThatHasChanged)
 {

 }
 */

 filebrowserVst3Sets::filebrowserVst3Sets(AudioProcessorValueTreeState& vts)
     :valueTreeStateP(vts)
 {
     updateVst3Sets = false;
     auto* mlaf = new CustomLookAndFeel();
     addLookAndFeel(mlaf, "Custom Look And Feel");
     mlaf->setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::mediumseagreen);
     // In your constructor, you should add any child components, and
     // initialise any special settings that your component needs.
     setOpaque(true);



     File fw =  { getSystemNameInfo() + "/DeadPoolAudio_V3/DpA_Presets" } ;//  just route to order/C://users..
     Vst3SetList.setDirectory(fw, true, true);

     directoryThread.startThread(1);

     fileTreeVst3.setTitle("Files");
     fileTreeVst3.addListener(this);
     fileTreeVst3.setColour(TreeView::backgroundColourId, Colours::black);
     addAndMakeVisible(fileTreeVst3);
    




     Vst3SetSave.reset(new juce::FilenameComponent("fileComp",
         {},                            // current file
         false,                        // can edit file name,
         false,                        // is directory,
         true,                          // is for saving,
         { "preset" },                       // browser wildcard suffix,
         { "preset" },                       // enforced suffix,
         "-"));  // text when nothing selected
     addAndMakeVisible(Vst3SetSave.get());
     Vst3SetSave.get()->setBrowseButtonText("Save");
     Vst3SetSave.get()->setDefaultBrowseTarget(fw);
     Vst3SetSave.get()->setVisible(true);
     // Vst3SetSave.get()->setLookAndFeel(mlaf);

 

     

 }

 filebrowserVst3Sets::~filebrowserVst3Sets()
 {
 }


 void filebrowserVst3Sets::hideMode(float m)
 {
 }

 void filebrowserVst3Sets::paint(juce::Graphics&g)
 {
  
     juce::Rectangle<float> area(0, 0, getWidth(), getHeight()); 
      g.setColour(juce::Colours::whitesmoke);
     g.drawRect(area,  30);
     g.setColour(juce::Colours::black);
     g.setFont(juce::Font("Aharoni", 20.0f, juce::Font::bold));
     g.drawText("Preset", 30, 5, getWidth() - 100, 20, juce::dontSendNotification);

 }

 void filebrowserVst3Sets::resized()
 {
     Vst3SetSave.get()->setBounds(140, 5, 50, 20);
     fileTreeVst3.setBounds(10, 26, getWidth()-40, getHeight()-50);
 }



 bool filebrowserVst3Sets::OpenVst3Preset()
 {
     auto selectedFile = fileTreeVst3.getSelectedFile();
     selectedFile.getFileName();

 
     juce::File InFileVst(selectedFile);
     juce::FileInputStream in(InFileVst);
   
     juce::ValueTree InValueTree{ "DeadPoolAudio_V3" };
   
     if (auto xml = juce::XmlDocument::parse(InFileVst)) {
         InValueTree = juce::ValueTree::fromXml(*xml);
         valueTreeStateP.replaceState(juce::ValueTree::fromXml(*xml));
          
     }
         
   
     return true;
   
 }
