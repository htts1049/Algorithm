#define _CRT_SECURE_NO_WARNINGS
#define ERROR -1

#include <stdio.h>
#include <stdlib.h>

/*---- 백준 10828번. 스택----*/
/*
간단한 스택 자료구조 구현 문제
*/

typedef struct __stk{
	int* data;
	int top;
	int capacity;
}Stack;

void Init(Stack* stk, int size) {
	stk->data = (int*)malloc(sizeof(int) * size);
	stk->top = 0;
	stk->capacity = size;
}

void Push(Stack* stk, int data) {

	// 스택이 꽉 차지 않았으면 삽입
	if (stk->top < stk->capacity) {
		stk->data[stk->top++] = data;
	}

	// 스택 오버플로우
	else {
		printf("error!\n");
	}
}

int Pop(Stack* stk) {

	// 스택이 비어있지 않으면
	if (stk->top > 0) {
		return stk->data[--stk->top];
	}
	// 스택 언더플로우
	else {
		return ERROR;
	}
}


int Size(Stack* stk) {
	return stk->top;
}

int isEmpty(Stack* stk) {
	return stk->top <= 0;
}

int Top(Stack* stk) {

	// 비어있지 않으면 맨 위의 값 반환
	if (!isEmpty(stk)) {
		return stk->data[stk->top - 1];
	}
	// 비어있으면 -1 반환
	else {
		return ERROR;
	}
}

int strncmp(char* str1, char* str2, int n) {
	int i;

	for (i = 0; i < n; ++i) {
		if (str1[i] != str2[i]) {
			return 0;
		}
	}

	return 1;
}

int main() {

	int n, x;
	scanf("%d", &n);
	char* str = (char*)malloc(sizeof(char) * 11);
	Stack stk;
	Init(&stk, 10000);

	for (int i = 0; i < n; ++i) {

		scanf("%s", str);

		// push
		if (strncmp(str, "push", 4)) {
			scanf("%d", &x);
			Push(&stk, x);
		}

		// pop
		else if (strncmp(str, "pop", 3)) {
			printf("%d\n", Pop(&stk));
		}

		// size
		else if (strncmp(str, "size", 4)) {
			printf("%d\n", Size(&stk));
		}

		// empty
		else if (strncmp(str, "empty", 5)) {
			printf("%d\n", isEmpty(&stk));
		}

		// top
		else if (strncmp(str, "top", 3)) {
			printf("%d\n", Top(&stk));
		}
	}
	

	return 0;
}