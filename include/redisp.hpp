
#pragma once
#include "explore.hpp"
#include <random>

template <class Clave>

class rehash : public explore
{
    operator()(const Clave&, int i)
    {
        srand(Clave)
        for(int x=0; x <=i; x++)
        {
            if (x == i)
            {
                return rand();
            }
            rand();
        }
    }
};