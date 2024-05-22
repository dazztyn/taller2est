#include <iostream>
#include <stdlib.h> //lib standar
#include <fstream> //lectura de archivos
#include <sstream> //lectura de archivos
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

using namespace std;

queue<Client*> clients;
queue<Client*> preferentialClients;

vector <string> splitLine(string str, char chr){

    vector<string> parts;
    stringstream ss(str);
    string part;

    while(getline(ss, part, chr)){
        parts.push_back(part);
    }
    return parts;
}//fin splitLine

void loadClients(){

    string line;
    ifstream file ("Clients.txt");
    char split = ',';

    while(getline(file,line)){

        vector<string> parts = splitLine(line,split);
        int numAttention = stoi(parts[0]);
        string name = parts[1];
        int age = stoi(parts[2]);
        string condition = parts[3];

        if(condition == "Ninguna"){
            Client* c = new AverageClient(numAttention,name,age,condition);
            clients.push(c);
        }
        else{
            Client* c = new PriorityClient(numAttention,name,age,condition);
            preferentialClients.push(c);
        }
    }

}//fin loadClients

void loadProducts(){

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

void callNext() //rellenar
{
    cout<<"Siguiente Porfavor!"<<endl;
    cout<<endl;
}
void numberAtten() // rellenar
{
    cout<<"Numero dado"<<endl; // rellenar
    cout<<endl;
}
void menuClient() // faltan opciones del menu por duda con el taller(opciones pendientes)
{   
    cout<<"--------------------------------"<<endl;
    cout<<"Atención al Cliente"<<endl; cout<<endl;
    cout<<"Ingrese Opcion: "<<endl;
    cout<<"1) Entregar numero de atencion"<<endl;
    cout<<"2) Llamar siguiente cliente"<<endl;
    cout<<"3) Salir"<<endl;
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