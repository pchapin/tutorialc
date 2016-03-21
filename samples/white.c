/*! \file    white.c
 *  \brief   Program that detects white space in a file.
 *  \author  Peter C. Chapin <PChapin@vtc.vsc.edu>
 *
 * This filter program detects white space at the ends of lines and informs the user which lines
 * are so affected. It also notices blank lines at the end of the input and informs the user of
 * the number of such lines.
 */
#include <stdio.h>

#define NO  0
#define YES 1

int main( void )
{
    int ch;                // A character from the input device.
    int seen_white  = NO;  // =YES after I see some white space.
    int line_blank  = YES; // =NO after I see a normal character on a line.
    int blank_count = 0;   // The number of blank lines before current point.
    int line_count  = 1;   // The line number of the current line.

    // Read the input one character at a time.
    while( ( ch = getchar( ) ) != EOF ) {

        // Is this the end of a line?
        if( ch == '\n' ) {
            if( seen_white == YES ) {
                printf( "Line %d has trailing white space.\n", line_count );
            }

            // If the previous line was blank, increment the blank line count.
            if( line_blank == YES ) {
                blank_count++;
            }

            line_blank = YES;
            seen_white = NO;
            line_count++;
        }
        
        // If I see white space, remember that.
        else if( ch == ' ' || ch == '\t' ) {
            seen_white = YES;
        }

        // If I see a normal character (not '\n' and not white space) then this is not a blank
        // line.
        else {
            line_blank = NO;
            seen_white = NO;
            blank_count = 0;
        }
    }

    // Was there an unterminated line?
    if(line_blank == NO ) {
        printf( "The last line of input does not have a newline at the end.\n" );
    }

    // Is the last line unterminated with just white space?
    if( line_blank == YES && seen_white == YES ) {
        printf(
            "Line %d (last line) is unterminated and has trailing white space.\n", line_count );
    }

    // Are there blank lines at the end?
    if( blank_count != 0 ) {
        if( blank_count == 1 ) {
            printf( "There is 1 blank line at the end of the input.\n" );
        }
        else {
            printf( "There are %d blank lines at the end of the input.\n", blank_count );
        }
    }

    return 0;
}
