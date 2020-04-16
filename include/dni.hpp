
#include <stdlib.h> 

class DNI 
{
    private:

        unsigned long numero;

    public:

        DNI():
        numero(rand()%100000000) {};

    //  operator unsigned long(const DNI&);

    friend bool operator==(const DNI&,const DNI&);
};

