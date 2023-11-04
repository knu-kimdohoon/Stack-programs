#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "Stack_Link.h"

int Convert(StackHead* head, int data) {
	int remain = 0;
	int count = 0;

	//printf("[Convert]data : %d\n", data);

	while (data != 0) {
		remain = 0;

		//printf("data[before]: %d\n", data);

		remain = data % 2;
		//printf("remain: %d\n", remain);

		Push_L(head, remain);

		data /= 2;

		//printf("data[after]: %d\n", data);
		count++;

		//printf("count: %d\n", count);
		//printf("\n");
	}
	
	return count;
}

void main() {
	StackHead* head=CreateStack_L();
	int data=0;
	int count = 0;
	int i = 0;
	printf("Enter a number:\n ");
	scanf("%d", &data);

	count=Convert(head, data);
	//printf("%d", Convert(head, data));

	printf("The binary number of %d : ", data);
	for (i = 0; i < count; i++) {
		data = 0;
		data=Pop_L(head);
		printf("%d", data);
	}
	
	DestroyStack_L(head);
}