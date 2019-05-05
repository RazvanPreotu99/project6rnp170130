/* Filename       readFile.cc
 * Date           May 5 2019
 * Author         Razvan Preotu
 * Email          rnp170130@utdallas.edu
 * Course         CS 3377.502 Spring 2019
 * Version        1.0
 * Copyright 2019, All Rights Reserved
 *
 * Description
 *
 * Reads contexts from binary file
 *
 *
 */

#include "project6.h"
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;

void readBinary (BinaryFileHeader *myHeader)
{
  
  ifstream binInfile ("cs3377.bin", ios::in | ios::binary);

  if (!binInfile)
  {
    cout << "error opening file" << endl;  
  }

  binInfile.read((char*) myHeader,sizeof(BinaryFileHeader));

  if (binInfile.fail())
  {
    cout << "error reading from binary file" << endl;
    exit(1);
  }

  binInfile.close();
}
