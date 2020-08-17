#include "sample_A2.h"
#include <iostream>

sample_A::sample_A(int a, int b)
{
    std::cout << "sample_A" << (a+b) <<std::endl;
}

void sample_A::echo()
{
    std::cout << "sample_A : echo" << std::endl;
}