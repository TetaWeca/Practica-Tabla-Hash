
#include "../include/tabla.hpp"
#include "../include/dni.hpp"

#include <iostream>
#include <iomanip>
#include <string>

int main(void)
{
    int nCeldas,tamCelda,fDispersion,fExploracion,nPruebas;
    float fLoad;
    std::string input;

    while(true)
    {
        std::cout << "Introduce el tamaño de la tabla: ";
        std::getline(std::cin,input); 
        
        try
        {
            nCeldas = std::stoi(input);
        }
        catch(const std::invalid_argument &e)
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
        std::cout << "Introduce el tamaño de las celdas: ";
        std::getline(std::cin,input); 
        
        try
        {
            tamCelda = std::stoi(input);
        }
        catch(const std::invalid_argument &e)
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
        std::cout << "Función de dispersión: [ (0) Modulo // (1) Suma // (2) PseudoAleatoria ]: ";
        std::getline(std::cin,input); 
        
        try
        {
            fDispersion = std::stoi(input);
        }
        catch(const std::invalid_argument &e)
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
        std::cout << "Función de exploración: [ (0) Lineal // (1) Cuadrática // (2) Doble Dispersión // (3) Redispersión ]: ";
        std::getline(std::cin,input); 
        
        try
        {
            fExploracion = std::stoi(input);
        }
        catch(const std::invalid_argument &e)
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
        std::cout << "Factor de carga: ";
        std::getline(std::cin,input); 
        
        try
        {
            fLoad = std::stof(input);
        }
        catch(const std::invalid_argument &e)
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
        std::cout << "Número de pruebas: ";
        std::getline(std::cin,input); 
        
        try
        {
            nPruebas = std::stof(input);
        }
        catch(const std::invalid_argument &e)
        {
            std::cout << "Argumento inválido, pruebe de nuevo";
        }
        if (nPruebas > 0)
        {
            break;
        }
        else
        {
            std::cout << "El número de pruebas debe ser mayor que 0";
        }         
    }

    int n = fLoad*nCeldas*tamCelda;

    std::srand(time(nullptr));
    Matricula* tabla = new Matricula[2*n];

    hashmap<Matricula> A(nCeldas,tamCelda,fDispersion,fExploracion);

    for (int i = 0;i<n;i++)
    {
        A.insert(tabla[i]);
    }
    int SearchMin=INT32_MAX;
    int SearchMax=0;
    int SearchAcum = 0;

    for (int i=0;i<nPruebas;i++)
    {
        Matricula::resetCounter();
        // std::cout << tabla[i] << std::endl;
        A.search(tabla[i]);
        if(Matricula::getCounter()<SearchMin)
        {
            SearchMin = Matricula::getCounter();
        }
        if(Matricula::getCounter()>SearchMax)
        {
            SearchMax = Matricula::getCounter();
        }
        SearchAcum = SearchAcum + Matricula::getCounter();
    }

    // std::cout << "Para la operación de búsqueda, los resultados fueron:";
    // std::cout << "\nMínimo = " << SearchMin;
    // std::cout << "\nMedia = " << (float)SearchAcum/(float)nPruebas;
    // std::cout << "\nMáximo = " << SearchMax;

    int InsertMin=INT32_MAX;
    int InsertMax=0;
    int InsertAcum = 0;

    for (int i=0;i<nPruebas;i++)
    {
        Matricula::resetCounter();
        // std::cout << tabla[i] << std::endl;
        A.search(tabla[2*n-i]);
        if(Matricula::getCounter()<InsertMin)
        {
            InsertMin = Matricula::getCounter();
        }
        if(Matricula::getCounter()>InsertMax)
        {
            InsertMax = Matricula::getCounter();
        }
        InsertAcum = InsertAcum + Matricula::getCounter();
    }
    // std::cout << "\nPara la operación de inserción, los resultados fueron:";
    // std::cout << "\nMínimo = " << InsertMin;
    // std::cout << "\nMedia = " << (float)InsertAcum/(float)nPruebas;
    // std::cout << "\nMáximo = " << InsertMax << std::endl;
    
    std::cout<<std::setw(11)<<"Celdas"<<std::setw(11)<<"nClaves"<<std::setw(15)<<"Dispersión"<<std::setw(15);
    std::cout<<"Exploración"<<std::setw(11)<<"Carga"<<std::setw(11)<<"Pruebas"<< std::endl;

    std::cout<<std::setw(11)<<nCeldas<<std::setw(11)<<tamCelda<<std::setw(14)<<fDispersion<<std::setw(14)<<fExploracion;
    std::cout<<std::setw(11)<<fLoad<<std::setw(11)<<nPruebas<<std::endl;

    std::cout<<std::setw(15)<<"Minimo"<<std::setw(6)<<"Media"<<std::setw(8)<<"Máximo"<<std::endl;
    std::cout<<"Búsqueda"<<std::setw(7)<<SearchMin<<std::setw(6)<<(float)SearchAcum/(float)nPruebas<<std::setw(7)<<SearchMax<<std::endl;
    std::cout<<"Inserción"<<std::setw(6)<<InsertMin<<std::setw(6)<<(float)InsertAcum/(float)nPruebas<<std::setw(7)<<InsertMax<<std::endl;
}

