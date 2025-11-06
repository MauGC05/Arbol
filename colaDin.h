#pragma once
#include <cstdio>  
#include <cstdlib> 
#include "Estructuras.h"


struct NodoCola {
    Nodos* dato;
    NodoCola* enlace;
};

class colaDin {
    private:
        NodoCola* front; 
        NodoCola* rear;  

    public:
    
        colaDin() {
            front = NULL;
            rear = NULL;
        }

    
        ~colaDin() {
            while (!cola_vacia()) {
                desencolar();
            }
        }

        bool cola_vacia() {
            return (front == NULL);
        }

    

        void encolar(Nodos* elemento) {
            NodoCola* nuevo = new NodoCola();
            nuevo->dato = elemento;
            nuevo->enlace = NULL;

            if (cola_vacia()) {
                front = nuevo;
                rear = nuevo;
            }
            else {
                // El que era el último ahora apunta al nuevo
                rear->enlace = nuevo;
                // El nuevo ahora es el último
                rear = nuevo;
            }
        }

        Nodos* desencolar() {
            if (cola_vacia()) {
                return NULL;
            }

            Nodos* elemento = front->dato;
            NodoCola* temp = front;

            front = front->enlace;

            if (front == NULL) {
                rear = NULL;
            }

            delete temp;
            return elemento;
        }

        void primer_elemento() {
            if (cola_vacia()) {
                printf("Cola vacia\n");
            }
            else {
                printf("Primer elemento: %s\n", front->dato);
            }
        }

        void ultimo_elemento() {
            if (cola_vacia()) {
                printf("Cola vacia\n");
            }
            else {
                printf("Ultimo elemento: %s\n", rear->dato);
            }
        }

        void mostrar_cola() {
            if (cola_vacia()) {
                printf("Cola vacia\n");
                return;
            }

            printf("Elementos en la cola:\n");
            NodoCola* actual = front;
            while (actual != NULL) {
                printf("%s ", actual->dato);
                actual = actual->enlace;
            }
            printf("\n");
    }
};

