#pragma once
#include "Product.h"
#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Product* value;
    Node* next;
    Node(int key, Product* value);
};
