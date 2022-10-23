/*
  ==============================================================================

    filebrowser.h
    Created: 28 Jul 2022 1:53:07pm
    Author:  roger hug

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include"customLook.h"



//==============================================================================
/*
 juce::File file("/path/to/file");

// writing
juce::ValueTree myValueTree{"someID"};
juce::FileOutputStream outstream(file);
myValueTree.writeToStream(outstream);

// reading
juce::FileInputStream in(file);
if (in.openedOk())
    auto newValueTree = juce::ValueTree::readFromStream(in);
------------------xml--------------
juce::ValueTree myValueTree { "myID" };
juce::File myFile ("/Path/To/File");

// writing
if (auto xml = myValueTree.createXml())
    xml->writeTo (myFile);

// reading
if (auto xml = juce::XmlDocument::parse (myFile))
    myValueTree = juce::ValueTree::fromXml (*xml);

*/
class SimpleThumbnailComponent : public juce::Component,
    private juce::ChangeListener
{
public:
    SimpleThumbnailComponent(int sourceSamplesPerThumbnailSample,
        juce::AudioFormatManager& formatManager,
        juce::AudioThumbnailCache& cache)
        : thumbnail(sourceSamplesPerThumbnailSample, formatManager, cache)
    {
        thumbnail.addChangeListener(this);
    }

    void setFile(const juce::File& file)
    {
        thumbnail.setSource(new juce::FileInputSource(file));
    }

    void paint(juce::Graphics& g) override
    {
        if (thumbnail.getNumChannels() == 0)
            paintIfNoFileLoaded(g);
        else
            paintIfFileLoaded(g);
    }

    void paintIfNoFileLoaded(juce::Graphics& g)
    {
        g.fillAll(juce::Colours::white);
        g.setColour(juce::Colours::darkgrey);
        g.drawFittedText("No File Loaded", getLocalBounds(), juce::Justification::centred, 1);
    }

    void paintIfFileLoaded(juce::Graphics& g)
    {
        g.fillAll(juce::Colours::white);

        g.setColour(juce::Colours::red);
        thumbnail.drawChannels(g, getLocalBounds(), 0.0, thumbnail.getTotalLength(), 1.0f);
    }

    void changeListenerCallback(juce::ChangeBroadcaster* source) override
    {
        if (source == &thumbnail)
            thumbnailChanged();
    }

private:
    void thumbnailChanged()
    {
        repaint();
    }

    juce::AudioThumbnail thumbnail;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SimpleThumbnailComponent)
};
//=======================================================================================


class filebrowserTriggers  : public juce::Component
                   , public FileBrowserListener
                   , public CustomLookAndFeel
{

public:
    filebrowserTriggers();
    ~filebrowserTriggers() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    static String getSystemNameInfo()
    {
        String systemInfo;

        systemInfo
            << File::getSpecialLocation(File::commonDocumentsDirectory).getFullPathName();

        //   DBG (systemInfo);
        return systemInfo;
    }
  //  void filenameComponentChanged(FilenameComponent* fileComponentThatHasChanged) override;
 std::unique_ptr<juce::FilenameComponent> TriggerSave;

 Value trin1;
 Value trin2;
 Value trin3;
 Value trin4;
 Value trin5;
 Value trin6;
 Value trin7;
 Value trinAll[7];

 float** getXmlIn();
 Value* getXmTriggersets();
 bool updateTriggers;

 /*
 ///=========textContent->stream readout============================
 static juce::String readUpToNextSpace(juce::FileInputStream& inputStream)
 {
     juce::MemoryBlock buffer(256);
     auto* data = static_cast<char*> (buffer.getData());
     size_t i = 0;

     while ((data[i] = inputStream.readByte()) != 0 && i < buffer.getSize())
         if (data[i++] == ' ')
             break;

     return juce::String::fromUTF8(data, (int)i);
 }
 void readFile(const juce::File& fileToRead)
 {
     if (!fileToRead.existsAsFile())
         return;  // file doesn't exist

     juce::FileInputStream inputStream(fileToRead);

     if (!inputStream.openedOk())
         return;  // failed to open

     textContent->clear();

     while (!inputStream.isExhausted())
     {
         auto nextWord = readUpToNextSpace(inputStream);
  
         textContent->insertTextAtCaret(nextWord);
     }
 }
 */

private:
    void addLookAndFeel(juce::LookAndFeel* laf, const juce::String& name) { }
    float** TriggersXmlIn;
    WildcardFileFilter imagesWildcardFilter{ "*.trg;*.trg;*.trg;*.trg", "*", "Image File Filter" };
    TimeSliceThread directoryThread{ "Image File Scanner Thread" };
    DirectoryContentsList triggerList{ &imagesWildcardFilter, directoryThread };
    FileTreeComponent fileTreeTriggers{ triggerList };

  //  std::unique_ptr<juce::TextEditor>        textContent;


    void selectionChanged() override
    {
        // we're only really interested in when the selection changes, regardless of if it was
        // clicked or not so we'll only override this method
   
            auto selectedFileTrigger = fileTreeTriggers.getSelectedFile();
            updateTriggers = true;
         
            if (selectedFileTrigger.existsAsFile())
                parsetriggers();
            else

                fileTreeTriggers.clearSelectedItems();
        
  
        // the image cache is a handy way to load images from files or directly from memory and
        // will keep them hanging around for a few seconds in case they are requested elsewhere
    }
    void parsetriggers();

    void fileClicked(const File&, const MouseEvent&) override {}
    void fileDoubleClicked(const File&)              override {}
    void browserRootChanged(const File&)             override {}
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (filebrowserTriggers)
};


//===============================================================================
//=======================wavesets=============================================
//*****************************************************************************


class filebrowserWaveSets : public juce::Component
    , public FileBrowserListener
    , public CustomLookAndFeel
{

public:
    filebrowserWaveSets();
    ~filebrowserWaveSets() override;
    static String getSystemNameInfo()
    {
        String systemInfo;

        systemInfo
            << File::getSpecialLocation(File::commonDocumentsDirectory).getFullPathName();

        //   DBG (systemInfo);
        return systemInfo;
    }
    void fileIn(File f, const int nUmber);

    void hideMode(float m);
    void paint(juce::Graphics&) override;
    void resized() override;
   
    std::unique_ptr<juce::FilenameComponent> WaveSetSave;
    void serialWaveSets(AudioProcessorValueTreeState& valueTreeState, File fileAudio,const int nUmb);
    Value outStr[7];
    void setFileIn(Value t, int n);
 
    Value* getXmlWavesets();
    bool updateWaveSets;
     // SimpleThumbnailComponent curve;
    bool updateTriggers;
private:

    void addLookAndFeel(juce::LookAndFeel* laf, const juce::String& name) { }
    WildcardFileFilter imagesWildcardFilterW{ "*.ww;*.ww;*.ww;*.ww", "*", "Image File Filter" };
    TimeSliceThread directoryThread{ "Image File Scanner Thread" };
    DirectoryContentsList WaveSetList{ &imagesWildcardFilterW, directoryThread };
    FileTreeComponent fileTreeWaves{ WaveSetList };


    void selectionChanged() override
    {
        // we're only really interested in when the selection changes, regardless of if it was
        // clicked or not so we'll only override this method


        auto selectedFileWave = fileTreeWaves.getSelectedFile();
           updateWaveSets = true;
        if (selectedFileWave.existsAsFile())
            SaveWaveSets();
        

        // the image cache is a handy way to load images from files or directly from memory and
        // will keep them hanging around for a few seconds in case they are requested elsewhere
    }
  
    void SaveWaveSets();
    void fileClicked(const File&, const MouseEvent&) override {}
    void fileDoubleClicked(const File&)              override {}
    void browserRootChanged(const File&)             override {}
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(filebrowserWaveSets)
};
class filebrowserVst3Sets : public juce::Component
    , public FileBrowserListener
    , public CustomLookAndFeel
{

public:
    filebrowserVst3Sets(AudioProcessorValueTreeState& vts);
    ~filebrowserVst3Sets() override;
    static String getSystemNameInfo()
    {
        String systemInfo;

        systemInfo
            << File::getSpecialLocation(File::commonDocumentsDirectory).getFullPathName();

        //   DBG (systemInfo);
        return systemInfo;
    }

    void hideMode(float m);
    void paint(juce::Graphics&) override;
    void resized() override;
    bool OpenVst3Preset();
    std::unique_ptr<juce::FilenameComponent> Vst3SetSave;

    bool updateVst3Sets;
 
  AudioProcessorValueTreeState& valueTreeStateP;
private:
    
    void addLookAndFeel(juce::LookAndFeel* laf, const juce::String& name) { }
    WildcardFileFilter imagesWildcardFilterW{ "*.preset;*.preset;*.preset;*.preset", "*", "Image File Filter" };
    TimeSliceThread directoryThread{ "Image File Scanner Thread" };
    DirectoryContentsList Vst3SetList{ &imagesWildcardFilterW, directoryThread };
    FileTreeComponent fileTreeVst3{ Vst3SetList };


    void selectionChanged() override
    {
        // we're only really interested in when the selection changes, regardless of if it was
        // clicked or not so we'll only override this method

    updateVst3Sets = true;
        auto selectedFileWave = fileTreeVst3.getSelectedFile();
       
        if (selectedFileWave.existsAsFile())
            OpenVst3Preset();
        

        // the image cache is a handy way to load images from files or directly from memory and
        // will keep them hanging around for a few seconds in case they are requested elsewhere
    }


    void fileClicked(const File&, const MouseEvent&) override {}
    void fileDoubleClicked(const File&)              override {}
    void browserRootChanged(const File&)             override {}
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(filebrowserVst3Sets)
};

