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
	int* stack; // int를 저장할 array의 시작주소를 저장하는 변수 - 이 변수에 담긴 주소를 찾아가면 int가 담긴 배열의 첫 번째 원소가 나옴
	int size; // array의 크기
	int top; // 가장 위에있는 index
}Stack; // struct{ ~ } 까지 표현하는 data type의 이름 = Stack. Stack data type의 크기는 4*3 = 12B임. 

Stack* CreateStack(int size) {
	
	Stack* pStack = (Stack*)malloc(sizeof(Stack));
	if (pStack == NULL)
		return NULL;

	pStack->stack = (int*)malloc(size * sizeof(int));  // malloc(sizeof(size*sizeof(int)))를 하면 오류가 남
	if (pStack->stack == NULL) {
		free(pStack);
		return NULL;
	}

	pStack->size = size;
	pStack->top = -1;

	return pStack;
}

//Stack에 데이터를 집어넣는 push 함수
void Push(Stack* pStack, int item) {
	// Push 함수는 pStack->stack[++top]에 집어넣을 데이터 item을 파라미터로 받음

	// Push 하기 전에 Stack이 꽉 찼는지 확인하는 과정
	if (pStack->top >= pStack->size - 1) {
		printf("Stack is full");
		return; // 만약 Stack에 데이터가 들어갈 자리가 없으면 아무것도 하지 않고 함수를 끝낸다. 
	}

	pStack->stack[++pStack->top] = item;
	return;
}

// Stack에서 가장 위의 데이터를 뽑는 함수. Top을 변화시킴
int Pop(Stack* pStack) {
	// Pop하기 전에 먼저 Stack이 비었는지 확인을 하는 과정
	if (pStack->top < 0) {
		printf("Stack is empty");
		return 0;
	}

	// Stack이 비어있지 않다면 Stack 가장 위에 있는 원소를 반환.
	// 그리고 Stack의 top인덱스는 1씩 감소시킴
	return pStack->stack[pStack->top--];
}

// Stack 가장 위에 있는 데이터가 뭔지 알려주는 함수. Top을 변화시키지 않음
int Top(Stack* pStack) {
	// Top을 하기 전에 Stack이 비었는지 확인하는 과정
	if (pStack->top < 0) {
		printf("Stack is empty");
		return 0;
	}

	// top을 변화시키지 않고 그냥 가장 위의 원소만 반환함
	// 따라서 Top함수는 Pop함수 뒤에 오는게 좋은가??
	return pStack->stack[pStack->top];
}

// Stack안에 있는 모든 item들을 없애고, Stack에 할당된 메모리를 반납하는 함수
void DestroyStackItem(Stack* pStack) {
	// parameter로 주소를 받는데 찾아가면 Stack data type이 있는 주소를 준다

	if (pStack->size > 0)
		free(pStack->stack);
	free(pStack);
	printf("Stack is Destoryed");
}

// Stack안에 몇 개의 item들이 들어있는지 확인하는 함수
//int CountStack(Stack* pStack) {
//	if (pStack->top > -1)
//		return pStack->top + 1;
//	else
//	{
//		printf("There are no itmes in Stack");
//		return 0;
//	}
//}

// Stack에 있는 item들을 없애는 함수. Stack이 할당된 메모리를 반환하지는 않음
//void ClearStackItem(Stack* pStack) {
//	if (pStack->size > 0)
//		free(pStack->stack);
//
//	else
//		printf("There are no itmes in Stack");
//}


