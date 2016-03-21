/*! \file    prec.c
 *  \brief   Program that demonstrates the basics of operator precedence.
 *  \author  Peter C. Chapin <PChapin@vtc.vsc.edu>
 *
 * This file contains a program which demonstrates operator precedence. It allows the user to
 * enter some values and then prints out the results of several expressions.
 */

#include <stdio.h>

int main( void )
{
    int i, j, k;  // Numbers entered by user
    int result;   // Result of calculations

    // Get some values from the user.
    printf( "i = " ); scanf( "%d", &i );
    printf( "j = " ); scanf( "%d", &j );
    printf( "k = " ); scanf( "%d", &k );
    printf( "\n" );

    // Compute a few interesting expressions and display the results.
    result = i * j + k;
    printf( "i * j + k = %d\n", result );

    result = i * (j + k);
    printf( "i * (j + k) = %d\n", result );

    result = i * j / k;
    printf( "i * j / k = %d\n", result );

    result = i / j * k;
    printf( "i / j * k = %d\n", result );

    result = i / (j * k);
    printf( "i / (j * k) = %d\n", result );

    return 0;
}

