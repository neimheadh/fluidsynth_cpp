#include "Synth.hpp"

using namespace std;
using namespace Fluidsynth;

void Synth::control(SynthControlInterface) {
    // @TODO
}

Chorus &Synth::getChorus() {
    return chorus;
}

Reverb &Synth::getReverb() {
    return reverb;
}

map<string, string> Synth::getSettings() {
    return settings;
}

string Synth::getSettings(string name) {
    return settings[name];
}

map<unsigned short, const Soundfont *> Synth::getSoundfonts() {
    return soundfonts;
}

const Soundfont *Synth::getSoundfonts(unsigned short fid) {
    return soundfonts[fid];
}

unsigned short Synth::getVolume() {
    return volume;
}

bool Synth::isActive() {
    return active;
}

void Synth::panic() {
    // @TODO
}

void Synth::raz() {
    // @TODO
}

void Synth::setSettings(map<string, string> settings, bool replace) {
    if (replace) {
        this->settings = settings;
    } else {
        for(auto &it : settings) {
            this->settings[it.first] = it.second;
        }
    }
}

void Synth::setSettings(string name, string value) {
    this->settings[name] = value;
}

void Synth::setSoundfonts(map<unsigned short, const Soundfont *> soundfonts, bool replace) {
    if (replace) {
        this->soundfonts = soundfonts;
    } else {
        for(auto &it : soundfonts) {
            this->soundfonts[it.first] = it.second;
        }
    }
}

void Synth::setSoundfonts(unsigned short fid, const Soundfont *soundfont) {
    this->soundfonts[fid] = soundfont;
}

void Synth::start() {
    active = true;
    // @TODO
}

void Synth::stop() {
    active = false;
    // @TODO
}
