#pragma once

template <class T>
class colaDePrioridad
{
public:
  virtual void push(T,int) = 0;

  virtual T pop() = 0;

  virtual T top() = 0;

  virtual bool isEmpty() = 0;

  virtual int size() = 0;
};