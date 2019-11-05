#include <stdio.h>

int main() {
    int forSum = 0;
    for (int i = 30; i <= 1000; i++) {
        if(i%4==0)
            forSum += i;
    }
    printf("Using for loop: ");
    printf("%d", forSum);

    int i = 30;
    int whileSum = 0;
    while(i<=1000){
        if(i%4==0)
            whileSum += i;
        i++;
    }
    printf("\nUsing while loop: ");
    printf("%d", whileSum);

    int j = 30;
    int doSum = 0;
    do{
        if(j%4==0)
            doSum += j;
        j++;
    } while(j<=1000);

    printf("\nUsing do loop: ");
    printf("%d", whileSum);


    return 0;
}