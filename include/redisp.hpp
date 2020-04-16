
#pragma once
#include "explore.hpp"
#include <random>

template <class Clave>

class rehash : public explore<Clave>
{
    int operator()(const Clave& clave, int i)
    {
        srand(clave);
        for(int x=0; x <=i; x++)
        {
            if (x == i)
            {
                return rand();
            }
            rand();
        }
        return 0;
    }
};