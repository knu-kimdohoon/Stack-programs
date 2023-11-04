#pragma once
#include <stdio.h>
#include <malloc.h>

//Node data type
typedef struct node {
	int data;
	struct node* link;
}StackNode; // 아직은 그냥 data type을 선언함. 그래서 메모리에 공간이 할당이 되지 않은 상태

//Head data type
typedef struct head {
	int count;
	StackNode* top;
}StackHead; // 아직은 그냥 data type을 선언함. 그래서 메모리에 공간이 할당이 되지 않은 상태

//CreateStack
StackHead* CreateStack_L() {
	// 1. make StackHead
	StackHead* head = (StackHead*)malloc(sizeof(StackHead));

	if (head == NULL) {
		printf("failed to give memory");
		return NULL;
	}
	//printf("Stack is created");
	head->count = 0;
	head->top = NULL;

	return head;
}

//Push(stack, data)
void Push_L(StackHead* head, int data) {

	StackNode* pNew = (StackNode*)malloc(sizeof(StackNode));

	if (pNew == NULL)
		return;
	//my code
	/*if (head->count == 0) {
		head->top = pNew;
		head->count++;
	}
	else {
		pNew->link = head->top;
		head->top = pNew;
		head->count++;

	}*/

	//code from Ph.D
	pNew->data = data;
	pNew->link = head->top;
	head->top = pNew;
	head->count++;
}

//Pop
int Pop_L(StackHead* head) {
	StackNode* dltPtr;
	int item;

	if (head->top == NULL) { //head->count == 0이라고 해도 상관 없는가?
		return 0;
	}
	else {
		dltPtr = head->top;
		item = dltPtr->data;
		head->top = dltPtr->link;
		free(dltPtr);
		head->count--;

		return item;
	}
}

//DestroyStack(Stack)
void DestroyStack_L(StackHead* head) {
	StackNode* dltPtr;

	while (1) {
		if (head->top == NULL) {
			printf("\nTHere is no data in the Stack\n");
			free(head);
			printf("The Stack is destoryed");
			return;
		}
		else {
			dltPtr = head->top;
			head->top = dltPtr->link;
			free(dltPtr);
			head->count--;
		}
	}
	printf("The Stack is destroyed");
}


