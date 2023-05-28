#include <cstdlib>
#include "partical_phys_tutorial.h"

namespace p_phys
{
    Particle2* PartPhysTutorial::get_particles(){
        return particles;
    }

    Particle2* PartPhysTutorial::get_particles(int index){
        return &particles[index];
    }

    void PartPhysTutorial::print_particles(){
        for (int i = 0; i < NUM_PARTICLES; i++) {
            Particle2 *particle = &particles[i];
            printf("particle[%i] (%.2f, %.2f)\n", i, 
                                                  std::get<X_DIR>(particle->position),
                                                  std::get<Y_DIR>(particle->position));
        }
    }

    void PartPhysTutorial::initialise_particles(){
        for(int i = 0; i < NUM_PARTICLES; i++) {
            particles[i].position = std::tuple<float,float>(rand()%X_DIM_MAX,rand()%Y_DIM_MAX);
            particles[i].velocity = std::tuple<float,float>(0,0);
            particles[i].mass = 1;
        }
    }

    std::tuple<float,float> PartPhysTutorial::compute_gravity(Particle2* particle){
        return std::tuple<float,float>(0, particle->mass * -9.81)
    }

    void PartPhysTutorial::simulate(){
        int TotalSimTime =10;
        int CurrTime = 0;
        int StepTime = 1;

        initialise_particles();
        print_particles();

        while (CurrTime < TotalSimTime) 
        {
            for (int i = 0; i < NUM_PARTICLES; i++)
            {
                Particle2 *particle = &particles[i];
                std::tuple<float,float> force = compute_gravity(particle);
                std::tuple<float,float> acceleration(force[X_DIR]/particle->mass, force[Y_DIR]/particle->mass);
                particle->velocity[X_DIR] += acceleration[X_DIR] * StepTime;
                particle->velocity[Y_DIR] += acceleration[Y_DIR] * StepTime;
                particle->position[X_DIR] += particle->velocity[X_DIR] * StepTime;
                particle->position[Y_DIR] += particle->velocity[Y_DIR] * StepTime;
            }

            print_particles()
            CurrTime += StepTime;
        }
    }

} // namespace p_phys
