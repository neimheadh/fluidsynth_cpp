#ifndef FLUIDSYNTH_SETTINGS_EXCEPTION_HPP
#define FLUIDSYNTH_SETTINGS_EXCEPTION_HPP

#include "exceptions/Exception.hpp"

using namespace std;

namespace Fluidsynth {
    class SettingsException : public Exception {
        public:
            SettingsException(const char *msg = "Undefined settings exception");
    };
}

#endif
