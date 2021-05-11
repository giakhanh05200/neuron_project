#include "helpers.h"
#include <stdio.h>
double dot(double *v, double *u, uint32_t n){
	
	double result = 0.0;
	for(uint32_t i = 0; i < n; i++){
		result += v[i] * u[i];
	}

	return result;
}
void request(void){
	printf("Please choose a number from 0 to 4: \n");
    printf("0: Add to file\n");
    printf("1: Delete specific line\n");
    printf("2: Delete the whole file\n");
    printf("3: Show File's content\n");
    printf("4: Quit!\n");
}
