#include "exceptions/SynthException.hpp"

using namespace Fluidsynth;

SynthException::SynthException(const char *msg) {
    this->msg = msg;
}

const char *SynthException::what() const throw() {
    return msg;
}
