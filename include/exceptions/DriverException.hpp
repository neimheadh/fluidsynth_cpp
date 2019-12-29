#ifndef FLUIDSYNTH_DRIVER_EXCEPTION_HPP
#define FLUIDSYNTH_DRIVER_EXCEPTION_HPP

#include "exceptions/Exception.hpp"

namespace Fluidsynth {
    class DriverException : public Exception {
        public:
            DriverException(const char *msg = "Undefined driver exception");
    };
}

#endif
