// This code adds onto the first version by converting decimals into fractions.

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// 1. Calculates the largest common divisor of two integers.
int gcd (int a, int b) {
    a = abs(a);       // abs(a) ensures a is not negative.
    b = abs(b);       // abs(b) ensures b is not negative.
    while (b != 0) {  //
        int t = b;    // Stores b in t. 
        b = a % b;    // Sets b to equal the remainder of a / b.
        a = t;        // Stores t into a. 
    }
    return a;         // When b is zero, a is the GCD
}

//2. Converts a float into a string
string to_fraction (double value) {     // to_fraction turns a decimal (double) into a fraction string.
    bool neg = value < 0;               // Stores if the value is negative.
    value = abs (value);                // Uses the positive part of the value.

    int whole = int (value);            // This is the integer part of the value. (Ex: the '1' from '1.75')
    double frac = value - whole;        // The fractional part of the value (Ex: the '0.75' from '1.75')

    const int PREC = 100;                       // The fractional part is treated as a numerator out of 100.
    int num = int (round (frac * PREC));   // This rounds the nearest integer (Ex: 0.75 * 100 turns into 75)
    int den = PREC;                             // The denominator starts a 100.

    int g = gcd (num, den);        // Finds the greatest common denominator of the values.
    if (g > 0) {                   // if integer g is greater than 0.
        num /= g;                  // 'num' would be divided by g.
        den /= g;                  // 'den' would be divided by g.
    }

    string s;                            // This holds the result.
    if (whole != 0){                     // If there is a non-zero whole number
        s += to_string (whole);          // and it (Ex: '1')
    }                            
    if (num != 0) {                                     // If there is a non-zero fraction number
        if (!s.empty ()) s += " ";                      // and there is already a whole number, add a space
        s += to_string (num) + "/" + to_string (den);   // and then add '/' and then add the denominator, making the fraction.
    }                                             
    if (whole == 0 && num == 0) {        // If everythin is zero (Ex: 0.00)                  
        s + "0";                         // print only 0.
    }
    if (neg)                             // If the original value was negative
        s = "-" + s;                     // add the minus sign.
               
    return s;                            // Returns the final fraction string.                       
}

int main(){
    double enteredDozen;                 // The variable that holds how many dozens the user wants.

    // Prompts the user:
    cout << "Hi! I see you want to make some yummy cookies.\n"
         << "How many dozens would you like?\n"
         << "Enter number of dozens: " << flush;

    cin >> enteredDozen;                 // Collects the users input.

    // The recipe per dozen cookies
    const double butter = 6;
    const double brown_sugar = 0.25;
    const double sugar = 3;
    const double egg = 1;
    const double vanilla = 0.75;
    const double flour = 0.5;
    const double salt = 0.12; 
    const double baking_soda = 0.25;
    const double baking_powder = 0.25;
    const double chocolate = 0.3;

    // Prints out the Recipe:
    cout << "\nHere is your recipe!\n";
    cout << "   1) " << to_fraction (enteredDozen * butter) << " tablespoons of unsalted butter.\n";
    cout << "   2) " << to_fraction (enteredDozen * brown_sugar) << " cup of dark brown sugar.\n";
    cout << "   3) " << to_fraction (enteredDozen * sugar) << " tablespoons of granulated sugar.\n";
    cout << "   4) " << to_fraction (enteredDozen * egg) << " large egg yolk.\n";
    cout << "   5) " << to_fraction (enteredDozen * vanilla) << " teaspoon of vanilla extract.\n";
    cout << "   6) " << to_fraction (enteredDozen * flour) << " cup all purpose flour.\n";
    cout << "   7) " << to_fraction (enteredDozen * salt) << " teaspoon of salt.\n";
    cout << "   8) " << to_fraction (enteredDozen * baking_soda) << " teaspoon of baking soda.\n";
    cout << "   9) " << to_fraction (enteredDozen * baking_powder) << " teaspoon of baking powder.\n";
    cout << "   10) " << to_fraction (enteredDozen * chocolate) << " cup of chocolate chips.\n";

    return 0;
}

// This prints: 
// Hi! I see you want to make some yummy cookies.
// How many dozens would you like?
// Enter number of dozens: 2
// 
// Here is your recipe!
//   1) 12 tablespoons of unsalted butter.
//   2) 1/2 cup of dark brown sugar.
//   3) 6 tablespoons of granulated sugar.
//   4) 2 large egg yolk.
//   5) 1 1/2 teaspoon of vanilla extract.
//   6) 1 cup all purpose flour.
//   7) 6/25 teaspoon of salt.
//   8) 1/2 teaspoon of baking soda.
//   9) 1/2 teaspoon of baking powder.
//   10) 3/5 cup of chocolate chips.
