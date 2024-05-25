#include <iostream>
#include <stdlib.h>
#include <fstream> 
#include <sstream>
#include <queue> 
#include <vector> 
#include "Client.h"
#include "AverageClient.h"
#include "PriorityClient.h"
#include "Product.h"
#include "SanitaryProd.h"
#include "NutritionalProd.h"
#include "BabyProd.h"
#include "CosmeticProd.h"
#include "Medicine.h"
#include "HashMap.h"

using namespace std;

queue<Client*> fullClientQueue;
queue<Client*> clients;
queue<Client*> preferentialClients;
HashMap products;

vector <string> splitLine(string str, char chr){//divide la linea en partes usando el char ',' y retorna un vector de strings que son las partes
    vector<string> parts;
    stringstream ss(str);
    string part;

    while(getline(ss, part, chr)){
        parts.push_back(part);
    }
    return parts;
}//fin splitLine

void loadClients(){ //lee el archivo de clientes

    string line;
    ifstream file ("Clients.txt");
    char split = ',';

    while(getline(file,line)){

        vector<string> parts = splitLine(line,split);
        string name = parts[0];
        int age = stoi(parts[1]);
        string condition = parts[2];

        if(condition == "Ninguna"){
            Client* c = new AverageClient(-1,name,age,condition);
            fullClientQueue.push(c);
        }
        else{
            Client* c = new PriorityClient(-1,name,age,condition);
            fullClientQueue.push(c);
        }
    }

}//fin loadClients

void loadProducts(){ //lee el archivo de productos

    string line;
    ifstream file("Bodega.txt");
    char split = ',';

    while(getline(file,line)){

        vector<string> parts = splitLine(line,split);
        string category = parts[0];
        string subcategory = parts[1];
        string product = parts[2];
        int price = stoi(parts[3]);
        int ID = stoi(parts[4]);
        int stock = stoi(parts[5]);

        if(category == "Sanitario"){
            Product* p = new SanitaryProd(subcategory,product,price,ID,stock,category);
        }
        else if(category == "Alimenticio"){
            Product* p = new NutritionalProd(subcategory,product,price,ID,stock,category);
        }
        else if(category == "Medicamento"){
            Product* p = new Medicine(subcategory,product,price,ID,stock,category);
        }
        else if(category == "Para Bebe"){
            Product* p = new BabyProd(subcategory,product,price,ID,stock,category);
        }
        else if(category == "Cosmetico"){
            Product* p = new CosmeticProd(subcategory,product,price,ID,stock,category);
        }
    }
}//fin de loadProducts

void addProd() // rellenar (Puede que se necesite crear otro objeto (Farmacia))
{
    cout<<"Producto Agregado a la bodega"<<endl;
    cout<<endl;
}

void salesTicket() // rellenar
{
    cout<<"Generando boleta..."<<endl;
    cout<<endl;
}

void sortClients(){ //se reordenan los clientes por tipo de fila

    if(fullClientQueue.empty()){
        cout << "La fila ya está dividida" << endl;
    }

    else{
        while(!fullClientQueue.empty()){
            Client* actual = fullClientQueue.front();
            if(actual -> getCondition() == "Ninguna"){ //si no tiene condicion
                clients.push(actual);
                fullClientQueue.pop();
            }
            else{ //si es embarazada, 3ra edad o discapacitado
                preferentialClients.push(actual);
                fullClientQueue.pop();
            }
        }
    }

}//fin sortClients

void callNext() //rellenar
{
    sortClients();

    while(!preferentialClients.empty()){ //se atiende primero a los preferenciales

    Client* actualPref = preferentialClients.front();

    


    }

    cout<<"Siguiente Porfavor!"<<endl;
    cout<<endl;
}

void numberAtten() // le asigna los numeros de atencion a los clientes en la fila
{
    if(fullClientQueue.empty()){
        cout << "La fila esta vacia." << endl;
        return;
    }

    queue<Client*> aux;
    int numAttention = 0;

    while(!fullClientQueue.empty()){
        Client* actualClient = fullClientQueue.front();
        fullClientQueue.pop();
        actualClient -> setNumAttention(++numAttention);
        cout<<"Numero asignado para "<<actualClient -> getName() << ": " << numAttention << endl;
        aux.push(actualClient);
    }
    while(!aux.empty()){
        Client* actualClient = aux.front();
        aux.pop();
        fullClientQueue.push(actualClient);
    }
    cout << "Numeros asignados. Saliendo..." <<endl;

}

void newClient(){

}

void menuClient() // faltan opciones del menu por duda con el taller(opciones pendientes)
{   
    cout<<"--------------------------------"<<endl;
    cout<<"Atención al Cliente"<<endl; cout<<endl;
    cout<<"Ingrese Opcion: "<<endl;
    cout<<"1) Entregar numeros de atencion"<<endl;
    cout<<"2) Llamar siguiente cliente"<<endl;
    cout<<"3) Ingresar nuevo cliente."<<endl;
    cout<<"4) Salir"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<">";

    string opt; cin>>opt; cout<<endl;
    if(opt == "1")
    {   
        numberAtten(); //dato int aleatorio referenciado al cliente
    }
    else if (opt == "2")
    {
        callNext(); // cola de prioridad para el cliente (por preferencia)
    }
    else if (opt == "3")
    {
        //newClient();
    }
    else if (opt == "4")
    {
        cout<< "Saliendo..."<<endl;
        return;
    }
    else
    {
        cout<< "Opcion invalida. Saliendo..."<<endl;
        return;
    }
    
}// fin menuClient

void menuSales() //(opciones pendientes)
{
    cout<<"--------------------------------"<<endl;
    cout<<"Gestion de Ventas."<<endl; cout<<endl;
    cout<<"Ingrese Opcion: "<<endl;
    cout<<"1) Agregar Producto a Bodega."<<endl;
    cout<<"2) Generar Boleta de Venta."<<endl;
    cout<<"3) Salir."<<endl;
    cout<<"--------------------------------"<<endl; cout<<">";

    string opt; cin>>opt; cout<<endl;

    if(opt == "1") { addProd(); } //agrega productos a la lista enlazada (se agrega a bodega)
    else if (opt == "2") { salesTicket(); } //solicita la boleta de venta (lista enlazada de producto con cliente)

    else if (opt == "3")
    {
        cout<< "Saliendo..."<<endl;
        return;
    }
    else
    {
        cout<< "Opcion invalida. Saliendo..."<<endl;
        return;
    }
}

void startmenu() // inicia el menu del programa
{
    string opt;
    cout<< "Bienvenido al Sistema de Farmacia."<< endl;
    do{
        cout<<"**************************************"<<endl; cout<<endl;
        cout<<"Ingrese Opcion: "<<endl;
        cout<<"1) Gestionar clientes."<<endl;
        cout<<"2) Gestionar ventas."<<endl;
        cout<<"3) Salir."<<endl;
        cout<<endl; cout<<"**************************************"<<endl;
        cout<<">"; cin>>opt; cout<<endl;

        if(opt == "1") {menuClient(); } //menu gestion clientes
        else if(opt == "2"){ menuSales(); }//menu gestion ventas
        else if(opt == "3"){ cout<< "Tenga buen dia. ¡Adios!"<<endl; }

        else{
            cout<<"Opcion incorrecta! porfavor ingrese una opcion valida"<<endl;
            cin.clear();
        }
    }
    while(opt != "3");
}// fin startmenu

int main()
{
    //aqui van las funciones de lectura de archivos
    loadClients();
    loadProducts();
    startmenu();
    return 0;
}