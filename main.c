/*
	Date: 2021-Apr-8
	TA: HYUN WOOK KANG
	Course: Data Structures
	Tutorial: Week6
	Description: This program shows an example of stack implementation.
				The input is provided from the text file.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main() {
	char line[100];
	size_t len=0;
	FILE *fp = fopen("stackInput.txt", "r");
	size_t num=0;
	char cmd[10];
	while(fscanf(fp, "%s", line)!=-1) {
				
		char *token = strtok(line, ":");
		if(!strcmp(token, "add")) {
			strcpy(cmd, "add"); 		
		}		
		else if(!strcmp(token, "pop")) {
			strcpy(cmd, "pop");
		}
		else {	
			token = strtok(line, ",");
			int data = atoi(token);
			if(!strcmp(cmd, "add")) {
				add(data);
			}
			else if(!strcmp(cmd, "pop")) {
				for(int i=0; i<data; i++)
					printf("popped: %d\n", pop());
			}	
		}		
	}
	return 0;
}