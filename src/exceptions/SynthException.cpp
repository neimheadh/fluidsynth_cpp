#include "exceptions/SynthException.hpp"

using namespace Fluidsynth;

SynthException::SynthException(const char *msg): Exception(msg) {}
