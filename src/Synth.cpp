#include <cstring>

#include "Synth.hpp"
#include "exceptions/SynthException.hpp"

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
    map<unsigned short, const Soundfont *> usf;

    for(auto &it : soundfonts) {
        usf[it.first] = it.second;
    }

    return usf;
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

void Synth::setSoundfonts(map<unsigned short, Soundfont *> soundfonts, bool replace) {
    if (replace) {
        this->soundfonts = soundfonts;
    } else {
        for(auto &it : soundfonts) {
            this->soundfonts[it.first] = it.second;
        }
    }
}

void Synth::setSoundfonts(unsigned short fid, Soundfont *soundfont) {
    this->soundfonts[fid] = soundfont;
}

void Synth::start() {
    char *buf;

    active = true;
    synth = settings->getFluidSynth();

    if (!synth) {
        throw new SynthException("Failed to create fluid synthesizer");
    }

    for (auto &it : soundfonts) {
        if (!fluid_synth_sfload(synth, it.second->getFile(), it.first)) {
            buf = new char[50 + strlen(it.second->getFile())];
            sprintf(buf, "Failed to load the soundfont #%d '%s'", it.first, it.second->getFile());
            throw new SynthException(buf);
        }
    }
    // @TODO
}

void Synth::stop() {
    active = false;
    delete_fluid_synth(synth);
    synth = NULL;
    // @TODO
}
