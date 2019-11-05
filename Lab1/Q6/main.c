#include <stdio.h>
#include <math.h>

int main() {
    int counter = 0;
    for (int i = 1; i <= 400; i++) {
        for (int j = 1; j <= 400; j++) {
            for (int k = 1; k <= 400; k++) {
                if( (pow(i, 2) + pow(j, 2) == pow(k, 2))  && i<=j){
                    printf("Triple: (%d, %d, %d) was found\n", i, j, k);
                    counter++;
                }
            }
        }       
    }
    
    printf("Counter: %d", counter);
    return 0;
}