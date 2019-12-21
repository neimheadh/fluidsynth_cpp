#include "Soundfont.hpp"

using namespace Fluidsynth;

Soundfont::Soundfont(const FILE *file) {
    this->file = file;
}

Soundfont::Soundfont(const FILE *file, unsigned short offset) {
    this->file = file;
    this->offset = offset;
}

const FILE *Soundfont::getFile() {
    return file;
}

unsigned short Soundfont::getOffset() {
    return offset;
}

void Soundfont::setFile(const FILE *file) {
    this->file = file;
}

void Soundfont::setOffset(unsigned short offset) {
    this->offset = offset;
}
