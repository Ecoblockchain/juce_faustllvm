/*
  ==============================================================================

    FaustUIComponent.h
    Author:  Oliver Larkin

  ==============================================================================
*/

#ifndef FAUSTUICOMPONENT_H_INCLUDED
#define FAUSTUICOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "faust/gui/UI.h"
#include "faust/gui/meta.h"


class FaustSlider : public Slider
{
public:
  FaustSlider(const juce::String& componentName)
  {
  }
protected:
  void mouseDown(const MouseEvent& e)
  {
  }
  
  void mouseUp(const MouseEvent& e)
  {
  }
  
};

class FaustUIComponent : public Component
                       , public UI
                       , public Meta
{
public:
  FaustUIComponent();
  ~FaustUIComponent();

  //Component
  void paint (Graphics&) override;
  void resized() override;

  // FAUST UI
  void openTabBox(const char* label) override;
  void openHorizontalBox(const char* label) override;
  void openVerticalBox(const char* label) override;
  void closeBox() override;
  void addButton(const char* label, FAUSTFLOAT* zone) override;
  void addCheckButton(const char* label, FAUSTFLOAT* zone) override;
  void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override;
  void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override;
  void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override;
  void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) override;
  void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) override;
  
  // UI metadata declarations
  void declare(FAUSTFLOAT* zone, const char* key, const char* val) override;
  
  // FAUST metadata declarations
  void declare(const char* key, const char* value) override;
  
private:
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FaustUIComponent)
};


#endif  // FAUSTUICOMPONENT_H_INCLUDED
