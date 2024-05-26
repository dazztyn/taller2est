#include <iostream>
#include "Product.h"
#include "Ticket.h"
#include <vector>

Ticket::Ticket(int total){
    this -> total = total;
}

void Ticket::fillTicket(vector<Product*> boughtProducts){

    for(Product* p: boughtProducts){

        this -> products.push_back(p);
    }

}

void Ticket::displayTicketInfo(){

    int count = 0, totalAmount = 0;

    for(Product* p: this -> products){
        count++;
        totalAmount += p->getPrice();
    }

    cout << "Productos comprados: " << this -> products.size() << "Total: " << this -> total << endl;
}