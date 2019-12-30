#ifndef FLUIDSYNTH_SETTINGS_H
#define FLUIDSYNTH_SETTINGS_H

#include <cstddef>
#include <map>
#include <string>

#include <fluidsynth.h>

using namespace std;

namespace Fluidsynth {
    class Settings {
        private:
            fluid_settings_t *settings;

            static void _settings_foreach(void *data, const char *name, int type);
            static char *_get_setting_str(fluid_settings_t *settings, const char *name, int type);
        public:
            Settings();
            ~Settings();

            fluid_settings_t *getFluidSettings();

            fluid_types_enum getSettingType(const char *setting);

            map<string, char *> getSettings();
            char *getSettings(const char *setting);
            void setSettings(const char *setting, const char *value);
    };
}

#endif
