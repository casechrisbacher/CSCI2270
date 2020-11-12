/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represent communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"
#include <iomanip>
#include <iostream>

using namespace std;

void displayMenu();
void handleUserInput(CountryNetwork& CountryNet); 

/************************************************
      Definitions from main.cpp
************************************************/

/* DO NOT MODIFY THIS MAIN FUNCTION */
int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    CountryNetwork CountryNet;

    // this will loop until user selects quit option
    handleUserInput(CountryNet);

    cout << "Goodbye!" << endl;
    return 0;
}

void handleUserInput(CountryNetwork& CountryNet)
{
    bool quit = false;
    string s_input;
    int input;

    // loop until the user quits
    while (!quit)
    {
        displayMenu();

        // read in input, assuming a number comes in
        getline(cin, s_input);
        try
        {
            input = stoi(s_input);
        }
        catch (exception& e)
        {
            // non-numeric input. trigger the default switch case.
            input = 10;
        }

        switch (input)
        {
            // print all nodes
            case 1: //rebuild network                
                CountryNet.loadDefaultSetup();
                CountryNet.printPath();
                break;

            case 2: // print path
                CountryNet.printPath();
                break;

            case 3: // add country
              {
                string newCountryName;
                string prevCountryName;
                cout << "Enter a new country name: " << endl;
                getline(cin, newCountryName);

                cout << "Enter the previous country name (or First): " << endl;
                getline(cin, prevCountryName);

                while(!CountryNet.searchNetwork(prevCountryName) and prevCountryName != "First")
                {
                  cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
                  getline(cin, prevCountryName);
                }

                // find the node containing prevcountry
                Country *tmp = NULL;
                if(prevCountryName != "First")
                {
                    tmp = CountryNet.searchNetwork(prevCountryName);
                }

                CountryNet.insertCountry(tmp, newCountryName);
                CountryNet.printPath();
              }
                break;

            case 4: // delete country
              {
                string country;
                cout << "Enter a country name: " << endl;
                getline(cin, country);
                CountryNet.deleteCountry(country);
                CountryNet.printPath();
              }
                break;

            case 5: // transmit
              {
                cout<< "Enter name of the country to receive the message: "<<endl;
                string country;
                getline(cin, country);
                cout << "Enter the message to send: " << endl;
                cout<<endl;
                string message;
                getline(cin, message);
                CountryNet.transmitMsg(country, message);
              }
                break;
            case 6: // clear
              {
                cout << "Network before deletion" <<endl;
                CountryNet.printPath();
                CountryNet.deleteEntireNetwork();
                cout << "Network after deletion" <<endl;
                CountryNet.printPath();
              }
                break;
            case 7: // quit
                quit = true;
                cout << "Quitting... cleaning up path: " << endl;
                break;

            default: // invalid input
                cout << "Invalid Input" << endl;
                break;
        }
    }
}

void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Add Country " << endl;
    cout << " 4. Delete Country " << endl;
    cout << " 5. Transmit Message" << endl;
    cout << " 6. Clear Network " << endl;
    cout << " 7. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}


/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()     
{
    head = NULL;
}


/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{
     if(head == NULL){      //Head is null if its empty
        return true;
    }
    else{
        return false;
    }
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName) 
{    
    Country * x = new Country();
    x->name = countryName;
    Country * temp = new Country();
    
    if(previous != NULL){               //if there are other pointers already
        temp = previous-> next;         //temp set to the position to add in the country
        cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;

        previous->next = x; 
        previous->next->next = temp;        //add in country

    }
    if(previous == NULL){
            cout << "adding: " << countryName << " (HEAD)" << endl;
            temp = head;            //add country into front if it is empty
            head = x;
            head->next = temp;   
    }

}


/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
void CountryNetwork::deleteCountry(string countryName) 
{
    Country * temp = head;
    bool deleted = false;
    
    while(temp != NULL && deleted == false){                    //goes through the LL
        if (temp -> name == countryName && temp == head){       //It it is found at the front
                head = temp->next;                              //moves head to the next in list
                deleted = true;
                return;
        
        }
        if(temp-> next != NULL){
        if(temp-> next -> name == countryName){             //if the next in the list is the country
            delete temp -> next;   
            temp -> next = temp -> next -> next;            //makes the next value in the list the next next value
            
            deleted = true;
            return;
        }
        }
        temp = temp -> next;

    }
    cout<<"Country does not exist."<<endl;          //if it makes it this far the country doesnt exist
}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
    //TODO: Complete this function
    deleteEntireNetwork();
    Country*x = head;

    string arr[6] = {"United States", "Canada", "Brazil", "India", "China", "Australia"};       //initialize array
    
    for(int k = 0; k < 6; k++){
        
            insertCountry(x, arr[k]);           //inserts country in the array


        x = head;
        while(x != NULL){           // sets the next pointer
            if(x-> next == NULL){
                break;
            }
            x = x-> next;
            
        }

    }
}


/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
    Country* tmp = head;
    bool found = false;

    while(found == false && tmp != NULL){       //goes through LL until found or end
        if(tmp->name == countryName){
            found = true;   
        }
        else{
            tmp = tmp->next;
        }

    }
    return tmp;
}

/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork()
{
    //TODO: Complete this function
        Country * temp = head;
        bool deleted = false;
    
    while(temp != NULL){                            //goes through LL
        cout<<"deleting: "<<temp-> name<<endl;
        delete temp;                            //deletes
        temp = temp -> next;                       //sets pointer to next
        deleted = true;
    }
    if(deleted == true){
    cout<<"Deleted network"<<endl;
    }
    head = NULL;
}
    


/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string msg)
{
    // TODO
    Country * tmp = head;
    bool found = false;

    if(head == NULL){                   //EMPTY
            cout<<"Empty list"<<endl;
            return;
        }
    while(tmp != NULL){             //goes through LL
        if(tmp->name == receiver){
            found = true;
        }
        tmp = tmp->next;
    }
    if (found == false){
        cout<<"Country not found"<<endl;
    }

    tmp = head;             //resets tmp to the head
    
    while(tmp != NULL && found == true){            //if it was found and until its not empty

        tmp->message = msg;
        tmp -> numberMessages = tmp -> numberMessages + 1;
        cout << tmp->name << " [# messages received: " << tmp->numberMessages << "] received: " << tmp->message << endl;        //given

        if(tmp-> name == receiver){
            return;
        }
        tmp = tmp -> next;
        
    }

}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath() 
{
    //TODO: Complete this function
    Country*ptr = head;
    cout << "== CURRENT PATH ==" << endl;       //header

    if(ptr == NULL){                        //empty LL
        cout << "nothing in path" << endl;
        cout << "===" << endl;
        return;
    }
 
    while(ptr-> next != NULL){              //prints until the last one
        cout << ptr->name << " -> ";
        ptr = ptr -> next;
    }

    cout << ptr->name << " -> ";                //prints last one and NULL
    cout << "NULL" << endl;
    cout << "===" << endl;
}
