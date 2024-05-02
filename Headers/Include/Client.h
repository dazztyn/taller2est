#pragma once

#include<iostream>

using namespace std;

class Client
{
    private: // atributos
        int NumAttention;
        string NameClient,TypeClient,Details;
        
    public: // metodos
        Client(int,string,string,string); //constructor
        ~Client(); //destructor

        //getters y setters
        int getNumAttention();
        string getNameClient();
        string getTypeClient();
        string getDetails();
        void setNumAttention(int);
        void setNameClient(string);
        void setTypeClient(string);
        void setDetails(string);

        string toString();

};



