
#pragma once

template <class Clave>

class explore 
{
    public:

    virtual int operator()(const Clave& clave, int i)=0;
};