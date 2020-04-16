
#pragma once

#include "hash.hpp"

template <class Clave>

class modulo : public hash<Clave>
{
    int operator()(const Clave& clave)
    {
        return clave;
    }
};