#include <stdlib.h>
#include <stdio.h>

//#define N 2

int main() {

    int N,M;


    scanf("%d",&N);
    scanf("%d",&M);
    
    int** mat = (int**) malloc(N*sizeof(int*));
    int i,j;
    for (i = 0; i < N; ++i) {
        int* p = (int*) malloc(M*sizeof(int));
        mat[i] = p;
    }

    for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {
            mat[i][j] = i+j;
        }

    }

    for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {
            printf("%d ",mat[i][j]);
        }
        printf("\n");

    }             
}




