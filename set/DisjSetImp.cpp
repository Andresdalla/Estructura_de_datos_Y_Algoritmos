// Código basado en https://graph.uruguayan.ninja/1
#pragma once
#include "DisjSet.cpp"
#include <iostream>
using namespace std;

class DisjSetImp
{
private:
    int *padre;
    int *altura;
    int size;

public:
    DisjSetImp(int n)
    {
        this->size = n;
        this->padre = new int[n + 1];
        this->altura = new int[n + 1];
        for (int i = 0; i <= n; i++)
        {
            this->padre[i] = i;
            this->altura[i] = 0;
        }
    }

    int buscar(int x)
    {
        if (this->padre[x] == x)
        {
            return x;
        }
        this->padre[x] = buscar(this->padre[x]);
        return this->padre[x];
    }

    void unir(int x, int y)
    {
        int xRoot = buscar(x);
        int yRoot = buscar(y);
        if (xRoot == yRoot)
        {
            return;
        }
        if (this->altura[xRoot] < this->altura[yRoot])
        {
            this->padre[xRoot] = yRoot;
        }
        else if (this->altura[xRoot] > this->altura[yRoot])
        {
            this->padre[yRoot] = xRoot;
        }
        else
        {
            this->padre[yRoot] = xRoot;
            this->altura[xRoot]++;
        }
    }
};