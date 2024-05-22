#include <iostream>
#include "Client.h"
#include "PriorityClient.h"
using namespace std;

PriorityClient::PriorityClient(int numAttention,string name, int age, string condition) : Client (numAttention,name,age)
{
    this -> condition = condition;
}

PriorityClient::~PriorityClient(){};

string PriorityClient::getCondition(){
    return this -> condition;
}
