#include <iostream>
#include "Product.h"
#include "Medicine.h"
using namespace std;

Medicine::Medicine(string subcategory, string productName, int price, int ID, int stock,string category) : 
Product(subcategory,productName,price,ID,stock){

    this -> category = category;

}

Medicine::~Medicine(){};

string Medicine::getCategory(){
    return this -> category;
}