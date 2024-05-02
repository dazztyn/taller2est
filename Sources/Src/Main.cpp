#include<iostream>


using namespace std;


void addProd() // rellenar
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
    cout<<endl;
    cout<<"Bienvenido al sistem de atencion para clientes"<<endl;
    cout<<"Escoja una opcion: "<<endl;
    cout<<"1) Entregar Numero de Atencion"<<endl;
    cout<<"2) Llamar al siguiente Cliente"<<endl;
    cout<<"3) Salir"<<endl;
    cout<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<">";

    string opt;
    cin>>opt;
    cout<<endl;
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
    cout<<endl;
    cout<<"Bienvenido al sistema de ventas"<<endl;
    cout<<"Escoja una opcion: "<<endl;
    cout<<"1) Agregar  Producto a Bodega"<<endl;
    cout<<"2) Generar Boleta de Venta"<<endl;
    cout<<"3) Salir"<<endl;
    cout<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<">";

    string opt;
    cin>>opt;
    cout<<endl;
    if(opt == "1")
    {   
        addProd(); //agrega productos a la lista enlazada (se agrega a bodega)
    }
    else if (opt == "2")
    {
        salesTicket(); //solicita la boleta de venta (lista enlazada de producto con cliente)
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
}

void startmenu() // inicia el menu del programa
{
    string opt;
    cout<< "Bienvenido al sistema de gestion"<< endl;
    do{

        cout<<"**************************************"<<endl;
        cout<<endl;
        cout<<"Ingrese una opcion, ¿Desea ver ventas o atender clientes?: "<<endl;
        cout<<"1) Clientes"<<endl;
        cout<<"2) Ventas"<<endl;
        cout<<"3) Salir"<<endl;
        cout<<endl;
        cout<<"**************************************"<<endl;
        cout<<">"; cin>>opt; cout<<endl;



        if(opt == "1")
        {
            menuClient();
            
        }
        else if(opt == "2")
        {
            menuSales(); 
            
        }
        else if(opt == "3"){ 
            cout<< "Tenga buen dia. ¡Adios!"<<endl;}
        else{
            cout<<"Opcion incorrecta! porfavor ingrese una opcion valida"<<endl;
            cin.clear();
        }

    }
    while(opt != "3");
}// fin startmenu

int main()
{

    startmenu();
    return 0;
}