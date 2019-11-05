#include <stdio.h>

int main() {
    int num = -1;
    while(num != 0) {
        printf("Please input an integer (0 to end): ");
        scanf("%d", &num);

        int remainder = num;
        int count = 0;
        while (remainder != 0) {
            remainder /= 10;
            count++;
        }
        if (count == 5) {
            printf("Your input is a five-digit number: %d\n", num);
        }
    }
    printf("Thank you for using my software. Bye!");
    return 0;
}