#include <stdio.h>

int main()
{
    float gallons;
    float miles;
    float totalGallons = 0.0;
    float totalMiles = 0.0;
    float totalAverage;

    printf ("%s","Enter the gallons used (-1 to end): ");
    scanf ("%f", &gallons);

    while (gallons != -1.0){
        totalGallons += gallons;
        printf ("%s","Enter the miles driven: ");
        scanf ("%f", &miles);

        totalMiles += miles;

        printf ("The miles / gallon for this tank was %f\n\n", miles / gallons);

        printf ("%s", "Enter the gallons used ( -1 to end): ");
        scanf ("%f", &gallons );
    }
    totalAverage = totalMiles / totalGallons;
    printf("\n The overall average miles / gallon was %f\n", totalAverage);
}
