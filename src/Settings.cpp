#include "Settings.hpp"

using namespace Fluidsynth;

Settings::Settings() {
    settings = new_fluid_settings();
}

Settings::~Settings() {
    delete_fluid_settings(settings);
}

fluid_synth_t *Settings::getFluidSynth() {
    return new_fluid_synth(settings);
}
