/*
Date: 2021.Mar.16
Course: Data Structures
TA: HYUN WOOK KANG
Description: This program generates random numbers and prints them out 
			either in ascending or descending order upon the user's 
			request. For sorting, it takes advantage of generic sort by 
			receiving function pointer as an actual paramter. See sort 
			function in array.c
*/

#include <stdio.h>  
#include <stdlib.h>
#include <time.h>

#include "array.h"

int size; //variable to store the size of the array

/*Asks the user to enter a number. Upon receiving the
value, random numbers are generated as much as the 
given number and put into the formal parameter arr.
*/
int* genRand(); 

/*Performs the process described in the above description.*/
void process(); 

int main() {
	srand(time(NULL));
	process();
}

void process() 
{
	int *arr = genRand();
	
	printf("정렬 방법을 선택 1. 오름차순 2. 내림차순 3. 종료 : ");
	getchar();
	char choice = getchar();
	
	while(choice!=EOF) {
		
		switch(choice) {
		case '1':
			sort(arr, size, greater);
			break;
		case '2':
			sort(arr, size, smaller);
			break;		
		case '3':
			printf("프로그램을 종료합니다.");
			exit(0);
			break;
		default:
			fprintf(stderr, "no such choice");
			exit(1);
			break;	
		}
		printf("======정렬 후======\n");
		printArray(arr, size);
		arr= genRand(arr);
		printf("정렬 방법을 선택 1. 오름차순 2. 내림차순 3. 종료 : ");
		getchar();
		choice = getchar();	
	}
}

int* genRand()
{
	printf("정수의 갯수: ");
	scanf("%d", &size);
	int *arr = malloc(sizeof(int)*size);
    for(int i=0; i<size; i++) {
        arr[i] = rand()%100;
    }
	printf("======정렬 전======\n");
	printArray(arr, size);
	
	return arr;
}
