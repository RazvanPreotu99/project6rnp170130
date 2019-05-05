/* Filename        project6.h
 * Date            May 5 2019
 * Author          Razvan Preotu
 * Email           rnp170130@utdallas.edu
 * Course          CS 3377.502 Spring 2019
 * Version         1.0
 * Copyright 2019, All Rights Reserved
 *
 * Description
 *
 * Header file for proejct 6
 *
 */

// include guard
#ifndef _PROJECT6_H
#define _PROJECT6_H

#include <stdint.h>

// BinaryFileHeader class definition
class BinaryFileHeader
{

 public:

  uint32_t magicNumber;
  uint32_t versionNumber;
  uint64_t numRecords;
};

// Constant
const int maxRecordStringLength = 25;

// BinaryFileRecord class definition
class BinaryFileRecord
{
 public:

  uint8_t strLength;
  char stringBuffer[maxRecordStringLength];
};

// Function prototype
void displayMatrix(BinaryFileHeader*,BinaryFileRecord*[]);

#endif
