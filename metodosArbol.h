#pragma once
#include "metodosGrafo.h"
#include "colaDin.h"
#include "Estructuras.h"
class metodosArbol
{
	Nodos* crearNodo(int x) { //Crea un nuevo nodo
		Nodos* p = new Nodos();
		p->dato = x;
		p->derecha = NULL;
		p->izquierda = NULL;
		return p;
	}

	void insertar(int dato) { //Funcion que inserta un nodo en el arbol
		Nodos* q = new Nodos();
		q = crearNodo(dato);
		
		if (raiz==NULL) {
			raiz = q;
		}
		else {
			Nodos* aux = raiz;
			Nodos* padre = NULL;
			while (aux!=NULL) {
				padre = aux;
				if (dato<=aux->dato) {
					aux = aux->izquierda;
				}
				else {
					aux = aux->derecha;
				}
			}

			if (dato<=padre->dato) {
				padre->izquierda = q;
			}
			else {
				padre->derecha = q;
			}
		}
	}

	Nodos* Padre(Nodos* raiz, int x) { //Funcion que nos da el padre
		Nodos* aux = raiz;
		Nodos* padre = NULL;
		while (aux!=NULL) {
			if (x == aux->dato) {
				return padre;
			}
			padre = aux;
			if (x<aux->dato) {
				aux = aux->izquierda;
			}
			else {
				aux = aux->derecha;
			}
		}

		return NULL; //no encontrado
	}

	void Hermanos(Nodos* raiz, int x) { //Funcion que nos da los hermanos
		Nodos* p = Padre(raiz, x);
		if (p==NULL) {
			printf("El nodo no tene padre (es la raiz)\n");
			return;
		}
		else {
			if (p->izquierda!=NULL && p->izquierda->dato == x) {
				if (p->derecha!=NULL) {
					printf("El hermano es: %d\n", p->derecha->dato);
				}
				else {
					printf("No tiene hermano.\n");
				}
			}
			else {
				if (p->derecha != NULL && p->derecha->dato == x) {
					if (p->izquierda!=NULL) {
						printf("El hermano es: %d\n", p->izquierda->dato);
					}
					else
					{
						printf("No tiene hermano.\n");
					}
				}
			}
		}
	}
	
	void EncontrarHojas(Nodos* nodo) { //Funcion que nos da las hojas
		if (nodo == NULL) {
			return;
		}
		else {
			EncontrarHojas(nodo);

			//Recorre sub arbol izquierdo
			if (nodo->izquierda==NULL && nodo->derecha==NULL) {
				printf("Hoja encontrada: %d\n", nodo->dato);
			}

			//Recorre sub arbol derecho
			EncontrarHojas(nodo->derecha);
		}
	}

	void MostrarDescendientes(Nodos* nodoInicio) { //Funcion que devuelve los hijos
		colaDin colaDeNodos{};
		colaDin hijos{};
		Hijos(nodoInicio, hijos);
		while (!hijos.cola_vacia()) {
			colaDeNodos.encolar(hijos.desencolar());
		}
		printf("Buscando hijos de: %d\n", nodoInicio->dato);
		while (colaDeNodos.cola_vacia() != NULL) {
			Nodos* nodoActual = colaDeNodos.desencolar();
			printf("->%d\n", nodoActual->dato);
			Hijos(nodoActual, hijos);
			while (!hijos.cola_vacia()) {
				colaDeNodos.encolar(hijos.desencolar());
			}
		}
	}

	void Hijos(Nodos* nodo, colaDin colaHijos) { //Funcion que nos da los hijos
		if (nodo ->izquierda == NULL && nodo->derecha == NULL) {
			printf("No tiene hijos, es una hoja.\n");
			return;
		}
		else {
			if (nodo->izquierda != NULL) {
				colaHijos.encolar(nodo->izquierda);
				printf("Hijo izquierdo: %d\n", nodo->dato);
			}
			if (nodo->derecha != NULL) {
				colaHijos.encolar(nodo->derecha);
				printf("Hijo derecho: %d\n", nodo->derecha);
			}
		}
	}

};

ccdvfvbkfdvkdkvfdkv