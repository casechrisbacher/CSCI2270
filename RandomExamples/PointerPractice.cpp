#include <iostream>
using namespace std;

int main(){
    int x = 5;                          //STATIC AKA STACK
    int *p = &x;
    cout<<"Address of P: "<<p<<endl;
    cout<<"Value of P: "<<*p<<endl;
    cout<<endl;

    int*a = new int;                   //DYNAMIC AKA HEAP
    *a = 10;
    cout<<"Dynamically allocated A value: "<<*a<<endl;
    cout<<"Address of A: "<<a<<endl;
    cout<<endl;
    delete a;








}