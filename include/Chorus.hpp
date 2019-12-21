#ifndef FLUIDSYNTH_CHORUS_HPP
#define FLUIDSYNTH_CHORUS_HPP

namespace Fluidsynth {
    enum ChorusType {Sine, Square, Triangle};

    class Chorus {
        private:
            bool active;
            unsigned char delay;
            unsigned char depth;
            unsigned char level;
            unsigned short speed;
            ChorusType type;

        public:
            void disable();
            void enable();

            unsigned char getDelay();
            unsigned char getDepth();
            unsigned char getLevel();
            unsigned short getSpeed();
            ChorusType getType();

            bool isActive();

            void setDelay(unsigned char delay);
            void setDepth(unsigned char depth);
            void setLevel(unsigned char level);
            void setSpeed(unsigned short speed);
            void setType(ChorusType type);
    };
}

#endif
