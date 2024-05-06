#pragma once
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
        void addValue(int); //agrega el valor ingresado por parametro a la lista
        
        Node* SearchValue(int); //busca el valor ingresado en la lista enlazada
        void DeleteValue(int); //elimina el valor ingresado en la lista 
        void print(); //imprime los valores que contiene la lista
};      




