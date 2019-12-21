#ifndef FLUIDSYNTH_SYNTH_H
#define FLUIDSYNTH_SYNTH_H

#include <map>
#include <string>

#include "Chorus.hpp"
#include "Reverb.hpp"
#include "Soundfont.hpp"
#include "SynthControlInterface.hpp"

using namespace std;

namespace Fluidsynth {
    class Synth {
        private:
            bool active;
            Chorus chorus;
            Reverb reverb;
            map<string, string> settings;
            map<unsigned short, const Soundfont *> soundfonts;
            unsigned short volume;

        public:
            void control(SynthControlInterface control);

            Chorus &getChorus();
            Reverb &getReverb();
            map<string, string> getSettings();
            string getSettings(string name);
            map<unsigned short, const Soundfont *> getSoundfonts();
            const Soundfont *getSoundfonts(unsigned short fid);
            unsigned short getVolume();

            bool isActive();

            void panic();
            void raz();

            void setChorus(Chorus chorus);
            void setReverb(Reverb reverb);
            void setSettings(map<string, string> settings, bool replace = false);
            void setSettings(string name, string value);
            void setSoundfonts(map<unsigned short, const Soundfont *> soundfonts, bool replace = false);
            void setSoundfonts(unsigned short fid, const Soundfont *soundfont);
            void setVolume(unsigned short volume);

            void start();
            void stop();
    };
}

#endif
