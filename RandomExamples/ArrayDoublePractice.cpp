#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
    int timesdoubled = 0;
    int size = 1;
    int*arr = new int[size];

    for(int i = 0; i < 101; i++){
        if(i == size){
            int*newarr = new int[size*2];
            for (int k = 0; k < size; k++){
                newarr[k] = arr[k];
            }

            delete [] arr;
            size = size*2;
            timesdoubled++;
            arr = newarr;

        }
        arr[i] = i;
        cout<<arr[i]<<endl;

    }
    cout<<"Times Doubled: "<<timesdoubled<<endl;

}
