#pragma once
#include<iostream>

using namespace std;

class Product
{
    private: // atributos
        string Category, Subcategory, IdProd, NameProd; // duda con atributos
        double PriceProd;
        
    public: // metodos
        Product(string, string, string, string, double); //constructor
        ~Product(); //destructor

        //getters y setters
        string getCategProd();
        string getSubcate();
        string getIdProd();
        string getNameProd();
        double getPriceProd();
        void setCategoProd(string);
        void setSubcate(string);
        void setIdProd(string);
        void setNameProd(string);
        void setPriceProd(double);
        
        string toString();


};
