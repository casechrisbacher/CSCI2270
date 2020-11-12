//Name: Case Chrisbacher
//Class: CSCI 2270
//Final Project

#ifndef DLL_HPP
#define DLL_HPP
#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
    int key;
    Node* next;
    Node* previous;
};

class dll {
    private:
        Node*head;
    
    public:
    dll();
    bool isEmpty();
    void insertNode(int inputkey);      //where
    void searchNode(int inputkey);
    void displayMethods();              //ask about this

};
#endif