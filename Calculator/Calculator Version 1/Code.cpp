#include <iostream>  //library
using namespace std; 

float x, y; 

void division(){
	float quotient = x / y;
	cout << “Quotient: “ << quotient <<end1; 
}

void addition(){
	float sum = x + y;
	cout << “Sum: “ << sum <<end1; 
}

void multiplication(){
	float product = x * y;
	cout << “Product: “ << product <<end1; 
}

void subtraction(){
	float difference = x - y;
	cout << “Difference: “ << difference <<end1; 
}

int main(){ 

	cout << “Enter the value of x: “;
	cin >> x;
	cout << “Enter the value of y: “;
	cin >> y;
	
	division();
  addition();
  multiplication();
	subtraction();
	
	return 0;
}


