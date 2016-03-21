/*****************************************************************************
FILE          : imath.c
PROGRAMMER    : Peter Chapin
LAST REVISION : 2001-06-16

(C) Copyright 2001 by Peter Chapin

This file contains the implementation of the various functions declared
and documented in imath.h. It is used as a library example in CS-211
at Vermont Technical College.

Please send comments or bug reports to

     Peter Chapin
     Vermont Technical College
     Randolph Center, VT 05061
     pchapin@ecet.vtc.edu
*****************************************************************************/

#include <stdio.h>   /* Only needed for the error message. */
#include "imath.h"   /* Good idea to #include this too.    */

/*
 * int factorial(int N)
 *
 * This function computes N! using the obvious method.
 *
 */
int factorial(int N)
{
  int result = 1;

  // Handle 0! as a special case. Just return 1 at once.
  if (N == 0) return result;

  // Keep looping until N == 1. Multiply N into result as we go.
  while (N > 1) {
    result *= N;
    N--;
  }

  return result;
}


/*
 * int GCD(int A, int B)
 *
 * This function computes the greatest common divisor of A and B using
 * Euclid's Algorithm. This method is described in most introductory
 * algorithm books. For example see "Fundamentals of Sequential and
 * Parallel Algorithms" by Kenneth Berman and Jerome Paul (PWS Publish-
 * ing (C) 1997, ISBN=053494674-7), page 5.
 *
 */
int GCD(int A, int B)
{
  int remainder;

  while (B != 0) {
    remainder = A % B;
    A = B;
    B = remainder;
  }

  return A;
}


/*
 * int raise_power(int base, int exponent)
 *
 * This function uses a recursive algorithm to efficiently compute base
 * raised to the power of exponent. This algorithm is also described in
 * "Fundamentals of Sequential and Parallel Algorithms" (full reference
 * in the GCD function header), page 20.
 *
 */
int raise_power(int base, int exponent)
{
  int pow;

  if (exponent == 1) pow = base;
  else {
    if (exponent % 2 == 0) {
      pow = raise_power(base * base, exponent/2);
    }
    else {
      pow = base * raise_power(base * base, (exponent - 1)/2);
    }
  }
  return pow;
}


/*
 * int combinations(int group, int total)
 *
 * This implementation uses the factorial function to compute the
 * standard combinations formula. This is not the best thing to do
 * since factorials quickly become very large and tend to overflow
 * int for all but the smallest inputs. Better methods exist that
 * don't overflow so easily.
 *
 */
int combinations(int group, int total)
{
  return factorial(total) / (factorial(group) * factorial(total - group));
}


/*
 * int Permutations(int group, int total)
 *
 * This implementation uses the combinations function as a base for the
 * calculation. This is not the best way to go, but it works in theory.
 * This function will suffer the same overflow concerns as combinations
 * since it uses combinations. In addition factorial(group) will be
 * calculated twice this way. It would be better to express combinations
 * in terms of Permutations rather than the other way around.
 *
 */
int Permutations(int group, int total)
{
  return factorial(group) * combinations(group, total);
}
