#include <stdio.h>

int main() {
    printf("Enter the student's average");
    double average = 0.0;
    scanf("%lf", &average);
    if(average > 100 || average < 0){
        printf("Average value must be between 0 to 100");
    }else if(average > 89){
        printf("4");
    }else if(average > 79){
        printf("3");
    }else if(average > 69){
        printf("2");
    }else if(average > 59){
        printf("1");
    }else{
        printf("0");
    }
    return 0;
}