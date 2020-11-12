//Name: Case Chrisbacher
//Class: CSCI 2270
//Final Project

#include "dll.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <chrono>
using namespace std;



int main(){
    dll Node;
    dll c;

    int testData[10000];                //total data
    int x = 0;
    int iteration = 0;
    int tempcounter;
    int index = 0;
    int pseudoRandomNumbers[100];
    float insert[100];
    float search[100];
    float average;
    float averageSearch;
    float count = 100;
    ifstream text;
    ofstream writeto;
    string s;
    // string dataSet = "dataSetA.csv";
    string dataSet = "dataSetB.csv";

    text.open(dataSet);                     //transfers integers from data set into testData array
    if(text.is_open()){
        while(getline(text, s, ',')){
            testData[x] = stoi(s);
            x++;
        }
    }

    while(iteration < 100){             //MEASURING LENGTH OF INSERT IN NANOSECONDS -- 100 iterations of 100 inserts & searches = 10,000 total
        tempcounter = 0;

        auto start = chrono::steady_clock::now();       //Insert clock starts
        while(tempcounter < 100){                       //runs through sets of 100 at a time
            c.insertNode(testData[index]);              
            tempcounter++;
            index++;                            //index leaves while loop at 100, 200, 300 .... 
        }                                       //BUT the last insert is at 99, 199, 299
        auto end = chrono::steady_clock::now();       //Insert clock ends
    
        average = chrono::duration_cast<chrono::nanoseconds>(end-start).count()/ count;     //average for insert
        insert[iteration] = average;                                                        //inserted for that iteration
        for(int i = 0; i < 100; i++){
            pseudoRandomNumbers[i] = rand() % (index +1);                                   //gives random number between 0-index
            if(pseudoRandomNumbers[i] != 0){                                                //this takes off one number just in case it hits the index
                pseudoRandomNumbers[i] = pseudoRandomNumbers[i] - 1;                        //still random, just one less, don't want to subtract if 0
            }
        }

        auto s = chrono::steady_clock::now();                                   //search clock start
        for(int i = 0; i < 100; i++){
            c.searchNode(testData[pseudoRandomNumbers[i]]);                     //looking for numbers at random indexes
        }
        auto e = chrono::steady_clock::now();                                   //search clock end

        averageSearch = chrono::duration_cast<chrono::nanoseconds>(e-s).count()/ count; //search average
        search[iteration] = averageSearch;                                              //insert search clock in array


        iteration++;

    }

 
    // *************COMMENTED OUT BECAUSE I DIDNT WANT ISSUES WITH WRITING TO FILES THAT DONT EXIST WHILE BEING GRADED***************

    // writeto.open("insert_search_dll_dataSetB.csv");         //This put the time averages in a csv
    // if(writeto.is_open()){
    //     for(int i = 0; i < 100; i++){
    //         writeto << insert[i] <<endl;                //1-100 lines insert
    //     }
    //     for(int i = 0; i < 100; i++){                   //101-200 lines search
    //         writeto << search[i] <<endl;
    //     }

    // }           

    // writeto.close();

        
}