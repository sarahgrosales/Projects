// This is a basic calculator with the addition of modulus and power using switch cases. 

#include <iostream>  //library
using namespace std;

int main (){
   int a;        // Declares the a integer.
   int b;        // Declares the b integer.
   int temp;     // Declares the temp integer.
   char c;       // Declared the c character.
   
   // What the user sees.
   cout << "Enter the first number: ";       // The user is prompted to enter the first number.
   cin >> a;                                 // The first number the user inputs is set to a.
   cout << "Enter the second number: ";      // The user is prompted to enter the second number.
   cin >> b;                                 // The first number the user inputs is set to b.

   // Prompts the user to select what operation they want done.
   cout << "Select the operation you want: " << endl;    
   cout << "       1. Addition" << endl;
   cout << "       2. Subtraction" << endl;
   cout << "       3. Multiplication" << endl;
   cout << "       4. Division" << endl;
   cout << "       5. Modulus" << endl;
   cout << "       6. Power" << endl;

   // Prompts the user to enter the operation they would like to do.
   cout << "Enter your choice: ";
   cin >> c;

       switch (c)                                                      // Declares the switch function.
       {
           case '1':                                                   // Case 1 is "Addition"
               cout << "Your addition is: " << a + b << endl;          // The function that adds variables a and b together.
               break;                                                  // Ends the case.
           case '2':                                                   // Case 2 is "Subtraction"
               cout << "Your subtraction is: " << a - b << endl;       // The function that subtracts variables a and b from each other. 
               break;                                                  // Ends the case.
           case '3':                                                   // Case 3 is "Multiplication"  
               cout << "Your product is: " << a * b << endl;           // The function that multiplies variables a and b together.
               break;                                                  // Ends the case.
           case '4':                                                   // Case 4 is "Division"
               cout << "Your quotient is: " << a / b << endl;          // The function that divides variable a by variable b.
               break;                                                  // Ends the case.
           case '5':                                                   // Case 5 is "Modulus"     
               cout << "Your module is: " << a % b << endl;            // The function finds the remainder of variable a being divided by variable b.  
               break;                                                  // Ends the case.
           case '6':                                                   // Case 6 is "Power" 
               temp = 1;                                               // The for loop is used here to simulate the power sign.
               for (int i = 0; i < b; i++){                            // Variable b represents the amount of iterations of the for loop.    
               temp = a * temp;                                        // Variable a is multiplied by 1 on the first iteration. On the second  
               }                                                       // iteration variable a would be multiplied by itself, simulating a power sign.
               cout << "Your power is: " << temp << endl;              // This prints the final temp variable.
               break;                                                  // Ends the case.

           default:                                                    // Default happens when none of the cases (1 - 6) are selected. (Ex: 0 or 7)
               cout << "Invalid operation" << endl;                    // This prints out "Invalid operation".  
               break;                                                  // Ends the case.
       }
   return 0;
}
