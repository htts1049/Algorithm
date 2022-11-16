/* 병합 정렬 프로그램 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

static int* buff;		/* 작업용 배열 */

/*--- 병합 정렬(main 부분) ---*/
static void __mergesort(int a[], int left, int right)
{
	if (left < right) {
		int center = (left + right) / 2;
		int p = 0;
		int i;
		int j = 0;
		int k = left;

		__mergesort(a, left, center);			/* 앞부분에 대한 병합 정렬 */
		__mergesort(a, center + 1, right);		/* 뒷부분에 대한 병합 정렬 */

		for (i = left; i <= center; i++)		/* 임시 배열 buff에 center까지 a를 복사 */
			buff[p++] = a[i];

		while (i <= right && j < p)								/* i는 a의 오른쪽 절반을 훑는 커서 */
			a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];	/* j는 buff(a의 왼쪽 절반)를 훑는 커서 */
																/* i가 끝까지 닿거나, j가 중앙까지 닿으면 종료하며 둘 중 작은 값을 a에 대입 */
		while (j < p)											/* buff에 남아있는 나머지를 a에 넣어줌 buff는 이미 정렬된 상태기에 다시 정렬할 필요 x */
			a[k++] = buff[j++];
	}
}

/*--- 병합 정렬 함수 ---*/
int mergesort(int a[], int n)
{
	if ((buff = calloc(n, sizeof(int))) == NULL)
		return -1;
	__mergesort(a, 0, n - 1);		/* 배열 전체를 병합 정렬 */

	free(buff);

	return 0;
}

int main(void)
{
	int i, nx;
	int* x;				/* 배열의 첫 번째 요소에 대한 포인터 */

	puts("병합 정렬");
	printf("요소 개수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	mergesort(x, nx);			/* 배열 x를 병합 정렬 */

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);		/* 배열을 해제 */

	return 0;
}