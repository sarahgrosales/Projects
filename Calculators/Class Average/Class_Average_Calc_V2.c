#include <stdio.h>
// Starts the code
int main( void )
{
    unsigned int counter; // The number of grades entered
    int grade;            // The grade value
    int total;            // Sum of grades

    float average;        // Number for average in decimal point

    total = 0;            // Sets the total to zero
    counter = 0;          // Sets the counter to zero

    printf( "%s", "Q1Enter grade, -1 to end: ");    // Prompt the input
    scanf( "%d", &grade );                        // reads the next grade

    // Loop while sentinel value not yet read from user
    while ( grade != -1){
        total = total + grade;       // Add grade total
        counter = counter +1;        // Increment counter

        // Gets next grade from user
        printf( "%s", "Q2Enter grade, -1 to end: ");    // Prompts user for input
        scanf("%d", &grade);                          // Read next grade
    }

    if ( counter != 0 ){                              // termination phase
        average = ( float ) total / counter;          // calculate average of all grades
        printf ("Class average is %.2f\n", average);  // Displays the average with two digit precision
    }
    else {                                  // This is if no grades were entered
        puts ("No grades were entered");    // Prints message
    }
}
