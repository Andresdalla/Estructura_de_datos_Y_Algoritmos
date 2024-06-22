#pragma once
#include "colaDePrioridad.cpp"
#include "../../func/funcionesMatematicas.cpp"
#include <iostream>
using namespace std;
class MaxHeap : colaDePrioridad<int>
{
private:
  int *heap;
  // cantidad de elementos en el heap
  int heapSize;
  // tamanio del array
  int heapLength;

  void swap(int a, int b)
  {
    int aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
  }

public:
  MaxHeap(int length)
  {
    this->heapSize = 0;
    this->heapLength = length;
    this->heap = new int[this->heapLength];
  }
  void push(int element, int priority)
  {
    this->heapSize++;
    // si no hay mas espacio, ampliamos el array
    if (this->heapLength <= this->heapSize)
    {
      int *newHeap = new int[this->heapLength * 2];
      for (int i = 1; i < this->heapLength; i++)
      {
        newHeap[i] = heap[i];
      }
      heap = newHeap;
      heapLength = heapLength * 2;
    }
    // insertamos elemento en el último lugar
    heap[heapSize] = element;
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
    int parent = heap[parentPos];
    int node = heap[pos];
    if (parent < node)
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
    int maxPos = leftSonPos;
    if ((rightSonPos <= this->heapSize) && (heap[rightSonPos] > heap[leftSonPos]))
    {
      maxPos = rightSonPos;
    }
    if (heap[pos] < heap[maxPos])
    {
      swap(pos, maxPos);
      siftDown(maxPos);
    }
  }
  // Devuelve el elemento con mayor prioridad y lo elimina del heap
  int pop()
  {
    int ret = heap[1];
    heap[1] = heap[this->heapSize];
    siftDown(1);
    this->heapSize--;
    return ret;
  }
  // Devuelve el elemento con mayor prioridad sin eliminarlo del heap
  int top()
  {
    return this->heap[1];
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