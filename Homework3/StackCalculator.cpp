#include <iostream>
#include <iomanip>
#include "StackCalculator.hpp"
using namespace std;


StackCalculator :: StackCalculator(){
    head = nullptr;
}

StackCalculator :: ~StackCalculator()
{
    while(!isEmpty()){
        pop();
    }
}

bool StackCalculator :: isEmpty()
{
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
}

void StackCalculator :: push(float inputnumber)
{
    Op* temp = new Op;
    temp-> num = inputnumber;
    temp -> next = head;
    head = temp;
}

void StackCalculator:: pop()
{
    Op* temp = new Op;
    if(head == NULL){
        cout<<"Stack empty, cannot pop an item."<<endl;
    }
    else{
        temp = head;
        head = temp-> next;
        delete temp;
    }
}

Op* StackCalculator:: peek()
{
    if(isEmpty()){
        cout<<"Stack empty, cannot peek."<<endl;
    }

        return head;
    
}

bool StackCalculator :: calculate(std::string symbol)
{
    float firstvary = 0;
    float secondvary = 0;
    float result = 0;
    Op*temp = new Op;
    temp = head;

    if(symbol != "+"){              //checks to make sure the symbol is correct
        if(symbol != "*"){
            cout<<"err: invalid operation"<<endl;
            return false;
        }
    }
    if(isEmpty()){                                      //Can't add/ multiply nothing together
        cout<<"err: not enough operands"<<endl;
        return false;
    }

    firstvary = temp-> num;     //declaring first thing to get added / multiplied
    pop();                      //gets rid of it immediatly
    temp = head;                //re assigns the temp as the new head

    if(temp == NULL){                       //this means that there was only one number in it
        push(firstvary);                    //we need to put the popped variable back in
        cout<<"err: not enough operands"<<endl;
        return false;
    
    }
    secondvary = temp-> num;                //since we know this exists, assign it and pop it
    pop();

    if(symbol == "+"){
        result = firstvary + secondvary;
        push(result);
        return true;
    }

    if(symbol == "*"){
        result = firstvary * secondvary;
        push(result);
        return true;
    }

}