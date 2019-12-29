#ifndef FLUIDSYNTH_SETTINGS_H
#define FLUIDSYNTH_SETTINGS_H

#include <cstddef>
#include <map>

#include <fluidsynth.h>

using namespace std;

namespace Fluidsynth {
    enum Setting {
        AUDIO_DRIVER
    };

    enum SettingType {
        INT,
        STR
    };

    class Settings {
        private:
            fluid_settings_t *settings;

        public:
            Settings();
            ~Settings();

            fluid_settings_t *getFluidSettings();

            const char *getSettingKey(Setting setting);
            SettingType getSettingType(Setting setting);
            SettingType getSettingType(const char *setting);

            map<const char *, const char *> getSettings();
            const char *getSettings(const char *setting);
            void setSettings(Setting setting, const char *value);
            void setSettings(const char *setting, const char *value);
            void setSettings(map<const char *, const char *> settings, bool replace = false);
    };
}

#endif
