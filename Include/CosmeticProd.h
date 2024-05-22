#pragma once
#include <iostream>
#include "Product.h"
using namespace std;

class CosmeticProd : public Product{
private:
    string category;
public:

    CosmeticProd(string,string,int,int,int,string);
    ~CosmeticProd();

    string getCategory();
};