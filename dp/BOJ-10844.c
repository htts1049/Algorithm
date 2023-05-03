#define _CRT_SECURE_NO_WARNINGS
#define mod 1000000000

#include <stdio.h>
#include <stdlib.h>

/*---- 백준 10844번. 쉬운 계단 수 ----*/
/*
헤맨 이유
1. dp를 2차원 배열로 쓸 생각을 하지 못했음
2. answer를 더해나갈 때에도 int 범위를 초과할 수 있으므로 나머지 연산을 해줘야한다는 것을 놓쳤음
*/

int main() {
    
    int n;
    scanf("%d", &n);

    // dp[i][j] = 길이가 i인 숫자의 마지막 자릿수가 j인 경우의 수
    int dp[101][10];
    dp[1][0] = 0;
    
    // 길이가 1인 숫자 중 0을 제외, 1~9를 나타는 경우는 모두 1가지씩
    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }

    // 길이가 i인 숫자의 마지막 자릿수 = 길이가 i-1인 숫자의 마지막 자릿수에 따라 다름
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {

            // 0, 9 뒤에는 각각 1, 8밖에 오지 못함
            if (j == 0) {
                dp[i][j] = dp[i - 1][j + 1] % mod;
            }
            else if (j == 9) {
                dp[i][j] = dp[i - 1][j - 1] % mod;
            }

            // 1~8은 각각 -1, +1 해준 숫자가 뒤에 붙을 수 있음
            else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i <= 9; i++) {
        answer = (answer + dp[n][i]) % mod;
    }

    printf("%d", answer);

    return 0;
}