#include <iostream>
#include <cstring>
#include <cassert>
#include <string>

#include "env.hpp"
#include "test.hpp"
#include "Synth.hpp"

using namespace std;
using namespace Fluidsynth;

int main() {
    Synth synth;
    Settings *settings = synth.getSettings();

    cout << C_INFO << "Test fluid settings" << C_END << endl;

    cout << C_INFO2 << "- List settings" << C_END << endl;
    map<string, char *> smap = settings->getSettings();
    assert(smap.size() > 10);
    assert(smap.find("audio.driver") != smap.end());
    assert(strcmp(smap["audio.driver"], "jack") == 0);

    cout << C_INFO2 << "- Get setting" << C_END << endl;
    assert(strcmp(settings->getSettings("audio.driver"), "jack") == 0);

    cout << C_INFO2 << "- Set setting" << C_END << endl;
    settings->setSettings("audio.driver", "alsa");
    assert(strcmp(settings->getSettings("audio.driver"), "alsa") == 0);


    return 0;
}
