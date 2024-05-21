#pragma once
#include<iostream>

using namespace std;

class Product {
private: // atributos
    string subcategory,productName;
    int price,ID,stock;
 
public: // metodos

    Product(string, string, int, int, int); //constructor
    ~Product(); //destructor

    //getters
    string getSubcategory();
    string getProductName();
    int getPrice();
    int getID();
    int getStock();

    string toString();

    void substractQuantity(int);

};
