/*
 * finalexamprep.c
 *
 *  Created on: Dec 7, 2021
 *      Author: matt
 */

#include "finalexamprep.h"


Data *readFileIntoArray(const char *filename, int *rows){
	FILE *f = fopen(filename, "r");
	if(f == NULL){
		return NULL;
	}
	Data *dataArray;
	if(fscanf(f, "%d", rows) != 0){
		dataArray = (Data *)malloc(sizeof(Data) * (*rows));

	}
	else{
		fclose(f);
		return NULL;
	}
	int i;
	for(i=0; i<*rows; i++){
		fscanf(f, "%s %s", dataArray[i].monster, dataArray[i].attack);
	}
	fclose(f);
	return dataArray;
}

char *alphaSortMonster(Data *dataArray, int index){
	char *string = malloc(sizeof(char) * 256);
	strcpy(string, dataArray[index].monster);
	int n = strlen(string);
	char temp;
	int i, j;
	for (i = 0; i < n-1; i++) {
		for (j = i+1; j < n; j++) {
			if (string[i] > string[j]) {
				temp = string[i];
				string[i] = string[j];
				string[j] = temp;
			}
		}
	}
	return string;
}

void freeData(Data *dataArray){
	if(dataArray == NULL){
		return;
	}
	free(dataArray);
}








