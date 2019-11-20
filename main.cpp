#include <iostream>

#include "Settlement.hpp"

int main()
{
    Settlement liege;

    for(int i = 0; i < 20; ++i)
    {
        liege.Update();
        liege.Print();
        std::cout<<"\n";
    }

    return 0;
}