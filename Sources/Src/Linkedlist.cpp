#include "Linkedtlist.h"
#include<iostream>

using namespace std;

Linkedlist::Linkedlist() // constructor 
{
    this -> head = nullptr; // inicializa el puntero head como null
}


void Linkedlist::addValue(int value) // agrega un valor entregado por parametro a la lista enlazada
{   
    Node* newNode = new Node(value); //se instancia un nuevo nodo con el valor entregado por parametro
    if(head == nullptr)
    {
        head = newNode;    // si la lista esta vacia el puntero head apunta al nodo inicializado con el valor entregado
    }
    else
    {
        Node* current = head; // se crea un puntero "actual" que apunta al mismo nodo que el puntero head
        while(current->next != nullptr)
        {
            current = current->next; // recorre la lista enlazada mientras el nodo sea distinto de null
        }
        current->next = newNode; 
    }
}

Node* Linkedlist::SearchValue(int value)
{
    if(this->head == nullptr)
    {
        return nullptr;
    }

    Node* aux = this->head;

    if(aux->value == value)
    {
        return aux;
    }

    while(aux->next != nullptr)
    {
        aux = aux->next;
        if(aux->value == value)
        {
            return aux;
        }
    }
    return nullptr;
}