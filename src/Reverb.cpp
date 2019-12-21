#include "Reverb.hpp"

using namespace Fluidsynth;

void Reverb::disable() {
    active = false;
}

void Reverb::enable() {
    active = true;
}

unsigned char Reverb::getDamp() {
    return damp;
}

unsigned char Reverb::getLevel() {
    return level;
}

unsigned char Reverb::getRoom() {
    return room;
}

unsigned char Reverb::getWidth() {
    return width;
}

bool Reverb::isActive() {
    return active;
}

void Reverb::setDamp(unsigned char damp) {
   this->damp = damp;
}

void Reverb::setLevel(unsigned char level) {
    this->level = level;
}

void Reverb::setRoom(unsigned char room) {
    this->room = room;
}

void Reverb::setWidth(unsigned char width) {
    this->width = width;
}
