//Name: Case Chrisbacher
//Class: CSCI 2270
//Final Project

#include "hashquad.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

HashTable :: HashTable(int bsize){              //constructor function for table
    tableSize = bsize;
    table = new node*[tableSize];
    for(int i = 0; i < tableSize; i++){             //sets to NULL
        table[i] = NULL;
    }
}

node * HashTable :: createNode(int key){            //constructor for nodes to be put into table
    node * tempnode = new node;
    tempnode->key = key;
    return tempnode;
}

bool HashTable :: insertItem(int key){
    int quad = 1;                           //quad starts at one
    int index = key % tableSize;            //first position to try
    node * temp = createNode(key);
    if(table[index] == NULL){               //first index empty -> insert
        table[index] = temp;
    }
    else{
 
        while(table[index] != NULL){                    //index not empty    
            if(index + quad*quad >= tableSize){         //to prevent from inserting out of the table size (SEG FAULT)
                index = index % tableSize;
            }
            else{
                index = index + quad*quad;          //index repositioned to index + quad squared
                quad++;                             //quad is increased by one, in case that position is still NULL
                collision++;                        //this is a collision
            }                                       //IF that position is filled, it tries index plus the (quad + 1) squared and keeps inc until position is found
        }                                           
        table[index] = temp;                        //sets node at found position
        
    }
    return true;
}

node* HashTable :: searchItem(int key){              
    int quad = 1;
    int index = key % tableSize;            //first position
    node * temp = new node();
    temp = table[index];                //setting node
    if(temp->key == key){           //found in first slot
        return temp;
    }
    else{
        while(temp->key != key){
            if(index + pow(quad, 2) >= tableSize){      //mods if passes table size, just like insert
                index = index % tableSize;
            }
            else{
                index = index + pow(quad, 2);               //has same square function for search, to follow same track as insert
                quad++;
            }
            temp = table[index];                            //resets what the node is for the new index
            
            
        }                                                   //breaks when found
        

        return temp;

    }
}

int HashTable :: getNumOfCollision()
{
    return collision;
}

int HashTable :: resetCollision(){          //to 0
    collision = 0;
    return collision;
}