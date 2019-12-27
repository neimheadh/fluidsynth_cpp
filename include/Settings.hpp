#ifndef FLUIDSYNTH_SETTINGS_H
#define FLUIDSYNTH_SETTINGS_H

#include <cstddef>

#include <fluidsynth.h>


namespace Fluidsynth {
    class Settings {
        private:
            fluid_settings_t *settings;

        public:
            Settings();
            ~Settings();

            fluid_synth_t *getFluidSynth();
            fluid_settings_t *getFluidSettings();
    };
}

#endif
