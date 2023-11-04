#include <stdio.h>
#include "Stack_Link2.h"

void main() {
	
	StackHead* headN = CreateStack_Number();
	int i = 0;
	int data = 0;

	printf("5 numbers: \n");
	for (i = 0; i < 5; i++) {
		scanf("%d", &data);
		Push_Number(headN, data);
	}
	
	printf("Reverse: \n");
	for (i = 0; i < 5; i++) {
		data = Pop_Number(headN);
		printf("%d\n", data);
	}

	DeleteStack_Number(headN);
	
	/*
	FILE* fp = NULL;
	int c = 0;

	fp = fopen("output.txt", "w");
	if (fp == NULL) {
		printf("Failed to open file");
		exit(1);
	}
	fputc('H', fp);
	fputc('E', fp);
	fputc('L', fp);
	fputc('L', fp);
	fputc('O', fp);
	fputc('K', fp);

	fclose(fp);

	fp = fopen("output.txt", "r");

	while ((c = fgetc(fp)) != EOF) {
		putchar(c);
	}
	fclose(fp);
	*/
}