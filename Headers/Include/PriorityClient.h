#pragma once
#include <iostream>
#include "Client.h"
using namespace std;

class PriorityClient : public Client{
private:
    string priorityType;

public:
    PriorityClient(int,string,string,string,string);
    ~PriorityClient();

    string getPriorityType();
    void setPriorityType(string);
};
