#include <stdlib.h>     /* atoi */
#include <cstring>      /* strcpy */

#include "Settings.hpp"
#include "exceptions/SettingsException.hpp"

using namespace Fluidsynth;

typedef struct {
    fluid_settings_t *settings;
    map<string, char *> *smap;
} _settings_foreach_t;

Settings::Settings() {
    settings = new_fluid_settings();

    if (settings == NULL) {
        throw new SettingsException("Failed to create the fluid settings");
    }
}

Settings::~Settings() {
    delete_fluid_settings(settings);
}

char *Settings::_get_setting_str(fluid_settings_t *settings, const char *name, int type) {
    char *buf, *str;
    double double_val;
    int int_val;

    switch (type) {
        case FLUID_NO_TYPE:
            str = new char[1];
            str[0] = '\0';
            return str;
        case FLUID_NUM_TYPE:
            fluid_settings_getnum(settings, name, &double_val);
            buf = new char[11];
            snprintf(buf, 11, "%f", double_val);
            break;
        case FLUID_INT_TYPE:
            fluid_settings_getint(settings, name, &int_val);
            buf = new char[11];
            snprintf(buf, 11, "%i", int_val);
            break;
        case FLUID_STR_TYPE:
            buf = new char[256];
            fluid_settings_copystr(settings, name, buf, 256);
            break;
        case FLUID_SET_TYPE:
            buf = new char[11];
            snprintf(buf, 11, "%i", fluid_settings_get_type(settings, name));
            break;
        default:
            buf = new char[256];
            snprintf(buf, 256, "Unable to get the '%s' setting type", name);
            throw new SettingsException(buf);
    }

    str = new char[strlen(buf) + 1];
    strcpy(str, buf);
    delete[] buf;
    return str;
}

void Settings::_settings_foreach(void *data, const char *name, int type) {
    _settings_foreach_t *d = reinterpret_cast<_settings_foreach_t *>(data);
    (*d->smap)[name] = Settings::_get_setting_str(d->settings, name, type);
}

fluid_settings_t *Settings::getFluidSettings() {
    return settings;
}

fluid_types_enum Settings::getSettingType(const char *setting) {
    return FLUID_STR_TYPE;
}

void Settings::setSettings(const char *setting, const char *value) {
    fluid_types_enum type = getSettingType(setting);
    char *buf = new char[256];

    if (
            (type == FLUID_STR_TYPE && fluid_settings_setstr(settings, setting, value) == FLUID_FAILED) ||
            (type == FLUID_INT_TYPE && fluid_settings_setint(settings, setting, atoi(value)) == FLUID_FAILED)
    ) {
        snprintf(buf, 256, "Failed to set '%s'(%s) setting", setting, type == FLUID_INT_TYPE ? "int": "str");
        throw new SettingsException(buf);
    }
}

map<string, char *> Settings::getSettings() {
    map<string, char *> smap;
    _settings_foreach_t *data = new _settings_foreach_t;

    data->settings = settings;
    data->smap = &smap;
    fluid_settings_foreach(settings, data, Settings::_settings_foreach);

    delete data;
    return smap;
}

char *Settings::getSettings(const char *name) {
    return _get_setting_str(settings, name, getSettingType(name));
}
