#include <iostream>
#include "Product.h"

using namespace std;

Product::Product(string Catego, string Subcate, string IdProd, string NameProd, double PriceProd)
{
    this->Category = Catego;
    this->Subcategory = Subcate;
    this->IdProd = IdProd;
    this->NameProd = NameProd;
    this->PriceProd = PriceProd;

}

Product::~Product(){}; // destructor

    //getters y setters
string Product::getCategProd()
{
    return this->Category;
}

void Product::setCategoProd(string categoProd)
{
    this->Category = categoProd;
}

string Product::getSubcate()
{
    return this->Subcategory;
}

void Product::setSubcate(string Subcate)
{
    this->Subcategory = Subcate;
}

string Product::getIdProd()
{
    return this->IdProd;
}

void Product::setIdProd(string Idprod)
{
    this->IdProd = Idprod;
}

string Product::getNameProd()
{
    return this->NameProd;
}

void Product::setNameProd(string NameProd)
{
    this->NameProd = NameProd;
}

double Product::getPriceProd()
{
    return this->PriceProd;
}

void Product::setPriceProd(double PriceProd)
{
    this->PriceProd = PriceProd;
}



