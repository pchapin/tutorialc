/*! \file    prime.c
 *  \brief   Program that checks a number for primality.
 *  \author  Peter C. Chapin <PChapin@vtc.vsc.edu>
 *
 * The following program tests to see if a number is prime. This version is fairly fast because
 * it lowers the upper limit of the test as it goes. As a result it only has to go up to
 * approximately the square root of the given number before it concludes that the number is
 * prime.
 */

#include <stdio.h>

int main( void )
{
    int number;    // The number I am testing.
    int i;         // Loop index.
    int prime = 1; // We start by assuming the number is prime.
    int upper;     // Upper bound of the for loop.

    // Ask the user to enter a number.
    printf( "Enter a number: " );
    scanf( "%d", &number );

    // Do I like it? If not, print a message and die.
    if( number < 2 ) {
        printf( "The value %d is not prime.\n", number );
        return 1;
    }

    // Can I divide this number by anything less than it?
    upper = number;
    for( i = 2; (i < upper) && prime; i++ ) {

        // If it divides evenly, it's not prime. Otherwise we can adjust upper.
        if( number % i == 0 ) {
            prime = 0;
        }
        else {
            upper = number / i;
        }
    }

    // What is the result of my test?
    if( prime ) {
        printf( "The number %d is prime!\n", number );
    }
    else {
        printf( "I'm sorry, %d is not prime. It can be divided by %d\n", number, i - 1 );
    }
    return 0;
}

