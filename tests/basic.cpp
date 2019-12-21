#include <iostream>
#include <assert.h>
#include <stdio.h>

#include "test.hpp"

#include "Chorus.hpp"
#include "Reverb.hpp"
#include "Soundfont.hpp"
#include "Synth.hpp"

using namespace std;
using namespace Fluidsynth;

void test_implements() {
    Chorus *chorus;
    Reverb *reverb;
    Soundfont *soundfont;
    Synth *synth;

    FILE *nFile = fopen("assets/file.sf2", "r");

    cout << C_INFO << "Test classes implementations" << C_END << endl;

    cout << C_INFO2 << "- Chorus" << C_END << endl;
    chorus = new Chorus();
    delete chorus;

    cout << C_INFO2 << "- Reverb" << C_END << endl;
    reverb = new Reverb();
    delete reverb;

    cout << C_INFO2 << "- Soundfont" << C_END << endl;
    soundfont = new Soundfont(nFile);
    assert(soundfont->getFile() == nFile);
    assert(soundfont->getOffset() == 0);
    delete soundfont;
    soundfont = new Soundfont(nFile, 9);
    assert(soundfont->getFile() == nFile);
    assert(soundfont->getOffset() == 9);
    delete soundfont;


    cout << C_INFO2 << "- Synth" << C_END << endl;
    synth = new Synth();
    delete synth;
}

int main() {
    test_implements();

    return 0;
}
