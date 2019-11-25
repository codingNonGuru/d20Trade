#include <iostream>

#include "Settlement.hpp"

int main()
{
    Settlement liege(100);

    for(int i = 0; i < 500; ++i)
    {
        liege.Update();
        std::cout<<"\n";
    }

    return 0;
}