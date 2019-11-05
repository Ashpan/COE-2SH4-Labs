#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *my_strcat(const char * const str1, const char * const str2);
int Q1(){

    char str1[50];
    char str2[50];
    printf("Enter your first string: \n");
    scanf("%s", str1); //ask user for str1 input and save to var
    printf("Enter your second string: \n");
    scanf("%s", str2); //ask user for str2 input and save to var
    printf("Concatenated string: %s\n", my_strcat(str1, str2)); //concatenate strings together
}


char *my_strcat(const char * const str1, const char * const str2){
    char *strOutput = calloc((strlen(str1)+strlen(str2)+1) , sizeof(char)); //creates str pointer with size of length of
    strOutput[strlen(str1)+strlen(str2)] = '\0'; //add null char at the end of the string
    for (int k = 0; k < strlen(strOutput); ++k) {
        strOutput[k] = 0;
    }
    //concatented strings * char size
    int i = 0, j = 0; //init values for for loop
    for (i = 0; str1[i] != '\0'; i++) {
        strOutput[i] = str1[i]; //iterate through the characters of str1 and copy them to strOutput at position i
    }
    for (j = 0; str2[j] != '\0'; j++) {
        strOutput[i+j] = str2[j];//iterate through the characters of str2 and copy them to strOutput at position i+j
    }
    return (char *) strOutput; //return the string
}
