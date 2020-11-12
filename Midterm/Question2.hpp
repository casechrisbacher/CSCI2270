#include <iostream>
using namespace std;

/* DO NOT MODIFY */
struct Node{
   int data;
   Node *next;
   Node(int v, Node *n=NULL){
       data = v;
       next = n;
   }
};


/* DO NOT MODIFY */
class LinkedList{
   private:
      Node *head;
      Node *search(int val);
   public:
      LinkedList(){head = NULL;};
      ~LinkedList();
      void insertNode(int leftVal, int newVal);
      void printList();
      void findAndMoveMin();
};