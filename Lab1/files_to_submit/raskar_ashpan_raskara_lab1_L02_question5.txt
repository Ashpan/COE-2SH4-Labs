#include <stdio.h>

int main() {
    printf("Enter your \"n\" value");
    int n = 0;
    double sum = 0.0;
    scanf("%d", &n);
    double operator = 4.0;

    for (int i = 0; i < n; i++) {
        double val = operator/(2.0*i+1);
        sum += val;
        operator *= -1;
    }

    printf("Your sum is %lf", sum);
    return 0;
}