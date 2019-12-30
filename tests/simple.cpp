#include <iostream>
#include <cstdlib>
#include <unistd.h>    /* usleep */

#include "env.hpp"
#include "test.hpp"
#include "Synth.hpp"
#include "exceptions/Exception.hpp"

using namespace std;
using namespace Fluidsynth;

int main() {
    try {
        Synth synth;
        cout << C_INFO << "Test synth - Simple note" << C_END << endl;

        synth.setSoundfonts(1, new Soundfont(SF2_FILE));
        synth.getSettings()->setSettings("audio.driver", SETTING_AUDIO_DRIVER);

        cout << C_INFO2 << "- Start synth" << C_END << endl;
        synth.start();

        cout << C_INFO2 << "- Play note" << C_END << endl;
        synth.play(60);
        usleep(3000000);

        cout << C_INFO2 << "- Stop synth" << C_END << endl;
        synth.stop();
    } catch (Exception *e) {
        cerr << C_ERR << e->what() << C_END << endl;
        return 1;
    }

    return 0;
}
