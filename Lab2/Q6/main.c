#include <stdio.h>

void efficient( const int source[], int val[], int pos[], int size);
void reconstruct(int source[], int m, const int val[], const int pos[], int n);
int main() {
    int regArr[]  = {0, 0, 12, 20, 0, 0, 5, 4, 0};
    int newArr[9]  = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int val[4] = {};
    int pos[4] = {};
    efficient(regArr, val, pos, 9);
    for(int loop = 0; loop < sizeof(val)/sizeof(val[0]); loop++)
        printf("[%d, %d]\n", pos[loop], val[loop]);
    reconstruct(newArr, 9, val, pos, 4);
    for(int loop = 0; loop < sizeof(newArr)/sizeof(newArr[0]); loop++)
        printf("%d, ", newArr[loop]);

    return 0;
}


void efficient( const int source[], int val[], int pos[], int size){
    int k = 0;
    for (int i = 0; i < size; i++) {
        if(source[i]!=0){
            val[k] = source[i];
            pos[k] = i;
            k++;
        }
    }
}

void reconstruct( int source[], int m, const int val[], const int pos[], int n ){
    for (int i = 0; i < n; ++i) {
        source[pos[i]] = val[i];
    }
}