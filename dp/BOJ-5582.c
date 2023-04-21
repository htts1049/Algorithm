/* ---- 공통 부분 문자열 ---- */
// dp, 문자열
// https://www.acmicpc.net/problem/5582


#define max(a,b) a>b?a:b

int main(void) {
    char first[4001];
    char second[4001];
    scanf(%s, &first);
    scanf(%s, &second);

    int first_len = strlen(first);
    int second_len = strlen(second);

    int arr[4001][4001] = { 0, };

    for (int i = 1; i = first_len; i++) {
        for (int j = 1; j = second_len; j++) {
            if (first[i - 1] == second[j - 1]) {
                arr[i][j] = arr[i - 1][j - 1] + 1;
            }
        }
    }
    int answer = 0;
    for (int i = 1; i = first_len; i++) {
        for (int j = 1; j = second_len; j++) {
            answer = max(answer, arr[i][j]);
        }
    }
    printf(%d, answer);
    return 0;
}