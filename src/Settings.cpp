#include "Settings.hpp"
#include "exceptions/SettingsException.hpp"

using namespace Fluidsynth;

Settings::Settings() {
    settings = new_fluid_settings();

    if (settings == NULL) {
        throw new SettingsException("Failed to create the fluid settings");
    }
}

Settings::~Settings() {
    delete_fluid_settings(settings);
}

fluid_settings_t *Settings::getFluidSettings() {
    return settings;
}
