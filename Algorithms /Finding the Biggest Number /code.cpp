#include <iostream>

int main (){
   int b = 0;
   int a = 6; // sets 'a' to 6; represents the # of indexes in array
   int n[a] = {8, 16, 25, 3, 0, 9}; // array of #'s ranging from [0,1,2,3,4,5]


   // if 'i' is less than 'a'(6) then it continues to next for loop and adds 1
   for (int i = 0; i < a; i++){ 
       // now 'i' equals 1 and 'j' equals 0; 'j' keeps adding 1 (0-5) then goes back to first loop
       for (int j = 0; j < a; j++){
           // if 'j' = 0; n[8] > n[8] && 0 < n[8] (this repeats all numbers from 0-5 for 'j')
           if (n[i] > n[j] && b < n[j]) {
           b = n[i];
           // else if 'j' = 0; n[8] > 0; which is true so it repeats 'j' for loop
           } else if(n[j]>b) {
           b = n[j];
       }
   }   
}
cout << b << endl;
}

