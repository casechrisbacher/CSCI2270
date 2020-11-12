//Name: Case Chrisbacher
//Class: CSCI 2270
//Final Project

#include "hashchain.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

HashTable :: HashTable(int bsize){              //constructor
    tableSize = bsize;
    table = new node*[tableSize];
    for(int i = 0; i < tableSize; i++){         //sets every slot NULL
        table[i] = NULL;
    }
}

node * HashTable :: createNode(int key, node * next){           //creates nodes
    node * tempnode = new node;
    tempnode->key = key;
    tempnode->next = NULL;
    return tempnode;
}

bool HashTable :: insertItem(int key){

    int index = key % tableSize;        //position to be inserted
    node * temp = new node; 
    node * newnode = new node;
    newnode->key = key;                 //setting values of key 
    newnode->next = NULL;               //equiv to calling createNode

    while(index >= tableSize){          //if the index goes out of total slots, it needs to be modded again
        index = index % tableSize;
    }
    if(table[index] == NULL){               //If it is first node there
        table[index] = newnode;             //its placed there
        return true;
    }
    else{
        node* temp = table[index];

        while(temp->next != NULL){
            temp = temp->next;                  //goes through chain, until next is empty
            collision++;                        //AKA a collision
        }
        
        temp->next = newnode;       //sets node to next when next is node
        
    }
    return true;
}

node* HashTable :: searchItem(int key){
    int index = key % tableSize;                //same mod as insert
    while(index >= tableSize){
        index = index % tableSize;
    }
    node * temp = table[index];

    if(temp->key != key){     

        while(temp->key != key && temp != NULL){        //goes through while loop until key is found
            temp = temp->next;

        }

    }
    
    return temp;
}

int HashTable :: getNumOfCollision()
{
    return collision;
}

int HashTable :: resetCollision(){          //sets col to 0
    collision = 0;
    return collision;
}

