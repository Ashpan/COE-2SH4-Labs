#include <stdio.h>

int main() {
    printf("Enter your \"m\" value!\n");
    long int m = 0;
    scanf("%ld", &m);
    int counter = 0;

    for (int j = 1; j <= m; j++) {
        int sum = 0;
        for (int i = 1; i < j; i++) {
            if(j%i == 0){
                sum += i;
            }
        }
        if(sum == j){
            printf("Perfect Number: %d\n", j);
            counter++;
        }
    }

    printf("There are %d perfect number(s) between 1 and %d", counter, m);
    return 0;
}