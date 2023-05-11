#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*---- 프로그래머스. 억억단을 외우자 ----*/
/*
헤맨 이유
1. count 배열 구할 때 sqrt 사용해서 구함 → 시간초과
2. [i,e] 구간에서 최대값 구할 때 구간만큼의 반복문을 돌아서 구함 → 시간초과
*/


typedef struct {
    int idx;
    int val;
} item;

int comp(item* x, item* y){
    if(x->val > y->val) return 1;
    else if(x->val < y->val) return -1;
    else return 0;
}

int* solution(int e, int starts[], size_t starts_len) {

    int* answer = (int*)malloc(starts_len * sizeof(int));
    
    // e이하의 i (1~e)의 배수 세기
    int* count = (int*)calloc(e+1, sizeof(int));
    for(int i=1; i <= e; ++i){
        int j=1;
        int multi;
        while( (multi = i*j) <= e){
            ++count[multi];
            ++j;
        }
    }
    
    // max_arr[i] = [i,e] 범위 내 억억단에서 가장 많이 등장한 수
    int* max_arr = (int*)malloc((e+1) * sizeof(int));
    max_arr[e] = e;
    for(int i=e-1; i>=1; --i){
        max_arr[i] = max_arr[i+1];
        
        if(count[i] >= count[max_arr[i+1]]){
            max_arr[i] = i;
        }
    }
    
    
    // starts 배열에 인덱스 정하고 val 값에따라 오름차순 정렬
    item* indexed = (item*)malloc(starts_len * sizeof(item));
    for(int i=0; i<starts_len; ++i){
        indexed[i].idx = i;
        indexed[i].val = starts[i];
    }
    qsort(indexed, starts_len, sizeof(item), comp); 
    
    for(int i=0; i<starts_len; ++i){
        answer[indexed[i].idx] = max_arr[indexed[i].val];
    }
    
    return answer;
}