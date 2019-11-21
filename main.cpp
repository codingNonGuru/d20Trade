#include <iostream>

#include "Settlement.hpp"

int main()
{
    Settlement liege(100);

    for(int i = 0; i < 20; ++i)
    {
        liege.Update();
    }

    return 0;
}