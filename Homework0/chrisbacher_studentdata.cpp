//CSCI 2270
//Name: Case Chrisbacher
//Godley
//Homework 0

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct studentData { //given struct
    string studentName; 
    int homework;
    int recitation;
    int quiz;
    int exam;
    double average; 
};

void addStudentData(studentData students[], string studentName, int homework, int recitation, int quiz, int exam, int length){
    //Places the student name and their average into the students array
        students[length].studentName = studentName;
        students[length].average = (((double)homework + (double)recitation + (double)quiz + (double)exam) / (double)4);
}

char calcLetter(double avg){        //Returns grade student receives with given average
     if(avg > 90){
         return 'A';
     }
     else{
         if(avg >= 80 && avg <= 89.9){
             return 'B';
         }
         if(avg >= 70 && avg <= 79.9){
             return 'C';
         }
         if(avg >= 60 && avg <= 69.9){
             return 'D';
         }
         if (avg < 60){
             return 'F';
         }
     }
 }

void printList(const studentData students[], int length){
    for (int i = 0; i < length; i++){               //loops and prints out each students name, average, grade
        char grade = ' ';
        grade = calcLetter(students[i].average);
        cout<<students[i].studentName<<" earned "<<students[i].average<<" which is an "<<grade<<endl;
    }
}

int split (string split, char seperator, string arr[], int size){       //Reused from CSCI 1300 (WRITTEN BY ME)
    arr[size];
    if (split == ""){           //if the split is empty return 0
        return 0;
    }
    int z = 0;          //initializing variables
    int t = 0;
    while (split[t] == seperator){          //this makes it so that if it starts with seperators, it skips past them
          t++;
      }
    for (t; t < split.length(); t++){
     
        if(split[t] != seperator){          //if it is not a seperator, it adds it to the current array slot
            arr[z] += split[t];
        }
        if (split[t] == seperator && split[t+1] != seperator && t != split.length() - 1){       //if it is a seperator, the next slot is a character (not a seperator), and it is not the final slot
            z++;                            //then it moves to the next array
        }
    

    }
}

int main(int argc, char* argv[]){
    string input;
    char* lower = argv[3]; 
    char* upper = argv[4];
    string s;
    int size = 5;
    string arr[size];
    int indx = 0; 
    studentData students[20];
    ifstream text;              //taking info from
    ofstream outfile;           //writing to
    int min = 0;
    int max = 0;

    text.open(argv[1]);
    outfile.open(argv[2]);
    if (text.is_open()){
        while(getline(text,s)){
            if (s != ""){
                for (int m = 0; m < 5; m++){  //intializes the arr[] as blank
                arr[m] = "";
                }

            //Gets rid of the commas, places them in the arr array and then adds the students to the students array with addStudentData
            split (s, ',', arr, size);
            addStudentData(students, arr[0], stoi(arr[1]), stoi(arr[2]), stoi(arr[3]), stoi(arr[4]), indx);


            if(*lower == 'A'){          //Hardcoded each of the values for upper and lower, couldn't get loop to work
                min = 90;
            }
            if(*lower == 'B'){
                min = 80;
            }
            if(*lower == 'C'){
                min = 70;
            }
            if(*lower == 'D'){
                min = 60;
            }
            if(*lower == 'F'){
                min = 0;
            }
            if(*upper == 'A'){
                max = 100;
            }
            if(*upper == 'B'){
                max = 89.9;
            }
            if(*upper == 'C'){
                max = 79.9;
            }
            if(*upper == 'D'){
                max = 69.9;
            }
            if(*upper == 'F'){
                max = 59.9;
            }

            if (students[indx].average <= max && students[indx].average >= min){        //Checks if the average fits in the given range, if it does it adds it to the output file
    
                outfile << arr[0] << "," << students[indx].average << "," << calcLetter(students[indx].average)<<endl;

            }

        }

        indx++;

    }
    printList(students, indx);
    }
}