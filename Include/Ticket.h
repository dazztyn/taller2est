#pragma once
#include <iostream>
#include "Product.h"
#include <vector>

class Ticket{
private:
    vector<Product*> products;
    int total;

public:
    Ticket(int);

    void fillTicket(vector<Product*>);
    void displayTicketInfo();
};