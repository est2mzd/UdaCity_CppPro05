#include "sample_B2.h"
#include <iostream>

sample_B::sample_B() : obj_A(1,2)
{
    std::cout << "sample B" << std::endl;
}

void sample_B::echo()
{
    std::cout << "sample_B : echo" << std::endl;
}