
#include "../include/tabla.hpp"
#include "../include/module.hpp"
#include "../include/addition.hpp"
#include "../include/pseudorand.hpp"
#include "../include/lineal.hpp"
#include "../include/quadratic.hpp"
#include "../include/doubledisp.hpp"
#include "../include/redisp.hpp"
#include "../include/dni.hpp"

#include <iostream>
#include <string>

int main(void)
{
    int nCeldas,tamCelda,fDispersion,fExploracion,fLoad,nPruebas;
    std::string input;

    while(true)
    {
        std::cout << "TamTabla";
        std::getline(std::cin,input); 
        
        try
        {
            nCeldas = std::stoi(input);
        }
        catch(const std::invalid_argument const &e)
        {
            std::cout << "Argumento inválido, pruebe de nuevo";
            continue;
        }
        if(nCeldas>=1) 
        {
            break;
        }
        else 
        {
            std::cout << "El número de celdas debe de ser mayor que 0";
        }
    }
    while(true)
    {
        std::cout << "TamCelda";
        std::getline(std::cin,input); 
        
        try
        {
            tamCelda = std::stoi(input);
        }
        catch(const std::invalid_argument const &e)
        {
            std::cout << "Argumento inválido, pruebe de nuevo";
            continue;
        }
        if(tamCelda>=1)
        {
            break;
        }
        else
        {
            std::cout << "El tamaño de celda debe ser mayor que 0";
        }           
    }
    while(true)
    {
        std::cout << "Función de dispersión: ";
        std::getline(std::cin,input); 
        
        try
        {
            fDispersion = std::stoi(input);
            break;
        }
        catch(const std::invalid_argument const &e)
        {
            std::cout << "Argumento inválido, pruebe de nuevo";
        }
        if (fDispersion >= 0 && fDispersion <= 2)
        {
            break;
        }
        else
        {
            std::cout << "El valor de la función de dispersión debe estar entre 0 y 2";
        }                    
    }
    while(true)
    {
        std::cout << "Función de exploración";
        std::getline(std::cin,input); 
        
        try
        {
            fExploracion = std::stoi(input);
            break;
        }
        catch(const std::invalid_argument const &e)
        {
            std::cout << "Argumento inválido, pruebe de nuevo";
        }
        if (fExploracion >= 0 && fExploracion <= 3)
        {
            break;
        }
        else
        {
            std::cout << "El valor de la función de dispersión debe estar entre 0 y 3";
        }        
    }
    while(true)
    {
        std::cout << "Factor de carga";
        std::getline(std::cin,input); 
        
        try
        {
            fLoad = std::stof(input);
            break;
        }
        catch(const std::invalid_argument const &e)
        {
            std::cout << "Argumento inválido, pruebe de nuevo";
        }
        if (fLoad >= 0 && fLoad <= 1)
        {
            break;
        }
        else
        {
            std::cout << "El valor del factor de carga debe estar entre 0 y 1";
        }         
    }
    while(true)
    {
        std::cout << "Número de pruebas";
        std::getline(std::cin,input); 
        
        try
        {
            nPruebas = std::stof(input);
            break;
        }
        catch(const std::invalid_argument const &e)
        {
            std::cout << "Argumento inválido, pruebe de nuevo";
        }
        if (fLoad > 0)
        {
            break;
        }
        else
        {
            std::cout << "El número de pruebas debe ser mayor que 0";
        }         
    }

    int n = fLoad*nCeldas*tamCelda;

    DNI* tabla = new DNI[2*n];

    hashmap<DNI> A(nCeldas,tamCelda,fDispersion,fExploracion);

    for (int i = 0;i<n;i++)
    {
        A.insert(tabla[i]);
    }

    int SearchMin=10000;
    int SearchMax=0;
    int SearchAcum = 0;

    for (int i=0;i<nPruebas;i++)
    {
        DNI::resetCounter();
        A.search(tabla[i]);
        if(DNI::getCounter()<SearchMin)
        {
            SearchMin = DNI::getCounter();
        }
        if(DNI::getCounter()>SearchMax)
        {
            SearchMax = DNI::getCounter();
        }
        SearchAcum = SearchAcum + DNI::getCounter();
    }

    std::cout << "Para la operación de búsqueda, los resultados fueron:";
    /*Mangel no se si estas leyendo esto pero tq (Ya se que luego hay un formato en el que mostrar
    los datos pero de momento así sirve)*/ 
    std::cout << "\nMínimo = " << SearchMin;
    std::cout << "\nMedia = " << SearchAcum/nPruebas;
    std::cout << "\nMáximo = " << SearchMax;

    int InsertMin=10000;
    int InsertMax=0;
    int InsertAcum = 0;

    for (int i=0;i<nPruebas;i++)
    {
        DNI::resetCounter();
        A.search(tabla[2*n-i]);
        if(DNI::getCounter()<InsertMin)
        {
            SearchMin = DNI::getCounter();
        }
        if(DNI::getCounter()>InsertMax)
        {
            InsertMax = DNI::getCounter();
        }
        InsertAcum = InsertAcum + DNI::getCounter();
    }
    std::cout << "Para la operación de inserción, los resultados fueron:";
    std::cout << "\nMínimo = " << InsertMin;
    std::cout << "\nMedia = " << InsertAcum/nPruebas;
    std::cout << "\nMáximo = " << InsertMax;
}

