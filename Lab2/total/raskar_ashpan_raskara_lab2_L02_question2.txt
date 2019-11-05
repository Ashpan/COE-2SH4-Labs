#include <stdio.h>
#include <math.h>
#define N 3

int is_diag_dom(int mat[][N]);
int q2() {
    int arr[][N] = {{1,2,0},{0,2,0},{0,0,3}};
    printf("%d", is_diag_dom(arr));
    return 0;
}

int is_diag_dom(int mat[][N]){
    int verify = 1;
    for (int i = 0; i < N; ++i) { //iterate from 0 to size
        int sum = 0;
        for (int j = 0; j < N; ++j) { //iterate from 0 to size
            if(j!=i) //if elements arent equal (as in not on diag)
                sum += mat[i][j]; //add value to sum
        }
        if(fabs(mat[i][i] <= fabs(sum))) //if abs of diag is < than sum then return 0
            verify = 0;
    }
    return verify;
}
