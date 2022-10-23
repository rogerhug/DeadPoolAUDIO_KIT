/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
NewProjectAudioProcessor::NewProjectAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )

, valueTreeState(*this,&undoManager)
,mainG(valueTreeState)
,BrowserVstPreset(valueTreeState)
,spg1(valueTreeState)
, spg2(valueTreeState)
,mStepPos(0)
,trg(valueTreeState)
,masterGain(0.5)
#endif

{
   
 
    
    
   

    valueTreeState.state = ValueTree(Identifier(JucePlugin_Name));

    ApVst = false;//----->AppMode if true Vst Mode
    Ptime.tm1.Start();
    for(int i=0;i<7;i++)
    Ptime.setGate(0.2,i, 0);

   
    spg1.sampelout.init(512,44100);
    spg1.serialParas(valueTreeState, "sp1Paras");
    spg1.mod1.serialStepps(valueTreeState, "sp1mod");
    spg1.urls.loadInit1(valueTreeState, 1);
    buff1 = new float[SP_BUFFERS];
    spg1.sampelout.parasIn(*spg1.mpc);

    spg2.sampelout.init(512, 44100);
    spg2.serialParas(valueTreeState, "sp2Paras");
    spg2.mod1.serialStepps(valueTreeState, "sp2mod");
    spg2.urls.loadInit2(valueTreeState, 1);
    buff2 = new float[SP_BUFFERS];
    spg2.sampelout.parasIn(*spg2.mpc);

    moogM.init();
    filterMode = 0;
    buffMix = new float[SP_BUFFERS];
    for(int i=0;i<SP_BUFFERS;i++)
    {
        buff1[i]=0;
        buff2[i] = 0;
        buffMix[i] = 0;
    }
  

   

 
  


}

NewProjectAudioProcessor::~NewProjectAudioProcessor()
{
}

//==============================================================================
const juce::String NewProjectAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool NewProjectAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool NewProjectAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool NewProjectAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double NewProjectAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int NewProjectAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int NewProjectAudioProcessor::getCurrentProgram()
{
    return 0;
}

void NewProjectAudioProcessor::setCurrentProgram (int index)
{
  
}

const juce::String NewProjectAudioProcessor::getProgramName (int index)
{
   
    return {};
}

void NewProjectAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
 
}

//==============================================================================
void NewProjectAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{

   Ptime.prepare(getSampleRate(), getBlockSize());
   for(int i=0;i< samplesPerBlock;i++)
   {
       buff1[i]=0;
       buff2[i] = 0;
       buffMix[i] = 0;
   }
   
}

void NewProjectAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
    Ptime.tm1.Zero();
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool NewProjectAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}

#endif
inline double fastClip(double x, double low, double high)
{
    double x1 = fabs(x - low);
    double x2 = fabs(x - high);
    x = x1 + low + high - x2;
    
    return x * 0.5;
}



void NewProjectAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{

  
     ignoreUnused(midiMessages);
     updateCurrentTimeInfoFromHost();
     auto totalNumInputChannels  = getTotalNumInputChannels();
     auto totalNumOutputChannels = getTotalNumOutputChannels();
     int nFrames=buffer.getNumSamples();
    
    // 
     const int timeIn = mainG.mpcM->mTimeIn;
     const int appStart = 1;
     if(int(timeIn) == 0)
         Ptime.timerChrono(getPlayHead(), buffer.getNumSamples(), appStart);
     
     if (int(timeIn) == 1)
     Ptime.prosessTimeSampels(getPlayHead(),lastPosInfo.timeInSamples, nFrames);
     if (int(timeIn) == 2)
     Ptime.processTimeHost(getPlayHead(), buffer.getNumSamples(), 0);
     

    
     auto lastLatencySamples = getLatencySamples();


     // if (lastPosInfo.isPlaying == true ) {

          if (int(mainG.mpcM->mStartStop) == 1) {

          spg1.sampelout.processOut(Ptime.getHtime1(), buff1,  nFrames);
          spg2.sampelout.processOut(Ptime.getHtime2(), buff2, nFrames);
  

    for (int so = 0; so < nFrames; so++)
    {
    
        buffMix[so] = (buff1[so] + buff2[so]);
        buffMix[so] *= smLevel.Process(masterGain);
  
        for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        
            buffer.setSample(i, so, fastClip((buffMix[so]), -1, 1));

 }
     
       
    }
      else {
          for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
              buffer.clear(i, 0, buffer.getNumSamples());
          Ptime.tm1.Zero();
      }

    

  



    
}
//==============================================================================
bool NewProjectAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* NewProjectAudioProcessor::createEditor()
{
   // return new NewProjectAudioProcessorEditor (*this, valueTreeState);
return new NewProjectAudioProcessorEditor (*this);
}

//==============================================================================
void NewProjectAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{

   
    auto state = valueTreeState.copyState();
    std::unique_ptr<XmlElement> xml (state.createXml());
    copyXmlToBinary (*xml, destData);


}

void NewProjectAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
   

    std::unique_ptr<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));

    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName(valueTreeState.state.getType()))
           
        {
         

}
     






}

void NewProjectAudioProcessor::updateCurrentTimeInfoFromHost()
{
    if (auto* ph = getPlayHead())
    {
        AudioPlayHead::CurrentPositionInfo newTime;

        if (ph->getCurrentPosition(newTime))
        {
            lastPosInfo = newTime;  // Successfully got the current time from the host..
            return;
        }
    }

    // If the host fails to provide the current time, we'll just reset our copy to a default..
    lastPosInfo.resetToDefault();
}
double midiDataOut[60];
void NewProjectAudioProcessor::midiCC_(juce::MidiBuffer& midiMessages)
{   /*
    MidiBuffer::Iterator MidiItr(midiMessages);
    
    MidiMessage MidiMsg; int smpPos;
  
    if (MidiItr.getNextEvent(MidiMsg, smpPos))
    {

        if (MidiMsg.isController()) {//---------------------------------------------------------------------check it is a controller change
        
         //---------------------------------Unused_midiparas::5-119: 
            if (MidiMsg.getControllerNumber() == 3)
            {   esp1.SampelVolume.setValue((((float)MidiMsg.getControllerValue()) / 127.0f));
             
            midiCCupdate = 3;
            }

           
        }
        else
        
        midiCCupdate = 0;
     
       
    
    }
    */
       
    
       

}



//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new NewProjectAudioProcessor();
}
