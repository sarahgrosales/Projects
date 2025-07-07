// A very basic nueral network with one neuron and two inputs which sums them with weights
// and a bias, then runs the result through a sigmoid activation. 

// How the Neuron computes the outputs:
// Inputs: (x0, x1..) are values you feed into the neuron (can be signals, features like pixel brightness, temp.)
// Weights: (w0, w1..) are multiplied by each input. During the learning, the network adjusts these weights so that
//          the neuron pays "more" or "less" attention to certain inputs.
// Bias (b): A constant term added in the end. Can be thought of as an intercept in a line equation.
//           It shifts activation up or down so the neuron isnt forced to always go throught the origin.
// Weighted sum (z): z = x0w0 + x1w1 + ... + b (This collapses all inputs into a single number)
// Activation Function (σ(z)): Applies a nonlinear transformation to z, in this case: σ(z) = 1 / 1 + e^-z.
//                             This makes sure 'z' is a value between 0 and 1.

#include <iostream>  // Includes the I/O library so we can use std::cout
#include <vector>    // Include the STL vector container (std::vector)
#include <cmath>     // Includes the math functions like std::exp()

using namespace std; // So that we don't have to write std:: before everything.

// Defining a sigmoid activation function (f(x) = 1 / (1 + e^-x))
// This will take a double x, returning 1 / (1 + e^-x)), stopping outputs between 0 and 1.

double sigmoid (double x) {
    return 1.0 / (1.0 + exp (-x));            // exp(-x) computes e^(-x)
}

// Starting the program:

int main () {
    vector <double> inputs = {1.0, 2.0};      // These are the two inputs for the values.
    vector <double> weights = {0.5, -1.5};    // These are the weights for each input.
    
    double bias = 1.0;                        // A bias term. (constant offset added to the neuron's) 
    
    double sum = inputs [0] * weights [0]     // Computes weighted sum: (input0 * weight0) + (input1 * weight1) + bias
               + inputs [1] * weights [1]
               + bias;
  
    double output = sigmoid (sum);            // Runs the sum through the activation.

    cout << "Output: " << output << endl;     // Prints the result.

    return 0;
}

// Why we need the sigmoid function:
// Without it, z would pass straight through the network and it would be a purely linear function (sum of weighted inputs)
// It would be equivalent to one big weighted sum unable to model curves or complex patterns.
// The function also limits the range of z by making it be between the interval (0,1). This is good
// when you want an output that falls within a known bound.

// A single neuron can be thought of as a mini calculator. It learns to map inputs to a desired output by:
//      1) Feeding data in     2) Adjusting weights and biases with training      3) Applying a non-linear activation

// The output of this code is: Output: 0.182426
// This number is the nueron's activation for the chosen inputs and weights.
// We got this number by getting the sum of all weights and running it through the sigmoid function.

// How to intepret the Output: 0.182426
// This output is the  nuerons confidence on a scale of 0 -1 on whether the inputss match whichver pattern you inputted.
// This number is basically saying "I'm only 18.2% confident that {1.0, 2.0} meets the criteria that was set."
