#ifndef ___IntQueue
#define ___IntQueue

typedef struct {
	int max;	// 큐 최대 용량
	int num;	// 현재 요소 개수
	int front;	// 프런트	-> 데이터의 출구
	int rear;	// 리어		-> 데이터의 입구
	int* que;	// 큐의 맨 앞 요소에 대한 포인터
} IntQueue;

/* 큐 초기화 */
int Initialize(IntQueue* q, int max);

/* 큐에 데이터 인큐 */
int Enque(IntQueue* q, int x);

/* 큐에서 데이터 디큐 */
int Deque(IntQueue* q);

/* 큐에서 데이터 피크 (꺼낼 데이터=프런트를 확인) */
int Peek(const IntQueue* q);

/* 모든 데이터 삭제 */
void Clear(IntQueue* q);

/* 큐 최대 용량 */
int Capacity(const IntQueue* q);

/* 스택에 들어있는 데이터 개수 */
int Size(const IntQueue* q);

/* 스택이 비어있는지 확인 */
int IsEmpty(const IntQueue* q);

/* 스택이 가득 찼는지 확인 */
int IsFull(const IntQueue* q);

/* 스택에서 검색하여 데이터 위치 반환 */
int Search(const IntQueue* q, int x);

/* 모든 데이터 출력 */
void Print(const IntQueue* q);

/* 큐 종료 */
void Terminate(IntQueue* q);

#endif