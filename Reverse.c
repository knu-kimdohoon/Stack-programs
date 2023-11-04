#define _CRT_SECURE_NO_WARNINIGS

#include <stdio.h>
#include "Stack_Link.h"

int main() {
	StackHead* head = CreateStack_L();
	int data = 0;

	while (1) {
		printf("Enter a number: <Ctrl+D> to stop : ");
		if (scanf("%d", &data) != EOF) {
			Push_L(head, data);
		}
		else {
			scanf("%*c");
			//printf("Done\n");
			break;
		}
	}
	printf("The List of numbers reversed: \n");
	while (head->top != NULL) {
		data = Pop_L(head); 
		printf("%d\n", data);
	}

	DestroyStack_L(head);
}
