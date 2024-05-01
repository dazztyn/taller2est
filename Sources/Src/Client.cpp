#include <iostream>
#include "Client.h"

using namespace std;

Client::Client(string typeClient, int NumAttention)//Constructor
{
    this->TypeClient = TypeClient;
    this->NumAttention = NumAttention;
}

Client::~Client(){}; // destructor

    //getters y setters
string Client::getTypeClient()
{
    return this->TypeClient;
}

void Client::setTypeClient(string TypeClient)
{
    this->TypeClient = TypeClient;
}

int Client::getNumAttention()
{
    return this->NumAttention;
}

void Client::setNumAttention(int NumAttention)
{
    this->NumAttention = NumAttention;
}


