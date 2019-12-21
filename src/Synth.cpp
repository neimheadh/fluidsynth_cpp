#include "Synth.hpp"

using namespace std;
using namespace Fluidsynth;

Synth::Synth() {
    own_settings = true;
    settings = new Settings();
    synth = NULL;
}

Synth::Synth(Settings *settings) {
    own_settings = false;
    this->settings = settings;
    synth = NULL;
}

Synth::~Synth() {
    if (active) {
        stop();
    }

    if (own_settings) {
        delete settings;
    }
}

void Synth::control(SynthControlInterface) {
    // @TODO
}

Chorus &Synth::getChorus() {
    return chorus;
}

Reverb &Synth::getReverb() {
    return reverb;
}

const Settings *Synth::getSettings() {
    return settings;
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

void Synth::setSettings(Settings *settings) {
    if (own_settings) {
        delete this->settings;
    }
    own_settings = false;
    this->settings = settings;
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
    synth = settings->getFluidSynth();
    // @TODO
}

void Synth::stop() {
    active = false;
    delete_fluid_synth(synth);
    synth = NULL;
    // @TODO
}
