
#pragma once

#include <iostream>
#include <vector>
#include <exception>

struct Myexception : public std::exception
{
	const char * what () const throw ()
    {
    	return "C++ Exception";
    }
};

template <class Clave>

class cell 
{
protected:

    int cellsize;
    std::vector<Clave> vCell;

public:

    cell(int tam):
    cellsize(tam) {};

    bool search(const Clave& x) const;

    void insert(Clave& x);

    bool isFull();
};

template <class Clave>
bool cell<Clave>::search(const Clave& x)const
{
    for (int i=0; i < vCell.size(); i++)
    {
        if (vCell.at[i] == x)
        {
            return true;
        }
    }
    return false;
}

template <class Clave>
void cell<Clave>::insert(Clave& x)
{
    if (isFull() == true)
    {
        throw Myexception();
    }
    vCell.push_back(x)
}

template <class Clave>
bool cell<Clave>::isFull()
{
    if (vCell.size()==cellsize)
    {
        return true;
    }
    return false;
}
