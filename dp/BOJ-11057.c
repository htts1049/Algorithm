#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

/*---- 백준 11057번. 오르막 수 ----*/
/* 
백준 10844번 쉬운 계단 수와 유사하고, 
프로그래머스 억억단을 외우자에서 나머지 연산을 매번 하지 않으면
int 값을 넘을 수도 있다는 걸 알았기에 헤매지는 않았다.

dp[i][k] = 자릿수가 k인 숫자 중에서 끝자리가 i일 때 오르막 수의 개수
*/


int main(void)
{
	int n;
	scanf("%d", &n);
	
	int dp[10][1001];

	for (int i = 0; i < 10; ++i) {
		dp[i][1] = 1;
	}

	for (int k = 2; k <= n; ++k) {
		dp[0][k] = 1;

		for (int i = 1; i < 10; ++i) {
			dp[i][k] = (dp[i][k - 1] + dp[i - 1][k]) % 10007;
		}
	}

	int answer = 0;
	for (int i = 0; i < 10; ++i) {
		answer = (answer + dp[i][n]) % 10007;
	}

	
	printf("%d\n", answer);

	return 0;
}
