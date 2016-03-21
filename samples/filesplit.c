/*****************************************************************************
FILE          : filesplit.c
PROGRAMMER    : Peter Chapin
LAST REVISION : 2001-06-16

(C) Copyright 2001 by Peter Chapin

This file contains an implementation of a file splitting utility. See 
EXAMPLE-08.txt for more information.

Please send comments or bug reports to

     Peter Chapin
     Vermont Technical College
     Randolph Center, VT 05061
     pchapin@ecet.vtc.edu
*****************************************************************************/

#include <stdio.h>

#define YES 1
#define NO  0

int main(void)
{
  char infile_name[128+1];
  char outfile_base[128+1];
  long piece_size;
  long byte_count;
  int  piece_count;
  int  open_flag;

  FILE *infile, *outfile;
  int  ch;
  char outfile_name[128+1];

  // Get the input from the user and validated it.
  printf("Input file name? ");
  gets(infile_name);
  printf("Output base name? ");
  gets(outfile_base);
  printf("Piece size? ");
  scanf("%ld", &piece_size);
  if (piece_size < 1) {
    printf("Error: The piece size of %ld is unacceptable.\n", piece_size);
    return 1;
  }

  // Try to open the input file.
  if ((infile = fopen(infile_name, "rb")) == NULL) {
    printf("Error: Can't open %s for input.\n", infile_name);
    return 1;
  }

  // Initialize.
  byte_count  = 0;
  piece_count = 1;
  open_flag   = NO;

  // Read the entire input.
  while ((ch = getc(infile)) != EOF) {

    // Do I need to open an output file? If so, then do it.
    if (open_flag == NO) {
      sprintf(outfile_name, "%s.%03d", outfile_base, piece_count);
      piece_count++;
      if ((outfile = fopen(outfile_name, "wb")) == NULL) {
        printf("Error: Can't open %s for writing.\n", outfile_name);
        fclose(infile);
        return 1;
      }
      open_flag = YES;
    }

    // Write this byte to the output, checking for errors.
    if (putc(ch, outfile) == EOF) {
      printf("Error: Can't write to output. Disk full?\n");
      fclose(outfile);
      fclose(infile);
      return 1;
    }

    byte_count++;
    if (byte_count == piece_size) {
      if (fclose(outfile) == EOF) {
        printf("Error: Output close failed. Disk full?\n");
        fclose(infile);
        return 1;
      }
      byte_count = 0;
      open_flag  = NO;
    }
  }

  // Is an output file still open when the loop ends?
  if (open_flag == YES) {
    if (fclose(outfile) == EOF) {
      printf("Error: Output close failed. Disk full?\n");
      fclose(infile);
      return 1;
    }
  }

  // Clean up.
  fclose(infile);
  printf("Split complete; %d pieces made.\n", piece_count - 1);
  return 0;
}
