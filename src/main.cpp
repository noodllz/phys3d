#include "main.h"

#include <iostream>

int main(){
    std::cout << "Hello World!";
    p_phys::PartPhysTutorial instance = p_phys::PartPhysTutorial();
    instance.simulate();
    return 0;
}