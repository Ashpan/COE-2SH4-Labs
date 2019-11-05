#include <stdlib.h>
#include <stdio.h>
typedef struct{
    int id;
    char fName[15];
    char lName[15];
    int proj1;
    int proj2;
    float finalGrade;
} student;
student **create_class_list(char *filename, int *sizePtr);
int find(int idNo, student **list, int size);
void input_grades( char *filename, student **list, int size);
void compute_final_course_grades(student **list, int size);
void output_final_course_grades(char *filename, student **list);
void print_list(student **list, int size);
void withdraw(int idNo, student **list, int *sizePtr);
void destroy_list(student **list, int *sizePtr);
int Q2(){
    int size = 0;
    int *sizePtr = &size; //pointer referencing the size variable
    char studFilename[] = "C:\\Users\\Ashpan\\Drive\\Current\\School\\Second Year\\COMPENG 2SH4\\Labs\\Lab3\\students.txt";
    char gradeFilename[] = "C:\\Users\\Ashpan\\Drive\\Current\\School\\Second Year\\COMPENG 2SH4\\Labs\\Lab3\\grades.txt";
    char finalgradeFilename[] = "C:\\Users\\Ashpan\\Drive\\Current\\School\\Second Year\\COMPENG 2SH4\\Labs\\Lab3\\finalGrades.txt";
    student **studList = create_class_list(studFilename, sizePtr); //create array of student structs
    printf("%d\n", find(1000, studList, size));
    input_grades(gradeFilename, studList, size);
    compute_final_course_grades(studList, size);
    output_final_course_grades(finalgradeFilename, studList);
    print_list(studList, size);
    withdraw(990532940, studList, sizePtr);
    print_list(studList, *sizePtr);
    withdraw(4000, studList, sizePtr);
    withdraw(643857392, studList, sizePtr);
    withdraw(432424224, studList, sizePtr);
    withdraw(132450000, studList, sizePtr);
    print_list(studList, *sizePtr);
    destroy_list(studList, sizePtr);
    printf("Size of list: %d", *sizePtr);
    return 0;
}


student **create_class_list(char *filename, int *sizePtr){
    FILE *input_file=fopen(filename, "r"); //open the file called input_file
    fscanf(input_file, "%d", sizePtr); //read the first value (should be an integer) and store in sizePtr
    student **classList = calloc(*sizePtr, sizeof(student));  //free up space for the array that is the sizePtr*size of student struct
    for (int i = 0; i < *sizePtr; ++i) { //iterate from 0 to sizePtr
        classList[i] = calloc(1, sizeof(student)); //free up space that is size of student struct in each array element
        fscanf(input_file, "%d %s %s", &(classList[i] -> id), classList[i] -> fName, classList[i] -> lName);
        //store the variables for id, first name, and last name in the array structs
    }
    fclose(input_file); //close file
    return classList; //return array
}

int find(int idNo, student **list, int size){
    if(size == 0){ //if size of list is 0, return -1
        return -1;
    }else{
        for (int i = 0; i < size; ++i) { //go through every element in array
            if(list[i] -> id == idNo){ //if any of the values equals idNo
                return i; //return index value
            }
        }
        return -1; //otherwise return -1
    }
}

void input_grades( char *filename, student **list, int size){
    FILE *input_file=fopen(filename, "r"); //open file and call it input_file
    for (int i = 0; i < size; ++i) { //iterate from 0 to size
        int fileStudentId = 0;
        fscanf(input_file, "%d", &fileStudentId); //read the first number in the file and save to fileStudentId
        int index = find(fileStudentId, list, size); //use find method to find the index of the studentNumber
        fscanf(input_file, "%d %d", &(list[index] -> proj1), &(list[index] -> proj2)); //update proj1 and 2 marks using that index and studentnumber
    }
    fclose(input_file); //close file
}

void compute_final_course_grades(student **list, int size){
    for (int i = 0; i < size; ++i) {
        list[i] -> finalGrade = (float)(list[i] -> proj1 + list[i] -> proj2)/2; //iterate through each student and take
    }                                                                           //average of proj1 and 2 grades and update in struct
}

void output_final_course_grades(char *filename, student **list){
    FILE *output_file=fopen(filename, "w"); //open file called output_file to write in it
    fprintf(output_file, "%d\n", sizeof(list)); //first write the size of the list followed by a newline
    for (int i = 0; i < sizeof(list); ++i) { //iterate through each student and print their id and final grade
        fprintf(output_file, "%d %lf\n", list[i]->id, list[i]->finalGrade); //separated by a space
    }
}

void print_list(student **list, int size){
    for (int i = 0; i < size; ++i) { //iterate through size of array (each student)
        int id = list[i] -> id;
        int proj1 = list[i] -> proj1;
        int proj2 = list[i] -> proj2;
        float final = list[i] -> finalGrade;
        printf("ID: %d, name: %s %s, Project 1 Grade: %d, Project 2 Grade: %d, Final Grade: %lf\n", id, list[i]->fName, list[i]->lName, proj1, proj2, final);
    //print out each value, id, first name, last name, project 1 & 2 grades, and final grade.
    }
}

void withdraw(int idNo, student **list, int *sizePtr){
    int index = find(idNo, list, *sizePtr); //find index of idNo
    if(index == -1){ //if value returned is -1, that id doesnt exist
        printf("This ID (%d) does not exist\n", idNo);
    }else{
        printf("Removing: %d\n", idNo);
        free(list[index]); //free the entry in that index
        if(index == (*sizePtr-1)){  //if its the last entry
            (*sizePtr)--; //reduce size of sizePtr by 1
            list = realloc(list, *sizePtr*sizeof(student)); //reallocate size of list by new value of sizePtr
        }else{ //otherwise
            for (int i = index+1; i < *sizePtr; ++i) { //iterate through array from the position of the removed element +1
                list[i-1] = list[i];                    // to the size of the array and shift everything to the left by 1
            }
            (*sizePtr)--; //reduce size of sizePtr by 1
        }
    }
}

void destroy_list(student **list, int *sizePtr){
    for (int i = 0; i < *sizePtr; ++i) { //iterate through array
        free(list[i]); //free every entry in the array
    }
    *sizePtr = 0; //set sizePtr to 0
    free(list); //free the actual array
}