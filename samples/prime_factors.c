/*****************************************************************************
FILE          : prime_factors.c
PROGRAMMER    : Peter Chapin
LAST REVISION : 2001-06-16

(C) Copyright 2001 by Peter Chapin

This file contains a filter program that will accept a series of integers
at the stdin and print out the prime factorization of each of those integers
on the stdout.

Please send comments or bug reports to

     Peter Chapin
     Vermont Technical College
     Randolph Center, VT 05061
     pchapin@ecet.vtc.edu
*****************************************************************************/

#include <stdio.h>

//
// The following function finds the first prime factor in its parameter
// It returns that factor or, if the parameter is prime, it returns the
// parameter itself. This function has undefined behavior if given a
// value less than 2. This implementation is fairly slow
//
int find_first_factor(int number)
{
  int i;

  // Loop over all values from 2 that are less than the given number.
  for (i = 2; i < number; i++) {

   // If we find a factor, return it. Since this is the first, it must
   // be prime.
   if (number % i == 0) return i;
  }

  // If we get here, number must be prime.
  return number;
}

//
// The following function displays a single term as a factor raised to a
// power. Although this version of the function is quite simple a future
// version might do more complicated things to get the display to look
// better.
//
void display_term(int factor, int count)
{
  if (count == 1) printf("%d", factor);
    else printf("%d^%d", factor, count);
}

/*----------------------------------*/
/*           Main Program           */
/*----------------------------------*/

int main(void)
{
  int number;          // The number under test.
  int prime_factor;    // The current factor under consideration.
  int factor_count;    // The number of copies of the latest factor.
  int old_factor = 0;  // The last factor for comparison.

  // Keep reading numbers from stdin until there are no more.
  while (scanf("%d", &number) != -1) {

    // Ignore numbers I don't like.
    if (number < 2) continue;

    factor_count = 0;

    // Keep looping as long as number isn't prime.
    while ((prime_factor = find_first_factor(number)) != number) {

      // If this factor is part of a set (or if it's the first) just
      // increment a counter.
      // 
      if (factor_count == 0 || prime_factor == old_factor) {
	factor_count++;
      }
      else {

        // Otherwise display the old set and get ready for the next. */
	display_term(old_factor, factor_count);
	printf(" * ");
	factor_count = 1;
      }
      old_factor = prime_factor;
      number /= prime_factor;
    }

    // We are done with the loop. Process any leftovers as well as the
    // last factor. The IF handles the case where the last factor is the
    // same as the ones we were accumulating. The ELSE handles the case
    // where the last factor is something different.
    // 
    if (number == old_factor) {
      factor_count++;
      display_term(old_factor, factor_count);
      printf("\n");
    }
    else {
      display_term(old_factor, factor_count);
      printf(" * %d\n", number);
    }
  }

  return 0;
}
