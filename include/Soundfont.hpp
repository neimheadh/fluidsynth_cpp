#ifndef FLUIDSYNTH_SOUNDFONT_HPP
#define FLUIDSYNTH_SOUNDFONT_HPP

namespace Fluidsynth {
    class Soundfont {
        private:
            const char *file;
            unsigned short offset;

        public:
            Soundfont(const char *file);
            Soundfont(const char *file, unsigned short offset);
            ~Soundfont();

            const char *getFile();
            unsigned short getOffset();

            void setFile(const char *file);
            void setOffset(unsigned short offset);
    };
}

#endif
