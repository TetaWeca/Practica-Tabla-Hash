
#pragma once

#include "hash.hpp"

template <class Clave>

class modulo : public hash
{
    int operator()(const Clave&)
    {
        return Clave;
    }
};