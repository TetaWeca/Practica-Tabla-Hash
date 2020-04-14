
#pragma once

template<class Clave>

class hash
{

public:

    virtual int operator()(const Clave&)=0;

};