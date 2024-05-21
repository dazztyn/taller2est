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
    if(this->head == nullptr) // se compara el puntero head para ver si la lista esta vacia
    {
        return nullptr; // en este caso se retorna null
    }

    Node* aux = this->head; // se crea una variable "aux" de tipo puntero y se inicializa para que apunte al nodo principal de la lista

    if(aux->value == value)
    {
        return aux; // en este caso si el valor al que apunta "aux" es el valor buscado se retorna el puntero
    }
    else
    {
        while(aux->next != nullptr) // sino se recorre mientras el puntero siguiente sea distinto de nulo
        {
            aux = aux->next;
            if(aux->value == value) // y se pregunta si el valor al que apunta "aux" es igual al valor buscado
            {
                return aux; // en ese caso se devuelve el puntero donde se encuentra
            }
        }
    }
    
    return nullptr; // si no se encuentra se retorna null
}

void Linkedlist::DeleteValue(int value)
{
    Node* valueDel = SearchValue(value); // se inicializa una variable "valorEliminado" de tipo puntero que se le asigna el puntero que retorna la funcion buscarValor con el valor dado por parametro
    Node* valuePrev = head; //se inicializa otra variable "ValorPrevio" de tipo puntero cuya asignacion es el puntero principal de la lista enlazada

    if(valueDel == nullptr) // si el puntero "valorEliminado" es nulo
    {
        cout<<"el dato que desea eliminar no existe"<<endl; // se imprime que no se puede borrar, porque no existe
        return;
    }
    if(valueDel == head) // si el valor a eliminar se encuentra la principio de la lista enlazada
    {
        head = valueDel->next;  // el puntero principal "head" ahora apunta al siguiente del nodo a eliminar
    }
    else // sino
    {
        while(valuePrev->next != valueDel) 
        {
            valuePrev = valuePrev->next;    // se recorre la lista enlazada mientras el nodo al que apunta "valor previo" sea distinto al del valor a eliminar
        }
        valuePrev->next = valueDel->next; // luego el puntero "valor previo" apunta hacia el nodo siguiente del que se va a eliminar
    }

    delete valueDel; //luego procede a borrarse el valor
}


void Linkedlist::print()
{
    Node* currentNode = head; // se crea una variable de tipo puntero "Nodo actual" que va a guardar la direccion de memoria del puntero head 
    while(currentNode != nullptr) // se recorre la lista enlazada mientras el nodo actual sea distinto de nulo
    {
        cout<<currentNode->value<<endl; // muestra los datos de la lista
        currentNode = currentNode->next; // el puntero "nodo actual" ahora apunta al siguiente nodo ( de esta forma vamos cambiando de nodo en la lista)
    }
    cout<< "nullptr" <<endl; // se imprime nulo cuando finaliza el ciclo while

}