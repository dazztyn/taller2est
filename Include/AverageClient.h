#pragma once
#include <iostream>
#include "Client.h"
using namespace std;

class AverageClient : public Client{

private:
    string condition;

public:
    AverageClient(int,string,int,string);
    ~AverageClient();

    string getCondition();
};
