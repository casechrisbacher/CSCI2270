#include <iostream>
#include "Question2.hpp"
using namespace std;



int main()
{
   LinkedList *ll = new LinkedList();

   /* Call insertNode to insert nodes you want to test */
   ll->insertNode(0, 9);
ll->insertNode(9, 5);
ll->insertNode(5, 13);
ll->insertNode(13, 2);
ll->insertNode(2, 7);
ll->insertNode(7, 8);
   
   ll->printList();
   
   cout << endl;
   ll->findAndMoveMin();
   
   // ll->findAndMoveMin();
   ll->printList();
	
   cout << endl;

   delete ll;
   
   return 0;
}