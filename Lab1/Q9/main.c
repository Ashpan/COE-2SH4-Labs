#include <stdio.h>
void decoder (); //19 0 1 1 0 0 0 1 1 0 1 0 0 0 0 0 1 1 1
void encoder (); //4 5 2 7 3

int main() {
    encoder();


    return 0;
}


void encoder(){
    FILE *input_file=fopen("C:\\Users\\Ashpan\\Drive\\Current\\School\\Second Year\\COMPENG 2SH4\\Labs\\Lab1\\Q9\\inputfile1.txt", "r");
    FILE *output_file=fopen("C:\\Users\\Ashpan\\Drive\\Current\\School\\Second Year\\COMPENG 2SH4\\Labs\\Lab1\\Q9\\outputfile1.txt", "w");

    int repeat = 0;
    int num = 0;
    int bin = 0;
    int counter = 0;
    fscanf(input_file,"%d", &repeat);
    for (int i = 0; i < repeat; i++) {
        fscanf(input_file,"%d", &num);
        for (int j = 0; j < num; j++) {
            fprintf(output_file,"%d ", bin);
        }
        bin = !bin;
    }
    fclose(input_file);
    fclose(output_file);
}


void decoder(){
    FILE *input_file=fopen("C:\\Users\\Ashpan\\Drive\\Current\\School\\Second Year\\COMPENG 2SH4\\Labs\\Lab1\\Q9\\inputfile2.txt", "r");
    FILE *output_file=fopen("C:\\Users\\Ashpan\\Drive\\Current\\School\\Second Year\\COMPENG 2SH4\\Labs\\Lab1\\Q9\\outputfile2.txt", "w");

    int repeat = 0;
    int num = 0;
    int binCheck = 0;
    int counter = 0;
    fscanf(input_file,"%d", &repeat);
    for (int i = 0; i < repeat; i++) {
        fscanf(input_file,"%d", &num);
        if(num != binCheck){
            fprintf(output_file,"%d ", counter);
            counter = 1;
            binCheck = !binCheck;
        }else{
            counter++;
        }
    }
    fprintf(output_file,"%d ", counter);
    fclose(input_file);
    fclose(output_file);
}