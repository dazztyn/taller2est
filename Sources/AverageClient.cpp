#include <iostream>
#include "Client.h"
#include "AverageClient.h"
using namespace std;

AverageClient::AverageClient(int numAttention,string name, int age, string condition) : Client (numAttention,name,age,condition)
{

}

AverageClient::~AverageClient(){};
