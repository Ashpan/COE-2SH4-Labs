#include <stdio.h>
void letter_freq(const char word[], int freq[]);
int main() {
    const char pls[] = "ABcdeFGHiJklmnOPQRstuvwXYzzzzz";
    int fre[26] = {0};
    letter_freq(pls, fre);
    return 0;
}

void letter_freq(const char word[], int freq[]){
    int len = 0;
    char currChar = ' ';
    int pos = 0;
    while(currChar != '\0'){
        currChar = word[pos];
        len++; pos++;
    }
    len--;
    for (int i = 0; i < len; ++i) {
        if(word[i] >= 'A' && word[i] <= 'Z'){
            freq[word[i]-'A']++;
        }else if(word[i] >= 'a' && word[i] <= 'z'){
            freq[word[i]-'a']++;
        }
    }
    for (int i = 0; i < 26; ++i) {
        printf("The count of %c and %c is %d\n", i+'A', i+'a', freq[i]);
    }
}
