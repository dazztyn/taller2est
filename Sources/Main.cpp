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
#include "HashMap.h"
#include "Ticket.h"

using namespace std;

queue<Client*> fullClientQueue;
queue<Client*> clients;
queue<Client*> preferentialClients;
HashMap* storage = new HashMap();
vector<Ticket*> tickets;

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
    ifstream file ("Clientes.txt");
    char split = ',';

    while(getline(file,line)){

        vector<string> parts = splitLine(line,split);
        string name = parts[0];
        int age = stoi(parts[1]);
        string condition = parts[2];

        if(condition == "Ninguna"){
            Client* c = new AverageClient(-1,name,age,condition);
            fullClientQueue.push(c);
            cout << "se agrega a " << name << endl;
        }
        else{
            Client* c = new PriorityClient(-1,name,age,condition);
            fullClientQueue.push(c);
            cout << "se agrega a " << name << endl;
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

        Product* p = new Product(subcategory,product,price,ID,stock,category);

        storage -> insert(p,p -> getID()); //se inserta el producto en la tabla hash de la bodega
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
        cout << "La fila ya está dividida o no hay clientes." << endl;
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

void addProduct(int productID, vector<Product*> cart, int amount) { //agrega el producto comprado al carrito, usado unicamente para generar boletas

    Product* product = storage -> get(productID); //se busca la id del producto usando la llave (de mismo numero)

    if (product != nullptr) { //producto encontrado -> se agrega

        if(product -> getStock() > amount){ //hay stock disponible

            product -> setStock(product -> getStock() - amount); //se modifica el stock

            for(int i = 0; i < amount; i++){
                cart.push_back(product);
            }
        }
    }
    else {
        cout << "Producto con ID " << product -> getID() << " no encontrado." << endl; //no encontrado
    }
} //fin addProduct

void startSale(){ //despliega el catalogo de productos y procesa las ventas

    vector<Product*> cart;
    cout << "¿Que va a llevar?" << endl;
    cout << "Ingrese ID o '-1' para salir." << endl;

    string id, amount;

    cout << ">"; cin >> id; cout << endl;
    cout << "Cuantas unidades? (ej: 2) " << endl;
    cout << ">"; cin >> amount; cout << endl;

    while(id != "-1"){

        int idKey = stoi(id); //se castea el cin a int
        int prodAmount = stoi (amount);

        addProduct(idKey,cart,prodAmount); //se agrega el producto al carrito usando la llave ingresada

        cout << "Ingrese ID o '-1' en ambas opciones para salir." << endl;
        cout << ">"; cin >> id; cout << endl;
    }

    int subtotal = 0;
    for(Product* p: cart){
        subtotal += p -> getPrice();
    }

    Ticket* ticket = new Ticket(subtotal); //se genera una boleta
    tickets.push_back(ticket);

}

void giveNumbers() // le asigna los numeros de atencion a los clientes en la fila
{
    if(fullClientQueue.empty()){
        cout << "La fila esta vacia o no hay clientes." << endl;
        return;
    }

    queue<Client*> aux;
    int numAttention = 0;

    while(!fullClientQueue.empty()){
        Client* actualClient = fullClientQueue.front();
        actualClient -> setNumAttention(++numAttention);
        cout<<"Numero asignado para "<<actualClient -> getName() << ": " << numAttention << endl;
        aux.push(actualClient);
        fullClientQueue.pop();
    }

    while(!aux.empty()){
        Client* actualClient = aux.front();
        fullClientQueue.push(actualClient);
        aux.pop();
    }
    cout << endl; cout << "Numeros asignados con éxito" <<endl;

}//fin numberAtten

void callNextPref(){ //se llama a los clientes de la fila preferencial

    sortClients(); //se reordenan los clientes por tipos de filas

    queue<Client*> thirdAges;
    queue<Client*> disableds;
    queue<Client*> pregnants;

    while(!preferentialClients.empty()){ //se separa la cola entre los tipos de preferencial en 3 colas, luego se revisan por prioridad

        Client* actualPref = preferentialClients.front();

        if(actualPref -> getCondition() == "Tercera Edad"){
            thirdAges.push(actualPref);
            preferentialClients.pop();
        }
        if(actualPref -> getCondition() == "Discapacitado"){
            disableds.push(actualPref);
            preferentialClients.pop();
        }
        if(actualPref -> getCondition() == "Embarazada"){
            pregnants.push(actualPref);
            preferentialClients.pop();
        }

    }

    storage -> displayProducts();
    cout << endl;

    while (!thirdAges.empty()){ //se atiende a los de 3ra edad

        Client* actual = thirdAges.front();
        cout << "Atendiendo a: " << actual -> getName() << endl;
        startSale();
        cout << "Venta finalizada, se ha registrado la boleta. Siguiente!" << endl;
        thirdAges.pop(); //se avanza al siguiente
    }

    while(!disableds.empty()){ //se atiende a los discapacitados
        Client* actual = disableds.front();
        cout << "Atendiendo a: " << actual -> getName() << endl;
        startSale();
        cout << "Venta finalizada, se ha registrado la boleta. Siguiente!" << endl;
        disableds.pop(); //se avanza al siguiente        
    }

    while(!pregnants.empty()){ //se atiende a las embarazadas
        Client* actual = pregnants.front();
        cout << "Atendiendo a: " << actual -> getName() << endl;
        startSale();
        cout << "Venta finalizada, se ha registrado la boleta. Siguiente!" << endl;
        pregnants.pop(); //se avanza al siguiente        
    }

    cout<<endl;

}//fin de callnextpref

void menuClient() // faltan opciones del menu por duda con el taller(opciones pendientes)
{   
    cout<<"--------------------------------"<<endl;
    cout<<"Atención al Cliente"<<endl; cout<<endl;
    cout<<"Ingrese Opcion: "<<endl;
    cout<<"1) Entregar numeros de atencion"<<endl;
    cout<<"2) Llamar siguiente cliente"<<endl;
    cout<<"4) Salir"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<">";

    string opt; cin>>opt; cout<<endl;

    if(opt == "1"){giveNumbers();}
    else if (opt == "2"){ callNextPref();} // cola de prioridad para el cliente (por preferencia)

    else if (opt == "3"){ cout<< "Saliendo..."<<endl; return;}
    else { cout<< "Opcion invalida. Saliendo..."<<endl; return; }
    
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
    loadClients(); loadProducts();
    startmenu(); //se inicia el sistema
    return 0;
}