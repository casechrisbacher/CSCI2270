//CSCI 2270
//Name: Case Chrisbacher
//Godley
//Homework 2

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct Country
{
 string name; // name of the country
 string message; // message this country has received
 int numberMessages; // no. of messages passed through this country
 Country *next; // pointer to the next country
};

class CountryNetwork{
    CountryNetwork :: Country * head;;

    CountryNetwork(){
        head = NULL;
    }
    
    bool CountryNetwork::isEmpty() 
    {
    // TODO: Complete the definition
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
    }
    
    Country* CountryNetwork::searchNetwork(string countryName) 
    {

    Country* tmp = head;
    bool found = false;

    while(found == false && tmp != NULL){
        if(tmp->name == countryName){
            found = true;
        }
        else{
            tmp = tmp->next;
        }

    }
    return tmp;

    }



    void CountryNetwork::insertCountry(Country* previous, string countryName)
    {
    // TODO: Complete the definition
    
    Country * x = new Country();
    x->name = countryName;
    Country * temp = new Country();
    
    if(previous != NULL){
        temp = previous-> next;
        cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;

        previous->next = x;
        previous->next->next = temp;
    
    }
    if(previous == NULL){
            cout << "adding: " << countryName << " (HEAD)" << endl;
            temp = head;
            head = x;
            head->next = temp;   
    }

    }

    void CountryNetwork :: deleteCountry(string countryName) {
    Country * temp = head;
    bool deleted = false;
    
    while(temp != NULL && deleted == false){
        if (temp -> name == countryName && temp == head){
                head = temp->next;
                deleted = true;
                return;
        
        }
        if(temp-> next != NULL){
        if(temp-> next -> name == countryName){
            delete temp -> next;
            temp -> next = temp -> next -> next;
            
            deleted = true;
            return;
        }
        }
        temp = temp -> next;

    }
    cout<<"Country does not exist."<<endl;

    
    
}

void CountryNetwork :: transmitMsg(string receiver, string msg){
    Country * tmp = head;
    bool received = false;
    
    while(tmp != NULL && received == false){

        tmp->message = msg;
        tmp -> numberMessages = tmp -> numberMessages + 1;
        cout << tmp->name << " [# messages received: " << tmp->numberMessages << "] received: " << tmp->message << endl;

        if(tmp-> name == receiver){
            return;
        }
        if(head == NULL){
            cout<<"Empty List"<<endl;
        }
        tmp = tmp -> next;
        
    }
    cout<<"Country not found"<<endl;
}

void CountryNetwork::loadDefaultSetup() {
    deleteEntireNetwork();
    Country * temp = new Country();
    Country*x = head;

    string arr[6] = {"United States", "Canada", "Brazil", "India", "China", "Australia"};
    
    for(int k = 0; k < 6; k++){
        
        
        if(k == 0){
            temp=NULL;
            insertCountry(x, arr[k]);
            
        }
        else{

            insertCountry(x, arr[k]);
        }

        x = head;
        while(x != NULL){
            if(x-> next == NULL){
                break;
            }
            x = x-> next;
            
        }

    }   
    
}

};
#endif