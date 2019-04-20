/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
AdvancedAudioProcessingCourseworkAudioProcessorEditor::AdvancedAudioProcessingCourseworkAudioProcessorEditor (AdvancedAudioProcessingCourseworkAudioProcessor& p)
    : AudioProcessorEditor(p), processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    sliderStereoPanPosition.reset (new Slider ("new slider"));
    addAndMakeVisible (sliderStereoPanPosition.get());
    sliderStereoPanPosition->setRange (-1, 1, 0);
    sliderStereoPanPosition->setSliderStyle (Slider::Rotary);
    sliderStereoPanPosition->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sliderStereoPanPosition->addListener (this);

    sliderStereoPanPosition->setBounds (24, 24, 128, 144);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

AdvancedAudioProcessingCourseworkAudioProcessorEditor::~AdvancedAudioProcessingCourseworkAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    sliderStereoPanPosition = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void AdvancedAudioProcessingCourseworkAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void AdvancedAudioProcessingCourseworkAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void AdvancedAudioProcessingCourseworkAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == sliderStereoPanPosition.get())
    {
        //[UserSliderCode_sliderStereoPanPosition] -- add your slider handling code here..

        //Added to read value from StereoPanPosition Rotary Dial and hold in float StereoPanPosition
        processor.StereoPanPosition = sliderStereoPanPosition->getValue();

        //[/UserSliderCode_sliderStereoPanPosition]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="AdvancedAudioProcessingCourseworkAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor"
                 constructorParams="AdvancedAudioProcessingCourseworkAudioProcessor&amp; p"
                 variableInitialisers="AudioProcessorEditor(p), processor(p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.33"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <SLIDER name="new slider" id="9149587c35e9c167" memberName="sliderStereoPanPosition"
          virtualName="" explicitFocusOrder="0" pos="24 24 128 144" min="-1.0"
          max="1.0" int="0.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
