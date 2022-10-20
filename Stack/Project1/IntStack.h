#ifndef ___IntStack
#define ___IntStack

typedef struct {
	int max;	// 스택 최대 용량, 배열 stk의 요소 개수와 같다.
	int ptr;	// 스택 포인터. 비어있으면 0, 가득 차있으면 max와 같다.
	int* stk;	// 스택의 첫 요소에 대한 포인터
} IntStack;

/* 스택 초기화 */
int Initialize(IntStack* s, int max);

/* 스택에 데이터 푸시 */
int Push(IntStack* s, int x);

/* 스택에서 데이터 팝 */
int Pop(IntStack* s);

/* 스택에서 데이터 피크 */
int Peek(const IntStack* s, int* x);

/* 스택 비우기 */
void Clear(IntStack* s);

/* 스택 최대 용량 */
int Capacity(const IntStack* s);

/* 스택에 들어있는 데이터 개수 */
int Size(const IntStack* s);

/* 스택이 비어있는지 확인 */
int IsEmpty(const IntStack* s);

/* 스택이 가득 찼는지 확인 */
int IsFull(const IntStack* s);

/* 스택에서 검색하여 데이터 위치 반환 */
int Search(const IntStack* s, int x);

/* 모든 데이터 출력 */
void Print(const IntStack* s);

/* 스택 종료 */
void Terminate(IntStack* s);

#endif
