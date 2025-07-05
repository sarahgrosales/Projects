// This is a basic calculator with the addition of modulus and power using switch cases. 

#include <iostream>  //library
using namespace std;

int main (){
   int a;
   int b;
   int temp;
   char c;

   cout << "Enter the first number: ";
   cin >> a;
   cout << "Enter the second number: ";
   cin >> b;

   cout << "Select the operation you want: " << endl;
   cout << "       1. Addition" << endl;
   cout << "       2. Subtraction" << endl;
   cout << "       3. Multiplication" << endl;
   cout << "       4. Division" << endl;
   cout << "       5. Modulus" << endl;
   cout << "       6. Power" << endl;

   cout << "Enter your choice: ";
   cin >> c;

       switch (c)
       {
           case '1':
               cout << "Your addition is: " << a + b << endl;
               break;
           case '2':
               cout << "Your subtraction is: " << a - b << endl;
               break;
           case '3':
               cout << "Your product is: " << a * b << endl;
               break;
           case '4':
               cout << "Your quotient is: " << a / b << endl;
               break;
           case '5':
               cout << "Your module is: " << a % b << endl;
               break;
           case '6':
               temp = 1;
               for (int i = 0; i < b; i++){
               temp = a * temp;
               }   
               cout << "Your power is: " << temp << endl;
               break;

           default:   
               cout << "Invalid operation" << endl;
               break;
       }
   return 0;
}
