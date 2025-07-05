// This algorithm finds the largest number in an array.

#include <iostream>
using namespace std;

int main (){
   int b = 0;                              // Declares b as an integer.
   int a = 6;                              // Declares a as an integer and sets it to equal 6.
   int n[a] = {8, 16, 25, 3, 0, 9};        // The array of #'s ranging from indexes [0,1,2,3,4,5]
   
    // The nested loops that search for the largest value.
   for (int i = 0; i < a; i++){            // The first for loop keeps track of the index number in the array. (Ex: n[0] = 8)
       for (int j = 0; j < a; j++){        // The second for loop uses j to find which variable is the largest.
           if (n[j]>b) {                   // If j is equal to index number 0, which is 8 (n[0] = 8) then, 8 > 0 (n[j] >b), which then sets b to equal 8 (b = n[j]).
           b = n[j];                       // If b now equals 8, then when n[j] equals 16, b will now be set as 16. This repeats until it sorts through all of the indexes.
       }                                   // Only the largest number is left until there is a number that is larger than the current b. 
   }   
}
cout << b << endl;
}

// Ways to improve:
// Adding a way for users to input their own array or variables.
