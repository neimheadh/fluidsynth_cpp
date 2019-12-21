#include "exceptions/SettingsException.hpp"

using namespace Fluidsynth;

SettingsException::SettingsException(const char *msg) {
    this->msg = msg;
}

const char *SettingsException::what() const throw() {
    return msg;
}
