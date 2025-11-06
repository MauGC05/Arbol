#pragma once
#include "Estructuras.h"
#include "colaDin.h"
#include <string>
#include <map>

Nodos* buscarVertice(std::string dato) {
    Nodos* actual = lista;
    while (actual != NULL) {
        if (actual->dato == dato) {
            return actual;
        }
        actual = actual->enlace;
    }
    return NULL;
}


std::string obtenerMaximoVertice() {
    std::string maximo = "-1";
    Nodos* actual = lista;
    while (actual != NULL) {
        if (actual->dato > maximo) {
            maximo = actual->dato;
        }
        actual = actual->enlace;
    }
    return maximo;
}


void insertarFinal_G(std::string x) {
    if (buscarVertice(x) != NULL) {
        printf("Error: El vertice %s ya existe.\n", x.c_str());
        return;
    }
    Nodos* p = new Nodos;
    p->dato = x;
    p->enlace = NULL;
    p->listaAdy = NULL;
    if (lista == NULL) {
        lista = p;
    }
    else {
        Nodos* aux = lista;
        while (aux->enlace != NULL) {
            aux = aux->enlace;
        }
        aux->enlace = p;
    }
}

void agregarArista(std::string origen, std::string destino) {
    Nodos* nodoOrigen = buscarVertice(origen);
    Nodos* nodoDestino = buscarVertice(destino);
    if (nodoOrigen == NULL || buscarVertice(destino) == NULL) {
        printf("Error: El vertice de origen o destino no existe.\n");
        return;
    }
    NodoAdy* nuevoAdy = new NodoAdy;
    nuevoAdy->dato = destino;
    nuevoAdy->direccion = nodoDestino;
    nuevoAdy->enlace = NULL;
    if (nodoOrigen->listaAdy == NULL) {
        nodoOrigen->listaAdy = nuevoAdy;
    }
    else {
        NodoAdy* aux2 = nodoOrigen->listaAdy;
        while (aux2->enlace != NULL) {
            aux2 = aux2->enlace;
        }
        aux2->enlace = nuevoAdy;
    }
    printf("Arista de %s a %s agregada.\n", origen.c_str(), destino.c_str());
}

void mostrarGrafo() {
    printf("Lista de Adyacencia.\n");
    if (lista == NULL) {
        printf("El grafo está vacío.\n");
        return;
    }
    Nodos* actual = lista;
    while (actual != NULL) {
        printf("Vertice %s: ", actual->dato.c_str());
        NodoAdy* ady = actual->listaAdy;
        while (ady != NULL) {
            printf("-> %s", ady->dato.c_str());
            ady = ady->enlace;
        }
        printf("\n");
        actual = actual->enlace;
    }
}

void imprimirAristas() {
    printf("Pares Ordenados: ");
    if (lista == NULL) {
        printf("El grafo esta vacío.\n");
        return;
    }
    Nodos* actual = lista;
    while (actual != NULL) {
        NodoAdy* ady = actual->listaAdy;
        while (ady != NULL) {
            printf("\n(%s, %s)", actual->dato.c_str(), ady->dato.c_str());
            ady = ady->enlace;
        }
        printf("\n");
        actual = actual->enlace;
    }
}


void sonAdyacentes(std::string origen, std::string destino) {
    Nodos* nodoOrigen = buscarVertice(origen);
    if (nodoOrigen == NULL) {
        printf("Error: El vertice de origen %s no existe.\n", origen.c_str());
        return;
    }

    NodoAdy* actual = nodoOrigen->listaAdy;
    while (actual != NULL) {
        if (actual->dato == destino) {
            printf("Si, el vertice %s es adyacente a %s.\n", destino.c_str(), origen.c_str());
            return;
        }
        actual = actual->enlace;
    }

    printf("No, el vertice %s no es adyacente a %s.\n", destino.c_str(), origen.c_str());
}

void recorridoAnchura(std::string datoInicio) {
    Nodos* v = buscarVertice(datoInicio);
    if (v == NULL) {
        printf("Error: El vertice de inicio %s no existe.\n", datoInicio.c_str());
        return;
    }

    std::map<std::string, bool>marca;

    colaDin C{};
    printf("Recorrido por Anchura (BPA) desde %s: ", datoInicio.c_str());

    marca[v->dato] = true;
    C.encolar(v);

    while (!C.cola_vacia()) {
        Nodos* x = C.desencolar();
        printf("%s ", x->dato.c_str());

        NodoAdy* y = x->listaAdy;
        while (y != NULL) {
            if (!marca[y->dato]) {
                marca[y->dato] = true;
                C.encolar(buscarVertice(y->dato));
            }
            y = y->enlace;
        }
    }
    printf("\n");

}


void recorridoProfundo(Nodos* v, std::map<std::string, bool>&marca) {
    
    marca[v->dato] = true; //El nodo se marca como visitado
    printf("%s\n", v->dato.c_str()); //Imprimir ése nodo
    //NodoAdy* w = v->listaAdy;
    
    
    for(NodoAdy* w = v->listaAdy; w!=nullptr; w=w->enlace)
    {
        if (marca[w->direccion->dato]==false) {
            recorridoProfundo(w->direccion, marca);
        }
    }
}

