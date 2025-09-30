#include <stdio.h>
#include <stdlib.h>
// making a body mass index calculator
// BMI = weightinpounds x 703 / heightininches x heightininches
int main()
{
    int weightp;
    int heighti;
  
    printf( "Do you want to know what your Body Mass Index is? \n" );
    printf( "\nEnter your weight in pounds: " ); // prompt
    scanf( "%d", &weightp ); // reads int 1
    printf( "Enter your height in inches: " ); // prompt
    scanf( "%d", &heighti ); // reads int 2
  
    int bmi; // variable to store sum
    bmi = (weightp * 703)/(heighti * heighti); // assign total to sum
  
    printf( "\nYour BMI is %d!\n", bmi); // prints sum
    puts ("\nBMI Values:");
    puts ("Underweight: less than 18.5");
    puts ("Normal: between 18.5 and 24.9");
    puts ("Overweight: between 25 and 29.9");
    puts ("Obese: 30 or greater");
  
    return 0;
}
