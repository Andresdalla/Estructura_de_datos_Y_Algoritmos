#pragma once
#include "pila.cpp"
#include <iostream>
using namespace std;

class pilaImp : public pila {
private:
    int* arr;
    int maxIdex;
    int tamaño;
public:
    pilaImp(int tamaño)
    {
        arr = new int[tamaño];
        maxIdex = -1;
        this->tamaño = tamaño;
    }

    void push(int element)  {
        if (maxIdex >= tamaño - 1) {
            cout << "pila llean";
        }
        arr[++maxIdex] = element;
    }

    int pop() {
        if (isEmpty()) {
            cout << "pila vacia";
            
        }
        return arr[maxIdex--];
    }

    int top()  {
        if (isEmpty()) {
            cout << "pila vacia";

        }
        return arr[maxIdex];
    }

    bool isEmpty()  {
        return maxIdex < 0;
    }

    int size(){
        return maxIdex + 1;
    }
};