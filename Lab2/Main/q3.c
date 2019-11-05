#include <stdio.h>
#define N 4
void diag_scan_print(int arr[][N]);
int q3() {
    int testArr[][N] = {{1,2,3,4},{5,6,7,8},{9,0,1,2},{3,4,5,6}};
    diag_scan_print(testArr);
    return 0;
}

void diag_scan_print(int arr[][N]){
    for (int j = 0; j < N; ++j) { //iterate from 0 to N
        for (int k = j; k >= 0; k--) { //iterate from J to 0
            printf("%d ", arr[k][j-k]); //print element [k][j-k]
        }
    }
    for (int j = 0; j < N-1; ++j) { //iterate from 0 to N-1
        for (int k = 0; k < (N-1-j); k++) { //iterate from 0 to N-1-j
            printf("%d ", arr[N-1-k][j+k+1]); //print element [N-1-k][j+k+1]
        }
    }
}