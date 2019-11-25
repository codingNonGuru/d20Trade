#include <iostream>

#include "Settlement.hpp"

int main()
{
    Settlement liege(100);

    for(int i = 0; i < 1000; ++i)
    {
        liege.Update();
        if(i % 10 == 0)
        {
            liege.Print();
        }
    }

    return 0;
}