#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*---- 프로그래머스. 테이블 해시 함수 ----*/
/*
헤맨 이유
1. qsort 함수 사용할 때 원소 크기를 data_cols * sizeof(int) 로 사용
2. answer 에 s[i]를 XOR이 아니라 +를 함 ( 문제를 똑바로 읽지 못함 )
*/


// 기준 열 번호
int std;

// 첫 번째 열 값에 따라 내림차순
int comp2(int** x, int **y){
    if( (*x)[0] > (*y)[0]) return -1;
    else if( (*x)[0] < (*y)[0]) return 1;
    else return 0;
}

// 기준 열 값에 따라 오름차순
int comp(int** x, int** y){
    if( (*x)[std] > (*y)[std]) return 1;
    else if( (*x)[std] < (*y)[std]) return -1;
    else return comp2(x, y);
}

int solution(int** data, size_t data_rows, size_t data_cols, int col, int row_begin, int row_end) {
    int answer = 0;
    
    std = col-1;
    
    // 2번 조건에 따라 행 정렬
    qsort(data, data_rows, sizeof(int*), comp);
    
    int s[2501];
    
    
    for(int i=row_begin; i<=row_end; ++i){
        s[i] = 0;
        
        // 3번 조건에 따라 S_i 구하기
        for(int j=0; j<data_cols; ++j){
            s[i] += data[i-1][j] % i;
        }
        
        // 4번 조건에 따라 XOR 연산
        answer ^= s[i];
    } 
    
    return answer;
}