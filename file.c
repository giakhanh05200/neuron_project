#include <stdio.h> 
#include "file.h"
#include <string.h>
#include "neuron.h"
FILE *file; 
char *filename = "myfile.txt";  
//show content of the file
void show_content(void){
    char c;
    file = fopen(filename, "r");
    printf("File's content %s\n", filename);
    while ((c = fgetc(file) )!= EOF){
        printf ("%c", c);
    }
    fclose(file); 
}

void create_file(void){
    file = fopen(filename, "a+");
    fclose(file);
}

//get the input value, pass through the analyze function
//and return the output value depends on the results of our training 
//and add them to a file if the file doesn't exist then create file and add. 
void append_file(void){
    char content[1000];
    int user_num,r,g,b,line;
    double results, test[3];
    printf("Enter a RGB value seperated by whitespace: \n");
    scanf("%d %d %d", &r, &g, &b);
    test[0]=(float)r/255; test[1]=(float)g/255; test[2]=(float)b/255;
    results = analyze(test);
    if (results>=0.5){
        printf("Your value %3d %3d %3d is red\n",r,g,b);
        sprintf(content,"%3d %3d %3d is red",r,g,b);
    }
    else{
        printf("Your value %3d %3d %3d is not red\n",r,g,b);
        sprintf(content,"%3d %3d %3d is not red",r,g,b);
    }
    if(file==NULL) {
        printf("Error: can't create file.\n");
    }
    else {
        file = fopen(filename, "a+");
        fprintf(file, "%s\n", content);
        fclose(file);
    }
}
void delete_file(void){
    file = fopen(filename, "w");
    printf("My file is empty now!\n");
}

void delete_line(void){
    int num_line, count = 0;
    FILE *temp_file;
    char str[MAX], temp[] = "temporary.txt";
    file = fopen(filename, "r");

	//error when file or temporary file not found
    if (!file) {
        printf(" File not found!\n");
    }
    temp_file = fopen(temp, "w"); 
    if (!temp_file) {
        printf("Temporary file not found!\n");
        fclose(file);
    }
    printf("Which line you want to remove : ");
    scanf("%d", &num_line);
			
	//write all of lines in the original file to the temporary file except the removed line
    while (!feof(file)){
        strcpy(str, "\0");
        fgets(str, MAX, file);
        if (!feof(file)) {
            count++;
            if (count != num_line) {
                fprintf(temp_file, "%s", str);
            }
        }   
    }
    fclose(file);
    fclose(temp_file);

	//remove old file and rename new file to the same name with the previous one
    remove(filename);  		
    rename(temp, filename); 	
}