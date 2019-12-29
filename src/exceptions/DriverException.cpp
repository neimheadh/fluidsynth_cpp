#include "exceptions/DriverException.hpp"

using namespace Fluidsynth;

DriverException::DriverException(const char *msg): Exception(msg) {}
