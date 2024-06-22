#pragma once
#include "../../iterator/Iterator.cpp"
template <class T>
class List : public iterable<T>
{
public:
    virtual void insert(T elem) = 0;

    virtual void remove(int pos) = 0;

    virtual T get(int pos) = 0;

    virtual bool contains(T elem) = 0;

    virtual bool isEmpty() = 0;
};