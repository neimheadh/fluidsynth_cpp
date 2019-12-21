#include "Soundfont.hpp"

using namespace Fluidsynth;

Soundfont::Soundfont(const char *file) {
    this->file = file;
    this->offset = 0;
}

Soundfont::Soundfont(const char *file, unsigned short offset) {
    this->file = file;
    this->offset = offset;
}

Soundfont::~Soundfont() {

}

const char *Soundfont::getFile() {
    return file;
}

unsigned short Soundfont::getOffset() {
    return offset;
}

void Soundfont::setFile(const char *file) {
    this->file = file;
}

void Soundfont::setOffset(unsigned short offset) {
    this->offset = offset;
}
