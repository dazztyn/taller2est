#include <iostream>
#include <vector>
#include "HashMap.h"
#include "Node.h"
#include "Product.h"

using namespace std;

HashMap::HashMap(double maxLoadFactor) {
    this -> tableSize = 1000; //tamaño de la
    this -> maxLoadFactor = maxLoadFactor; //factor de carga
    table.resize(tableSize, nullptr); //nuevo tamaño 
}

void HashMap::rehash() { //duplica el tamaño de la tabla hash en caso de que se acabe el espacio y reinserta los elementos

    int newTableSize = tableSize * 2;
    vector<Node*> newTable(newTableSize, nullptr);

    for (int i = 0; i < tableSize; i++) { //se recorre la tabla original

        Node* actualNode = table[i];

        while (actualNode != nullptr) {

            int index = hashFunction(actualNode->key) % newTableSize; //retorna el indice
            Node* newNode = new Node(actualNode->key, actualNode->value);

            // Insertar newNode mientras se conservan las claves más grandes
            Node* prev = nullptr;
            Node* next = newTable[index];
            while (next != nullptr && next->key > actualNode->key) { // Buscar clave más grande
                prev = next;
                next = next->next;
            }

            if (prev == nullptr) { // Bucket vacío o clave más pequeña
                newTable[index] = newNode;
            } else {
                prev->next = newNode;
            }
            newNode->next = next; // Mantener el orden original de la lista enlazada

            actualNode = actualNode->next;
        }
    }
    table.swap(newTable);
    tableSize = newTableSize;
}

void HashMap::insert(int key, Product* value) {
    int index = hashFunction(key);
    Node* newNode = new Node(key, value);

    if (table[index] == nullptr) 
    {
        table[index] = newNode;
    } 
    else 
    {
        Node* prev = nullptr;
        Node* curr = table[index];
        while (curr != nullptr) 
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = newNode;
    }

    double loadFactor = (double) getNumberOfElements() / tableSize;

    if (loadFactor > maxLoadFactor) 
    {
        rehash();
    }
}

Product* HashMap::get(int key) 
{
    int index = hashFunction(key);
    Node* actualNode = table[index];

    while (actualNode != nullptr) 
    {
        if (actualNode->key == key) 
        {
            return actualNode->value;
        }
        actualNode = actualNode->next;
    }

    return nullptr;
}

void HashMap::erase(int key) 
{
    int index = hashFunction(key);
    Node* previusNode = nullptr;
    Node* actualNode = table[index];

    while (actualNode != nullptr) 
    {
        if (actualNode -> key == key) 
        {
            if (previusNode == nullptr) 
            {
                table[index] = actualNode->next;
            } 
            else 
            {
                previusNode -> next = actualNode->next;
            }
            delete actualNode;
            return;
        }
        previusNode = actualNode;
        actualNode = actualNode->next;
    }
}

int HashMap::getNumberOfElements() 
{
    int count = 0;
    for (int i = 0; i < tableSize; i++) 
    {
        Node* actualNode = table[i];
        while (actualNode != nullptr) 
        {
            count++;
            actualNode = actualNode->next;
        }
    }
    return count;
}