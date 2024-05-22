#pragma once
#include<iostream>

using namespace std;

class Client
{
    private: // atributos
        int numAttention;
        string name;
        int age;
        string condition;
        
    public: // metodos
        Client(int,string,int,string); //constructor
        ~Client(); //destructor

        //getters
        virtual int getNumAttention();
        virtual string getName();
        virtual int getAge();
        virtual string getCondition();
        virtual void setNumAttention(int);

        virtual string toString(); //para modificar txt (?)

};



