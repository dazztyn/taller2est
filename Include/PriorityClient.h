#pragma once
#include <iostream>
#include "Client.h"
using namespace std;

class PriorityClient : public Client{

public:
    PriorityClient(int,string,int,string);
    ~PriorityClient();
};
