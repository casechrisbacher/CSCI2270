#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{

  int foo[5] = {1, 2, 3, 4, 5};

  cout << "Addresses of elements:" << endl;
  //TODO Print the addresses of array elements
  for(int i = 0; i < 5; i++){
      cout << &foo[i] << endl;
  }

  cout << endl;

  cout << "Elements:" << endl;;
  //TODO Print all the elements using pointers
  for(int j = 0; j < 5; j++){
      cout << *(foo + j) << endl;
  }

  cout << endl;

  return 0;
}
