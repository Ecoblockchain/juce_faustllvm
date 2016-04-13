/*
  ==============================================================================

    FaustAudioProcessorEditor.h
    Author:  Oliver Larkin

  ==============================================================================
*/

#ifndef FAUSTAUDIOPROCESSOREDITOR_H_INCLUDED
#define FAUSTAUDIOPROCESSOREDITOR_H_INCLUDED

class FaustAudioProcessorEditor : public AudioProcessorEditor
                                , private AudioProcessorListener
                                , private Timer
{
public:
  FaustAudioProcessorEditor (AudioProcessor& processor);
  ~FaustAudioProcessorEditor();
  
  //Component
  void paint (Graphics& g) override;
  void resized() override;

  //AudioProcessorListener
  void audioProcessorChanged (AudioProcessor*) override;
  void audioProcessorParameterChanged (AudioProcessor* p, int parameterIndex, float newValue) override;

  //Timer
  void timerCallback() override;
  
private:
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FaustAudioProcessorEditor)
};

#endif //FAUSTAUDIOPROCESSOREDITOR_H_INCLUDED