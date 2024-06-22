#include <iostream>
#include "../lista/listImp.cpp"
#include "cola.cpp"
using namespace std;

template <class T>
class colaImp : public cola<T>{
private:
    listImp<T>* cola;
public:
    colaImp()
    {
        this->cola = new listImp<T>();
    }

    void encolar(T elem) {
        cola->insert(elem);
    }

    void desencolar() {
        if (!cola->isEmpty()) {
            cola->remove(0);
        } else {
            cout << "La cola esta vacia";
        }
    }

    T frente() {
        if (!cola->isEmpty()) {
            return cola->get(0);
        } else {
            cout << "La cola esta vacia";
            return T(); 
        }
    }

    bool esVacia() {
        return cola->isEmpty();
    }

    int sizeCola() {
        return cola->size();
    }
};