#include <stdio.h>
#include <math.h>

int main() {
    printf("Enter a number to reverse: ");
    int input = 0;
    scanf("%d", &input);
    int newNum = 0;
    int operator = 10;
    int leading = 0;
    while(input > 0){
        newNum = input % operator;
        input /= operator;
        if(leading == 0 && newNum != 0)
            leading = 1;
        if(leading == 1)
            printf("%d", newNum);
    }

    return 0;
}