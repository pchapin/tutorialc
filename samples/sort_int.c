/*****************************************************************************
FILE          : sort_int.c
PROGRAMMER    : Peter Chapin
LAST REVISION : 2001-06-16

(C) Copyright 2001 by Peter Chapin

This file contains a program that sorts the integers presented to it
on standard input. It is used as Example #6 in CS-211 at Vermont
Technical College. See the example for further documentation.

Please send comments or bug reports to

     Peter Chapin
     Vermont Technical College
     Randolph Center, VT 05061
     pchapin@ecet.vtc.edu
*****************************************************************************/

#include <stdio.h>

int array[1000];
  /* Can only handle 1000 integers maximum. */

/*
 * int read_input(void)
 *
 * This function reads integers from the standard input and loads those
 * integers into array. It returns the number of integers read. It won't
 * attempt to load more than 1000 integers into array and thus it avoids
 * array bounds overflow errors.
 *
 */
int read_input(void)
{
  int  number;
  int *current = array;

  // Keep reading integers from the standard input until I hit EOF.
  while (scanf("%d", &number) != -1) {
    *current = number;
    current++;

    // If I read 1000 of them, abort this loop!
    if (current - array == 1000) break;
  }

  return current - array;
}


/*
 * void sort(int size)
 *
 * This function does a bubble sort on array. It only sorts the first
 * size elements. All other elements are ignored.
 *
 */
void sort(int size)
{
  int *p1, *p2;
  int did_swap;

  // If the array is too small to be interesting it is already sorted.
  if (size < 2) return;

  // Keep looping as long as I have to swap something.
  do {

    // Initialize for this pass.
    did_swap = 0;
    p1 = &array[0];
    p2 = &array[1];

    // Sweep down the array.
    do {

      // If the current two elements are out of order, swap them.
      if (*p1 > *p2) {
        int Temp = *p1;
        *p1      = *p2;
        *p2      = Temp;
        did_swap = 1;
      }

      // Get ready for the next pair of elements.
      p1++;
      p2++;
    } while (p2 < array + size);
  } while (did_swap);
}


/*
 * void output_results(int size)
 *
 * This function prints array onto the standard output device, putting
 * one integer on each line. It only outputs size elements. The other
 * elements of array are ignored.
 *
 */
void output_results(int size)
{
  int *p;

  for (p = array; p < array + size; p++) {
    printf("%d\n", *p);
  }
}


/*
 * Main Program
 *
 */
int main(void)
{
  int size;

  size = read_input();
  sort(size);
  output_results(size);
  return 0;
}
