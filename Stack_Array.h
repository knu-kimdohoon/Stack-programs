//Stack aaplication
#include <stdio.h>
#include <malloc.h>

//what is needed for application Stack by array?
// 1. CreateStack
// 2. push
// 3. pop
// 4. top
// 5. DestroyStack
// 6. IsFullStack
// 7. IsEmptyStack
// 8. CountStackItem
// 9. ClearStackItem

typedef struct {
	int* stack; // int�� ������ array�� �����ּҸ� �����ϴ� ���� - �� ������ ��� �ּҸ� ã�ư��� int�� ��� �迭�� ù ��° ���Ұ� ����
	int size; // array�� ũ��
	int top; // ���� �����ִ� index
}Stack; // struct{ ~ } ���� ǥ���ϴ� data type�� �̸� = Stack. Stack data type�� ũ��� 4*3 = 12B��. 

Stack* CreateStack(int size) {
	
	Stack* pStack = (Stack*)malloc(sizeof(Stack));
	if (pStack == NULL)
		return NULL;

	pStack->stack = (int*)malloc(size * sizeof(int));  // malloc(sizeof(size*sizeof(int)))�� �ϸ� ������ ��
	if (pStack->stack == NULL) {
		free(pStack);
		return NULL;
	}

	pStack->size = size;
	pStack->top = -1;

	return pStack;
}

//Stack�� �����͸� ����ִ� push �Լ�
void Push(Stack* pStack, int item) {
	// Push �Լ��� pStack->stack[++top]�� ������� ������ item�� �Ķ���ͷ� ����

	// Push �ϱ� ���� Stack�� �� á���� Ȯ���ϴ� ����
	if (pStack->top >= pStack->size - 1) {
		printf("Stack is full");
		return; // ���� Stack�� �����Ͱ� �� �ڸ��� ������ �ƹ��͵� ���� �ʰ� �Լ��� ������. 
	}

	pStack->stack[++pStack->top] = item;
	return;
}

// Stack���� ���� ���� �����͸� �̴� �Լ�. Top�� ��ȭ��Ŵ
int Pop(Stack* pStack) {
	// Pop�ϱ� ���� ���� Stack�� ������� Ȯ���� �ϴ� ����
	if (pStack->top < 0) {
		printf("Stack is empty");
		return 0;
	}

	// Stack�� ������� �ʴٸ� Stack ���� ���� �ִ� ���Ҹ� ��ȯ.
	// �׸��� Stack�� top�ε����� 1�� ���ҽ�Ŵ
	return pStack->stack[pStack->top--];
}

// Stack ���� ���� �ִ� �����Ͱ� ���� �˷��ִ� �Լ�. Top�� ��ȭ��Ű�� ����
int Top(Stack* pStack) {
	// Top�� �ϱ� ���� Stack�� ������� Ȯ���ϴ� ����
	if (pStack->top < 0) {
		printf("Stack is empty");
		return 0;
	}

	// top�� ��ȭ��Ű�� �ʰ� �׳� ���� ���� ���Ҹ� ��ȯ��
	// ���� Top�Լ��� Pop�Լ� �ڿ� ���°� ������??
	return pStack->stack[pStack->top];
}

// Stack�ȿ� �ִ� ��� item���� ���ְ�, Stack�� �Ҵ�� �޸𸮸� �ݳ��ϴ� �Լ�
void DestroyStackItem(Stack* pStack) {
	// parameter�� �ּҸ� �޴µ� ã�ư��� Stack data type�� �ִ� �ּҸ� �ش�

	if (pStack->size > 0)
		free(pStack->stack);
	free(pStack);
	printf("Stack is Destoryed");
}

// Stack�ȿ� �� ���� item���� ����ִ��� Ȯ���ϴ� �Լ�
//int CountStack(Stack* pStack) {
//	if (pStack->top > -1)
//		return pStack->top + 1;
//	else
//	{
//		printf("There are no itmes in Stack");
//		return 0;
//	}
//}

// Stack�� �ִ� item���� ���ִ� �Լ�. Stack�� �Ҵ�� �޸𸮸� ��ȯ������ ����
//void ClearStackItem(Stack* pStack) {
//	if (pStack->size > 0)
//		free(pStack->stack);
//
//	else
//		printf("There are no itmes in Stack");
//}


