#pragma once
#include <iostream>
#include "Product.h"
using namespace std;

class BabyProd : public Product{
private:
    string category;
public:

    BabyProd(string,string,int,int,int,string);
    ~BabyProd();

    string getCategory();
};