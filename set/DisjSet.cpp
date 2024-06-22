#pragma once
#include <iostream>
using namespace std;

class DisjSet {
public:
  virtual void unir(int x, int y) = 0;

  virtual int buscar(int x) = 0;
};