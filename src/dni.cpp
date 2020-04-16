
#include "../include/dni.hpp"

int DNI::getCounter()
{
    return contador;
}

void DNI::resetCounter()
{
    contador = 0;
}

void DNI::incrementCounter()
{
    contador = contador+1;
}
bool operator==(const DNI& A,const DNI& B)
{
    DNI::incrementCounter();
    return A.numero==B.numero;
}