/*! \file    types_demo.c
 *  \brief   Program that demonstrates C's built-in types.
 *  \author  Peter C. Chapin <PChapin@vtc.vsc.edu>
 *
 * This file contains a program that demonstrates all the standard built it types. It uses the
 * macros in limits.h and float.h to print out interesting facts about your implementation. As a
 * side effect, this program also demonstrates all the different format specifiers for printf.
 */
#include <limits.h>
#include <float.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    // Integral types.
    unsigned char ucMin = 0, ucMax = UCHAR_MAX;
    signed char scMin = SCHAR_MIN, scMax = SCHAR_MAX;
    char cMin = CHAR_MIN, cMax = CHAR_MAX;
    short sMin = SHRT_MIN, sMax = SHRT_MAX;
    unsigned short usMin = 0, usMax = USHRT_MAX;
    int iMin = INT_MIN, iMax = INT_MAX;
    unsigned int uiMin = 0, uiMax = UINT_MAX;
    long lMin = LONG_MIN, lMax = LONG_MAX;
    unsigned long ulMin = 0, ulMax = ULONG_MAX;
    long long llMin = LLONG_MIN, llMax = LLONG_MAX;
    unsigned long long ullMin = 0, ullMax = ULLONG_MAX;

    // Floating point types.
    float fMin = FLT_MIN, fMax = FLT_MAX;
    double dMin = DBL_MIN, dMax = DBL_MAX;
    long double ldMin = LDBL_MIN, ldMax = LDBL_MAX;

    printf( "\n" );
    printf( "Ranges of Arithmetic Types\n" );
    printf( "==========================\n" );
    printf(    "%20d <= unsigned char   <= %-20d\n", ucMin, ucMax );
    printf(    "%20d <=   signed char   <= %-20d\n", scMin, scMax );
    printf(    "%20d <=          char   <= %-20d\n", cMin, cMax );
    printf(   "%20hd <=          short  <= %-20hd\n", sMin, sMax );
    printf(   "%20hu <= unsigned short  <= %-20hu\n", usMin, usMax );
    printf(    "%20d <=          int    <= %-20d\n", iMin, iMax );
    printf(    "%20u <= unsigned int    <= %-20u\n", uiMin, uiMax );
    printf(   "%20ld <=          long   <= %-20ld\n", lMin, lMax );
    printf(   "%20lu <= unsigned long   <= %-20lu\n", ulMin, ulMax );
    printf(  "%20lld <=          long long <= %-20lld\n", llMin, llMax );
    printf(  "%20llu <= unsigned long long <= %-20llu\n", ullMin, ullMax );
    printf(  "%20.8e <=          float  <= %-20.8e\n", fMin, fMax );
    printf(  "%20.8e <=          double <= %-20.8e\n", dMin, dMax );
    printf( "%20.8Le <=     long double <= %-20.8Le\n", ldMin, ldMax );

    printf( "\n" );
    printf( "Sizes of Arithmetic Types\n" );
    printf( "=========================\n" );
    printf( "The sizeof char         : %d\n", sizeof(char) );
    printf( "The sizeof short        : %d\n", sizeof(short) );
    printf( "The sizeof int          : %d\n", sizeof(int) );
    printf( "The sizeof long         : %d\n", sizeof(long) );
    printf( "The sizeof long long    : %d\n", sizeof(long long) );
    printf( "The sizeof float        : %d\n", sizeof(float) );
    printf( "The sizeof double       : %d\n", sizeof(double) );
    printf( "The sizeof long double  : %d\n", sizeof(long double) );
    printf( "The sizeof a pointer    : %d\n", sizeof(char *) );
    printf( "The sizeof size_t       : %d\n", sizeof(size_t) );
    printf( "The sizeof ptrdiff_t    : %d\n", sizeof(ptrdiff_t) );
 
    printf( "\n" );
    printf( "Other Values of Interest\n" );
    printf( "========================\n" );
    printf( "Number of bits in a char: %d\n", CHAR_BIT );
    printf( "Number of decimal digits of precision of the floating types:\n" );
    printf( "\tfloat      : %d\n", FLT_DIG );
    printf( "\tdouble     : %d\n", DBL_DIG );
    printf( "\tlong double: %d\n", LDBL_DIG );

    return EXIT_SUCCESS;
}
