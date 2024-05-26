#pragma once
#include<iostream>

using namespace std;

class Product {
private: // atributos
    string subcategory,productName;
    int price,ID,stock;
    string category;
 
public: // metodos

    Product(string, string, int, int, int, string); //constructor
    ~Product(); //destructor

    //getters
    string getSubcategory();
    string getProductName();
    string getCategory();
    int getPrice();
    int getID();
    int getStock();
    void setStock(int);

    string toString();


};
