#include <iostream>
#include "Product.h"
#include "SanitaryProd.h"
using namespace std;

SanitaryProd::SanitaryProd(string subcategory, string productName, int price, int ID, int stock,string category) : 
Product(subcategory,productName,price,ID,stock){

    this -> category = category;

}

SanitaryProd::~SanitaryProd(){};

string SanitaryProd::getCategory(){
    return this -> category;
}