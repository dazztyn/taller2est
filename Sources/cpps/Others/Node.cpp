#include <iostream>
#include "Node.h"
#include "Product.h"
using namespace std;

Node::Node(int key, Product* value)
{
    this -> key = key;
    this -> value = value;
    this -> next = nullptr;
}