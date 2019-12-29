#ifndef FLUIDSYNTH_DRIVER_HPP
#define FLUIDSYNTH_DRIVER_HPP

#include <fluidsynth.h>

#include "Settings.hpp"

namespace Fluidsynth {
    class Synth;

    class Driver {
        private:
            fluid_audio_driver_t *driver;
            Settings *settings;
            Synth *synth;

            void _init_fluid_driver();

        public:
            Driver(Settings *settings, Synth *synth);
            ~Driver();

            fluid_audio_driver_t *getFluidDriver();
    };
}

#endif
