#include "Chorus.hpp"

using namespace Fluidsynth;

void Chorus::disable() {
    active = false;
}

void Chorus::enable() {
    active = true;
}

unsigned char Chorus::getDelay() {
    return delay;
}

unsigned char Chorus::getDepth() {
    return depth;
}

unsigned char Chorus::getLevel() {
    return level;
}

unsigned short Chorus::getSpeed() {
    return speed;
}

ChorusType Chorus::getType() {
    return type;
}

bool Chorus::isActive() {
    return active;
}

void Chorus::setDelay(unsigned char delay) {
    this->delay = delay;
}

void Chorus::setDepth(unsigned char depth) {
    this->depth = depth;
}

void Chorus::setLevel(unsigned char level) {
    this->level = level;
}

void Chorus::setSpeed(unsigned short speed) {
    this->speed = speed;
}

void Chorus::setType(ChorusType type) {
    this->type = type;
}
