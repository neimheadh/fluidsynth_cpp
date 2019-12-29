#ifndef FLUIDSYNTH_SYNTH_EXCEPTION_HPP
#define FLUIDSYNTH_SYNTH_EXCEPTION_HPP

#include "exceptions/Exception.hpp"

using namespace std;

namespace Fluidsynth {
    class SynthException : public Exception {
        public:
            SynthException(const char *msg = "Undefined synth exception");
    };
}

#endif
