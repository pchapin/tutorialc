/*! \file    char_count.c
 *  \brief   Program that counts characters in an input file.
 *  \author  Peter C. Chapin <PChapin@vtc.vsc.edu>
 *
 * This file contains the final version of char_count.c as developed in Example #5.
 */
#include <stdio.h>

/* This array holds a counter for every possible character. */
int counters[256];

/*
 * This function intiailizes the program. In this version it just insures that all the character
 * counters are zeroed.
 *
 */
void initialize( void )
{
    int i;

    for( i = 0; i < 256; i++ ) {
        counters[i] = 0;
    }
}


/*
 * This function reads the input file, assumed to be at the standard input device, and counts
 * how many times each character occurs. Each character has its own counter in the counters
 * array.
 *
 */
void read_input( void )
{
    int ch;

    while( (ch = getchar( )) != EOF ) {
        counters[ch]++;
    }
}


/*
 * This function sweeps over the counters array and look for the element that is the largest. It
 * then returns the index into the array for that element. Note that this function returns an
 * array index. It does not return the largest element directly!
 *
 */
int get_largest_index( void )
{
    int i;
    int max = counters[0];  //Guess that the zeroth element is the max.
    int max_index = 0;      // The index of the maximum element.

    // Sweep over the rest of the array.
    for( i = 1; i < 256; i++ ) {

        // If this counter is bigger than our current max, remember it.
        if( counters[i] > max ) {
            max = counters[i];
            max_index = i;
        }
    }

    return max_index;
}


/*
 * This function outputs information on the ten most popular characters in the input file. It
 * should be called only after read_input has executed.
 *
 */
void output_results( void )
{
    int i;
    int max_index;

    // Print a nice header.
    printf( "Rank  ASCII  Ch  Count\n" );
    printf( "----  -----  --  -----\n" );

    // I want to print the top ten characters.
    for( i = 0; i < 10; i++ ) {

        // Find the largest and print information about it.
        max_index = get_largest_index( );
        printf(
            "%2d    %3d    %c   %d\n",
            i + 1, max_index, max_index, counters[max_index] );

        // Erase this one so that the second largest becomes the largest.
        counters[max_index] = -1;
    }
}


/*
 * This is just an empty placeholder function. It exists to facilitate future enhancements of
 * this program.
 *
 */
void clean_up( void )
{
    return;
}


/*
 * The Main Program
 *
 */
int main( void )
{
    initialize( );
    read_input( );
    output_results( );
    clean_up( );
    return 0;
}
