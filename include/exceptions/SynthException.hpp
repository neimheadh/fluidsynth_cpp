#ifndef FLUIDSYNTH_SYNTH_EXCEPTION_HPP
#define FLUIDSYNTH_SYNTH_EXCEPTION_HPP

#include <exception>

using namespace std;

namespace Fluidsynth {
    class SynthException : public exception {
        private:
            const char *msg;

        public:
            SynthException(const char *msg = "Undefined synth exception");
            const char *what() const throw ();
    };
}

#endif
