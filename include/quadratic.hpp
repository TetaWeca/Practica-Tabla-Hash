
#pragma once
#include "explore.hpp"

template <class Clave>

class quadratic : public explore<Clave>
{
   int operator()(const Clave&, int i)
    {
        return i*i;
    }
};