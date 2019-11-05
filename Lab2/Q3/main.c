#include <stdio.h>
#define N 4
void diag_scan_print(int arr[][N]);
int main() {
    int testArr[][N] = {{1,2,3,4},{5,6,7,8},{9,0,1,2},{3,4,5,6}};
    diag_scan_print(testArr);
    return 0;
}

void diag_scan_print(int arr[][N]){
    for (int j = 0; j < N; ++j) {
        for (int k = j; k >= 0; k--) {
//            printf("%d %d\n", k, j-k);
            printf("%d ", arr[k][j-k]);
        }
    }
    for (int j = 0; j < N-1; ++j) {
        for (int k = 0; k < (N-1-j); k++) {
            printf("%d ", arr[N-1-k][j+k+1]);
        }
    }
}