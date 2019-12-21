#ifndef FLUIDSYNTH_SOUNDFONT_HPP
#define FLUIDSYNTH_SOUNDFONT_HPP

#include <stdio.h>

namespace Fluidsynth {
    class Soundfont {
        private:
            const FILE *file;
            unsigned short offset;

        public:
            Soundfont(const FILE *file);
            Soundfont(const FILE *file, unsigned short offset);
            ~Soundfont();

            const FILE *getFile();
            unsigned short getOffset();

            void setFile(const FILE *file);
            void setOffset(unsigned short offset);
    };
}

#endif
