/*****************************************************************************
FILE          : imath_test.c
PROGRAMMER    : Peter Chapin
LAST REVISION : 2001-06-16

(C) Copyright 2001 by Peter Chapin

This file contains a test fixture program for the imath library.

Please send comments or bug reports to

     Peter Chapin
     Vermont Technical College
     Randolph Center, VT 05061
     pchapin@ecet.vtc.edu
*****************************************************************************/

#include <stdio.h>
#include "imath.h"

int main(void)
{
  int choice;
  int number;
  int A, B;

  // Ask the user what needs to be tested.
  printf("\nSelect a test:\n\n");
  printf("1) factorial\n");
  printf("2) GCD\n");
  printf("3) raise_power\n");
  printf("4) combinations\n");
  printf("5) permutations\n");
  scanf("%d", &choice);
  printf("\n");

  // Perform the appropriate test.
  switch (choice) {
    case 1:
      // Get the value from the user.
      printf("What number? ");
      scanf("%d", &number);

      // Run the factorial function and print the result.
      printf("%d factorial is %d\n", number, factorial(number));
      break;

    case 2:
      // Get values from the user.
      printf("What numbers? ");
      scanf("%d %d", &A, &B);

      // Run the GCD function and print the result.
      printf("The GCD of %d and %d is %d\n", A, B, GCD(A, B));
      break;

    case 3:
      // Get values from the user.
      printf("Base and Exponent? ");
      scanf("%d %d", &A, &B);

      // Run the raise_power function and print the result.
      printf("%d to the power of %d is %d\n", A, B, raise_power(A, B));
      break;

    case 4:
      // Get values from the user.
      printf("Group and Total? ");
      scanf("%d %d", &A, &B);

      // Run the combinations function and print the result.
      printf(
        "There are %d ways to choose %d items from %d.\n",
         combinations(A, B), A, B
      );
      break;

    case 5:
      // Get values from the user.
      printf("Group and Total? ");
      scanf("%d %d", &A, &B);

      // Run the permutations function and print the result.
      printf(
        "There are %d ways to choose and arrange %d items from %d.\n",
         permutations(A, B), A, B
      );
      break;
  }
  return 0;
}
