#pragma once

#include<iostream>

using namespace std;

class Client
{
    private: // atributos
        string TypeClient;
        int NumAttention;
    public: // metodos
        Client(string, int); //constructor
        ~Client(); //destructor

        //getters y setters
        string getTypeClient();
        int getNumAttention();
        void setTypeClient(string);
        void setNumAttention(int);

        string toString();


};



