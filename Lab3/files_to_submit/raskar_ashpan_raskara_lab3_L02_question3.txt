#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char **read_words(const char *input_filename, int *nPtr);
void output_words(char **stringArr, int arraySize);

int Q3(){
    char input_filename[] = "C:\\Users\\Ashpan\\Drive\\Current\\School\\Second Year\\COMPENG 2SH4\\Labs\\Lab3\\words.txt";
    int size = 0;
    char **stringArray = read_words(input_filename, &size);
    printf("yo %d\n", sizeof(stringArray[1]));

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
        printf("word: %s\n", strArray[i]);
        printf("memory for string %d: %d\n", i, sizeof(strArray[i]));
    }
    fclose(input_file);
    return strArray;
}


void output_words(char **stringArr, int arraySize){
    printf("%s\n", stringArr[0]);
    for(int i = 0; i < arraySize; i++){
        //printing the individual word
        printf("String %d %s\n", i, stringArr[i]);
    }
    //printing a new line
}