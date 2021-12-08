/*
 * main.c
 *
 *  Created on: Dec 7, 2021
 *      Author: matt
 */

#include "finalexamprep.h"

#define FILENAME "monsters.txt"

// DO NOT EDIT ME!!!
int main(int argc, char *argv[]){

	int rows = 0;
	Data *dataArray = readFileIntoArray(FILENAME, &rows);
	if(dataArray == NULL){
		printf("Data Array was not filled\n");
		exit(-1);
	}
	if(rows == 0){
		printf("Rows was not saved\n");
		exit(-2);
	}
	for(int i=0; i<rows; i++){
		printf("%s %s\n", dataArray[i].monster, dataArray[i].attack);
	}

	char *string = alphaSortMonster(dataArray, 5);
	if(string != NULL){
		printf("New String: %s\n", string);
		printf("Old String: %s\n", dataArray[5].monster);
		free(string);
	}
	freeData(dataArray);

}
