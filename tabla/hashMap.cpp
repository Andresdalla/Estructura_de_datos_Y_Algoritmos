#include "map.cpp"
#include "../../func/intHashFunc.cpp"
#include <iostream>
using namespace std;

template<class K,class V> 
class hashMap : public map<K,V>
{
public:
    struct hashNode
    {
        bool empty;
        bool deleted;
        K key;
        V value;
    };
    
    hashMap(intHashFunc func, int size)
    {
        this->func = func;
        this->arrSize = size;
        this->elems = 0;
        this->nodeArr = new hashNode[arrSize];
        this->boolArr = new bool[arrSize];
        for(int i = 0;i < arrSize;i++)
        {
            this->nodeArr[i].empty = true;
            this->nodeArr[i].deleted = false;
            this->boolArr[i] = false;
        }
    }
    bool has(K key) override
    {
        int pos = this->func.hash(key) % this->arrSize;
        int i = 0;
        while (!this->nodeArr[pos].empty) {
            if (!(this->nodeArr[pos].deleted) && (this->nodeArr[pos].key == key)) {
                return true;
            }
            pos = (pos + 1) % this->arrSize;
            i++;
            if (i == this->arrSize) {
                break;
            }
        }
        return false;
    }

    V get(K key) override
    {
        int pos = this->func.hash(key) % this->arrSize;
        int i = 0;
        while (!this->nodeArr[pos].empty) {
            if (!(this->nodeArr[pos].deleted) && (this->nodeArr[pos].key == key)) {
                return this->nodeArr[pos].value;
            }
            pos = (pos + 1) % this->arrSize;
            ++i;
            if (i == this->arrSize) {
                break;
            }
        }
        return nullptr;
    }   
    
    void set(K key, V value) override
    {
        if(this->arrSize == this->size())
        {
            cerr << "Error: no hay espacio en la tabla2" << endl;
            return;
        }
        int pos = this->func.hash(key) % this->arrSize;
        int i = 0;
        //buscamos el índice y en caso de no encontrarlos recurrimos a la sonda lineal
        while((!(this->nodeArr[pos].empty) && (this->nodeArr[pos].key != key)))
        {
            pos = (pos + 1) % this->arrSize;
            i++;
            if (i == this->arrSize) {
                cerr << "Error: table is full3" << endl;
                return;
            }
        }
        if (this->nodeArr[pos].empty || this->nodeArr[i].deleted) 
        {
            this->nodeArr[pos].empty = false;
            this->nodeArr[pos].key = key;
            this->nodeArr[pos].value = value;
            this->nodeArr[pos].deleted = false;
        } else {
            this->nodeArr[pos].value = value;
        }
        this->elems++;
    }       
    
    void remove(K key, V value) override
    {
        
    }

    int size() override
    {
        return this->elems;
    }
 
private:
    intHashFunc func;
    int arrSize;
    int elems;
    hashNode * nodeArr; 
    bool *boolArr;
};