
#pragma once

template <class Clave>

class explore 
{
    virtual int operator()(const Clave&, int i)=0;
};