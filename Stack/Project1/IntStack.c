#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h" // 현재 디렉토리에서 헤더파일 찾음. 만약 없다면 컴파일러 라이브러리 폴더에서 찾음.


// 스택을 생성하고 다루는 예제
int main() {
	int max;
	printf("스택 최대 용량 입력 : ");
	scanf("%d", &max);
	
	IntStack s;
	if (Initialize(&s, max) == -1) {
		printf("스택 생성 실패");
		return -1;	// 종료
	}

	while (1) {
		int menu, x;
		puts("");
		printf("현재 데이터 수 : %d / %d\n", Size(&s),Capacity(&s));
		printf("(1)푸시 (2)팝 (3)피크 (4)출력 (0)종료 : ");
		scanf("%d", &menu);
		
			// 종료
		if (menu == 0) break;

		switch (menu) {
		case 1:	// 푸시
			printf("데이터 : ");
			scanf("%d", &x);
			if (Push(&s, x) == -1)
				puts("\a오류 : 푸시 실패");
			break;

		case 2:	// 팝
			if (Pop(&s) == -1)
				puts("\a오류 : 팝 실패");
			else
				printf("팝 데이터는 %d입니다.\n", s.stk[s.ptr]);
			break;

		case 3:	// 피크 출력
			if (Peek(&s, &x) == -1)
				puts("\a오류 : 피크 실패");
			else
				printf("피크 데이터는 %d입니다.\n", x);
			break;

		case 4:	// 스택 전체 출력
			Print(&s);
			break;
		}
	}
		

	Terminate(&s);
	return 0;
}



/* 스택 초기화 */
int Initialize(IntStack* s, int max)
{
	s->ptr = 0;

	if ((s->stk = calloc(max, sizeof(int))) == NULL) {
		s->max = 0;
		return -1;	// 스택 첫 요소 주소가 NULL 이면 스택 생성 실패
	}

	s->max = max;	// 스택 생성 성공. 전달 받은 max를 스택 max에 저장
	return 0;
}

/* 스택에 데이터 푸시 */
int Push(IntStack* s, int x)
{
	if (s->ptr >= s->max)	// 스택 포인터가 최대 용량보다 크다 = 스택이 가득 찼다.
		return -1;

	s->stk[s->ptr++] = x;	// 스택 포인터가 가리키는 곳에 푸시하려는 데이터 x를 넣고 스택 포인터 증가
	return 0;
}

/* 스택에서 데이터 팝 */
int Pop(IntStack* s)
{
	if (s->ptr <=0)			// 스택 포인터가 0 이하 = 스택이 비어있다.
		return -1;

	s->ptr--;	// 스택 포인터 감소
	return 0;
}


/* 스택에서 데이터 피크 */
int Peek(const IntStack* s, int* x)
{
	if (s->ptr <= 0)
		return -1;
	*x = s->stk[s->ptr - 1];	// x가 가리키는 값에 Top 값 저장
	return 0;
}


/* 스택 비우기 */
void Clear(IntStack* s)
{
	s->ptr = 0;		// 스택 포인터에 0만 넣어도 비워진다.
}


/* 스택 최대 용량 */
int Capacity(const IntStack* s)
{
	return s->max;
}


/* 스택에 들어있는 데이터 개수 */
int Size(const IntStack* s)
{
	return s->ptr;
}


/* 스택이 비어있는지 확인 */
int IsEmpty(const IntStack* s)
{
	return s->ptr <= 0;
}


/* 스택이 가득 찼는지 확인 */
int IsFull(const IntStack* s)
{
	return s->ptr >= s->max;
}


/* 스택에서 검색하여 데이터 위치 반환 */
int Search(const IntStack* s, int x) {
	int i;
	for (i = s->ptr - 1; i >= 0; i--) {
		if (s->stk[i] == x)
			return i;
	}
	return -1;
}


/* 모든 데이터 출력 */
void Print(const IntStack* s)
{
	int i;
	for (i = 0; i < s->ptr; i++)
		printf("%d ", s->stk[i]);

	putchar('\n');
}


/* 스택 종료 */
void Terminate(IntStack* s)
{
	if (s->stk != NULL)
		free(s->stk);
	s->max = s->ptr = 0;
}