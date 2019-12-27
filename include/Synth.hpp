#ifndef FLUIDSYNTH_SYNTH_H
#define FLUIDSYNTH_SYNTH_H

#include <cstddef>
#include <map>
#include <string>
#include <fluidsynth.h>

#include "Chorus.hpp"
#include "Reverb.hpp"
#include "Settings.hpp"
#include "Soundfont.hpp"
#include "SynthControlInterface.hpp"

using namespace std;

namespace Fluidsynth {
    class Synth {
        private:
            bool active;
            Chorus chorus;
            bool own_settings;
            Reverb reverb;
            Settings *settings;
            map<unsigned short, Soundfont *> soundfonts;
            fluid_synth_t *synth;
            unsigned short volume;

            void _init_fluid_synth();

        public:
            Synth();
            Synth(Settings *settings);
            ~Synth();

            void control(SynthControlInterface control);

            Chorus &getChorus();
            fluid_synth_t *getFluidSynth();
            Reverb &getReverb();
            const Settings *getSettings();
            map<unsigned short, const Soundfont *> getSoundfonts();
            const Soundfont *getSoundfonts(unsigned short fid);
            unsigned short getVolume();

            bool isActive();

            void panic();
            void raz();

            void setChorus(Chorus chorus);
            void setReverb(Reverb reverb);
            void setSettings(Settings *settings);
            void setSoundfonts(map<unsigned short, Soundfont *> soundfonts, bool replace = false);
            void setSoundfonts(unsigned short fid, Soundfont *soundfont);
            void setVolume(unsigned short volume);

            void start();
            void stop();
    };
}

#endif
