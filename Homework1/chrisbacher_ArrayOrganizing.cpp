//CSCI 2270
//Name: Case Chrisbacher
//Godley
//Homework 1

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;



struct wordRecord {
    string word;
    int count;
};

void getIgnoreWords(const char *ignoreWordFileName, string ignoreWords[])
{
    ifstream text;
    string s;
    int x = 0;
    text.open(ignoreWordFileName);
    
    if(text.is_open()){                 //reads the ignore file and puts them in the array
        while(getline(text, s)){
            ignoreWords[x] = s;
            s = "";
            x++;

        }
    }
    else{
        cout << "Failed to open " << ignoreWordFileName << endl;
    }

}

bool isIgnoreWord(string word, string ignoreWords[]){
    for(int j = 0; j < 50; j++){
        if(word == ignoreWords[j]){
            return true;
        }

    }
    return false;
}

int getTotalNumberNonIgnoreWords(wordRecord distinctWords[], int length){
    int uniquewords = 0;

    for(int i = 0; i < length; i++){
        uniquewords = uniquewords + distinctWords[i].count;         //adds up count for every slot
    }
        return uniquewords;                                         //returns the count
}

void sortArray(wordRecord distinctWords[], int length)
{
    int maxcount = 0;
    string temparray[length];
    int tempcount[length];
    int arraycounter = 0; 
    int wordcount;
    string tempstring = "";
    
    for(int i = 0; i < length; i ++){                   //Goes through and looks for the max count
        if(distinctWords[i].count > maxcount){
            maxcount = distinctWords[i].count;
        }
    }
    wordcount = maxcount;                       //needed two of the same variable for sorting by count and alphabetical


    while (maxcount > 0){
        wordcount = 0;
        
        for(int j = 0; j < length; j++){                    //if the count is the max, word and count get added, and the index is increased
            if(distinctWords[j].count == maxcount){
                temparray[arraycounter] = distinctWords[j].word;
                tempcount[arraycounter] = distinctWords[j].count;
                arraycounter++;
                wordcount++;
              
            }
        }
        maxcount--;                                         //goes all the way down to words with a count of 1
    }
    
    for (int k = 0; k < length; k++){
        distinctWords[k].word = temparray[k];               //re enters the words and counts into the distinct words array
        distinctWords[k].count = tempcount[k];

    }
    while (wordcount  > 0){                                 //alphabetizes
        for(int k = 0; k < length; k++){                       //If the count is the same for current place and the next and if the asci value is less
            if(distinctWords[k].count == distinctWords[k+1].count && (int)distinctWords[k+1].word[0] < (int)distinctWords[k].word[0]){
                tempstring = distinctWords[k+1].word;           //It enters and the two words are swapped
                distinctWords[k+1].word = distinctWords[k].word;       //They have the same count so the counts stay the same
                distinctWords[k].word = tempstring;
                tempstring = "";
                

            }
        }
        wordcount--;                                        //same system as the maxcount above
    }



    

    

}

void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords)
{

    for (int i = 0; i < 10; i++){
        cout << setprecision(4) <<fixed<< (((double)distinctWords[N].count)/((double)totalNumWords)) << " - " << distinctWords[N].word << endl;
        N++;
    }
}





int main(int argc, char* argv[]){
    int size = 100;
    wordRecord * distinctWords = new wordRecord[size];      //dynamically allocated
    string s;
    int wordcounter = 0;
    int index = 0;
    int timesdoubled = 0;
    bool match = false;
    ifstream text;
    text.open(argv[2]);             //opens the book file
    string ignoreWords[50];

    getIgnoreWords(argv[3], ignoreWords); //initializes the ignorewords array

    

    if(text.is_open()){
    //    text>> std:: ws;                        //https://stackoverflow.com/questions/20045726/skip-whitespaces-with-getline
    //while(getline(text, s, ' ')){             //outputted slightly higher wordcount        
   //    text>> std:: ws;
   while(text >> s)                     //goes through the book
    {

        if(isIgnoreWord(s, ignoreWords) == false){          //checks that its not an ignore word
        if (s != "" && s[0] <= (char)126){

        for(int i = 0; i < wordcounter; i++){
            if(s == distinctWords[i].word && i != wordcounter){     //checks to see if the word has occured before and it is not the same spot
                match = true;
                index = i;
                
            }
        }

        if(match == true){                  //the word has occured, so the count at that index increases
            distinctWords[index].count++;
        }
        else{                                   //For the distinct words
            
            if(wordcounter >= size){                              //ARRAY DOUBLING!!!
                                                                  // SUPER USEFUL EXAMPLE: http://www.fredosaurus.com/notes-cpp/newdelete/55dynexample.html
                wordRecord * tempArr = new wordRecord[size*2];      //Dynamicly allocate a neew array of double size
                for (int g = 0; g < size; g++){
                    tempArr[g].word = distinctWords[g].word;        //copy info
                    tempArr[g].count = distinctWords[g].count;
                }
                size = size * 2;                                    //restate what size is now
                delete [] distinctWords;                            //delete original

                distinctWords = tempArr;                            //transfer info


                distinctWords[size];

                timesdoubled++;

            }

            distinctWords[wordcounter].word = s;                     //If the array doesn't need to be doubled
            distinctWords[wordcounter].count++;                        //word and count are increased along with total count
            wordcounter++;
        }
        }

        match = false;
        s = "";
        index = 0;

        
    }
    }
    }

    sortArray(distinctWords, wordcounter);

    int rank = stoi(argv[1]);                                               //where the ten words are read from
    int words = getTotalNumberNonIgnoreWords(distinctWords, wordcounter);


     cout << "Array doubled: " << timesdoubled << endl;
     cout << "Distinct non-common words: " << wordcounter << endl;
     cout << "Total non-common words: " << getTotalNumberNonIgnoreWords(distinctWords, wordcounter) << endl;
     cout << "Probability of next 10 words from rank " << rank << endl;
     cout << "---------------------------------------" << endl;
     printTenFromN(distinctWords, rank, words);
     


}

