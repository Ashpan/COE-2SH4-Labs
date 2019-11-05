#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char **read_words(const char *input_filename, int *nPtr);
void output_words(char **stringArr, int arraySize);

int Q3(){
    char input_filename[] = "C:\\Users\\Ashpan\\Drive\\Current\\School\\Second Year\\COMPENG 2SH4\\Labs\\Lab3\\words.txt";
    int size = 0;
    char **stringArray = read_words(input_filename, &size);
    output_words(stringArray, size);
    return 0;
}

char **read_words(const char *input_filename, int *nPtr){
    FILE *input_file = fopen(input_filename, "r");
    fscanf(input_file, "%d", nPtr);
    char **strArray = malloc(sizeof(char*) * (*nPtr));
    char currString[50];
    for (int i = 0; i < *nPtr; ++i) {
        fscanf(input_file, "%s", currString);
        strArray[i] = malloc(sizeof(char) * strlen(currString));
        strcpy(strArray[i], currString);
    }
    fclose(input_file);
    return strArray;
}


void output_words(char **stringArr, int arraySize){
    for(int i = 0; i < arraySize; i++){
        //printing the individual word
        printf("%s\n", stringArr[i]);
    }
    //printing a new line
}

int compareString(char *str1, char *str2){ //if str1 before str2, it will return 1, else return 0
    int length = 0;
    if(strlen(str1)<strlen(str2)){
        length = (int) strlen(str1);
    }else{
        length = (int) strlen(str2);
    }
    for (int i = 0; i < length; ++i) {
        if(str1[i] < str2[i]){
            return 1;
        }else if(str2[i] < str1[i]){
            return 0;
        }
    }
    if(strlen(str1)<strlen(str2)){
        return 1;
    }else{
        return 0;
    }
}

void sort_words(char **stringArray, int arraySize){
    int currPos = 0;
    char *currWord;
    for (currPos = 0; currPos < arraySize; currPos++) {
        for (int i = currPos; i >= 0; i--) {
            if(compareString(stringArray[currPos], stringArray[i])){
                strcpy(currWord, stringArray[currPos]);

            }

        }
    }
}