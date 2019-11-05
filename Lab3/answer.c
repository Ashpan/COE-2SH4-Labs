//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <string.h>
//#include <sys/types.h>
//bool sort2_words(char *word1, char *word2)
//{
//    //length of two words
//    int len1 = strlen(word1);
//    int len2 = strlen(word2);
//    //to store minimum length of the two words
//    int min;
//    //find length of minimum word
//    if(len1 > len2)
//    {
//        min = len2;
//    }
//    else
//    {
//        min = len1;
//    }
//    int i;
//    for(i = 0; i < len1; i++)
//    {
//        if(word1[i] == word2[i])
//        {
//            continue;
//        }
//        else if(word1[i] > word2[i])
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
//    return false;
//}
//void sort_words(char **wordsarray, int arraySize)
//{
//    //insertion sort for sorting array of words
//    int i, j;
//    char *key;
//    for (i = 1; i < arraySize; i++)
//    {
//        strcpy(key, wordsarray[i]);
//        j = i - 1;
//        /* Move elements of wordsarray[0..i-1], that are
//
//        greater than key, to one position ahead
//
//        of their current position */
//        while (j >= 0 && sort2_words(wordsarray[j], key))
//        {
//            strcpy(wordsarray[j + 1], wordsarray[j]);
//            j = j - 1;
//        }
//        strcpy(wordsarray[j + 1], key);
//    }
//    return;
//}
//void output_words(char **wordsarray, int arraySize){
//    int i;
//    //iterate thw words array, and print each word in a line
//    for(i = 0; i < arraySize; i++){
//        //printing the individual word
//        printf("%s\n", wordsarray[i]);
//    }
//    //printing a new line
//    printf("\n");
//}
//
//char **read_words(const char *input_filename, int *nPtr)
//{
//    char *line = NULL;
//    size_t len = 0;
//    ssize_t read;
//    FILE *fp = fopen(input_filename, "r");
//    //exit if failure
//    if(fp == NULL)
//    {
//        exit(EXIT_FAILURE);
//    }
//    // read the first line and store the number to *nPtr
//    if((read = getline(&line, &len, fp)) != -1)
//    {
//        *nPtr = atoi(line);
//    }
//    printf("%d\n", *nPtr);
//    // create words array of the required size
//    char *wordsarray[*nPtr];
//    int i = 0;
//    while((read = getline(&line, &len, fp)) != -1)
//    {
//        printf("%s\n", line);
//        //copy the word read to the words array
//        strcpy(wordsarray[i], line);
//        printf("you still wokring?\n");
//        i++;
//    }
//    printf("pls");
//    fclose(fp);
//    return wordsarray;
//}
//
//int main2(){
//    //words array
//    char **wordsarray;
//    // number of words in the file
//    int num_words;
//    //file name to read
//    char *input_filename = "C:\\Users\\Ashpan\\Drive\\Current\\School\\Second Year\\COMPENG 2SH4\\Labs\\Lab3\\words.txt";
//    //call the read_words function and store the length in num_words and the words array in words_array
//    wordsarray = read_words(input_filename, &num_words);
//    //sort the words
//    sort_words(wordsarray, num_words);
//    //output the words
//    output_words(wordsarray, num_words);
//    return 0;
//}