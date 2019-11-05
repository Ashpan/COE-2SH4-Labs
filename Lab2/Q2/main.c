#include <stdio.h>
#include <math.h>
#define N 3

int is_diag_dom(int mat[][N]);
int main() {
    int arr[][N] = {{6,1,8},{1,8,2},{1,2,9}};
    printf("%d", is_diag_dom(arr));
    return 0;
}

int is_diag_dom(int mat[][N]){
    int verify = 1;
    for (int i = 0; i < N; ++i) {
        int sum = 0;
        for (int j = 0; j < N; ++j) {
            if(j!=i)
                sum += mat[i][j];
        }
        if(fabs(mat[i][i] <= fabs(sum)))
            verify = 0;
    }
    return verify;
}
