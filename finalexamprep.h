/*
 * finalexamprep.h
 *
 *  Created on: Dec 7, 2021
 *      Author: matt
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef FINALEXAMPREP_H_
#define FINALEXAMPREP_H_

typedef struct data{
	char attack[256];
	char monster[256];
}Data;

Data *readFileIntoArray(const char *filename, int *rows);

char *alphaSortMonster(Data *dataArray, int index);

void freeData(Data *dataArray);




/*******************************************************
 *
 * Step 1: Implement readFileIntoArray to read data from a file
 * 			into a Data array. You may assume no monster or attack is
 * 			longer than 256 bytes. NOTE: The first value in a valid
 * 			file must contain a number indicating the number of
 * 			monsters to read. This number must be able to be
 * 			accessed by the main function.
 *
 * Step 2: Implement alphaSortMonster to pull a piece of data
 * 			from the data array at the provided index.
 * 			Then sort the array alphabetically (A-z)
 * 			maintaining capitalization. Also note, this should not be
 * 			done in place, and main should be able to validate the
 * 			original string is the same and a new string is alphabetical
 *
 *******************************************************/

#endif /* FINALEXAMPREP_H_ */
