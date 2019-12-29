#include <stdlib.h>     /* atoi */

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

const char *Settings::getSettingKey(Setting setting) {
    if (setting == AUDIO_DRIVER) {
        return "audio.driver";
    }

    throw new SettingsException("Unknown setting key");
}

SettingType Settings::getSettingType(const char *setting) {
    return STR;
}

SettingType Settings::getSettingType(Setting setting) {
    return getSettingType(getSettingKey(setting));
}

void Settings::setSettings(Setting setting, const char *value) {
    setSettings(getSettingKey(setting), value);
}

void Settings::setSettings(const char *setting, const char *value) {
    SettingType type = getSettingType(setting);
    char *buf = new char[255];

    if (
            (type == STR && fluid_settings_setstr(settings, setting, value) == FLUID_FAILED) ||
            (type == INT && fluid_settings_setint(settings, setting, atoi(value)) == FLUID_FAILED)
    ) {
        snprintf(buf, 255, "Failed to set '%s'(%s) setting", setting, type == INT ? "int": "str");
        throw new SettingsException(buf);
    }
}
