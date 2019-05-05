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
 * Creates a CDK matrix to display contexts of binary files
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
#include <string.h>

#define MATRIX_WIDTH 3
#define MATRIX_HEIGHT 5
#define BOX_WIDTH 20
#define MATRIX_NAME_STRING "Binary File Contents"

using namespace std;

void displayMatrix(BinaryFileHeader *myHeader, BinaryFileRecord *myRecords[])
{

  WINDOW	*window;
  CDKSCREEN	*cdkscreen;
  CDKMATRIX     *myMatrix;           // CDK Screen Matrix

  const char 		*rowTitles[MATRIX_WIDTH+1] = {"R0", "a", "b", "c"};
  const char 		*columnTitles[MATRIX_HEIGHT+1] = {"C0", "a", "b", "c","d","e"};
  int		boxWidths[MATRIX_WIDTH+1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int		boxTypes[MATRIX_WIDTH+1] = {vMIXED, vMIXED, vMIXED, vMIXED};

  // Initialize the Cdk screen
  window = initscr();
  cdkscreen = initCDKScreen(window);

  // Start CDK Colors
  initCDKColor();

  // Create the matrix
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH,
			  MATRIX_NAME_STRING, (char **) columnTitles, (char **) rowTitles, boxWidths,
				     boxTypes, 1, 1, ' ', ROW, true, true, false);

  // Check if matrix was created successfully
  if (myMatrix ==NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }

  // Create message for magicNumber
  char magicMsg[] = "Magic: 0x";
  char magic[10];
  sprintf(magic, "%X", myHeader-> magicNumber);
  strcat (magicMsg,magic);

  // Display magicNumber message
  setCDKMatrixCell(myMatrix, 1, 1, (const char*)magicMsg);

  // Create message for versionNumber
  char versionMsg[] = "Version: ";
  char version[10];
  sprintf(version, "%u", myHeader-> versionNumber);
  strcat(versionMsg,version);

  // Display versionNumber message
  setCDKMatrixCell(myMatrix, 1, 2, (const char*)versionMsg);

  // Create message for numRecords
  char recordMsg[] = "NumRecords: ";
  char numRecords[20];
  sprintf(numRecords, "%lu", myHeader-> numRecords);
  strcat(recordMsg,numRecords);

  // Display numRecords message
  setCDKMatrixCell(myMatrix, 1, 3, (const char*)recordMsg);

  // Display all record information
  for (unsigned int i = 0; i < myHeader->numRecords;i++)
  {
    // Create message for strLength
    char lengthMsg[] = "strlen: ";
    char size[3];

    sprintf(size,"%u", myRecords[i]->strLength);
    strcat(lengthMsg,size);
    
    // Display strLength
    setCDKMatrixCell(myMatrix, i + 2, 1, (const char*)lengthMsg);
    
    // Display stringBuffer
    setCDKMatrixCell(myMatrix, i + 2, 2, (const char*)myRecords[i]-> stringBuffer);
  } 

  // Display the Matrix
  drawCDKMatrix(myMatrix, true);

  // Show Matrix until user enters a character
  char exit;

  cin >> exit;

  // Cleanup screen
  endCDK();
}
