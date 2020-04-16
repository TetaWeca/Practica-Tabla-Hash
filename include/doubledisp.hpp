
#pragma once
#include "explore.hpp"
#include "addition.hpp"

template <class Clave>

class doublehash : public explore<Clave>
{
   int operator()(const Clave& clave, int i)
    {
        addition<Clave> suma;
        return i*suma(clave);
    }
};