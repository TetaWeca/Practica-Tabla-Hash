
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
        hash* hash;
        explore* exploration;
    
    public:

        hashmap(int tamMap, int tamCell, int hashtype, int explorationtype);
        
        bool search(Clave x);

        bool insert(Clave x);

};


template <class tuvi>
hashmap<tuvi>::hashmap(int tamMap, int tamCell, int hashtype, int explorationtype):
map(tamMap)
{
    {
        for (int i = 0; i<tamMap; i++)
        {
            map[i]=new cell(tamCell); 
        }
        switch(hashtype)
        {
            case Module:
                //Fallas el 100% de los tiros que no tiras
                hash = new modulo;
                break;

            case Addition:
                //Cada día es una nueva oportunidad para cambiar tu vida
                hash = new addition;
                break;

            case PseudoRandom:
                //Ningún mar en calma hizo experto a un marinero
                hash = new pseudorand;
                break;
        }
        switch (explorationtype)
        {
            case TiposExploracion::Lineal:
                //Tu mejor profesor es tu mayor error
                exploration = new lineal;
                break;

            case TiposExploracion::Quadratic:
                //Cuando te das cuenta que estás procrastinando preguntate: ¿ Dé qué estoy intentando huir?
                exploration = new quadratic;
                break;

            case TiposExploracion::DoubleHashing:
                //Intenta ser un Arco iris en el día nublado de alguien
                exploration = new doublehash;
                break;

            case TiposExploracion::Rehashing:
                //Queda terminantemente prohibido levantarse sin ilusiones
                exploration = new rehash;
                break;
        }
    }
}

template <class Clave>
bool hashmap<Clave>::search(Clave x)
{
    unsigned index = (*hash)(x)%map.size();

    if(map[index]->search(x))
    {
        return true;
    }
    return false;
}

template <class Clave>
bool hashmap<Clave>::insert(Clave x)
{
    for(int i=0;i<map.size();i++)
    {
        unsigned index = (*hash)(x)+(*exploration)(x,i)%map.size();

        try
        {
            map[index]->insert(x)
            return true;
        }
        catch(const Myexception& e){}    
    }
    return false;
}
