
#pragma once

#include "hash.hpp"
#include <random>

template <class Clave>

class pseudorand : public hash
{
    int operator()(const Clave&)
    {
        srand(Clave);
        return rand();
    }
};