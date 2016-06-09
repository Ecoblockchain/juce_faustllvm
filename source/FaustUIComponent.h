/*
  ==============================================================================

    FaustUIComponent.h
    Author:  Oliver Larkin

  ==============================================================================
*/

#ifndef FAUSTUICOMPONENT_H_INCLUDED
#define FAUSTUICOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "faust/gui/GUI.h"
#include "faust/gui/meta.h"
#include "faust/gui/ValueConverter.h"

class FaustSlider : public Slider
                  , public uiItem
{
public:
  enum Scale
  {
    kLin,
    kLog,
    kExp
  };
  
  FaustSlider(const char* label, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT cur, FAUSTFLOAT lo, FAUSTFLOAT hi, FAUSTFLOAT step, Scale scale);

  void reflectZone() override;
  
private:
  FAUSTFLOAT fCur;
  FAUSTFLOAT fMin;
  FAUSTFLOAT fMax;
  FAUSTFLOAT fStep;
  ScopedPointer<ValueConverter> fConverter;
};

class FaustUIComponent : public Component
                       , public GUI
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
  
  FaustSlider::Scale getScale(FAUSTFLOAT* zone)
  {
    if (fLogSet.count(zone) > 0)
      return FaustSlider::kLog;
    if (fExpSet.count(zone) > 0)
      return FaustSlider::kExp;
    return FaustSlider::kLin;
  }
  
  /**
   * Format tooltip string by replacing some white spaces by
   * return characters so that line width doesn't exceed n.
   * Limitation : long words exceeding n are not cut
   */
  std::string formatTooltip(int n, const std::string& tt)
  {
    std::string  ss = tt;	// ss string we are going to format
    int	lws = 0;	// last white space encountered
    int 	lri = 0;	// last return inserted
    for (int i=0; i< (int)tt.size(); i++) {
      if (tt[i] == ' ') lws = i;
      if (((i-lri) >= n) && (lws > lri)) {
        // insert return here
        ss[lws] = '\n';
        lri = lws;
      }
    }
    return ss;
  }
  
  void clearMetadata()
  {
    fGuiSize.clear();
    fTooltip.clear();
    fUnit.clear();
    fRadioDescription.clear();
    fMenuDescription.clear();
    fKnobSet.clear();
    fLedSet.clear();
    fNumSet.clear();
    fLogSet.clear();
    fExpSet.clear();
  }
  
private:
  std::map<FAUSTFLOAT*, FAUSTFLOAT>      fGuiSize;            // map widget zone with widget size coef
  std::map<FAUSTFLOAT*, std::string>     fTooltip;            // map widget zone with tooltip strings
  std::map<FAUSTFLOAT*, std::string>     fUnit;               // map widget zone to unit string (i.e. "dB")
  std::map<FAUSTFLOAT*, std::string>     fRadioDescription;   // map zone to {'low':440; ...; 'hi':1000.0}
  std::map<FAUSTFLOAT*, std::string>     fMenuDescription;    // map zone to {'low':440; ...; 'hi':1000.0}
  std::set<FAUSTFLOAT*>                  fKnobSet;            // set of widget zone to be knobs
  std::set<FAUSTFLOAT*>                  fLedSet;             // set of widget zone to be LEDs
  std::set<FAUSTFLOAT*>                  fNumSet;             // set of widget zone to be numerical bargraphs
  std::set<FAUSTFLOAT*>                  fLogSet;             // set of widget zone having a log UI scale
  std::set<FAUSTFLOAT*>                  fExpSet;             // set of widget zone having an exp UI scale
  
  std::string gGroupTooltip;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FaustUIComponent)
};


#endif  // FAUSTUICOMPONENT_H_INCLUDED
