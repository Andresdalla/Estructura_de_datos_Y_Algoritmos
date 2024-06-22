#pragma once
#include <iostream>

#include "bst.cpp"
using namespace std;

template <class T>
struct AVLNode
{
  T data;
  AVLNode<T> *left = nullptr;
  AVLNode<T> *right = nullptr;
  int height = 1;
  int amount= 1;
  

  AVLNode(T data)
  {
    this->data = data;
  }
};

template <class T>
class AVL : public BST<T>
{
private:
  AVLNode<T> *root = nullptr;
  int elements = 0;

  int nodeHeight(AVLNode<T> *node)
  {
    if (node == nullptr)
    {
      return 0;
    }
    else
    {
      return node->height;
    }
  }

  int balanceFactor(AVLNode<T> *node)
  {
    return nodeHeight(node->left) - nodeHeight(node->right);
  }

  int max(int a, int b)
  {
    if (a > b)
    {
      return a;
    }
    return b;
  }

  AVLNode<T> *insertNode(AVLNode<T> *node, T data)
  {
    if (node == nullptr)
    {
      this->elements++;
      return new AVLNode<T>(data);
    }
    // else
    if (node->data == data)
    {
      node->amount++;
      return node;
    }
    // else
    if (data > node->data)
    {
      node->right = insertNode(node->right, data);
    }
    else
    {
      node->left = insertNode(node->left, data);
    }



    node->height = 1 + max(nodeHeight(node->left), nodeHeight(node->right));





    int bF = balanceFactor(node);
   if(bF > 1 && data < node->left->data)
    {
        return rightRotation(node);
    }
    if(bF < -1 && data > node->right->data)
    {
        return leftRotation(node);
    } 
    if(bF > 1 && data > node->left->data)
    {
       node->left = leftRotation(node->left);  
        return rightRotation(node);  
    }   
    if(bF < -1 && data < node->right->data)
    {
       node->right = rightRotation(node->right);  
        return leftRotation(node); 
    }
  

    return node;

  }

  AVLNode<T> *leftRotation(AVLNode<T> *node)
  {
     /*
     *    z               y
     *   / \             / \
     *  a   y    =>     z   x
     *     / \         / \
     *    b   x       a   b
     */

    AVLNode<T> *y = node->right;
    AVLNode<T> *b = y->left;

    y->left = node;
    node->right = b;
   

    node->height = 1 + max(nodeHeight(node->left), nodeHeight(node->right));
    y->height = 1 + max(nodeHeight(y->left), nodeHeight(y->right));

    return y;
  }
  AVLNode<T> *rightRotation(AVLNode<T> *node)
   {

    AVLNode<T> *x = node->left;
    AVLNode<T> *z = x->right;

  
    x->right = node;
    node->left = z;

   
    node->height = 1+ max(nodeHeight(node->left), nodeHeight(node->right)) ;
    x->height = 1+ max(nodeHeight(x->left), nodeHeight(x->right)) ;

    return x;
}
  
  int recorridoNodo(AVLNode<T>* node, T l, T k) {
    if (node == nullptr) {
        return 0;
    }
    
    if (node->data + l == k) {
        return 1;
    }
    if(node->data + l < k) {
        return recorridoNodo(node->right, l, k);
    } else {
        return recorridoNodo(node->left, l, k);
    } 
    return 0;
}

public:
  void insert(T data) override
  {
    this->root = insertNode(this->root, data);
  }

  int height() override
  {
    return nodeHeight(this->root);
  }

  int size() override
  {
    return this->elements;
  }
  bool contains(T data) override
  {
    while (this->root != nullptr)
    {
      if (this->root->data == data)
      {
        return true;
      }
      else if (data > this->root->data)
      {
        this->root = this->root->right;
      }
      else
      {
        this->root = this->root->left;
      }
    }
    return false;
  }
  int recorridonodo(int l, int k) override
  {
    return recorridoNodo(this->root,l,k);
  }

  void remove(T data) override
  { }
};