#pragma once
#include <stdio.h>
#include <malloc.h>

typedef struct node {
	char data;
	struct node* link;
}StackNode;

typedef struct head {
	int count;
	StackNode* top;
}StackHead;

typedef struct nodeN {
	int data;
	struct nodeN* link;
}StackNode_Number;

typedef struct headN {
	int count;
	StackNode_Number* top;
}StackHead_Number;

StackHead* CreateStack()
{
	StackHead* head = (StackHead*)malloc(sizeof(StackHead));
	if (head == NULL) {
		printf("memory did not allocated to head");
		return NULL;
	}

	head->count = 0;
	head->top = NULL;

	return head;
}

StackHead_Number* CreateStack_Number() {
	StackHead_Number* headN = (StackHead_Number*)malloc(sizeof(StackHead_Number));
	if (headN == NULL) {
		printf("memory did not allocated to head_n\n");
		return NULL;
	}

	headN->count = 0;
	headN->top = NULL;

	return headN;
}

void Push(StackHead* head, char data) {
	StackNode* node = (StackNode*)malloc(sizeof(StackNode));
	if (node == NULL) {
		printf("The memory did not allocated to node");
		free(head);
		return;
	}

	node->data = data;
	node->link = head->top;
	head->top = node;
	head->count++;
}

void Push_Number(StackHead_Number* headN, int data) {
	StackNode_Number* nodeN = (StackNode_Number*)malloc(sizeof(StackNode_Number));
	if (nodeN == NULL) {
		printf("Memory did not allocated to node_n\n");
		free(headN);
		return;
	}

	nodeN->data = data;
	nodeN->link = headN->top;
	headN->top = nodeN;
	headN->count++; 
}

char Pop(StackHead* head) {
	StackNode* dltNode;
	char data;
	if (head->top == NULL) {
		//printf("There is no data in the Stack[Pop]");
		return 'N';
	}

	dltNode = head->top;
	data = dltNode->data;
	head->top = dltNode->link;
	free(dltNode);
	head->count--;

	return data;
}

int Pop_Number(StackHead_Number* headN) {
	StackNode_Number* dltNode;
	int data = 0;
	if (headN->top == NULL) {
		printf("There is no data in the Stack_Number\n");
		return 0;
	}

	dltNode = headN->top;
	data = dltNode->data;
	headN->top = dltNode->link;
	free(dltNode);
	headN->count--;

	return data;
}

char Top(StackHead* head) {
	char data;

	if (head->top == NULL) {
		//printf("There is no data in the Stack[Top]\n");
		return 'N';
	}

	data = head->top->data;
	return data;
}

void DeleteStack(StackHead* head) {
	StackNode* desNode;
	while (1) {
		if (head->top == NULL) {
			//printf("\nThere is no data in the Stack[DeleteStack]\n");
			free(head);
			//printf("The Stack is destoryed[DeleteStack]\n");
			return;
		}
		else {
			desNode = head->top;
			head->top = desNode->link;
			free(desNode);
			head->count--;
		}
	}
}

void DeleteStack_Number(StackHead_Number* headN) {
	StackNode_Number* desNode;
	while (1) {
		if (headN->top == NULL) {
			//printf("\nThere is no data in the Stack\n");
			free(headN);
			//printf("\nTHe Stack is destroyed[DeleteStack_Number]\n");
			return;
		}
		else {
			desNode = headN->top;
			headN->top = desNode->link;
			free(desNode);
			headN->count--;
		}
	}
}

int IsEmptyStack(StackHead* head) {
	if (head->top == NULL) {
		return 0;
	}
	else
		return 1;
}