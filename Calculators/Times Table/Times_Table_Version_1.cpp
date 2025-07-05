// This code prints a times table 

#include <iostream>
using namespace std;

int temp = 5;

int main (){
   for (int i = 0; i < 5; i++){
       for (int j = 0; j <= temp; j++){
           cout << i << " * " << j << " = " << i * j;
           cout << endl;
       }
   cout << endl;
   }
}

// Ways to improve:
// 1) Create more dialouge.
// 2) Allow users to input what numbers they want to be multiplied.
// 3) Allow users to input how many charts they want.

// This prints:
//  0 * 0 = 0
//  0 * 1 = 0
//  0 * 2 = 0
//  0 * 3 = 0
//  0 * 4 = 0
//  0 * 5 = 0
// 
//  1 * 0 = 0
//  1 * 1 = 1
//  1 * 2 = 2
//  1 * 3 = 3
//  1 * 4 = 4
//  1 * 5 = 5
// 
//  2 * 0 = 0
//  2 * 1 = 2
//  2 * 2 = 4
//  2 * 3 = 6
//  2 * 4 = 8
//  2 * 5 = 10
// 
//  3 * 0 = 0
//  3 * 1 = 3
//  3 * 2 = 6
//  3 * 3 = 9
//  3 * 4 = 12
//  3 * 5 = 15
//
//  4 * 0 = 0
//  4 * 1 = 4
//  4 * 2 = 8
//  4 * 3 = 12
//  4 * 4 = 16
//  4 * 5 = 20
