#ifndef FLUIDSYNTH_REVERB_HPP
#define FLUIDSYNTH_REVERB_HPP

namespace Fluidsynth {
    class Reverb {
        private:
            bool active;
            unsigned char damp;
            unsigned char level;
            unsigned char room;
            unsigned char width;

        public:
            void disable();
            void enable();

            unsigned char getDamp();
            unsigned char getLevel();
            unsigned char getRoom();
            unsigned char getWidth();

            bool isActive();

            void setDamp(unsigned char);
            void setLevel(unsigned char);
            void setRoom(unsigned char);
            void setWidth(unsigned char);
    };
}

#endif
