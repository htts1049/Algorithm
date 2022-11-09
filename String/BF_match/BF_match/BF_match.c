#define _CRT_SECURE_NO_WARNINGS

/* 브루스-포스법으로 문자열을 검색하는 프로그램 */
#include <stdio.h>

/* 브루트-포스법으로 문자열을 검색하는 함수 */
int bf_match(const char txt[], const char pat[])
{
	int pt = 0;
	int pp = 0;
	while (txt[pt] != '\0' && pat[pp] != '\0') {
		if (txt[pt] == pat[pp]) {
			pt++;					// pt,pp를 하나씩 늘려가며 텍스트, 패턴 비교
			pp++;
		}
		else {
			pt = pt - pp + 1;		// 패턴과 불일치시 텍스트는 다음 문자로
			pp = 0;					// 패턴 초기화
		}
	}
	if (pat[pp] == '\0')
		return pt - pp;
	return -1;
}

int main(void)
{
	int idx;
	char s1[256];
	char s2[256];
	puts("브루트-포스법");
	printf("텍스트 : ");
	scanf("%s", s1);
	printf("패턴 : ");
	scanf("%s", s2);
	idx = bf_match(s1, s2);
	if (idx == -1)
		puts("텍스트에 패턴이 없습니다.");
	else
		printf("%d번째 문자부터 match합니다.\n", idx + 1);

	return 0;
}