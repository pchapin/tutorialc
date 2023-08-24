/*! \file   string_test.c
 *  \brief  A program that illustrates the C library string functions.
 *  \author Peter Chapin <peter.chapin@vermontstate.edu>
 *
 * This file contains a demo program that exercises some of the commonly used functions declared
 * in <string.h>. To compile this program use a command such as:
 *
 *     $ gcc -Wall string_test.c -o string_test -lncurses
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <curses.h>

/*!
 * This function prepares curses for action. It sets appropriate screen modes for this
 * application.
 *
 */
void initialize_screen( void )
{
    initscr( );
    cbreak( );
    noecho( );
    nonl( );
}


/*!
 * This function cleans up curses and performs any other display related clean up this
 * application requires.
 *
 */
void reset_screen( void )
{
    endwin( );
}


/*
 * This function prints the string pointed at by string onto the screen. It starts at (row, col)
 * and prints exactly length characters. It will print past the null character if necessary. For
 * characters that are not normal printable characters, this function will print a special
 * symbol directly above the character and replace the character in the string with a '.'.
 *
 */
void print_string( const char *string, int length, int row, int col )
{
    int i;

    // i special characters above string.
    for( i = 0; i < length; i++ ) {

        switch( string[i] ) {
        case '\0': mvaddch( row, col + i, '0' ); break;
        case '\n': mvaddch( row, col + i, 'n' ); break;
        case '\t': mvaddch( row, col + i, 't' ); break;
        case '\v': mvaddch( row, col + i, 'v' ); break;
        case '\a': mvaddch( row, col + i, 'a' ); break;
        case '\r': mvaddch( row, col + i, 'r' ); break;
        case '\b': mvaddch( row, col + i, 'b' ); break;
        case '\f': mvaddch( row, col + i, 'f' ); break;
        default: mvaddch( row, col + i, ' ' ); break;
        }
    }

    // Print entire array -- not just to first null.
    for( i = 0; i < length; i++ ) {
        switch( string[i] ) {
        case '\0':
        case '\n':
        case '\t':
        case '\v':
        case '\a':
        case '\r':
        case '\b':
        case '\f':
            mvaddch( row + 1, col + i, '.' );
            break;
        
        default:
            if( isprint( string[i] ) )
                mvaddch( row + 1, col + i, string[i] );
            else
                mvaddch( row + 1, col + i, '.' );
            break;
        }
    }
}


/*!
 * This function gets a line of text from the keyboard. It starts getting text at the indicated
 * coordinates. It echos the characters as it gets them. This function is fairly rough, but it
 * will be sufficient for this program.
 *
 */
void get_line( int row, int col, char *buffer )
{
    int ch;
  
    move( row, col );

    // Keep reading characters until the user hits the carriage return key.
    while( ( ch = getch( ) ) != '\r' ) {
        *buffer = ch;
        buffer++;
        addch( ch );
    }

    // Null terminate what I've got.
    *buffer = '\0';
}


/*
 * The Main Program
 *
 */
int main( void )
{
    char s[40];         // Arrays for demonstration.
    char t[40];

    char buffer[128];   // To hold responses from user.
    int  quit_flag = 0; // =1 when the user wants to quit.

    // Display the main menu.
    initialize_screen( );

    mvaddstr( 16, 0, "a) gets(s)               q) Quit" );
    mvaddstr( 17, 0, "b) gets(t)" );
    mvaddstr( 19, 0, "c) strcpy(s, t)          f) strncpy(s, t, n)" );
    mvaddstr( 20, 0, "d) strcat(s, t)          g) strncat(s, t, n)" );
    mvaddstr( 21, 0, "e) strcmp(s, t)          h) strncmp(s, t, n)" );
    mvaddstr( 23, 0, "i) strchr(s, ch)" );

    mvaddstr( 2,  8, "string s" );
    mvaddstr( 2, 63, "strlen(s)=" );
    mvaddstr( 7,  8, "string t" );
    mvaddstr( 7, 63, "strlen(t)=" );

    do {

        // Print strings inside of box.
        print_string( s, 40, 3, 19 );
        mvprintw( 2, 73, "%d", strlen( s ) );
        print_string( t, 40, 8, 19);
        mvprintw( 7, 73, "%d", strlen( t ) );

        // Erase interaction line and prompt. Print new prompt.
        move( 13, 0 ); clrtoeol( );
        move( 14, 0 ); clrtoeol( );
        mvaddstr( 13, 0, "Option? " );

        // Get command and handle it.
        get_line( 13, 8, buffer );
        switch( toupper( buffer[0] ) ) {

            char *result;

        case 'A':
            mvaddstr( 14, 0, "s : " );
            get_line( 14, 4, s );
            break;

        case 'B':
            mvaddstr( 14, 0, "t : " );
            get_line( 14, 4, t );
            break;

        case 'C': strcpy( s, t ); break;

        case 'D': strcat( s, t ); break;

        case 'E':
            mvprintw( 14, 0, "strcmp(s,t) returns %d. Strike any key", strcmp( s, t ) );
            getch( );
            break;

        case 'F':
            mvaddstr( 14, 0, "What value to use for n? " );
            get_line( 14, 28, buffer );
            strncpy( s, t, atoi( buffer ) );
            break;

        case 'G':
            mvaddstr( 14, 0, "What value to use for n? " );
            get_line( 14, 28, buffer );
            strncat( s, t, atoi( buffer ) );
            break;

        case 'H':
            mvaddstr( 14, 0, "What value to use for n? " );
            get_line( 14, 28, buffer );
            mvprintw( 14, 0,
              "strncmp( s, t, %d ) returns %d. Strike any key.",
              atoi( buffer ), strncmp( s, t, atoi( buffer ) ) );
            getch( );
            break;

        case 'I':
            mvaddstr( 14, 0, "What value to use for ch? " );
            get_line( 14, 29, buffer );
            result = strchr( s, buffer[0] );
            if( result == NULL ) {
                mvprintw( 14, 0,
                  "strchr(s, '%c') returns NULL. Strike any key.", buffer[0] );
                getch( );
            }
            else {
                mvaddch( 5, 19 + ( result - s ), '^' );
                mvprintw( 14, 0,
                  "strchr(s, '%c') returns pointer as shown. Strike any key.", buffer[0] );
                getch( );
                mvaddch( 5, 19 + ( result - s ), ' ' );
            }
            break;

        case 'Q':
            quit_flag = 1;
            break;
        }

    } while( !quit_flag );

    reset_screen( );
    return EXIT_SUCCESS;
}
