
#include <stdlib.h> 

class DNI 
{
    private:

        unsigned long numero;
        static int contador;

    public:

        DNI():
        numero(rand()%100000000) {};

    operator unsigned long() const;

    static int getCounter();

    static void resetCounter();

    static void incrementCounter();

    friend bool operator==(const DNI&,const DNI&);
};

