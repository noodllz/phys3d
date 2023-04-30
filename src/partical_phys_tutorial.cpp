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
                                                  std::get<DIM_X>(particle->position),
                                                  std::get<DIM_Y>(particle->position));
        }
    }

} // namespace p_phys
