# Example Audio Plugin CMakeLists.txt

cmake_minimum_required (VERSION 3.16..3.22)
project (juce_audio_plugin VERSION 0.0.1)
file (GLOB_RECURSE SOURCE CONFIGURE_DEPENDS *.cpp *.h)

set (juce_dir "$ENV{HOME}/Documents/Code/JUCE/")
add_subdirectory (${juce_dir} "${PROJECT_BINARY_DIR}/juce")

set (JUCE_BUILD_EXTRAS OFF)
set (JUCE_BUILD_EXAMPLES OFF)

juce_add_plugin (${PROJECT_NAME}
    # IS_SYNTH TRUE/FALSE
    # NEEDS_MIDI_INPUT TRUE/FALSE
    # NEEDS_MIDI_OUTPUT TRUE/FALSE
    # IS_MIDI_EFFECT TRUE/FALSE
    # EDITOR_WANTS_KEYBOARD_FOCUS TRUE/FALSE
    # COPY_PLUGIN_AFTER_BUILD TRUE/FALSE
    PRODUCT_NAME "Audio Plugin Example"
    COMPANY_NAME dev.juce
    PLUGIN_MANUFACTURER_CODE Juce
    PLUGIN_CODE Dem0
    FORMATS Standalone AU VST3
)

juce_generate_juce_header (${PROJECT_NAME})

add_compile_definitions (
    JUCE_DISABLE_JUCE_VERSION_PRINTING=1
    JUCE_DISPLAY_SPLASH_SCREEN=0
    JUCE_USE_CUSTOM_PLUGIN_STANDALONE_APP=0
    JUCE_USE_CUSTOM_PLUGIN_STANDALONE_ENTRYPOINT=0
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0
)

target_sources (${PROJECT_NAME} PRIVATE ${SOURCE})

target_link_libraries (${PROJECT_NAME}
PRIVATE
    juce::juce_audio_utils
PUBLIC
    juce::juce_recommended_config_flags
    juce::juce_recommended_lto_flags
    juce::juce_recommended_warning_flags
)
