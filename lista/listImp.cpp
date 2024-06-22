#pragma once
#include "list.cpp"
#include <string>
#include <iostream>
#include "../../iterator/Iterator.cpp"
using namespace std;

template <class T>
struct Node
{
    T elem;
    Node<T> *next;
    Node(T element) : elem(element), next(nullptr) {}
};

template <class T>
class listImp : List<T>
{
private:
    Node<T> *root;
    Node<T> *tail;
    int cantElems;

public:
    listImp() : root(nullptr), tail(nullptr), cantElems(0) {}

    void insert(T elem) override
    {
        Node<T> *newNode = new Node<T>(elem);
        if (root == nullptr)
        {
            root = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cantElems++;
    }

    void remove(int pos) override
    {
        Node<T> *actual = this->root;
        Node<T> *anterior = nullptr;
        if (pos == 0)
        {
            this->root = actual->next;
        }
        else
        {
            for (int i = 0; i < pos; i++)
            {
                anterior = actual;
                actual = actual->next;
            }
            anterior->next = actual->next;
        }

        delete actual;
        cantElems--;
    }

    T get(int pos) override
    {
        Node<T> *l = this->root;
        int i = 0;
        while (i != pos)
        {
            l = l->next;
            i++;
        }
        return l->elem;
    }

    bool contains(T elem) override
    {
        Node<T> *l = this->root;
        while (l != nullptr)
        {
            if ((l->elem == elem))
            {
                return true;
            }
            l = l->next;
        }
        return false;
    }

    int size()
    {
        return cantElems;
    }

    int getPos(T value)
    {
        assert(this->contains(value));
        Node<T> *l = this->root;
        int i = 0;
        while (l != nullptr)
        {
            if (l->elem->equals(value))
            {
                return i;
            }
            i++;
            l = l->next;
        }
        return 0;
    }
    bool isEmpty() override
    {
        return this->root == nullptr;
    }

    // Implementacion de iterador
    class listImpIterator : public Iterator<T>
    {
    private:
        Node<T> *current;

    public:
        listImpIterator(Node<T> *root) : current(root) {}

        bool hasNext() override
        {
            return current != nullptr;
        }

        T next() override
        {
            if (!hasNext())
            {
                throw std::runtime_error("no hay elems");
            }
            T value = current->elem;
            current = current->next;
            return value;
        }
    };

    Iterator<T> *getIterator() override
    {
        return new listImpIterator(root);
    }
};
