#include <stdio.h>
int main( void )
{
// Declare Variables
unsigned int counter;
int grade;
int total;
int average;
// Initializing Conditions
total = 0;
counter = 1;
while (counter <= 10) {   // hard code 10 = you cannot break the code unless u go inside the progran
    printf("%s", "Enter grade: ");
    scanf( "%d", &grade);
    total = total + grade;
    counter = counter + 1;
}
average = total/10;
printf( "Class average is %d\n", average);
}
