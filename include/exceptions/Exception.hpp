#ifndef FLUIDSYNTH_EXCEPTION_HPP
#define FLUIDSYNTH_EXCEPTION_HPP

#include <exception>

using namespace std;

namespace Fluidsynth {
    class Exception : public exception {
        protected:
            const char *msg;

        public:
            Exception(const char *msg = "Undefined exception");
            const char *what() const throw();
    };
}

#endif
