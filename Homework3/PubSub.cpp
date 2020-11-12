#include <iostream>
#include <string>
#include "PubSub.hpp"
using namespace std;



PubSub :: PubSub()
{
    queueFront = 0;
    queueEnd = 0;
}

bool PubSub :: isEmpty()
{
    if(counter == 0){
        return true;
    }
    return false;
}

bool PubSub :: isFull()
{
    if(counter == 20){
        return true;
    }
    return false;
}

void PubSub :: enqueue(std::string item)
{
    if(!isFull()){
        
        queue[queueEnd] = item;
        counter++;
        if(queueEnd == 19){
            queueEnd = 0; 
        }
        else{
            queueEnd++;
        }
    }
    else{
        cout<<"Queue full, cannot add new item"<<endl;
    }
}

void PubSub :: dequeue()
{
    if(counter != 0){
        queue[queueFront] = "";
        if(queueFront == 19){
            queueFront = 0;
        }
        else{
        queueFront++;
        }
        counter--;
    }
    else
    {
        cout<<"Queue empty, cannot dequeue an item"<<endl;
    }
    
}

int PubSub :: queueSize()
{
    return counter;
}

string PubSub :: peek()
{
    if(!isEmpty()){
        return queue[queueFront];
    }
    else{
        cout<<"Queue empty, cannot peek"<<endl;
        return "";
    }
    
}