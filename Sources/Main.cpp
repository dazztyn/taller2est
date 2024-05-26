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
vector<Ticket*> tickets; //boletas

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

        Product* p = new Product(subcategory,product,price,ID,stock,category);

        storage -> insert(p,p -> getID()); //se inserta el producto en la tabla hash de la bodega
    }

}//fin de loadProducts

void reStock(){ //permite reponer las unidades de un producto en la tabla hash

    storage -> displayAllProducts();
    cout << endl;
    cout << "¿A cual producto desea agregar stock?" << endl;

    string id;
    cout<<">";cin>>id;cout<<endl;

    int idSelected = stoi(id);

    Product* p = storage -> get(idSelected);

    cout << "Cuantas unidades desea reponer? (ej: 20)" << endl;

    string cant;
    cout << ">";cin>>cant;cout<<endl;
    int amount = stoi(cant);

    p -> setStock(p -> getStock() + amount);

    cout << "Se han repuesto " << amount << " unidades de " << p -> getProductName() << ". " << endl;

}//fin restock

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

void addProduct(int productID, vector<Product*> cart, int amount) { //agrega el producto comprado al carrito

    Product* product = storage -> get(productID); //se busca la id del producto usando la llave (de mismo numero)

    if (product != nullptr) { //producto encontrado -> se agrega

        if(product -> getStock() >= amount){ //hay stock disponible

            product -> setStock(product -> getStock() - amount); //se modifica el stock

            for(int i = 0; i < amount; i++){
                cart.push_back(product);
            }
        }

        else{ //no hay stock disponible
            cout << "No hay stock suficiente, cancelando venta." << endl;
            return;
        }
    }
    else {
        cout << "Producto con ID " << product -> getID() << " no encontrado." << endl; //no encontrado
    }
} //fin addProduct

bool selectCategory(){ //permite seleccionar una categoria de producto para filtrar busqueda

    cout << "1) Sanitario" << endl;
    cout << "2) Alimenticio" << endl;
    cout << "3) Medicamento" << endl;
    cout << "4) Para Bebe" << endl;
    cout << "5) Cosmetico" << endl;
    string opt;
    cout << ("Ej: 1") << endl;
    cout << ">"; cin >> opt; cout<<endl; 

    return storage -> displayProducts(opt);

}//fin selectCategory

void startSale(){ //despliega el catalogo de productos y procesa las ventas

    bool canBeDisplayed = selectCategory(); //se verifica si es una categoria valida

    while(!canBeDisplayed){ 
        cout << "Categoría incorrecta, vuelva a intentarlo. "<<endl;
        canBeDisplayed = selectCategory();
    }

    cout << endl;
    vector<Product*> cart; //se crea el carrito

    cout << "¿Que va a llevar?" << endl;
    cout << "Ingrese ID o '-1' para salir." << endl;

    string id, amount;

    cout << ">"; cin >> id; cout << endl;
    if(id == "-1"){return;}
    cout << "Cuantas unidades? (ej: 2) " << endl;
    cout << ">"; cin >> amount; cout << endl;

    while(id != "-1"){

        int idKey = stoi(id); //se castea el cin a int
        int prodAmount = stoi (amount);

        addProduct(idKey,cart,prodAmount); //se agrega el producto al carrito usando la llave ingresada
        cin.clear();

        cout << "Producto agregado al carrito! ¿Desea agregar algo mas?" << endl;
        cout << "Ingrese ID o '-1' para salir." << endl;
        cout << ">"; cin >> id; cout << endl;

        if(id == "-1"){break;}
        cout << "Cuantas unidades? (ej: 2) " << endl;
        cout << ">"; cin >> amount; cout << endl;
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
    cout << "Separando filas..." << endl;

    sortClients(); //se reordenan los clientes por tipos de filas

    cout << "Se han separado las filas" << endl;

}//fin numberAtten

void callNextPref(){ //se llama a los clientes de la fila preferencial

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

    
    cout << endl;

    while (!thirdAges.empty()){ //se atiende a los de 3ra edad

        Client* actual = thirdAges.front();
        cout << "Atendiendo a: " << actual -> getName() << endl;
        cout << endl;
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
    cout << "Fila de clientes preferenciales vaciada. " << endl;

}//fin de callnextpref

void callNextClient() { //llama a los, clientes sin discapacidades

    if(!preferentialClients.empty()){
        cout << "Hay clientes en la fila preferencial, atiendalos primero" << endl;
        return;
    }
    else{
        while(!clients.empty()){

            Client* actual = clients.front();
            cout << "Atendiendo a: " << actual -> getName() << endl;
            startSale();
            cout << "Venta finalizada, se ha registrado la boleta. Siguiente!" << endl;
            clients.pop();
        }
        cout << endl;
        cout << "Fila de clientes no preferenciales vaciada. " << endl;
    }
}

void menuClient() // faltan opciones del menu por duda con el taller(opciones pendientes)
{   
    cout<<"--------------------------------"<<endl;
    cout<<"Atención al Cliente"<<endl; cout<<endl;
    cout<<"Ingrese Opcion: "<<endl;
    cout<<"1) Entregar numeros de atencion"<<endl;
    cout<<"2) Llamar Clientes preferenciales"<<endl;
    cout<<"3) Llamar Clientes de fila normal"<<endl;
    cout<<"4) Salir"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<">";

    string opt; cin>>opt; cout<<endl;

    if(opt == "1"){giveNumbers();}
    else if (opt == "2"){callNextPref();}
    else if (opt == "3"){callNextClient();}
    else if (opt == "4"){ cout<< "Saliendo..."<<endl; return;}
    else {cout<< "Opcion invalida. Saliendo..."<<endl; return;}
    cin.clear();
    
}// fin menuClient

void menuSales() //(opciones pendientes)
{
    cout<<"--------------------------------"<<endl;
    cout<<"Gestion de Ventas."<<endl; cout<<endl;
    cout<<"Ingrese Opcion: "<<endl;
    cout<<"1) Agregar Stock de producto."<<endl;
    cout<<"2) Generar Boleta de Venta."<<endl;
    cout<<"3) Salir."<<endl;
    cout<<"--------------------------------"<<endl; cout<<">";

    string opt; cin>>opt; cout<<endl;

    if(opt == "1") { reStock(); } //agrega productos a la lista enlazada (se agrega a bodega)
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