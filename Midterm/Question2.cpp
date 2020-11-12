#include "Question2.hpp"
#include <iostream>

using namespace std;



/* DO NOT MODIFY */
LinkedList::~LinkedList()
{
   Node *next;
   while(head != NULL)
   {
      next = head->next;
      delete head;
      head = next;
   }
}

/* DO NOT MODIFY */
void LinkedList::insertNode(int leftValue, int value) {
   Node* left = search(leftValue);
   Node* node = new Node(value);
   
   if (left == 0) { /* inserting a new head node */
      node->next = head;
      head = node;
   }
   else if (left->next == 0) { /* inserting a new tail node */
      left->next = node;
      if (head == 0) 
         head = node;
   }
   else { /* inserting a node in the middle */
      node->next = left->next;
      left->next = node;
   }
}

/* DO NOT MODIFY */
Node* LinkedList::search(int val) {
   Node* current = head;
   while (current != 0) {
      if (current->data == val)
         return current;
      current = current->next;
   }
   return 0;
}

/* DO NOT MODIFY */
void LinkedList::printList()
{
   Node *current = head;
   
   while (current != NULL)
   {
      cout << current->data << " ";
      current = current->next;
   }
}

/* TBC */
void LinkedList::findAndMoveMin()
{
    // to be completed by you :)
    Node*temp = head;
    Node*min = new Node(0, NULL);
    int currentmin = head->data;

    bool deleted = false;
    while(temp != NULL ){
        if(temp->data < currentmin){
            currentmin = temp->data;
           
        }
        temp = temp->next;
    }

    temp = head;
    if(temp->data ==currentmin){
        return;
    }
    while(temp != NULL && deleted == false){
        
        if(temp->next->data == currentmin){
            min = temp->next;
            temp ->next = temp->next->next;
            min ->next = head;
            head = min;
            deleted = true;
            return;
            
        }
        temp = temp->next;
    }


}