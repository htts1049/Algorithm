#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"



int main(void) {
	IntQueue que;
	int max;
	printf("큐의 최대 개수 : ");
	scanf("%d", &max);

	if (Initialize(&que, max) == -1) {
		puts("큐 생성 실패");
		return 1;
	}
	while (1) {
		int menu;
		int x;
		printf("현재 데이터 개수 : %d/%d \n", Size(&que), Capacity(&que));
		printf("(1)인큐 (2)디큐 (3)피크 (4)출력 (0)종료\n");
		printf("실행할 동작을 입력하세요. : ");
		scanf("%d", &menu);
		
		if (menu == 0) break;
		switch(menu) {
			case 1:				
			printf("입력할 데이터 : ");
			scanf("%d", &x);
										
			if( Enque(&que, x) == -1) {
				puts("\a인큐 실패\n");
			}
			break;
			
			
			case 2:
			if (Deque(&que) == -1) {
				printf("\a디큐 실패\n");
			}
			else {
				printf("디큐한 데이터는 %d입니다.\n", que.que[(que.front-1)%que.max]);
			}
			break;


			case 3:
			if (Peek(&que) == -1)
				printf("\a피크 실패\n");
			else {
				printf("피크한 데이터는 %d입니다.\n", Peek(&que));
			}
			break;

			case 4:
				Print(&que);
				break;
			}
		putchar('\n');
		}
	Terminate(&que);
	return 0;
}



/* 큐 초기화 */
int Initialize(IntQueue* q, int max)
{
	if ((q->que = calloc(max, sizeof(int))) == NULL) {
		q->max = 0;
		return -1;
	}
	q->front = q->rear = q->num = 0;
	q->max = max;
	return 0;
}

/* 큐에 데이터 인큐 */
int Enque(IntQueue *q, int x) {
	if (q->num >= q->max)
		return -1;
	else {
		q->num++;
		q->que[q->rear++] = x;

		if (q->rear == q->max)
			q->rear = 0;
		return 0;
	}
}

/* 큐에서 데이터 디큐 */
int Deque(IntQueue* q) {
	if (q->num <= 0)
		return -1;
	else {
		q->num--;
		q->front++;
		
		if (q->front >= q->max)
			q->front = 0;
		return 0;
	}
}

/* 큐에서 데이터 피크 (꺼낼 데이터=프런트를 확인) */
int Peek(const IntQueue* q) {
	if (q->num <= 0)
		return -1;
	return q->que[q->front];
}

/* 모든 데이터 삭제 */
void Clear(IntQueue* q) {
	q->num = 0;
	q->front = 0;
	q->rear = 0;
}

/* 큐 최대 용량 */
int Capacity(const IntQueue* q) {
	return q->max;
}

/* 큐에 들어있는 데이터 개수 */
int Size(const IntQueue* q) {
	return q->num;
}

/* 큐가 비어있는지 확인 */
int IsEmpty(const IntQueue* q) {
	return q->num <= 0;
}

/* 큐가 가득 찼는지 확인 */
int IsFull(const IntQueue* q) {
	return q->num >= q->max;
}

/* 큐에서 검색하여 데이터 위치 반환 */
int Search(const IntQueue* q, int x) {
	int i;
	
	for (i = 0; i < q->num; i++) {
		if ((q->que[(i + q->front)% q->max] == x))
			return (i + q->front) % q->max;
	}
	return -1;
}

/* 모든 데이터 출력 */
void Print(const IntQueue* q) {
	int i;

	for (i = 0; i < q->num; i++) {
		printf("%d ", q->que[(i + q->front) % q->max]);
	}
	putchar('\n');
}

/* 큐 종료 */
void Terminate(IntQueue* q) {
	if (q->que != NULL)
		free(q->que);
	q->max = q->num = q->front = q->rear = 0;
}