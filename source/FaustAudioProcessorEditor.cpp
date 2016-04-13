/*
  ==============================================================================

    FaustAudioProcessorEditor.cpp
    Author:  Oliver Larkin

  ==============================================================================
*/

#include "FaustAudioProcessorEditor.h"
#include "FaustUIComponent.h"

FaustAudioProcessorEditor::FaustAudioProcessorEditor(AudioProcessor& processor)
: AudioProcessorEditor(processor)
{
  FaustUIComponent* ui = new FaustUIComponent();
  dynamic_cast<FaustAudioPluginInstance&>(processor).getDSP()->buildUserInterface(ui);
  
  addAndMakeVisible(ui);
  
  setSize(300, 300);
}

FaustAudioProcessorEditor::~FaustAudioProcessorEditor()
{
  deleteAllChildren();
}

void FaustAudioProcessorEditor::paint(Graphics& g)
{
  g.fillAll (Colours::grey);
}

void FaustAudioProcessorEditor::resized()
{
  Rectangle<int> r (getLocalBounds().reduced (8));
  
  if(getNumChildComponents())
    getChildComponent(0)->setBounds(r);
}

#pragma mark AudioProcessorListener
void FaustAudioProcessorEditor::audioProcessorChanged (AudioProcessor*)
{
}

void FaustAudioProcessorEditor::audioProcessorParameterChanged (AudioProcessor* p, int parameterIndex, float newValue)
{
}

#pragma mark Timer
void FaustAudioProcessorEditor::timerCallback()
{
}