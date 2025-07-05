// This is a basic calculator using functions. 

#include <iostream>       //library
using namespace std; 

float x, y;               // Globally declares x and y as floats.

void division(){					// This is the void division function.
	float quotient = x / y;				// The equation to divide variables x and y.
	cout << “Quotient: “ << quotient <<end1; 	// Prints the quotient.
}

void addition(){					// This is the void addition function.
	float sum = x + y;				// The equation to add variables x and y.
	cout << “Sum: “ << sum <<end1; 			// Prints the sum.
}

void multiplication(){					// This is the void multiplication function.
	float product = x * y;				// The equation to multiply variables x and y.
	cout << “Product: “ << product <<end1; 		// Prints the product.
}

void subtraction(){					// This is the void subtraction function.
	float difference = x - y;			// The equation to subtract variables x and y.
	cout << “Difference: “ << difference <<end1; 	// Prints the difference.
}

int main(){ 

	cout << “Enter the value of x: “;		// Prompts the user to enter the value of x.
	cin >> x;					// The user enters the x value.
	cout << “Enter the value of y: “;		// Prompts the user to enter the value of y.
	cin >> y;					// The user enters the y value.
	
	division();					// Calls the void division function.
  	addition();					// Calls the void addition function.
	multiplication();				// Calls the multiplication function.
	subtraction();					// Calls the subtraction function.
	
	return 0;
}


