#pragma once
#include <iostream>
#include "Client.h"
using namespace std;

class AverageClient : public Client{

public:
    AverageClient(int,string,int,string);
    ~AverageClient();
};
