#include "Driver.hpp"
#include "Synth.hpp"
#include "exceptions/DriverException.hpp"

using namespace Fluidsynth;

Driver::Driver(Settings *settings, Synth *synth) {
    this->settings = settings;
    this->synth = synth;

    _init_fluid_driver();
}

Driver::~Driver() {
    delete_fluid_audio_driver(driver);
}

void Driver::_init_fluid_driver() {
    driver = new_fluid_audio_driver(
            settings->getFluidSettings(),
            synth->getFluidSynth()
    );

    if (driver == NULL) {
        throw new DriverException("Failed to create the audio driver");
    }
}

fluid_audio_driver_t *Driver::getFluidDriver() {
    return driver;
}


