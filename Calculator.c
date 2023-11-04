#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Stack_Link2.h"

int IsEquationIsCorrect_1(char equation[50]) {
	int i;

	for (i = 0; equation[i]!='\0'; i++) {
		if (equation[i] - '0' >= 0 && equation[i] - '0' <= 9) {
			continue;
		}
		else {
			if (equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '%' || equation[i] == ' ' || equation[i] == '(' || equation[i] == ')' || equation[i] == '/') {
				continue;
			}
			else {
				return 0;
			}
		}
	}
	return 1;
}

int IsEquationIsCorrect_2(char equation[50]) {
	int i = 0;
	int j;

	if (equation[0] == '+' || equation[0] == '-' || equation[0] == '*' || equation[0] == '%' || equation[0] == '/' || equation[strlen(equation) - 1] == '+' || equation[strlen(equation) - 1] == '-' || equation[strlen(equation) - 1] == '*' || equation[strlen(equation) - 1] == '%' || equation[strlen(equation)-1]=='/')  {
		printf("Error[1][Function2]");
		return 0;
	}
	
	for (i = 1; equation[i]!='\0'; i++) {
if (equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '%' || equation[i]=='/') {
	for (j = i - 1; j > -1; j--) {
		if (equation[j] == ' ') {
			//printf("Correct[1][Func2]\n");
			//printf("i : %d, j : %d\n", i, j);
			continue;
		}
		else {
			if ((equation[j] - '0' >= 0 && equation[j] - '0' <= 9) || equation[j] == '(' || equation[j] == ')') {
				//printf("Correct[2][Func2]\n");
				//printf("i : %d, j : %d\n", i, j);
				break;
			}
			else {
				//printf("Error[2][Func2]\n");
				//printf("i : %d, j : %d\n", i, j);
				return 0;
			}
		}
	}
}
else {
	continue;
}
	}

	for (i = 1; equation[i]!='\0'; i++) {
		if (equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '%' || equation[i]=='/') {
			for (j = i + 1; equation[i]!='\0'; j++) {
				if (equation[j] == ' ') {
					//printf("Correct[3][Function2]\n");
					//printf("i : %d, j : %d\n", i, j);
					continue;
				}
				else {
					if ((equation[j] - '0' >= 0 && equation[j] - '0' <= 9) || equation[j] == '(' || equation[j] == ')') {
						//printf("Correct[4][Func2]\n");
						//printf("i : %d, j : %d\n", i, j);
						break;
					}
					else {
						//printf("Error[3][Func2]\n");
						//printf("i : %d, j : %d\n", i, j);
						return 0;
					}
				}
			}
		}
		else {
			continue;
		}
	}

	return 1;

}

int IsEquationIsCorrect_3(char equation[50]) {
	int i = 0;
	StackHead* head = CreateStack();

	for (i = 0; equation[i]!='\0'; i++) {
		if (equation[i] == '(') {
			Push(head, equation[i]);
		}
		else {
			if (equation[i] == ')') {
				if (head->count == 0) {
					//printf("Error[1][Func3]\n");
					return 0;
				}
				else {
					Pop(head);
				}
			}
		}
	}

	if (head->count != 0) {
		//printf("Error[2][Func3]\n");
		return 0;
	}
	else {
		//printf("Correct[1][Func3]\n");
		return 1;
	}

	DeleteStack(head);
}

int IsEquationIsCorrect_4(char equation[50]) {
	StackHead* pStack = CreateStack();
	int i = 0;

	for (i = 0; equation[i]!='\0'; i++) {
		if (equation[i] != ' ') {
			Push(pStack, equation[i]);
		}
		else if (equation[i] == ' ') {
			i++;
			if ((equation[i] >= '0' && equation[i] <= '9') && (Top(pStack) >= '0' && Top(pStack) <= '9')) {
				printf("Error, check the Binary Expression\n");
				return 0;
			}
			else
				Push(pStack, equation[i]);
		}
	}
	while (pStack->count != 0) {
		Pop(pStack);
	}
	DeleteStack(pStack);

	return 1;
}

void InfixToPostfix(char equation[50]) {
	StackHead* head = CreateStack();
	int i = 0;
	char op='0';
	FILE* fp = NULL;
	fp = fopen("2022114399kimdohoon.txt", "w");

	if (fp == NULL) {
		printf("Failed to open file");
		exit(1);
	}

	printf("equation : %s\n", equation);
	printf("Postfix notation : ");
	for (i = 0; equation[i]!='\0'; i++) {
		if (equation[i] - '0' >= 0 && equation[i] - '0' <= 9) {
			printf("%c", equation[i]);
			fputc(equation[i], fp);
			continue;
		}
		else if (equation[i] == ' ') {
			fputc(equation[i], fp);
			continue;
		}
		else if (IsEmptyStack(head)==0 || Top(head) == '(' || equation[i] == '(' || ((equation[i] == '*' || equation[i] == '%' || equation[i]=='/') && (Top(head) == '+' || Top(head) == '-'))) {
			printf(" ");
			fputc(' ', fp);
			Push(head, equation[i]);
			continue;
		}
		/*
		else if (Top(head) == '(' || equation[i] == '(') {
			printf(" ");
			Push(head, equation[i]);
			//continue;
		}
		*/
		/*
		else if ((equation[i] == '*' || equation[i] == '%') && (Top(head) == '+' || Top(head) == '-')) {
			
			Push(head, equation[i]);
			//continue;
		}
		*/
		else if (equation[i] == ')') {

			while (1) {
				op = Top(head);
				if (op == '(') {
					op = Pop(head);
					break;
				}
				else {
					op = Pop(head);
					printf(" %c ", op);
					fputc(' ', fp);
					fputc(op, fp);
					fputc(' ', fp);
					//PostEquation[i++] = op;
					//i--;
				}
			}
			//Pop(head);
			continue;
		}
		else if (((equation[i] == '*' || equation[i] == '%' || equation[i]=='/') && (Top(head) == '*' || Top(head) == '%' || Top(head)=='/')) || ((equation[i] == '+' || equation[i] == '-') && (Top(head) == '+' || Top(head) == '-'))) {
			
			op = Pop(head);
			printf(" %c ", op);
			fputc(' ', fp);
			fputc(op, fp);
			fputc(' ', fp);
			Push(head, equation[i]);
			//continue;
		}
		else if ((equation[i] == '+' || equation[i] == '-') && (Top(head) == '*' || Top(head) == '%' || Top(head)=='/')) {
			/*
			while (head->top != NULL || Top(head)!= '(') {
				op = Pop(head);
				printf(" %c", op);
			}
			*/
			while (1) {
				op = Top(head);
				if (head->top == NULL) {
					break;
				}
				else {
					if (op == '(') {
						//op = Pop(head);
						break;
					}
					else {
						op = Pop(head);
						printf(" %c ", op);
						fputc(' ', fp);
						fputc(op, fp);
						fputc(' ', fp);
						//PostEquation[i++] = op;
						//i--;
					}
				}
			}
			Push(head, equation[i]);
		}
		
	}
	while (1) {
		if (head->count > 0) {
			op = Pop(head);
			printf(" %c ", op);
			fputc(' ', fp);
			fputc(op, fp);
			fputc(' ', fp);
			//PostEquation[i++] = op;
		}
		else {
			break;
		}
	}

	//PostEquation[++i] = NULL;
	fclose(fp);

	DeleteStack(head);

	return;
}

int EvaluatePostfix() {
	StackHead_Number* headN = CreateStack_Number();
	FILE* fp = NULL;
	int c = 0;
	int num = 0;
	int op1 = 0;
	int op2 = 0;
	int con = 0;

	fp = fopen("2022114399kimdohoon.txt", "r");
	if (fp == NULL) {
		printf("Failed to open file");
		exit(1);
	}

	while ((c = fgetc(fp)) != EOF) {
		if ((c - '0') >= 0 && (c - '0') <= 9) {
			Push_Number(headN, (c-'0'));
			while (1) {
				c = fgetc(fp);
				if ((c - '0') >= 0 && (c - '0') <= 9) {
					num = Pop_Number(headN) * 10 + (c - '0');
					Push_Number(headN, num);
				}
				else {
					break;
				}
			}
		}
		else if (c == ' ') {
			continue;
		}
		else if (c == '+' || c == '*' || c == '-' || c == '%' || c == '/') {
			op2 = Pop_Number(headN);
			op1 = Pop_Number(headN);
			if (c == '+') {
				Push_Number(headN, op1 + op2);
			}
			else if (c == '-') {
				Push_Number(headN, op1 - op2);
			}
			else if (c == '*') {
				Push_Number(headN, op1 * op2);
			}
			else if (c == '%') {
				Push_Number(headN, op1 % op2);
			}
			else if (c == '/') {
				Push_Number(headN, op1 / op2);
			}
		}
	}

	con = Pop_Number(headN);
	printf("\nConclusion : %d", con);

	DeleteStack_Number(headN);

	fclose(fp);
}

void main() {
	
	char equation[50];
	int Check1 = 0;
	int count = 0;
	int i = 0;

	printf("Equation: ");
	scanf("%[^\n]s", equation);

	Check1 = IsEquationIsCorrect_1(equation);

	if (Check1 == 0) {
		printf("Error, input must be number or operators\n");
		exit(1);
	}
	else {
		//printf("Correct[1][main]\n");
	}

	Check1 = IsEquationIsCorrect_2(equation);

	if (Check1 == 0) {
		printf("Error, check the binary Expression\n");
		exit(1);
	}
	else {
		//printf("Correct[2][main]\n");
		//printf("%s", equation);
	}

	Check1 = IsEquationIsCorrect_3(equation);

	if (Check1 == 0) {
		printf("Error, Check the pairs of Parenthesis\n");
		exit(1);
	}
	else {
		//printf("Correct[3][main]\n");
		//printf("%s\n", equation);
	}
	
	Check1 = IsEquationIsCorrect_4(equation);
	if (Check1 == 0) {
		printf("Error, check the binary expression\n");
		exit(1);
	}
	
	InfixToPostfix(equation);

	EvaluatePostfix();

}