#pragma once
#include <JuceHeader.h>

extern juce::JUCEApplicationBase* juce_CreateApplication();

//==============================================================================
class StandaloneFilterApp   : public JUCEApplication
{
public:
    //==============================================================================
    StandaloneFilterApp()
    {
    }

    //==============================================================================
    void systemRequestedQuit() override                     { quit(); }
    void shutdown() override                                {}

    //==============================================================================
    const String getApplicationName() override              { return JucePlugin_Name; }
    const String getApplicationVersion() override           { return JucePlugin_VersionString; }
    bool moreThanOneInstanceAllowed() override              { return false; }
    void anotherInstanceStarted (const String&) override    {}

    //==============================================================================
    void initialise (const String&) override
    {
    }
};