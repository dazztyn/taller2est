#include <iostream>
#include "Product.h"
#include "CosmeticProd.h"
using namespace std;

CosmeticProd::CosmeticProd(string subcategory, string productName, int price, int ID, int stock,string category) : 
Product(subcategory,productName,price,ID,stock){

    this -> category = category;

}
CosmeticProd::~CosmeticProd(){};

string CosmeticProd::getCategory(){
    return this -> category;
}