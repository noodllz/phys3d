#ifndef PARTICAL_PHYS_TUTORIAL_H
#define PARTICAL_PHYS_TUTORIAL_H

#include <tuple>
#include <vector>

namespace p_phys{
    #define NUM_PARTICLES 1
    #define DIM_X 0
    #define DIM_Y 1

    typedef struct {
            std::tuple<float,float> position;
            std::tuple<float,float> velocity;
            float mass;
        } Particle2;

    class PartPhysTutorial {
        private: Particle2 particles[NUM_PARTICLES];

        public: Particle2* get_particles(int index);
        public: Particle2* get_particles();
        public: void print_particles();
        
    };
} // namespace p_phys

#endif /* PARTICAL_PHYS_TUTORIAL_H */