#include <iostream>
#include "Client.h"

using namespace std;

Client::Client(int numAttention, string name, int age,string condition)//Constructor
{   
    this -> numAttention = numAttention;
    this -> name = name;
    this -> age = age;
    this -> condition = condition;
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
void Client::setNumAttention(int num){
    this -> numAttention = num;
}
string Client::getCondition(){
    return this -> condition;
}

string Client::toString(){
    return "esto es un to string";
}




