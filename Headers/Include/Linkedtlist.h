#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

class Linkedlist
{
    private:    //atributo
        Node* head;

    public:
        Linkedlist(); // constructor (vacio)
        ~Linkedlist(); // destructor
        //metodos
        void addValue(int); //agrega los valores a la lista
        void print(); //imprime los valores que contiene la lista
        Node* SearchValue(int); //busca el valor en la lista enlazada
        void DeleteValue(int); //elimina el valor en la lista 
};




