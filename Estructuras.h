#pragma once
#include <cstdio>  
#include <cstdlib> 
#include <string>



struct Nodos {
    int dato;
    struct Nodos* izquierda;
    struct Nodos* derecha;
    struct NodoAdy* listaAdy;
}*p, *raiz = NULL;

struct NodoAdy {
    std::string dato;
    Nodos* direccion;
    struct NodoAdy* enlace;
};