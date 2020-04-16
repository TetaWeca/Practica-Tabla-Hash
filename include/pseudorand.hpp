
#pragma once

#include "hash.hpp"
#include <random>

template <class Clave>

class pseudorand : public hash<Clave>
{
    int operator()(const Clave& clave)
    {
        srand(clave);
        return rand();
    }
};