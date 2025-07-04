// This is the first version of my cookie recipe calculator.
// It's meant to calculate how many tablespoons, teaspoons, or cup 
// of an ingredient you need to make the desired amount of dozen's. 

#include <iostream>
using namespace std;

float butter = 6;
float brown_sugar = 0.25;
float sugar = 3;
float egg = 1;
float vanilla = 0.75;
float flour = 0.5;
float salt = 0.12; 
float baking_soda = 0.25;
float baking_powder = 0.25;
float chocolate = 0.33;

int main(){
    float enteredDozen;
    
    cout << "Hi! I see you want to make some yummy cookies." << endl;
    cout << "How many dozens would you like?" << endl;
    cout << "Enter number of dozens: " << flush;
    cin >> enteredDozen;
    
    cout << "\n";
    cout << "Here is your recipe!" << endl;
    cout << "   1. " << enteredDozen * butter << " tablespoons of unsalted butter." << endl;
    cout << "   2. " << enteredDozen * brown_sugar << " cup of dark brown sugar." << endl;
    cout << "   3. " << enteredDozen * sugar << " tablespoons of granulated sugar." << endl;
    cout << "   4. " << enteredDozen * egg << " large egg yolk." << endl;
    cout << "   5. " << enteredDozen * vanilla << " teaspoon of vanilla extract." << endl;
    cout << "   6. " << enteredDozen * flour << " cup all purpose flour." << endl;
    cout << "   7. " << enteredDozen * salt << " teaspoon of salt." << endl;
    cout << "   8. " << enteredDozen * baking_soda << " teaspoon of baking soda." << endl;
    cout << "   9. " << enteredDozen * baking_powder << " teaspoon of baking powder." << endl;
    cout << "   10. " << enteredDozen * chocolate << " cup of chocolate chips." << endl;

    return 0;
}
