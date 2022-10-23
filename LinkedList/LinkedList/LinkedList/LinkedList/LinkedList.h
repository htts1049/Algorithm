/* 포인터로 만든 연결 리스트(헤더) */

#ifndef ___LinkedList
#define ___LinkedList

#include "Member.h"

/* 노드 */
typedef struct __node {
	Member data;			// 데이터
	struct __node* next;	// 다음 노드 포인터
}Node;

/* 연결 리스트 */
typedef struct {
	Node* head;		// 헤더 노드
	Node* crnt;		// 선택한 노드
	}List;

/* 연결 리스트 초기화 */
void Initialize(List* list);

/* 함수 compare로 x와 같은 노드 검색 */
Node* search(List* list, const Member* x, int compare(const Member* x, const Member* y));

/* 머리에 노드 삽입 */
void InsertFront(List* list, const Member* x);

/* 꼬리에 노드 삽입 */
void InsertRear(List* list, const Member* x);

/* 머리 노드 삭제 */
void RemoveFront(List* list);

/* 꼬리 노드 삭제 */
void RemoveRear(List* list);

/* 선택 노드 삭제 */
void RemoveCurrent(List* list);

/* 모든 노드 삭제 */
void Clear(List* list);

/* 선택 노드 데이터 출력 */
void PrintCurrent(const List* list);

/* 선택 노드 데이터 출력(개행문자) */
void PrintLnCurrent(const List* list);

/* 모든 노드 데이터 리스트 순서대로 출력 */
void Print(const List* list);

/* 연결 리스트 종료 */
void Terminate(List* list);

#endif