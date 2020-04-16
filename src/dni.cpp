
#include "../include/dni.hpp"
#include <iostream>

int Matricula::contador = 0;

int Matricula::getCounter()
{
    return contador;
}

void Matricula::resetCounter()
{
    contador = 0;
}

void Matricula::incrementCounter()
{
    contador = contador+1;
}
bool operator==(const Matricula& A,const Matricula& B)
{
    Matricula::incrementCounter();
    // std::cout<< A.numero << "==" << B.numero << std::endl;
    return A.numero==B.numero;
}

Matricula::operator unsigned long() const
{
    unsigned long valor=numero;
    for(int i = 0; i<3;i++)
    {
        valor = (valor*100)+(letras[i]-'A');
    }
    return valor;
}