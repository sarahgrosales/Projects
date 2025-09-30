#include <stdio.h>

int main(){

    float hoursWorked = 0.0;
    float hourlyRate = 0.0;
    float salary = 0.0;
    float value;

    while (hoursWorked != -1.0){

        printf ("%s","Enter the # of hours worked (-1 to end): ");
        scanf ("%f", &hoursWorked);

        if (hoursWorked < 40){

            printf ("%s","Enter the hourly rate of the worker ($00.00): ");
            scanf ("%f", &hourlyRate);

            salary = hoursWorked * hourlyRate;
            printf ("Salary is %f\n\n", salary);
        }
        else (hoursWorked > 40);{

            printf ("%s","Enter the hourly rate of the worker ($00.00): ");
            scanf ("%f", &hourlyRate);

            value = (hoursWorked - 40) * (hourlyRate)*1.5;
            salary = (hourlyRate * 40) + value;
            printf ("Salary is %.2f\n\n", salary);
        }
    }
}
