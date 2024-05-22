#include <iostream>
#include "Product.h"
#include "BabyProd.h"
using namespace std;

BabyProd::BabyProd(string subcategory, string productName, int price, int ID, int stock,string category) : 
Product(subcategory,productName,price,ID,stock){

    this -> category = category;

}

BabyProd::~BabyProd(){};

string BabyProd::getCategory(){
    return this -> category;
}