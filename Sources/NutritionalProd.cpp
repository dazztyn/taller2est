#include <iostream>
#include "Product.h"
#include "NutritionalProd.h"
using namespace std;

NutritionalProd::NutritionalProd(string subcategory, string productName, int price, int ID, int stock,string category) : 
Product(subcategory,productName,price,ID,stock){

    this -> category = category;

}

NutritionalProd::~NutritionalProd(){};

string NutritionalProd::getCategory(){
    return this -> category;
}