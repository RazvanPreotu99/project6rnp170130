/* Filename        matrix.cc
 * Date            May 5 2019
 * Author          Razvan Preotu
 * Email           rnp170130@utdallas.edu
 * Course          CS 3377.502 Spring 2019
 * Version         1.0
 * Copyright 2019, All Rights Reserved
 *
 * Description
 *
 * Creates a cdk matrix to display contexts of binary files
 *
 */

#include "project6.h"
#include <iostream>
#include "cdk.h"
#include <stdint.h>
#include <stdio.h>
#include <cstring>
#include <sstream>
#include <string>

#define MATRIX_WIDTH 3
#define MATRIX_HEIGHT 5
#define BOX_WIDTH 20
#define MATRIX_NAME_STRING "Binary File Contents"

using namespace std;

void displayMatrix(BinaryFileHeader *myHeader)
{

  WINDOW	*window;
  CDKSCREEN	*cdkscreen;
  CDKMATRIX     *myMatrix;           // CDK Screen Matrix

  const char 		*rowTitles[MATRIX_WIDTH+1] = {"R0", "a", "b", "c"};
  const char 		*columnTitles[MATRIX_HEIGHT+1] = {"C0", "a", "b", "c","d","e"};
  int		boxWidths[MATRIX_WIDTH+1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int		boxTypes[MATRIX_WIDTH+1] = {vMIXED, vMIXED, vMIXED, vMIXED};

  /*
   * Initialize the Cdk screen.
   *
   * Make sure the putty terminal is large enough
   */
  window = initscr();
  cdkscreen = initCDKScreen(window);

  /* Start CDK Colors */
  initCDKColor();

  /*
   * Create the matrix.  Need to manually cast (const char**) to (char **)
  */
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH,
			  MATRIX_NAME_STRING, (char **) columnTitles, (char **) rowTitles, boxWidths,
				     boxTypes, 1, 1, ' ', ROW, true, true, false);

  if (myMatrix ==NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }

  // Create message for magic number
  char magicMsg[] = "Magic: 0x";
  char magic[10];
  sprintf(magic, "%X", myHeader-> magicNumber);
  strcat (magicMsg,magic);

  // Display magic number message
  setCDKMatrixCell(myMatrix, 1, 1, (const char*)magicMsg);

  // Create message for version
  char versionMsg[] = "Version: ";
  char version[10];
  sprintf(version, "%d", myHeader-> versionNumber);
  strcat(versionMsg,version);

  // Display version message
  setCDKMatrixCell(myMatrix, 1, 2, (const char*)versionMsg);

  // Create message for numrecords
  char recordMsg[] = "NumRecords: ";
  char numRecords[10];
  sprintf(numRecords, "%lu", myHeader-> numrecords);
  strcat(recordMsg,numRecords);

  // Display record message
  setCDKMatrixCell(myMatrix, 1, 3, (const char*)recordMsg);

  /* Display the Matrix */
  drawCDKMatrix(myMatrix, true);

  // Show Matrix until user enters a character
  char exit;

  cin >> exit;

  // Cleanup screen
  endCDK();
}
