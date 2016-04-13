/*
  ==============================================================================

    FaustUIComponent.cpp
    Author:  Oliver Larkin

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "FaustUIComponent.h"

FaustUIComponent::FaustUIComponent()
{
}

FaustUIComponent::~FaustUIComponent()
{
}

void FaustUIComponent::paint (Graphics& g)
{
}

void FaustUIComponent::resized()
{
}

#pragma mark Faust UI
void FaustUIComponent::openTabBox(const char* label)
{
  //TODO:
}

void FaustUIComponent::openHorizontalBox(const char* label)
{
  //TODO:
}

void FaustUIComponent::openVerticalBox(const char* label)
{
  //TODO:
}

void FaustUIComponent::closeBox()
{
  //TODO:
}

void FaustUIComponent::addButton(const char* label, FAUSTFLOAT* zone)
{
  //TODO:
}

void FaustUIComponent::addCheckButton(const char* label, FAUSTFLOAT* zone)
{
  //TODO:
}

void FaustUIComponent::addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
{
  addAndMakeVisible(new Slider(String(label)));
}

void FaustUIComponent::addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
{
  addAndMakeVisible(new Slider(String(label)));
}

void FaustUIComponent::addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
{
  //TODO:
}

void FaustUIComponent::addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
{
  //TODO:
}

void FaustUIComponent::addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
{
  //TODO:
}

void FaustUIComponent::declare(FAUSTFLOAT* zone, const char* key, const char* value)
{
  //  if (zone == 0) {
  //    // special zone 0 means group metadata
  //    if (strcmp(key, "tooltip")==0) {
  //      // only group tooltip are currently implemented
  //      gGroupTooltip = formatTooltip(30, value);
  //    }
  //  } else {
  //    if (strcmp(key, "size") == 0) {
  //      fGuiSize[zone]=atof(value);
  //    }
  //    else if (strcmp(key, "tooltip") == 0) {
  //      fTooltip[zone] = formatTooltip(30, value) ;
  //    }
  //    else if (strcmp(key, "unit") == 0) {
  //      fUnit[zone] = value ;
  //    }
  //    else if (strcmp(key, "scale") == 0) {
  //      if (strcmp(value, "log") == 0) {
  //        fLogSet.insert(zone);
  //      } else if (strcmp(value, "exp") == 0) {
  //        fExpSet.insert(zone);
  //      }
  //    }
  //    else if (strcmp(key, "style") ==0) {
  //      // else if ((strcmp(key,"style")==0) || (strcmp(key,"type")==0)) {
  //      if (strcmp(value, "knob") == 0) {
  //        fKnobSet.insert(zone);
  //      } else if (strcmp(value, "led") == 0) {
  //        fLedSet.insert(zone);
  //      } else if (strcmp(value, "numerical") == 0) {
  //        fNumSet.insert(zone);
  //      } else {
  //        const char* p = value;
  //        if (parseWord(p, "radio")) {
  //          fRadioDescription[zone] = string(p);
  //        } else if (parseWord(p, "menu")) {
  //          fMenuDescription[zone] = string(p);
  //        }
  //      }
  //    }
  //  }
}

#pragma mark FAUST metadata declarations
void FaustUIComponent::declare(const char* key, const char* value)
{
  
}
