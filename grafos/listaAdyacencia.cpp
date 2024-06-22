#pragma once
#include "graph.cpp"
#include <iostream>
#include <climits>
#include "../lista/listImp.cpp"
#include "../pila/pilaImp.cpp"
#include "../cola/colaImp.cpp"
#include "../set/DisjSetImp.cpp"
#include "../colaDePrioridad/minHeap.cpp"

using namespace std;

template <class T>
class listaAdyacencia
{
private:
    int size;
    // Array de punteros a listas
    listImp<T> **array;
    int cantidadAristas;

public:
    // Constructor de la lista de adyacencia
    listaAdyacencia(int size, bool esPonderado)
    {
        this->size = size;
        this->array = new listImp<int> *[size + 1];
        for (int i = 0; i < size + 1; i++)
        {
            array[i] = new listImp<T>();
        }
        this->cantidadAristas = 0;
    }
    // Agregar arista no ponderada
    void addEdge(int v, int w)
    {
        if (!this->array[v]->contains(w))
        {
            this->array[v]->insert(w);
        }
        this->cantidadAristas++;
    }
    // Agregar arista ponderada
    void addweightedEdge(int v, int w, int peso)
    {
        if (!this->array[v].contains(w))
        {
            this->array[v].insert(w);
        }
        this->cantidadAristas++;
    }
    // Eliminar arista
    void removeEdge(int v, int w)
    {
        this->array[v].remove(w);
        this->cantidadAristas--;
    }
    // Verificar si existe arista
    bool hasEdge(int v, int w)
    {
        return this->array[v].contains(w);
    }
    // Obtener vecinos de un vertice
    // Se devuelve un iterador de la lista de adyacencia para obtener mejores ordenes
    Iterator<int> *getNeighbors(int v)
    {
        return this->array[v]->getIterator();
    }

    int cantVertices()
    {
        return this->size;
    }

    int cantAristas()
    {
        return this->cantidadAristas;
    }

    // Algoritmo DFS: Depth First Search - Usado en el ejercicio 4
    bool *DFS(int inicio)
    { // O(V + A)
        // Inicializo un array de visitados
        bool *visitados = new bool[this->size + 1]();
        // Inicializo una pila
        pilaImp *pila = new pilaImp(this->size + 1);
        pila->push(inicio); // O(1)
        visitados[inicio] = true;
        while (!(pila->isEmpty()))
        {
            int v = pila->top();
            pila->pop(); // O(1)
            visitados[v] = true;
            Iterator<int> *l = this->getNeighbors(v);
            while (l->hasNext())
            {
                int w = l->next();
                if (!visitados[w])
                {
                    pila->push(w);
                    visitados[w] = true;
                }
            }
        }
        return visitados;
    }
    // Algoritmo de camino mas corto no ponderado (BFS) - Usado en el ejercicio 5
    int caminoMasCortoNoPoderado(int origen)
    {
        // inicializo arreglo de visitados: O(V)
        int suma = 0;
        bool *visitados = new bool[this->size + 1]();
        int *costo = new int[this->size + 1];
        // inicializo los arreglos de costo y anterior: O(V)
        for (int i = 0; i < this->size + 1; i++)
        {
            costo[i] = INT_MAX;
        }
        // inicializo la cola: O(1)
        colaImp<int> *cola = new colaImp<int>();
        // encolo el origen: O(n)--> n cantidad de elementos en la cola
        cola->encolar(origen);
        costo[0] = 0;
        costo[origen] = 0;
        while (!(cola->esVacia()))
        {
            int vertice = cola->frente();
            cola->desencolar();
            Iterator<int> *l = this->getNeighbors(vertice);
            visitados[vertice] = true;
            while (l->hasNext())
            {
                int adyacente = l->next();
                if (!visitados[adyacente] && costo[adyacente] > (costo[vertice] + 1))
                {
                    cola->encolar(adyacente);
                    costo[adyacente] = costo[vertice] + 1;
                    suma += costo[vertice] + 1;
                }
            }
        }
        return suma;
    }
};