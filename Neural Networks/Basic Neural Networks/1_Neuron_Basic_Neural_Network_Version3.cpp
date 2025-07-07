// This is version 3 of the basic neural network with one neuron.
// This will add onto version 2 by adding a data set, loop over the data set, 
// compute the output and error, and update the weights and biases.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std; 

// Defines the sigmoid function
double sigmoid (double x) {
    return 1.0 / (1.0 + exp (-x));
}            

// Defines the derivative of sigmoid (needed for backpropagation):    
// Backpropagation: a fundemental algorithm used to calculate the error between network's predicted output 
//                  and the actual output, and then using this error to adjust the weights and biases of the
//                  connections between neurons. This helps the network learn and improve the accuracy over time.
double sigmoidPrime (double x) {
    double s = sigmoid (x);             // Compute σ(x) once and reuse it.
    return s * (1.0 - s);               // σ(x) = σ(x) * [1 - σ(x)]
}

int main () {
    // Adding a small dataset: {{whisker, ear}, label}
    vector<pair<vector<double>,double>> data = {               // Each pair holds a feature-vector and it's label.
        {{4.0, 7.0}, 1.0},  // cat                             // 1.0 for cat and 0.0 for not a cat.
        {{2.0, 3.0}, 0.0},  // not cat
        {{4.2, 6.9}, 1.0},  // cat
        {{1.2, 2.5}, 0.0},  // not cat
    };
    
    // Initialize the neuron's parameters:    
    vector <double> weights = {0.6, 0.4};                       // You can start with whichever numbers you like, during  
    double bias = -4.0;                                         // training this will be adjusted.
    
    // Adding a learning rate and epochs
    double learningRate = 0.1;                                  
    int epochs = 1000;                                          // Number of training passes over data set.
    
    // Training the network
    //Outer loop: repeat for each epoch
    for (int e = 0; e < epochs; ++e) {                          // Repeats over the data many times (epochs) to gradually improve.
        double totalLoss = 0.0;
        
        // Inner loop: This iterates over each training example
        for (auto &example : data) {
            auto &x = example.first;            //'x' is the feature vector (whisker,ear)
            double target = example.second;     // 'target' is the true label (1.0 or 0.0)
            
            // Calculates the weighted sum of z
            double z = x[0] * weights[0] + x[1] * weights[1] + bias;
            
            // Limits z to 0 - 1
            double output = sigmoid (z);

            // Computes the error and add to total loss
            double error = target - output;
            totalLoss += 0.5 * error * error;                     // Compute the loss 

            // Back propagation loss (Gradient of loss function) is the process of calculating how much each weight and bias
            // in the network contributes to the overall error (or loss) of the network's predictions. 
            double gradZ = error * sigmoidPrime (z);               // gradZ tells you how much to nudge weights to reduce loss.

            //Update weights and bias
            for (int i = 0; i < 2; ++i) {
                weights [i] += learningRate * gradZ * x[i];        // You scale by the feature x[i] and by a small learningRate so the updates are stable.
            }

            // Updates the bias
            bias += learningRate * gradZ;
        }
        
        // Optional: prints loss every 100 epochs (10 times)
        if (e % 100 == 0 ) {
            cout << "Epoch " << e                                //Epoch means one complete pass through your dataset.
                 << "        Loss: " << totalLoss << endl;
        }
    }

// Training-test on new input 
vector <double> test = {5.0, 8.0};
    double z = test [0] * weights [0] + test [1] * weights [1] + bias;
    double prob = sigmoid (z); 

    cout << "\nCat probability: " << prob << endl;     

    if (prob > 0.5)                             
        cout << "\nProbably a cat! :)" << endl;
    else
        cout << "\nProbably not a cat :(" << endl;

    return 0;
}

// Epoch 0        Loss: 0.0670865
// Epoch 100        Loss: 0.0391465
// Epoch 200        Loss: 0.0329414
// Epoch 300        Loss: 0.0283451
// Epoch 400        Loss: 0.0248182
// Epoch 500        Loss: 0.0220346
// Epoch 600        Loss: 0.0197869
// Epoch 700        Loss: 0.0179371
// Epoch 800        Loss: 0.0163902
// Epoch 900        Loss: 0.0150789
// 
// Cat probability: 0.983661
//
// Probably a cat! :)
