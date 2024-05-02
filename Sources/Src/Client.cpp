#include <iostream>
#include "Client.h"

using namespace std;

Client::Client(int NumAttention, string NameClient, string TypeClient, string Details)//Constructor
{   
    this->NumAttention = NumAttention;
    this->NameClient = NameClient;
    this->TypeClient = TypeClient;
    this->Details = Details;
    
}

Client::~Client(){}; // destructor

    //getters y setters
int Client::getNumAttention()
{
    return this->NumAttention;
}
string Client::getNameClient()
{
    return this->NameClient;
}
string Client::getTypeClient()
{
    return this->TypeClient;
}
string Client::getDetails()
{
    return this->Details;
}
void Client::setNumAttention(int NumA)
{
    this->NumAttention = NumA;
}
void Client::setNameClient(string NameC)
{
    this->NameClient = NameC;
}
void Client::setTypeClient(string TypeC)
{
    this->TypeClient = TypeC;
}
void Client::setDetails(string Details)
{
    this->Details = Details;
}




