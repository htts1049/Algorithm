#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

/*---- ���� 11057��. ������ �� ----*/
/* 
���� 10844�� ���� ��� ���� �����ϰ�, 
���α׷��ӽ� ������ �ܿ��ڿ��� ������ ������ �Ź� ���� ������
int ���� ���� ���� �ִٴ� �� �˾ұ⿡ ������� �ʾҴ�.

dp[i][k] = �ڸ����� k�� ���� �߿��� ���ڸ��� i�� �� ������ ���� ����
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