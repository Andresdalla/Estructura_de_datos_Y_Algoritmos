#pragma once
#include "colaDePrioridad.cpp"
#include "../../func/funcionesMatematicas.cpp"
#include <iostream>
using namespace std;

template <class T, class K>
struct minHeapNode
{
  T element;
  K priority;
  // Constructor del nodo con parametros
  minHeapNode(T element, K priority) : element(element), priority(priority) {}
  // Constructor del nodo sin parametros
  minHeapNode() : element(T()), priority(K()) {}
};

template <class T, class K>
class minHeap
{
private:
  minHeapNode<T, K> *heap;
  int heapSize;
  int heapLength;

  void swap(int a, int b)
  {
    minHeapNode<T, K> aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
  }

public:
  // Constructor del heap con parametros
  minHeap(int length)
  {
    this->heapSize = 0;
    this->heapLength = length;
    this->heap = new minHeapNode<T, K>[this->heapLength];
  }
  // Inserta un elemento en el heap
  void push(T element, K priority)
  {
    minHeapNode<T, K> *node = new minHeapNode<T, K>(element, priority);
    this->heapSize++;
    if (this->heapLength <= this->heapSize)
    {
      minHeapNode<T, K> *newHeap = new minHeapNode<T, K>[this->heapLength * 2];
      for (int i = 1; i < this->heapLength; i++)
      {
        newHeap[i] = heap[i];
      }
      heap = newHeap;

      heapLength = heapLength * 2;
    }
    heap[heapSize] = *node;
    siftUp(heapSize);
  }
  // Version recursiva
  void siftUp(int pos)
  {
    int parentPos = pos / 2;
    if (parentPos < 1)
    {
      return;
    }
    minHeapNode<T, K> parent = heap[parentPos];
    minHeapNode<T, K> node = heap[pos];
    if (parent.priority > node.priority)
    {
      swap(pos, parentPos);
      siftUp(parentPos);
    }
  }
  // Version recursiva
  void siftDown(int pos)
  {
    int leftSonPos = pos * 2;
    int rightSonPos = pos * 2 + 1;
    if (leftSonPos > this->heapSize)
    {
      return;
    }
    int minPos = leftSonPos;
    if ((rightSonPos <= this->heapSize) && (heap[rightSonPos].priority < heap[leftSonPos].priority))
    {
      minPos = rightSonPos;
    }
    if (heap[pos].priority > heap[minPos].priority)
    {
      swap(pos, minPos);
      siftDown(minPos);
    }
  }
  // Elimina el elemento con mayor prioridad
  T pop()
  {
    T ret = heap[1].element;
    heap[1] = heap[this->heapSize];
    siftDown(1);
    this->heapSize--;
    return ret;
  }
  // Devuelve el elemento con mayor prioridad
  T top()
  {
    return this->heap[1].element;
  }

  bool isEmpty()
  {
    return this->heapSize == 0;
  }

  int size()
  {
    return this->heapSize;
  }
};