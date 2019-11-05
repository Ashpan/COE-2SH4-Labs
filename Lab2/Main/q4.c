#include <stdio.h>
void letter_freq(const char word[], int freq[]);
int q4() {
    const char pls[] = "AaBbCcD";
    int fre[26] = {0};
    letter_freq(pls, fre);
    return 0;
}

void letter_freq(const char word[], int freq[]){
    int len = 0;
    char currChar = ' ';
    int pos = 0;
    while(currChar != '\0'){ //loop to get length of string
        currChar = word[pos];
        len++; pos++;
    }
    len--;
    for (int i = 0; i < len; ++i) { //iterate from 0 to length
        if(word[i] >= 'A' && word[i] <= 'Z'){ //if capital
            freq[word[i]-'A']++; //iterate index of letter minus ascii value to get correct index
        }else if(word[i] >= 'a' && word[i] <= 'z'){ //if lowercase
            freq[word[i]-'a']++; //iterate index of letter minus ascii value to get correct index
        }
    }
    for (int i = 0; i < 26; ++i) {
        printf("The count of %c and %c is %d\n", i+'A', i+'a', freq[i]); //loop to print letter and frequency
    }
}
