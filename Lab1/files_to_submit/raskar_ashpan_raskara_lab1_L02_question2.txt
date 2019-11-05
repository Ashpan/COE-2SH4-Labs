#include <stdio.h>
#include <limits.h>

int main() {
    int n = -1;
    while (n < 0){
        printf("Input the value of n: ");
        scanf("%d", &n);
    }
    int smallestVal = INT_MAX;
    int input = 0;
    for (int i = 0; i < n; i++) {
        printf("Input a value: ");
        scanf("%d", &input);
        if(input < smallestVal){
            smallestVal = input;
        }
    }
    printf("The smallest value you entered is: %d", smallestVal);
    return 0;
}