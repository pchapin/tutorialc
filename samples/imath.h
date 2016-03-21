/*****************************************************************************
FILE          : imath.h
PROGRAMMER    : Peter Chapin
LAST REVISION : 2001-06-16

(C) Copyright 2001 by Peter Chapin

This file contains the declarations of a number of functions in a simple
integer math library. This library is used as an example in CS-211 at
Vermont Technical College.

Please send comments or bug reports to

     Peter Chapin
     Vermont Technical College
     Randolph Center, VT 05061
     pchapin@ecet.vtc.edu
*****************************************************************************/

int factorial(int N);
  /* This function computes N! and returns the result. N! is found by
     multiplying N * (N-1) * (N-2) * ... * 1. Zero factorial is 1 by
     definition. Negative values of N yield undefined behavior. If N!
     overflows int, the effect is undefined. */

int GCD(int A, int B);
  /* This function returns the greatest common divisor (GCD) of A and
     B. The GCD is the largest integer that will divide into both A
     and B evenly. It is useful for reducing fractions. This function
     assumes A and B are positive. */

int raise_power(int base, int exponent);
  /* This function raises Base to the power of exponent. It uses a
     special method which allows it to execute much faster than by
     just "multiplying it out." In particular it executes in a time
     proportional to the log base 2 of exponent. If the result overflows
     integer or if exponent is negative the effect is undefined. */

int combinations(int group, int total);
  /* This function returns the number of different ways you can take
     group items from a collection of total items. For example, if you
     had 10 distinct marbles, how many different sets of three could
     you make from the 10. The call combinations(3, 10) would tell you.
     This function assumes total >= group and that both total and group
     are positive, non-zero values. */

int permutations(int group, int total);
  /* This function is similar to combinations except that it regards
     different orderings of the items in group as distinct. This
     function has the same restrictions on its use as Combinations. */
