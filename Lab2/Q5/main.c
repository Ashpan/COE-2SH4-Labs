#include <stdio.h>
int str_len(char string[]);
void string_copy(const char source[], char destination[], int n);
int main() {
    char source[] = "Hey whats up";
    char dest[] = "           ";
    int length = str_len(dest);
    string_copy(source, dest, length);
    printf("%s", dest);
    return 0;
}

void string_copy(const char source[], char destination[], int n){
    int len = str_len(source);
    if(len>n) {
        for (int i = 0; i < n; ++i) {
            destination[i] = source[i];
        }
    }else{
        for (int i = 0; i < len; ++i) {
            destination[i] = source[i];
        }
    }
    destination[len] = '\0';
    printf("\n");
}

int str_len(char string[]){
    int len = 0;
    char currChar = ' ';
    int pos = 0;
    while(currChar != '\0'){
        currChar = string[pos];
        len++; pos++;
    }
    len--;
    return(len);
}