#include <iostream>
#include <iomanip>
using namespace std;



void removeEvenElement(int *&arr,int &size)
{
    int position = 0;
    for(int i = 0; i < size; i++){          //figures out size of new array
        if(arr[i] % 2 != 0){
            position++;
        }
    }

    int*newarr = new int[position];
    position = 0;

    for(int k = 0; k < size; k++){          //stores odd numbers in it
        if(arr[k] % 2 != 0){
            newarr[position] = arr[k];
            position++;
        }
    }
    
    delete [] arr;              //deletes original array
    //size = position;
    //cout<<position<<endl;
    arr = newarr;               //copies over values
    size = position;
    //cout<<position;
    //delete [] newarr;         //questionable delete *****
}




int main()
{
   int i;
   int size = 6;
   int *arr;

   arr = new int[size];
   arr[0] = 14;
   arr[1] = 4;
   arr[2] = 11;
   arr[3] = 3;
   arr[4] = 7;
   arr[5] = 6;

   cout << "Original Array is" << endl;

   for(i=0;i<size-1;i++)
      cout << arr[i] << " ";

   cout << arr[size-1] << endl;

   cout << "Original size is : " << size << endl;

   removeEvenElement(arr,size);

   cout << "Modified Array is" << endl;

   for(i=0;i<size-1;i++)
      cout << arr[i] << " ";

   if(size == 0)
      cout << "EMPTY" << endl;
   else
      cout << arr[size-1] << endl;	

   cout << "Modified size is : " << size << endl;

   return 0;
}