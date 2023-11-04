#define _CRT_SECURE_NO_WARNINIGS

#include <stdio.h>
#include "Stack_Array.h"
#include "Stack_Link.h"

int StackArray(Stack* pStack) {

	int i = 0;
	int item = 0;

	printf("input 10 numbers: \n");
	for (i = 0; i < 5; i++) {
		item = 0;
		scanf("%d", &item);
		Push(pStack, item);
	}

	printf("Reversed: \n");
	while (pStack->top >= 0) {
		item = Pop(pStack);
		printf("%d \n", item);
		//printf("top of Stack ; %d \n", pStack->top);
		//return item;
	}

	if (pStack->top >= 0) {
		printf("Stack is not empty");
	}
	return 0;
}

int StackLinkedList(StackHead* LStack) {
	int i = 0;
	int item = 0;

	if (LStack == NULL) {
		printf("Failed to allocate memory");
		return 0;
	}
	else {
		printf("address of the Stack: %p\n", LStack);
	}
	
	printf("input 5 numbers: \n");
	for (i = 0; i < 5; i++) {
		item = 0;
		scanf("%d", &item);
		Push_L(LStack, item);
	}

	/*while (1) {
		printf("Enter a number: <Ctrl+d> to stop: ");
		scanf("%d", &item);
		if (item == EOF) {
			Push_L(LStack, NULL);
			break;
		}
		else {
			Push_L(LStack, item);
			continue;
		}
	}*/

	printf("The List of numbers reversed: ");
	while (LStack->top != NULL) {
		item = Pop_L(LStack);
		printf("%d ", item);
		//return item;
	}
	return 0;
}

int main() {

	//Stack* pStack = CreateStack(5);
	StackHead* LStack=CreateStack_L();

	printf("Using Array Stack");

	//StackArray(pStack);
	//DestroyStackItem(pStack);

	//printf("\n");

	//printf("Using Linked list Stack\n");

	StackLinkedList(LStack);
	printf("The number of data in the Stack : %d\n", LStack->count);
	DestroyStack_L(LStack);
	printf("\nLinked list Stack is destroyed");

	return 0;
}