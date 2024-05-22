#pragma once
#include <iostream>
#include "Client.h"
using namespace std;

class PriorityClient : public Client{
private:
    string condition;

public:
    PriorityClient(int,string,int,string);
    ~PriorityClient();

    string getCondition();
};
