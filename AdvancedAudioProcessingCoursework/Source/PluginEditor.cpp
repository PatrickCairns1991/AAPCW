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
    
    //***A clipping is apparent when we load in REAPER and automute applied if the pan slider is untouched.
    //***This happens because StereoPanPosition float does not have a startup value.
    //***As such it can contain grabage and therefore triggers REAPER automute (channel gain is garbage).
    //***Adding this in constructor seems to have fixed the bug.
    processor.StereoPanPosition = 0;

    comboBoxStereoPanningAlgorithm.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBoxStereoPanningAlgorithm.get());
    comboBoxStereoPanningAlgorithm->setEditableText (false);
    comboBoxStereoPanningAlgorithm->setJustificationType (Justification::centredLeft);
    comboBoxStereoPanningAlgorithm->setTextWhenNothingSelected (TRANS("Linear"));
    comboBoxStereoPanningAlgorithm->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBoxStereoPanningAlgorithm->addItem (TRANS("Linear"), 1);
    comboBoxStereoPanningAlgorithm->addItem (TRANS("Equal Power"), 2);
    comboBoxStereoPanningAlgorithm->addListener (this);

    comboBoxStereoPanningAlgorithm->setBounds (184, 80, 150, 24);
    
    //Set default choice index for panning algorithm
    processor.AlgoChoiceIndex = 0;


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
    comboBoxStereoPanningAlgorithm = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void AdvancedAudioProcessingCourseworkAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    {
        int x = 156, y = 36, width = 200, height = 30;
        String text (TRANS("Panning Algorithm"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

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

void AdvancedAudioProcessingCourseworkAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBoxStereoPanningAlgorithm.get())
    {
        //[UserComboBoxCode_comboBoxStereoPanningAlgorithm] -- add your combo box handling code here..

        //When combo box selection is changed store index in int AlgoChoiceIndex
        processor.AlgoChoiceIndex = comboBoxStereoPanningAlgorithm->getSelectedItemIndex();

        //[/UserComboBoxCode_comboBoxStereoPanningAlgorithm]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
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
  <BACKGROUND backgroundColour="ff323e44">
    <TEXT pos="156 36 200 30" fill="solid: ff000000" hasStroke="0" text="Panning Algorithm"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="new slider" id="9149587c35e9c167" memberName="sliderStereoPanPosition"
          virtualName="" explicitFocusOrder="0" pos="24 24 128 144" min="-1.0"
          max="1.0" int="0.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <COMBOBOX name="new combo box" id="cf755da7e47243ed" memberName="comboBoxStereoPanningAlgorithm"
            virtualName="" explicitFocusOrder="0" pos="184 80 150 24" editable="0"
            layout="33" items="Linear&#10;Equal Power" textWhenNonSelected="Linear"
            textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
