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

    sliderStereoPanPosition.reset (new Slider ("PanSlider"));
    addAndMakeVisible (sliderStereoPanPosition.get());
    sliderStereoPanPosition->setRange (-1, 1, 0);
    sliderStereoPanPosition->setSliderStyle (Slider::Rotary);
    sliderStereoPanPosition->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sliderStereoPanPosition->addListener (this);

    sliderStereoPanPosition->setBounds (8, 96, 128, 144);

    comboBoxStereoPanningAlgorithm.reset (new ComboBox ("Panning Combo"));
    addAndMakeVisible (comboBoxStereoPanningAlgorithm.get());
    comboBoxStereoPanningAlgorithm->setEditableText (false);
    comboBoxStereoPanningAlgorithm->setJustificationType (Justification::centredLeft);
    comboBoxStereoPanningAlgorithm->setTextWhenNothingSelected (TRANS("Linear"));
    comboBoxStereoPanningAlgorithm->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBoxStereoPanningAlgorithm->addItem (TRANS("Linear"), 1);
    comboBoxStereoPanningAlgorithm->addItem (TRANS("Equal Power"), 2);
    comboBoxStereoPanningAlgorithm->addListener (this);

    comboBoxStereoPanningAlgorithm->setBounds (16, 288, 128, 24);

    sliderStereoWidth.reset (new Slider ("WidthSlider"));
    addAndMakeVisible (sliderStereoWidth.get());
    sliderStereoWidth->setRange (0, 2, 0);
    sliderStereoWidth->setSliderStyle (Slider::Rotary);
    sliderStereoWidth->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sliderStereoWidth->addListener (this);

    sliderStereoWidth->setBounds (152, 96, 128, 144);

    comboBoxInputSelect.reset (new ComboBox ("Input Combo"));
    addAndMakeVisible (comboBoxInputSelect.get());
    comboBoxInputSelect->setEditableText (false);
    comboBoxInputSelect->setJustificationType (Justification::centredLeft);
    comboBoxInputSelect->setTextWhenNothingSelected (TRANS("Stereo"));
    comboBoxInputSelect->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBoxInputSelect->addItem (TRANS("Stereo"), 1);
    comboBoxInputSelect->addItem (TRANS("Mid-Side"), 2);
    comboBoxInputSelect->addListener (this);

    comboBoxInputSelect->setBounds (16, 56, 112, 24);

    comboBoxOutputSelect.reset (new ComboBox ("Output Combo"));
    addAndMakeVisible (comboBoxOutputSelect.get());
    comboBoxOutputSelect->setEditableText (false);
    comboBoxOutputSelect->setJustificationType (Justification::centredLeft);
    comboBoxOutputSelect->setTextWhenNothingSelected (String());
    comboBoxOutputSelect->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBoxOutputSelect->addItem (TRANS("Stereo"), 1);
    comboBoxOutputSelect->addItem (TRANS("Mid-Side"), 2);
    comboBoxOutputSelect->addListener (this);

    comboBoxOutputSelect->setBounds (160, 56, 112, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

	//Set default choice index for panning algorithm
	processor.AlgoChoiceIndex = 0;

	//Set default choice index for Input Selection
	processor.InputChoiceIndex = 0;
	
	//Set default choice index for Output Selection
	processor.OutputChoiceIndex = 0;

	//***A clipping is apparent when we load in REAPER and automute applied if the pan slider is untouched.
	//***This happens because StereoPanPosition float does not have a startup value.
	//***As such it can contain grabage and therefore triggers REAPER automute (channel gain is garbage).
	//***Adding this in constructor seems to have fixed the bug.
	processor.StereoPanPosition = 0.0;

	//Set default of 0.5 for Stereo Width ****Possibly Reset this to 0.5?
	processor.StereoWidth = 0.0;

    //[/Constructor]
}

AdvancedAudioProcessingCourseworkAudioProcessorEditor::~AdvancedAudioProcessingCourseworkAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    sliderStereoPanPosition = nullptr;
    comboBoxStereoPanningAlgorithm = nullptr;
    sliderStereoWidth = nullptr;
    comboBoxInputSelect = nullptr;
    comboBoxOutputSelect = nullptr;


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
        int x = 20, y = 252, width = 116, height = 30;
        String text (TRANS("Panning Algorithm"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 12, y = 12, width = 124, height = 36;
        String text (TRANS("Input Format"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 156, y = 12, width = 132, height = 36;
        String text (TRANS("Output Fomat"));
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
    else if (sliderThatWasMoved == sliderStereoWidth.get())
    {
        //[UserSliderCode_sliderStereoWidth] -- add your slider handling code here..

        //Added to read value from StereoWidth Rotary Dial and hold in float StereoWidth
        processor.StereoWidth = sliderStereoWidth->getValue();

        //[/UserSliderCode_sliderStereoWidth]
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
    else if (comboBoxThatHasChanged == comboBoxInputSelect.get())
    {
        //[UserComboBoxCode_comboBoxInputSelect] -- add your combo box handling code here..

        //When combo box selection is changed store index in int InputChoiceIndex
        processor.InputChoiceIndex = comboBoxInputSelect->getSelectedItemIndex();

        //[/UserComboBoxCode_comboBoxInputSelect]
    }
    else if (comboBoxThatHasChanged == comboBoxOutputSelect.get())
    {
        //[UserComboBoxCode_comboBoxOutputSelect] -- add your combo box handling code here..

        //When combo box selection is changed store index in int OutputChoiceIndex
        processor.OutputChoiceIndex = comboBoxOutputSelect->getSelectedItemIndex();


        //[/UserComboBoxCode_comboBoxOutputSelect]
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
    <TEXT pos="20 252 116 30" fill="solid: ff000000" hasStroke="0" text="Panning Algorithm"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="12 12 124 36" fill="solid: ff000000" hasStroke="0" text="Input Format"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="156 12 132 36" fill="solid: ff000000" hasStroke="0" text="Output Fomat"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="PanSlider" id="9149587c35e9c167" memberName="sliderStereoPanPosition"
          virtualName="" explicitFocusOrder="0" pos="8 96 128 144" min="-1.0"
          max="1.0" int="0.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <COMBOBOX name="Panning Combo" id="cf755da7e47243ed" memberName="comboBoxStereoPanningAlgorithm"
            virtualName="" explicitFocusOrder="0" pos="16 288 128 24" editable="0"
            layout="33" items="Linear&#10;Equal Power" textWhenNonSelected="Linear"
            textWhenNoItems="(no choices)"/>
  <SLIDER name="WidthSlider" id="69ea6263bdd08eee" memberName="sliderStereoWidth"
          virtualName="" explicitFocusOrder="0" pos="152 96 128 144" min="0.0"
          max="2.0" int="0.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <COMBOBOX name="Input Combo" id="2c089223bb5a65e3" memberName="comboBoxInputSelect"
            virtualName="" explicitFocusOrder="0" pos="16 56 112 24" editable="0"
            layout="33" items="Stereo&#10;Mid-Side" textWhenNonSelected="Stereo"
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="Output Combo" id="445defdb571c2659" memberName="comboBoxOutputSelect"
            virtualName="" explicitFocusOrder="0" pos="160 56 112 24" editable="0"
            layout="33" items="Stereo&#10;Mid-Side" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
