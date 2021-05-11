#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "sigmoid.h"
#include "helpers.h"
#include "neuron.h"
#include "file.h"

int main(int argc, char *argv[]){
    get_result();
    printf("PROGRAM CHECKING THE RGB VALUE IS RED OR NOT\n");
    int user_num;
	//loop the request for user input until they press 4 to quit
    while (user_num != 4){
        request();
        scanf("%d",&user_num);
        create_file();

		//switch for all the cases
        switch(user_num){

		//case 0 get the input value, pass through the analyze function
		//and return the output value depends on the results of our training 
		//and add them to a file if the file doesn't exist then create file and add. 
        case 0:
            append_file();
            break;

		//case 1 delete specific line in the file	
        case 1:
            show_content();
            delete_line();
            show_content();
            break;
		
		//remove all the content by "w"
        case 2:
            delete_file();
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