#include <iostream>
#include <cstdlib>

#include "env.hpp"
#include "test.hpp"
#include "Synth.hpp"

using namespace std;
using namespace Fluidsynth;

int main() {
    Synth synth;
    cout << C_INFO << "Test synth - Simple note" << C_END << endl;

    synth.setSoundfonts(1, new Soundfont(SF2_FILE));

    cout << C_INFO2 << "- Start synth" << C_END << endl;
    synth.start();

    cout << C_INFO2 << "- Stop synth" << C_END << endl;
    synth.stop();

    return 0;
}
