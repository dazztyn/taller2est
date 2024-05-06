#pragma once
using namespace std;
class Node
{
    public: // duda struct o class para nodo (clase arraigada a posible cambio y eliminacion posterior aclaracion de dudas)
        int value;
        Node* next;

        Node(int value)
        {
            this->value = value;
            next = nullptr;
        }
    
};

