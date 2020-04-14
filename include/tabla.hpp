
#pragma once

#include "celda.hpp"
#include "hash.hpp"
#include "explore.hpp"
#include <iostream>

template <class Clave>

class HashMap
{
    protected:
        
        std::vector<cell<Clave>*> map;     
        hash* hash;
        explore* exploration;
    
    public:

        HashMap(int tamMap, int tamCell, int hashtype, int explorationtype):

         {};

        bool search(Clave x);

        bool insert(Clave x);

};
