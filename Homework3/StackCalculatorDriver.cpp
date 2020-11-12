/****************************************************************/
/*                  Stack Calculator Driver File                  */
/****************************************************************/
/*      TODO: Implement driver as described in the writeup      */
/****************************************************************/

#include "StackCalculator.hpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: Determine whether some user input string is a
 *          valid floating point number
 * @param none
 * @return true if the string s is a number
 */
bool isNumber(string s)
{
    if(s.size() == 1 && s == "-") return false;
    else if(s.size() > 1 && s[0] == '-') s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++)
    {
      if(!isdigit(s[i]) && s[i] != '.') return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

int main()
{
  // TODO - Declare a stack to hold the operands
  StackCalculator calc;
  string input;
  bool noequal = true;

  cout << "Enter the operators and operands ('+', '*') in a postfix format" << endl;

  while(noequal == true)          //exits when equals sign is entered
  {
    cout << "#> ";
    getline(cin, input);
    /* TODO
       1. Read input (operators and operands) until you encounter a "="
       2. Use the isNumber function to check if the input is an operand
       3. push all operands to the stack
       4. If input is not an operand, call the compute function to evaluate
          the partial expression
    */
   if(input == "="){        //checks for equal sign
     noequal = false;

   }
   else{
     if(isNumber(input) == true){         //pushes numbers on
       calc.push(stod(input));
     }
     else{ 
       if(input == "*" || input == "+"){    //calculates when symbol arrises
         calc.calculate(input);
       }
     }
   }
    

  
  }

  /* TODO - If the stack is empty then print "No operands: Nothing to evaluate" */
  if(calc.isEmpty()){
    cout<<"No operands: Nothing to evaluate"<<endl;
  }
  if(!calc.isEmpty()){        //there should be one leftover value: the final result of the calculation
  Op *temp = calc.peek();
  float finalresult = temp->num;        //assigns to local vary so it can be popped
  calc.pop();
  /* TODO - Validate the expression
      1. If valid then print the result
      2. Else, print "Invalid expression"*/
  if(calc.isEmpty()){                           //since the final result was popped, it would be empty
    cout<<finalresult<<endl;
  }
  else{
    cout<<"Invalid expression"<<endl;         //input was not done in the correct order
  }
  }

  return 0;
}
