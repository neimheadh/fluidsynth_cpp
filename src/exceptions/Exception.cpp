#include "exceptions/Exception.hpp"

using namespace Fluidsynth;

Exception::Exception(const char *msg) {
    this->msg = msg;
}

const char * Exception::what() const throw() {
    return msg;
}
