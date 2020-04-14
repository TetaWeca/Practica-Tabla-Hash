
#pragma once

#include "hash.hpp"

template <class Clave>

class addition : public hash
{
    int operator()(const Clave&)
    {
        int d = 0;
        int x = Clave;
        int y = 0;
        while (x > 0)
        {
            y = x % 10;
            d = d + y;
            x = x/10;
        }
    return d;
    }
};