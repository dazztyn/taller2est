#pragma once
#include <iostream>
#include "Product.h"
using namespace std;

class NutritionalProd : public Product{
private:
    string category;
public:

    NutritionalProd(string,string,int,int,int,string);
    ~NutritionalProd();

    string getCategory();
};