/* 오픈 주소법으로 구현한 해시(소스) */
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ClosedHash.h"

/* 해시 함수 (key 값 반환) */
static int hash(int key, int size)
{
	return key % size;
}

/* 재해시 함수 */
static int rehash(int key, int size)
{
	return (key + 1) % size;
}

/* 노드의 각 멤버에 값 설정 */
static void SetBucket(Bucket* n, const Member* x, Status stat)
{
	n->data = *x;		// 데이터
	n->stat = stat;		// 요소 상태
}

/* 해시 테이블 초기화 */
int Initialize(ClosedHash* h, int size)
{
	int i;
	if ((h->table = calloc(size, sizeof(Bucket))) == NULL) {
		h->size = 0;
		return 0;
	}
	h->size = size;
	for (i = 0; i < size; i++) {
		h->table[i].stat = Empty;
	}
	return 1;
}

/* 검색 */
Bucket* Search(const ClosedHash* h, const Member* x)
{
	int i;
	int key = hash(x->no, h->size);		/* 검색할 데이터의 해시 값 */
	Bucket* p = &h->table[key];			/* 현재 선택한 노드 */

	for (i = 0; p->stat != Empty && i < h->size; i++) {		// 해시 테이블 크기만큼 반복, Bucket 상태가 비어있는지 확인
		if (p->stat == Occupied && p->data.no == x->no)		// Bucket에 자료가 저장되어있고 번호가 동일하다면 Bucket 주소 반환
			return p;									
		key = rehash(key, h->size);							// 재해시 ( 해시 값 1 증가 )
		p = &h->table[key];									// 선택 노드를 변경
	}

	return NULL;
}

/* 데이터 추가 */
int Add(ClosedHash* h, const Member* x)
{
	int i;
	int key = hash(x->no, h->size);		/* 추가할 데이터의 해시 값 */
	Bucket* p = &h->table[key];			/* 현재 선택한 노드 */
	
	if (Search(h, x))					// 해시 테이블에 x가 있는지 확인
		return 1;
	for (i = 0; i < h->size; i++) {		// 해시 테이블 크기만큼 반복
		if (p->stat == Empty || p->stat == Deleted) {		// Bucket의 상태가 비어있거나 삭제된 상태면
			SetBucket(p, x, Occupied);						// Bucket에 자료를 넣고, 상태 변경
			return 0;
		}
		key = rehash(key, h->size);							// 재해시
		p = &h->table[key];									// 선택 노드 변경
	}

	return 2;
}

/* 데이터 삭제 */
int Remove(ClosedHash* h, const Member* x)
{
	Bucket* p = Search(h, x);		// 해시 테이블에 자료가 있는지 확인
	if (p == NULL)
		return 1;					// 없으면 종료

	p->stat = Deleted;				// 추가와 검색 등 다른 작업들은 버켓 상태만으로 조건을 확인한 뒤 진행
									// 따라서 stat만 변경해주면 된다.
	return 0;
}

/* 해시 테이블 덤프 */
void Dump(const ClosedHash* h)
{
	int i;
	for (i = 0; i < h->size; i++) {		// 해시 테이블 크기 만큼 번호 출력
		printf("%02d : ", i);		
		switch (h->table[i].stat) {		// 요소 상태에 따라 출력
		case Occupied: printf("%d(%s)\n",
			h->table[i].data.no, h->table[i].data.name); break;

		case Empty: printf("-- 미등록 --\n"); break;
		case Deleted: printf("-- 삭제 마침 --\n"); break;

		}
	}
}

/* 모든 데이터 삭제 */
void Clear(ClosedHash* h)
{
	int i;
	for (i = 0; i < h->size; i++)
		h->table[i].stat = Empty;
}

/* 해시 테이블 종료 */
void Terminate(ClosedHash* h)
{
	Clear(h);
	free(h->table);
	h->size = 0;
}