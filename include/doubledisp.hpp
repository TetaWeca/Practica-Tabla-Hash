
#pragma once
#include "explore.hpp"
#include "addition.hpp"

template <class Clave>

class doublehash : public explore
{
    operator()(const Clave&, int i)
    {
        addition A;
        return i*A(Clave);
    }
};