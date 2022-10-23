#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "LinkedList.h"


/* 노드 동적 생성 */
static Node* AllocNode(void)
{
	return calloc(1, sizeof(Node));
}

/* n이 가리키는 노드의 각 멤버에 값 설정 */
static void SetNode(Node* n, const Member* x, const Node* next)
{
	n->data = *x;
	n->next = next;
}

/* 연결 리스트 초기화 */
void Initialize(List* list)
{
	list->head = NULL;
	list->crnt = NULL;
}

/* 함수 compare로 x와 같은 노드 검색 */
Node* search(List* list, const Member* x, int compare(const Member* x, const Member* y))
{
	Node* ptr = list->head;
	while (ptr != NULL) {
		if (compare(&ptr->data, x) == 0) {	/* 키 값이 같으면 */
			list->crnt = ptr;
			return ptr;						/* 검색 성공 */
		}
		ptr = ptr->next;					/* 다음 노드 선택 */
	}
	return NULL;							/* 검색 실패 */
}

/* 머리에 노드 삽입 */
void InsertFront(List* list, const Member* x) {
	Node* ptr = list->head;
	list->head = list->crnt = AllocNode();		// 노드를 하나 생성해서 머리 노드와 선택 노드 값에 저장
	SetNode(list->head, x, ptr);				// 새로 생성한 머리 노드에 데이터 x를 넣고 ptr(이전 머리 노드)을 가리키도록 Set
}

/* 꼬리에 노드 삽입 */
void InsertRear(List* list, const Member* x) {
	if (list->head == NULL)	// 리스트가 비어있으면 머리에 노드 삽입과 동일
		InsertFront(list, x);
	else {
		Node* ptr = list->head;
		while (ptr->next != NULL)	// 꼬리노드를 찾았으면 종료
			ptr = ptr->next;
		ptr->next = list->crnt = AllocNode();	// 꼬리 노드가 가리키는 새로운 노드 생성
		SetNode(ptr->next, x, NULL);
	}	
}

/* 머리 노드 삭제 */
void RemoveFront(List* list) {
	if (list->head != NULL) {
		Node* ptr = list->head->next;	// 임시 포인터 ptr에 머리 노드의 다음 노드 저장
		free(list->head);				// 머리노드 삭제
		list->head = list->crnt = ptr;	// 리스트가 가리키는 머리 노드의 값은 임시 포인터에 저장한 노드가 된다.
	}
}

/* 꼬리 노드 삭제 */
void RemoveRear(List* list) {
	if (list->head != NULL) {
		if ((list->head)->next == NULL) {
			RemoveFront(list);
		}
		else {
			Node* ptr = list->head;		// 임시 포인터 ptr에 머리 노드 저장
			Node* pre = AllocNode();					// 임시 포인터 pre
			while (ptr->next != NULL) {	// ptr이 꼬리 노드일 때 까지 찾음
				pre = ptr;				
				ptr = ptr->next;
			}
			pre->next = NULL;			// pre가 가리키는 건 꼬리 노드의 직전 노드
			free(ptr);					// 꼬리 노드 삭제
			list->crnt = pre;			// 선택 노드에 pre (새로운 꼬리 노드) 저장
		}
	}
}

/* 선택 노드 삭제 */
void RemoveCurrent(List* list) {
	if (list->head != NULL) {
		if (list->crnt == list->head) {
			RemoveFront(list);
		}
		else {								// A->B->C 인 상태에서 선택노드 B를 삭제한다면
			Node* ptr = list->head;			
			while (ptr->next != list->crnt)	// 선택 노드(B)의 직전 노드(A) 찾아서 ptr에 대입
				ptr = ptr->next;
			ptr->next = list->crnt->next;	// ptr이 가리키는 노드는 선택 노드(crnt)가 가리키는 노드(C) : A->C 가 된다.
			free(list->crnt);				// 선택노드 crnt 삭제
			list->crnt = ptr;				// crnt에 ptr 대입, 선택 노드는 A가 된다.
		}
	}
}

/* 모든 노드 삭제 */
void Clear(List* list) {
	while (list->head != NULL)
		RemoveFront(list);
	list->crnt = NULL;		// RemoveFront 함수에선 head만 삭제한다.
}

/* 선택 노드 데이터 출력 */
void PrintCurrent(const List* list) {
	if (list->crnt == NULL)
		printf("선택 노드가 없습니다.");
	else
		PrintMember(&list->crnt->data);
}

/* 선택 노드 데이터 출력(개행문자) */
void PrintLnCurrent(const List* list) {
	PrintCurrent(list);
	putchar('\n');
}

/* 모든 노드 데이터 리스트 순서대로 출력 */
void Print(const List* list)
{
	if (list->head == NULL)
		puts("노드가 없습니다.");
	else {
		Node* ptr = list->head;
		puts("【모두보기】");
		while (ptr != NULL) {
			PrintLnMember(&ptr->data);	// data 출력후 개행
			ptr = ptr->next;			// 다음 노드 선택
		}
	}
}

/* 연결 리스트 종료 */
void Terminate(List* list)
{
	Clear(list);
}