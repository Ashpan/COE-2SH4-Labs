#include <stdio.h>
int str_len(char string[]);
void string_copy(const char source[], char destination[], int n);
int q5() {
    char source[] = "AaBbCcD";
    char dest[] = "    ";
    int length = str_len(dest);
    string_copy(source, dest, length);
    printf("Copied Word: %s", dest);
    return 0;
}

void string_copy(const char source[], char destination[], int n){
    int len = str_len(source);
    if(len>n) { //if length of source is greater than dest
        for (int i = 0; i < n; ++i) { //keep going until length of dest
            destination[i] = source[i]; //copy each character
        }
    }else{ //else
        for (int i = 0; i < len; ++i) { //keep going until length of source
            destination[i] = source[i]; //copy each char
        }
    }
    destination[len] = '\0'; //add null character
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