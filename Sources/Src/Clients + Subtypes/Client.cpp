#include <iostream>
#include "Client.h"

using namespace std;

Client::Client(int numAttention, string name, int age)//Constructor
{   
    this -> numAttention = numAttention;
    this -> name = name;
    this -> age = age;
}

Client::~Client(){}; // destructor

    //getters y setters
int Client::getNumAttention()
{
    return this -> numAttention;
}
string Client::getName()
{
    return this -> name;
}
int Client::getAge()
{
    return this -> age;
}




