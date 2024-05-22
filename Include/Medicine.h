#pragma once
#include <iostream>
#include "Product.h"
using namespace std;

class Medicine: public Product{
private:
    string category;

public:

    Medicine(string,string,int,int,int,string);
    ~Medicine();

    string getCategory();
};