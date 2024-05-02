#include <iostream>
#include "Product.h"

using namespace std;

Product::Product(int IdProd, string NameProd, string Catego, string Subcate, int PriceProd, int Quantity)
{
    this->IdProd = IdProd;
    this->NameProd = NameProd;
    this->Category = Catego;
    this->Subcategory = Subcate;
    this->PriceProd = PriceProd;
    this->QuantityStore = Quantity;

}

Product::~Product(){}; // destructor

    //getters y setters
int Product::getIdProd()
{
    return this->IdProd;
 
}
string Product::getNameProd()
{
    return this->NameProd;
}
string Product::getCategProd()
{
    return this->Category;
}
string Product::getSubcate()
{
    return this->Subcategory;
}
int Product::getPriceProd()
{
    return this->PriceProd;
}
int Product::getQuantity()
{
    return this->QuantityStore;
}

void Product::setIDProd(int Idprod)
{
    this->IdProd = Idprod;
}
void Product::setNameProd(string Namep)
{
    this->NameProd = Namep;
}
void Product::setCategProd(string Cate)
{
    this->Category = Cate;
}
void Product::setSubcate(string Subc)
{
    this->Subcategory = Subc;
}
void Product::setPriceProd(int Pricep)
{
    this->PriceProd = Pricep;
}
void Product::setQuantity(int Quanti)
{
    this->QuantityStore = Quanti;
}