/* 원형 이중 연결 리스트 (소스) */
#include <stdio.h>
#include <stdlib.h>
#include "CircleDoubleLinkedList.h"


/* 1개의 노드를 동적으로 생성 */
static Dnode* AllocDNode(void)
{
	return calloc(1, sizeof(Dnode));
}

/* 노드의 각 멤버 값 설정 */
static void SetDnode(Dnode* n, const Member* x, const Dnode* prev, const Dnode* next)
{
	n->data = *x;
	n->prev = prev;
	n->next = next;
}

/* 리스트가 비었는지 검사 */
static int IsEmpty(const Dlist* list)
{
	return list->head->next == list->head;
}

/* 리스트 초기화 */
void Initialize(Dlist* list)
{
	Dnode* dummyNode = AllocDNode();		// 더미노드 생성
	list->head = list->crnt = dummyNode;
	dummyNode->prev = dummyNode->next = dummyNode; // 리스트 생성시 더미노드는 자기자신을 가리킴
}

/* 선택한 노드의 데이터 출력 */
void PrintCurrent(const Dlist* list)
{
	if (IsEmpty(list))
		printf("선택한 노드가 없습니다.");
	else
		PrintMember(&list->crnt->data);				// 선택 노드의 데이터 출력
}

/* 선택한 노드의 데이터 출력 (개행) */
void PrintLnCurrent(const Dlist* list)
{
	PrintCurrent(list);
	putchar('\n');
}

/* compare 함수로 x와 일치하는 노드 검색 */
Dnode* Search(Dlist* list, const Member* x, int compare(const Member* x, const Member* y))
{
	Dnode* ptr = list->head->next;
	while (ptr != list->head) {					// 머리 노드에서부터 검색 시작
		if (compare(&ptr->data, x) == 0) {
			list->crnt = ptr;					// 노드의 값과 x가 같으면 선택 노드를 update 하고 반환
			return ptr;
		}
		ptr = ptr->next;						// 다음 노드로
	}
	return NULL;	// 검색 실패
}

/* 모든 노드의 데이터를 리스트 순서대로 출력 */
void Print(const Dlist* list)
{
	if (IsEmpty(list))
		puts("노드가 없습니다.");
	else {
		Dnode* ptr = list->head->next;
		puts("【모두 보기】");
		while (ptr != list->head) {
			PrintLnMember(&ptr->data);
			ptr = ptr->next;
		}
	}
}

/* 모든 노드의 데이터를 리스트 역순으로 출력 */
void PrintReverse(const Dlist* list)
{
	if(IsEmpty(list))
		puts("노드가 없습니다.");
	else {
		Dnode* ptr = list->head->prev;
		puts("【모두 보기】");
		while (ptr != list->head) {
			PrintLnMember(&ptr->data);
			ptr = ptr->prev;
		}
	}
}

/* 선택한 노드의 다음으로 진행 */
int Next(Dlist* list)
{
	if (IsEmpty(list) || list->crnt->next == list->head)
		return 0;
	list->crnt = list->crnt->next;
	return 1;
}

/* 선택한 노드의 앞쪽으로 진행 */
int Prev(Dlist* list)
{
	if (IsEmpty(list) || list->crnt->prev == list->head)
		return 0;
	list->crnt = list->crnt->prev;
	return 1;
}

/* p가 가리키는 노드 바로 뒤에 노드 삽입 */
void InserAfter(Dlist* list, Dnode* p, const Member* x)
{
	Dnode* ptr = AllocDNode();
	Dnode* nxt = p->next;
	p->next = p->next->prev = ptr;
	SetDnode(ptr, x, p, nxt);
	list->crnt = ptr;
}

/* 머리에 노드를 삽입 */
void InsertFront(Dlist* list, const Member* x)
{
	InserAfter(list, list->head, x);
}

/* 꼬리에 노드를 삽입 */
void InsertRear(Dlist* list, const Member* x)
{
	InserAfter(list, list->head->prev, x);
}

/* p가 가리키는 노드 삭제 */
void Remove(Dlist* list, Dnode *p)
{
	p->prev->next = p->next;
	p->next->prev = p->prev;
	list->crnt = p->prev;
	free(p);
	if (list->crnt == list->head)
		list->crnt = list->head->next;
}

/* 머리 노드 삭제 */
void RemoveFront(Dlist* list)
{
	if (!IsEmpty(list))
		Remove(list, list->head->next);
}

/* 꼬리 노드 삭제 */
void RemoveRear(Dlist* list)
{
	if (!IsEmpty(list))
		Remove(list, list->head->prev);
}

/* 선택 노드 삭제 */
void RemoveCurrent(Dlist* list)
{
	if (list->crnt != list->head)
		Remove(list, list->crnt);
}

/* 모든 노드 삭제 */
void Clear(Dlist* list)
{
	while (!IsEmpty(list))
		RemoveFront(list);
}

/* 원형 이중 연결 리스트 종료 */
void Terminate(Dlist* list)
{
	Clear(list);
	free(list->head);
}