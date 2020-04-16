
#include <stdlib.h> 
#include <iostream>

class Matricula     
{
    private:

        unsigned long numero;
        char letras[3];
        static int contador;

    public:

        Matricula():
        numero(rand()%10000) 
        {
            for (int i = 0; i < 3; i++)
            {
                letras[i]='A'+rand()%26;
            }
        };

    operator unsigned long() const;

    static int getCounter();

    static void resetCounter();

    static void incrementCounter();

    friend bool operator==(const Matricula& A,const Matricula& B);
};

