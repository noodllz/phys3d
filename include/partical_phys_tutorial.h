#ifndef PARTICAL_PHYS_TUTORIAL_H
#define PARTICAL_PHYS_TUTORIAL_H

#include <tuple>
#include <vector>

namespace p_phys{
    #define NUM_PARTICLES 1
    #define X_DIR 0
    #define Y_DIR 1
    #define X_DIM_MAX 100
    #define Y_DIM_MAX 100

    typedef struct {
            std::tuple<float,float> position;
            std::tuple<float,float> velocity;
            float mass;
        } Particle2;

    class PartPhysTutorial {
        private: Particle2 particles[NUM_PARTICLES];

        private: Particle2* get_particles(int index);
        private: Particle2* get_particles();
        private: void print_particles();
        private: void initialise_particles();
        private: void compute_force(Particle2* particle);
        public: void simulate();
    };
} // namespace p_phys

#endif /* PARTICAL_PHYS_TUTORIAL_H */