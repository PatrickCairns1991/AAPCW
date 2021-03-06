/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AdvancedAudioProcessingCourseworkAudioProcessor::AdvancedAudioProcessingCourseworkAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{

}

AdvancedAudioProcessingCourseworkAudioProcessor::~AdvancedAudioProcessingCourseworkAudioProcessor()
{
}

//==============================================================================
const String AdvancedAudioProcessingCourseworkAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool AdvancedAudioProcessingCourseworkAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool AdvancedAudioProcessingCourseworkAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool AdvancedAudioProcessingCourseworkAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double AdvancedAudioProcessingCourseworkAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int AdvancedAudioProcessingCourseworkAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int AdvancedAudioProcessingCourseworkAudioProcessor::getCurrentProgram()
{
    return 0;
}

void AdvancedAudioProcessingCourseworkAudioProcessor::setCurrentProgram (int index)
{
}

const String AdvancedAudioProcessingCourseworkAudioProcessor::getProgramName (int index)
{
    return {};
}

void AdvancedAudioProcessingCourseworkAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void AdvancedAudioProcessingCourseworkAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void AdvancedAudioProcessingCourseworkAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool AdvancedAudioProcessingCourseworkAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
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

void AdvancedAudioProcessingCourseworkAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());


    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    
    //Any Constants used in channel data processing may be calculated here.
    //This prevents recalculating the constants for each sample, and therefore decreases processing load.
    //It is also useful to calculate any user input variables here, so that these will only be computed on parameter change and not every sample.
    
    //Calculate pdash for stereo panning
    //Linear Panning algorithm pDash
    float pDashStereoLinear = (StereoPanPosition + 1.0) / 2.0;
    
    //ConstantPower panning algorithm pDash
    float pDashStereoConstant = (3.14159265359 * (StereoPanPosition + 1))/4;
    
    //Store Width in float width. Calculate (2-w).
    float Width = StereoWidth;
    float WidthRightElement = 2 - StereoWidth;
    
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        
        //For Loop Added to process Stereo Panning For Linear Gain as in Lab 4
        
        for (int i = 0; i < buffer.getNumSamples(); i++)
        {
            if (AlgoChoiceIndex==0)//Linear Panning
            {
                if (channel == 0) // Left channel
                {
                    channelData[i] = channelData[i] * (1.0 - pDashStereoLinear);
                }
                else // Right channel (or any other channel)
                {
                channelData[i] = channelData[i] * pDashStereoLinear;
                }
            }
            else if(AlgoChoiceIndex==1)//Constant Power
            {
                if (channel == 0) // Left channel
                {
                    channelData[i] = channelData[i] * cos(pDashStereoConstant);
                }
                else // Right channel (or any other channel)
                {
                channelData[i] = channelData[i] * sin(pDashStereoConstant);
                }
            }
        }

        // ..do something to the data...
    }
}

//==============================================================================
bool AdvancedAudioProcessingCourseworkAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* AdvancedAudioProcessingCourseworkAudioProcessor::createEditor()
{
    return new AdvancedAudioProcessingCourseworkAudioProcessorEditor (*this);
}

//==============================================================================
void AdvancedAudioProcessingCourseworkAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void AdvancedAudioProcessingCourseworkAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new AdvancedAudioProcessingCourseworkAudioProcessor();
}
