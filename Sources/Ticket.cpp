#include <iostream>
#include "Product.h"
#include "Ticket.h"
#include <vector>

Ticket::Ticket(int total){
    this -> total = total;
}

void Ticket::addProductsToTicket(vector<Product*> productList){

    for(Product* p : productList){
        this -> products.push_back(p);
    }
}

void Ticket::displayTicketInfo(){

    if(this -> products.size() == 0) { 
        cout << "Boleta vacia" <<endl;
        cout << endl;
    }
    else{
        cout << "---------------------------------------" << endl;
        cout << "        *Recibo de Compra*"<<endl;
        cout << "Productos comprados: " << this -> products.size() << endl;
        
        for(Product* p: this -> products){
            cout << "-" << p -> getProductName() << endl;
        }
        
        cout<<". Total: &" << this -> total << endl;
        cout << endl;
        cout << "---------------------------------------" << endl;
    }
}