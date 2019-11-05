#include <stdio.h>

void efficient( const int source[], int val[], int pos[], int size);
void reconstruct(int source[], int m, const int val[], const int pos[], int n);
int q6() {
    int regArr[]  = {1, 2, 0, 0, 0, 6};
    int newArr[6]  = {0, 0, 0, 0, 0, 0};
    int val[3] = {1,2,6};
    int pos[3] = {0,1,5};
//    efficient(regArr, val, pos, 6);
//    for(int loop = 0; loop < sizeof(val)/sizeof(val[0]); loop++)
//        printf("[%d, %d]\n", pos[loop], val[loop]);
    reconstruct(newArr, 3, val, pos, 3);
    for(int loop = 0; loop < sizeof(newArr)/sizeof(newArr[0]); loop++)
        printf("%d, ", newArr[loop]);

    return 0;
}


void efficient( const int source[], int val[], int pos[], int size){
    int k = 0;
    for (int i = 0; i < size; i++) { //iterate througb size of source
        if(source[i]!=0){ //as long as the value isnt 0
            val[k] = source[i]; //store the value in the kth index of val[]
            pos[k] = i; //store i in the kth val of pos[]
            k++;
        }
    }
}

void reconstruct( int source[], int m, const int val[], const int pos[], int n ){
    for (int i = 0; i < n; ++i) { //for size of val/pos
        source[pos[i]] = val[i]; //put val[i] into source at position pos[i]
    }
}