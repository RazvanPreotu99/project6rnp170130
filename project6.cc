/* Filename       project6.cc
 * Date           May 5 2019
 * Author         Razvan Preotu
 * Email          rnp170130@utdallas.edu
 * Course         CS 3377.502 Spring 2019
 * Version        1.0
 * Copyright 2019, All Rights Reserved
 *
 * Description
 *
 * Reads contexts from a binary file and displays them using CDK matrix
 *
 */

#include "project6.h"
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{

  // Create pointer to a BinaryFileHeader object
  BinaryFileHeader *header = new BinaryFileHeader();

  // Open binary file
  ifstream binInfile ("cs3377.bin", ios::in | ios::binary);

  // Check if binary file was opened properly
  if (!binInfile)
  {
    cout << "error opening file" << endl;  
    exit(1);
  }

  // Read from binary file and store in header
  binInfile.read((char*) header,sizeof(BinaryFileHeader));

  // Check if read failed
  if (binInfile.fail())
  {
    cout << "error reading from binary file" << endl;
    exit(1);
  }

  // Create an array of pointers to BinaryFileRecord objects, size was read from before
  BinaryFileRecord *records [header->numRecords];

  // Loop through array and read from binary file for each index
  for (unsigned int i = 0; i < header->numRecords; i++)
  {
    // Create pointer to a BinaryFileRecord
    records[i] = new BinaryFileRecord();

    // Read from binary file and store in records[i]
    binInfile.read((char*) records[i], sizeof(BinaryFileRecord));

    // Check if read failed
    if (binInfile.fail())
    {
      cout << "eror reading from binary file" << endl;
      exit(1);
    }
  } 
  
  // Close binary file
  binInfile.close();
  
  // Display information using a CDK matrix
  displayMatrix(header,records);

  return 0;

}
