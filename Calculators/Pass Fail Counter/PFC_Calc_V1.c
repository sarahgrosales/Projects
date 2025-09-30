#include <stdio.h>
#include <stdlib.h>

// function main begins program execution
int main( void )
{
    unsigned int passes = 0;
    unsigned failures = 0;
    unsigned student = 1;
    int result;

    while ( student <= 10 ) {

        printf( "%s", "Enter result ( 1=pass,2=fail ): " );
        scanf( "%d", &result );

        if (result == 1) {
            passes = passes + 1;
        }
        else {
            failures = failures + 1;
        }
        student = student + 1;
    }

printf( "Passed %u\n", passes );
printf( "Failed %u\n", failures );

if ( passes > 8 ) {
puts( "Bonus to instructor!" );
    }
}
