/****************************************************************/
/*                Publisher Subscriber Driver File              */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "PubSub.hpp"
#include <iostream>
#include <string>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Publisher (Publish items to the queue)" << endl;
	cout << "2. Subscriber (Retrieve items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}
// Use getline for reading
int main(int argc, char const *argv[])
{
	
	int numitems = 0;		//this is inputted in number 1
	int retreive = 0;		//how many out puts are wanted in second option
	int runningcount = 0;   //running count of numitems to know how many items are in queue
	int choice = 1;			//you have to pick the first option first or it doesnt work
	string s;				//used for getline input
	PubSub c;
	int k = 0;				//needed for a while statement
	string input;			//getline
	string peeked = "";		//when peek function is called, it is set equal to this string
	
	menu();

	while(choice >= 1 && choice <= 2){		//3 is quit
	input = "";
	getline(cin, input);
	if(input != ""){				//gets rid of blank lines
	choice = stoi(input);
	switch(choice){
		case 1:
			cout << "Enter the number of items to be published:" << endl;
			cin >> numitems;
			for(int i = 1; i <= numitems; i++){				//outputs item count
				cout << "Item" << i << ":" << endl;
				runningcount++;
			}
			
			k = numitems;
			while(k > 0){					//creates the queue
				s = "";
				getline(cin, s);
				if(s != ""){
				c.enqueue(s);
				k--;
				}
				}
			
			menu();
		break;

		case 2:
	
			cout << "Enter the number of items to be retrieved:" << endl;
			cin >> retreive;
			for(int j = 0; j < retreive; j++){
				peeked = c.peek();							//peeks the head
				cout << "Retrieved: " << peeked << endl;	//outputs head
				c.dequeue();								//gets rid of head
				peeked = "";
				numitems--;
				runningcount--;
				if(numitems == 0){
					cout<< "No more items to retrieve from queue" << endl;
					break;
				}
				
			}
			menu();
		break;

		case 3:
			cout << "Number of items in the queue:" << runningcount;	//quit

		break;

    }


	}
	}

}
