#pragma once
#include <iostream>
#include "Product.h"
using namespace std;

class SanitaryProd : public Product{
private:
    string category;

public:

    SanitaryProd(string,string,int,int,int,string);
    ~SanitaryProd();

    string getCategory();
};