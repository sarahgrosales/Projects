// This code prints a right triangle using asterisks. 

#include <iostream> // library
using namespace std;

int main (){ 
  for (int i = 0; i <= 5; i++){              // This for loop keeps track of the amount of lines used when printing the triangle.
           for (int a = 0; a <= i; a++){     // This for loop prints one '*' and adds another one with each iteration. 
               cout << '*';                  // This prints the asterisk.
           }
      cout << endl;                          // This ends the lines which happens because of the first for loop.
  } 
}

// Ways to improve:
// 1) Add a way for users to input how big they want the triangle to be.
// 2) Create a UI for it.
//
// This prints:
//  *
//  **
//  ***
//  ****
//  *****
//  ******


