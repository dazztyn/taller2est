#include <iostream>
#include <vector>
#include "HashMap.h"
#include "Node.h"
#include "Product.h"

using namespace std;

HashMap::HashMap(double maxLoadFactor) { // constructor

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

void HashMap::insert(Product* value, int key) { //inserta un producto a la tabla hash asociandolo con un id "key" y un indice

    int index = hashFunction(key);
    Node* newNode = new Node(key, value);

    if (table[index] == nullptr) {
        table[index] = newNode;
    }

    else 
    {
        Node* previousNode = nullptr;
        Node* actualNode = table[index];
        while (actualNode != nullptr) 
        {
            previousNode = actualNode;
            actualNode = actualNode -> next;
        }
        previousNode -> next = newNode;
    }

    double loadFactor = (double) getAmountOfElements() / tableSize; //se verifica el espacio disponible respecto al factor de carga

    if (loadFactor > maxLoadFactor) { //si se empieza a llenar la tabla
        rehash();
    }
}

Product* HashMap::get(int key) 
{
    int index = hashFunction(key);
    Node* actualNode = table[index];

    while (actualNode != nullptr) 
    {
        if (actualNode -> key == key) 
        {
            return actualNode -> value;
        }
        else{
            actualNode = actualNode->next;
        }
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

int HashMap::getAmountOfElements() //se obtiene la cantidad de elementos en la tabla para calcular el factor de carga (osea que tan cerca está de llenarse)
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

bool HashMap::displayProducts(string opt){ //despliega todos los productos en la tabla

    string category = "";
    bool categoryExists = false;

    if(opt == "1") {category = "Sanitario";}
    else if(opt == "2") {category = "Alimenticio";}
    else if(opt == "3") {category = "Medicamento";}
    else if(opt == "4") {category = "Para Bebé";}
    else if(opt == "5") {category = "Cosmético";}

    int verifier = 0;

    for (int i = 0; i < tableSize; ++i) {
        Node* actualNode = table[i];
        while (actualNode != nullptr) {
            Product* product = actualNode->value;
            
            if(product -> getCategory() == category){
                categoryExists = true;
                cout << "ID: " << product->getID() << ". " << product->getProductName() << ", Precio: $" << product->getPrice()
                << ", Stock: " << product->getStock() << ", Subcategoría: " << product->getSubcategory()
                << endl;
            }
            
            actualNode = actualNode -> next;
            }
        }

    return categoryExists;

}

void HashMap::displayAllProducts(){

    for (int i = 0; i < tableSize; ++i) {
        Node* actualNode = table[i];
        while (actualNode != nullptr) {

            Product* product = actualNode->value;
            cout << "ID: " << product->getID() << ". " << product->getProductName() << ", Stock: " << product->getStock() 
            << ", Categoría: " << product->getCategory() << endl;
            
            actualNode = actualNode -> next;
            }
        }


}
