#include<iostream>


using namespace std;
void menuClient()
{

}

void menuSales()
{

}

void startmenu() // inicia el menu del programa
{
    string opt;
    cout<< "Bienvenido al sistema de gestion"<< endl;
    do{

        cout<<"**************************************"<<endl;
        cout<<"Ingrese una opcion, ¿Usted es?: "<<endl;
        cout<<"1) Cliente"<<endl;
        cout<<"2) Trabajador"<<endl;
        cout<<"3) Salir"<<endl;
        cout<<endl;
        cout<<"**************************************"<<endl;
        cout<<">"; cin>>opt; cout<<endl;



        if(opt == "1"){menuClient();}
        else if(opt == "2"){menuSales();}
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