#include <iostream>
#include "Product.h"

using namespace std;

Product::Product(string subcategory, string productName, int price,int ID, int Quantity, string category)
{
    this -> subcategory = subcategory;
    this -> productName = productName;
    this -> price = price;
    this -> ID = ID;
    this -> stock = Quantity;
    this -> category = category;
}

Product::~Product(){}; // destructor

//getters y setters
string Product::getSubcategory()
{
    return this -> subcategory;
}
string Product::getCategory()
{
    return this -> category;
}

string Product::getProductName()
{
    return this -> productName;
}

int Product::getPrice()
{
    return this -> price;
}

int Product::getID()
{
    return this -> ID;
}

int Product::getStock()
{
    return this -> stock;
}

void Product::setStock(int amount){
    this -> stock = amount;
}