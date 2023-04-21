#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct __node {
    int flag;
    char ch;
    struct __node* child[10];
}node;


void init(node** curr) {
    if (*curr == NULL) {
        *curr = (node*)malloc(sizeof(node));
        for (int i = 0; i < 10; i++) {
            (*curr)->flag = 0;
            (*curr)->ch = '\0';
            (*curr)->child[i] = NULL;          
        }
    }
}

void insert(node** curr, char* str) {
    if ((*curr)->child[*str - '0'] == NULL) {
        init(&(*curr)->child[*str - '0']);
    }

    (*curr)->child[*str - '0']->ch = *str;

    if (*(str+1) != '\0') { 
        insert(&(*curr)->child[*str - '0'], str + 1); 
    }
    else {
        (*curr)->child[*str - '0']->flag = 1;
    }
}

int chk;

void check(node* root) {
    
    if (chk) return;

    if (root->flag == 1) {
        for (int i = 0; i < 10; i++) {
            if (root->child[i] != NULL) {
                chk = 1;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        if (root->child[i] != NULL) {
            check(root->child[i]);
        }
    }
}

int main(void) {
    
    int T, N;
    char str[11];
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        scanf("%d", &N);

        node* root = NULL;
        init(&root);
        for (int i = 0; i < N; i++) {
            scanf("%s", &str);
            insert(&root, str);
        }
        chk = 0;
        check(root);
        if (chk) {
            printf("NO\n");
        }
        else {
            printf("YES\n");
        }
    }
    
    return 0;
}