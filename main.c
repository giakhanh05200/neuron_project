#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "sigmoid.h"
#include "helpers.h"
#include "neuron.h"

#include <string.h>
//define Max   
#define MAX 256
//show content function that print the content of the file

void show_content(){
    FILE *file; 
    char *filename = "myfile.txt";
    char c;
    file = fopen(filename, "r");
    printf("File's content %s\n", filename);
    while ((c = fgetc(file) )!= EOF){
        printf ("%c", c);
    }
    fclose(file); 
}

int main(int argc, char *argv[]){
    get_result();
    printf("PROGRAM CHECKING THE RGB VALUE IS RED OR NOT\n");
    int user_num,r,g,b,line;
    FILE *file; 
    char *filename = "myfile.txt";
    char c,content[1000];
    double results, test[3];

	//loop the request for user input until they press 4 to quit
    while (user_num != 4){
        printf("Please choose a number from 0 to 4: \n");
        printf("0: Add to file\n");
        printf("1: Delete specific line\n");
        printf("2: Delete the whole file\n");
        printf("3: Show File's content\n");
        printf("4: Quit!\n");
        scanf("%d",&user_num);

        file = fopen(filename, "a+");
        fclose(file);
		//switch for all the cases
        switch(user_num){

		//case 0 get the input value, pass through the analyze function
		//and return the output value depends on the results of our training 
		//and add them to a file if the file doesn't exist then create file and add. 
        case 0:
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
            break;

		//case 1 delete specific line in the file	
        case 1:
            show_content();
            int num_line, count = 0;
            FILE *temp_file;
            char str[MAX], temp[] = "temporary.txt";
            file = fopen(filename, "r");

			//error when file or temporary file not found
            if (!file) {
                    printf(" File not found!\n");
                    return 0;
            }
            temp_file = fopen(temp, "w"); 
            if (!temp_file) {
                    printf("Temporary file not found!\n");
                    fclose(file);
                    return 0;
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
            show_content();
            break;
		
		//remove all the content by "w"
        case 2:
            file = fopen(filename, "w");
            printf("My file is empty now!\n");
            break;
		
		//show content of the file
        case 3:
            show_content();
            break;

		//break and show content of the file
        case 4:
            show_content();
            break;
        default:
            printf("The number is incorrect\n");
            break;
        }
    }
    return 0;
}