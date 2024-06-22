#pragma once

template <class T>
class cola{
public:
    void encolar(T elem);

    void desencolar();
    
    T frente();
    
    bool isEmpty();
    
    int size();
};