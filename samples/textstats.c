/*****************************************************************************\
FILE          : textstats.c
PROGRAMMER    : Peter Chapin
LAST REVISION : June 16, 2001

(C) Copyright 2001 by Peter Chapin

This file contains a filter program that analyizes a text file looking
for odd characters. It prints a short report at the end to alert the
user to anything that it found.

Please send comments or bug reports to

     Peter Chapin
     P.O. Box 317
     Randolph Center, VT 05061
     Peter.Chapin@vtc.vsc.edu
*****************************************************************************/

#include <stdio.h>

int main(void)
{
  int  ch;               // Current character from file.
  long number_lines = 0; // Number of complete lines found.
  long number_FF    = 0; // Number of form feeds found.
  long number_BS    = 0; // Number of back spaces found.
  long number_CR    = 0; // Number of carriage returns found.
  long number_other = 0; // Number of other control chars found.
  long number_chars = 0; //Total number of characters found.

  // Read input file.
  printf("\nReading input...");
  while ((ch = getchar()) != EOF) {
    number_chars++;
    
    switch (ch) {

      case '\n':
        number_lines++;
        break;

      case '\f':
        printf("\nLine %ld: Formfeed found", number_lines + 1);
        number_FF++;
        break;

      case '\b':
        printf("\nLine %ld: Backspace found", number_lines + 1);
        number_BS++;
        break;

      case '\r':
        printf("\nLine %ld: Carriage return found", number_lines + 1);
        number_CR++;
        break;

      default:
        if (ch < 0x20  &&  ch != '\t') {
          printf("\nLine %ld: Unusual control char found: %02X",
            number_lines + 1, ch
          );
          number_other++;
        }
        break;
    }
  }

  // Print report.
  printf("\n\n");
  printf("Total number of lines               : %ld\n", number_lines);
  printf("Total number of characters          : %ld\n", number_chars);
  printf("Total number of form feeds          : %ld\n", number_FF);
  printf("Total number of backspaces          : %ld\n", number_BS);
  printf("Total number of carriage returns    : %ld\n", number_CR);
  printf("Total number of other control chars : %ld\n", number_other);

  return 0;
}
