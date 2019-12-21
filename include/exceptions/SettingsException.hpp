#ifndef FLUIDSYNTH_SETTINGS_EXCEPTION_HPP
#define FLUIDSYNTH_SETTINGS_EXCEPTION_HPP

#include <exception>

using namespace std;

namespace Fluidsynth {
    class SettingsException : public exception {
        private:
            const char *msg;

        public:
            SettingsException(const char *msg = "Undefined settings exception");
            const char *what() const throw ();
    };
}

#endif
