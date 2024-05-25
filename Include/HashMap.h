#pragma once
#include <iostream>
#include <vector>
#include "Node.h"
#include "Product.h"

using namespace std;

class HashMap{
private:

    int tableSize;
    double maxLoadFactor;
    vector<Node*> table;

    int hashFunction(int key){
        return key % tableSize;
    }

    void rehash();

public:

    HashMap(double maxLoadFactor = 0.75);
    void insert(int key, Product* value);
    Product* get(int key);
    void erase(int key);
    int getNumberOfElements();

};