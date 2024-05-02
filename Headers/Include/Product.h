#pragma once
#include<iostream>

using namespace std;

class Product
{
    private: // atributos
        int IdProd;
        string NameProd, Category, Subcategory; // duda con atributos
        int PriceProd, QuantityStore;

        
    public: // metodos
        Product(int, string, string, string, int, int); //constructor
        ~Product(); //destructor

        //getters
        int getIdProd();
        string getNameProd();
        string getCategProd();
        string getSubcate();
        int getPriceProd();
        int getQuantity();
        void setIDProd(int);
        void setNameProd(string);
        void setCategProd(string);
        void setSubcate(string);
        void setPriceProd(int);
        void setQuantity(int);

    
        
        string toString();

        void substractQuantity(int);


};
