
#pragma once

#include "celda.hpp"
#include "module.hpp"
#include "addition.hpp"
#include "pseudorand.hpp"
#include "lineal.hpp"
#include "quadratic.hpp"
#include "doubledisp.hpp"
#include "redisp.hpp"

#include <iostream>

enum TiposHash
{
    Module,
    Addition,
    PseudoRandom
};

enum TiposExploracion
{
    Lineal,
    Quadratic,
    DoubleHashing,
    Rehashing
};

template <class Clave>

class hashmap
{
    protected:
        
        std::vector<cell<Clave>*> map;     
        hash<Clave>* hash_;
        explore<Clave>* exploration;
    
    public:

        hashmap(int tamMap, int tamCell, int hashtype, int explorationtype);
        
        bool search(Clave x);

        bool insert(Clave x);

};


template <class Clave>
hashmap<Clave>::hashmap(int tamMap, int tamCell, int hashtype, int explorationtype):
map(tamMap)
{
    {
        for (int i = 0; i<tamMap; i++)
        {
            map[i] = new cell<Clave>(tamCell); 
        }
        switch(hashtype)
        {
            case Module:
                hash_ = new modulo<Clave>;
                break;

            case Addition:
                hash_ = new addition<Clave>;
                break;

            case PseudoRandom:
                hash_ = new pseudorand<Clave>;
                break;
        }
        switch (explorationtype)
        {
            case TiposExploracion::Lineal:
                exploration = new lineal<Clave>;
                break;

            case TiposExploracion::Quadratic:
                exploration = new quadratic<Clave>;
                break;

            case TiposExploracion::DoubleHashing:
                exploration = new doublehash<Clave>;
                break;

            case TiposExploracion::Rehashing:
                exploration = new rehash<Clave>;
                break;
        }
    }
}

template <class Clave>
bool hashmap<Clave>::search(Clave x)
{
    for(int i=0;i<map.size();i++)
    {
        unsigned index = ((*hash_)(x)+(*exploration)(x,i))%map.size();
        if(map[index]->search(x))
        {
            return true;
        }
        if(!map[index]->isFull())
        {
            return false;
        }
    }
        return false;
}

template <class Clave>
bool hashmap<Clave>::insert(Clave x)
{
    for(int i=0;i<map.size();i++)
    {
        unsigned index = ((*hash_)(x)+(*exploration)(x,i))%map.size();

        try
        {
            map[index]->insert(x);
            return true;
        }
        catch(const Myexception& e){}    
    }
    return false;
}
