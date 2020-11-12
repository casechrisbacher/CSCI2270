//Name: Case Chrisbacher
//Class: CSCI 2270
//Final Project

#ifndef HASHLINEAR_HPP
#define HASHLINEAR_HPP

#include <string>
#include <iostream>
using namespace std;


struct node
{
    int key;

};

class HashTable
{
    int tableSize;  // No. of buckets 

    // Pointer to an array containing buckets
    node* *table;
    int collision =0;
    node* createNode(int key, node* next);
public:
    HashTable(int bsize);  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    void printTable();
    int getNumOfCollision();
    int resetCollision();           // to 0

    node* searchItem(int key);
};

#endif
