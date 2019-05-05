/* Filename        project6.cc
 * Date            May 5 2019
 * Author          Razvan Preotu
 * Email           rnp170130@utdallas.edu
 * Course          CS 3377.502 Spring 2019
 * Version         1.0
 * Copyright 2019, All Rights Reserved
 *
 * Description
 *
 * Reads binary files and displays them by using a cdk matrix
 */

#include "project6.h"
#include <stdlib.h>
#include <stdint.h>
#include <iostream>

using namespace std;

int main()
{
  BinaryFileHeader *header = new BinaryFileHeader();

  readBinary(header);

  displayMatrix(header);

  return 0;
}
