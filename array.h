#ifndef ARRAY_H
#define ARRAY_H
#include <stdio.h>
#define TRUE 1
#define FALSE 0

/*returns true if x is greater than y */
int greater(int x, int y);
/*returns true if x is smaller than y */
int smaller(int x, int y);
/*prints out the elements in arr*/
void printArray(int arr[], int size);
/*Implements generic sort depending on the 
value of the formal parameter of (*fp)() that 
is the function given as an actual parameter*/
void sort(int arr[], int size, int (*fp)());

#endif