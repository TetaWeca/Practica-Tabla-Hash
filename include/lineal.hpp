
#pragma once
#include "explore.hpp"

template <class Clave>

class lineal : public explore
{
    operator()(const Clave&, int i)
    {
        return i;
    }
};