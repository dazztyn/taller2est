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

    HashMap(double maxLoadFactor = 0.85);
    void insert(Product* value, int key);
    Product* get(int key);
    void displayProducts();
    void erase(int key);
    int getAmountOfElements();

};