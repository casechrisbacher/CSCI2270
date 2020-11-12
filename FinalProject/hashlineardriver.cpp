//Name: Case Chrisbacher
//Class: CSCI 2270
//Final Project

#include "hashchain.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;



int main(){
    int tableSize = 40009;
    HashTable c(tableSize);

    int testData[10000];
    int x = 0;
    int iteration = 0;
    int randomindex;
    int index = 0;
    int tempcounter;
    float count = 100;
    float colCount;
    int pseudoRandomNumbers[100];
    float averageInsert;
    float averageSearch;
    float insert[100];
    float search[100];
    float colInsert[100];
    ifstream text;
    ofstream writeto;
    string s;
    // string dataSet = "dataSetA.csv";
    string dataSet = "dataSetB.csv";

    text.open(dataSet);
    if(text.is_open()){
        while(getline(text, s, ',')){           //puts 10,000 int from csv into array
            testData[x] = stoi(s);
            x++;
        }
    }



       while(iteration < 100){             //MEASURING LENGTH OF INSERT IN nanoseconds total of 10,000 insert & search
        tempcounter = 0;

        auto start = chrono::steady_clock::now();       //starts insert clock
        for(int j = 0; j < 100; j++){                      //runs through sets of 100 at a time
            c.insertItem(testData[index]);
            tempcounter++;
            index++;
        }
        auto end = chrono::steady_clock::now();          //ends insert clock

        averageInsert = chrono::duration_cast<chrono::nanoseconds>(end-start).count()/ count;       //averages out inserts
        colCount = c.getNumOfCollision();                                                            //gets collisions for 100 inserts    

        colInsert[iteration] = colCount;                            //puts collisions in array
        insert[iteration] = averageInsert;                          //puts inserts in array
        for(int i = 0; i < 100; i++){
            pseudoRandomNumbers[i] = rand() % (index +1);           //random number between 0 and index - 1
            if(pseudoRandomNumbers[i] != 0){
                pseudoRandomNumbers[i] = pseudoRandomNumbers[i] - 1;
            }
        }
        
        auto s = chrono::steady_clock::now();                       //start search clock
        for(int i = 0; i < 100; i++){
            c.searchItem(testData[pseudoRandomNumbers[i]]);             //search for random number at random index
        }
        auto e = chrono::steady_clock::now();                       //end search clock

        averageSearch = chrono::duration_cast<chrono::nanoseconds>(e-s).count()/ count;     //average the searches
        search[iteration] = averageSearch;                                                  //puts avg into an array

        //cout<<"Avg Search time From 0-"<<index<<" === "<< search[iteration]<<" NANOSECONDS"<<endl;        //useful output to see data

        iteration++;
        c.resetCollision();     //to 0
    }  


    //*************COMMENTED OUT BECAUSE I DIDNT WANT ISSUES WITH WRITING TO FILES THAT DONT EXIST WHILE BEING GRADED***************
    
    // writeto.open("insert_search_hl_dataSetB.csv");
    // if(writeto.is_open()){                          //puts data in csv for later export
    //     for(int i = 0; i < 100; i++){
    //         writeto << insert[i] <<endl;            //insert 1-100
    //     }
    //     for(int i = 0; i < 100; i++){
    //         writeto << colInsert[i] <<endl;         //collisions 101-200
    //     }

    //     for(int i = 0; i < 100; i++){
    //         writeto << search[i] <<endl;                    //search 201-300
    //     }

    // }

    // writeto.close();


}