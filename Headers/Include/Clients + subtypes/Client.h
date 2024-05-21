#pragma once
#include<iostream>

using namespace std;

class Client
{
    private: // atributos
        int numAttention;
        string name;
        int age;
        
    public: // metodos
        Client(int,string,int); //constructor
        ~Client(); //destructor

        //getters
        int getNumAttention();
        string getName();
        int getAge();

        string toString(); //para modificar txt (?)

};



