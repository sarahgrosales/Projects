// Version 2 of the Basic Neural Network with one neuron.
// This version applies real-world problems for a better understanding.
// Imagine we are looking at a mystery animal, we are answering the question: "Is it a cat?"

#include <iostream>
#include <vector>
#include <cmath>

using namespace std; 

// The sigmoid function that makes our output between 0 and 1.
double sigmoid (double x) {
    return 1.0 / (1.0 + exp (-x));
}            

int main () {
    vector <double> inputs = {4.0, 7.0};           // The mystery animal has these features: Input [0] = whisker length (cm) and Input [1] = ear height (cm)
    vector <double> weights = {0.6, 0.4};          // With the weights we chose how much we "trust" each feature when guessing.
    
    double bias = -4.0;                            // A more negative bias makes it "harder" to say "yes, it is a cat."                 
    
    double sum = inputs [0] * weights [0]          // This copmutes the weighted sum: z = w0*x0 + w1*x1 + b
               + inputs [1] * weights [1]
               + bias;
  
    double output = sigmoid (sum);                 // This runs z or the weighted sum through the sigmoid function to get a probabilty. 

    cout << "Cat probability: " << output << endl;     

    if (output > 0.5)                              // This will print a message if the probability is over 0.5.
        cout << "Probably a cat! :)" << endl;
    else
        cout << "Probably not a cat :(" << endl;

    return 0;
}

// The output is: 
// Cat probability: 0.768525
// Probably a cat! :)

// Usually, we would train this network so that it can know what an actual cat looks like and then use this code
// to determine how close it is to an actual cat by changing the weights. 
