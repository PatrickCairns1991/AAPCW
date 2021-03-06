/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/**
*/
class AdvancedAudioProcessingCourseworkAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    AdvancedAudioProcessingCourseworkAudioProcessor();
    ~AdvancedAudioProcessingCourseworkAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    //Declare float to store stereo pan position
    float StereoPanPosition;
    
    //Declare Float to store stereo width
    float StereoWidth;
    
    //Declare Integer to store Index for StereoPanningAlgorithm ComboBox Choice
	int AlgoChoiceIndex;
	
	//Declare Integer to store Index for ComboBoxInputSelectIndex
	int InputChoiceIndex;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AdvancedAudioProcessingCourseworkAudioProcessor)
};
