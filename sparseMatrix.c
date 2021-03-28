/*
	Date: 2021-Mar-28
	TA: HYUN WOOK KANG
	Course: Data Structures, tutorial
	Description: This program shows an example of the inner product 
				of two sparse matrices.
*/

#include <stdio.h>		
#include <stdlib.h>
#define MAX_TERMS 101	
	
#define COMPARE(a, b) a>b?1:((a==b)?0:-1)

typedef struct {	
	int row;		
	int col;		
	int value;		
} term;				

term a[MAX_TERMS];
term b[MAX_TERMS];
term d[MAX_TERMS];

void printSparseMatrix(term a[]);							
void transpose(term a[], term b[]);
void mmult(term a[], term b[], term d[]);

void storesum(term a[], int* totald, int row, int column, int* sum) {
	if (*sum) {
		if (*totald < MAX_TERMS) {
			d[++*totald].row = row;
			d[*totald].col = column;
			d[*totald].value = *sum;
			*sum = 0;
		}
	}	
}		

void mmult(term a[], term b[], term d[]) {		
	int totald = 0;
	
	term new_b[MAX_TERMS+1];
	
	transpose(b, new_b); //new_b is the transposed matrix of b
	
	a[a[0].value + 1].row = a[0].row;			
	new_b[new_b[0].value + 1].row = b[0].col;		
	int row = a[1].row;					
	int row_begin = 1, sum = 0;			
	
	for (int i = 1; i <= a[0].value; ) {
		int column = 0;
		//fill in here
				
		row_begin = i;
		row = a[i].row;
	}			
	d[0].row = a[0].row;
	d[0].col = b[0].col;
	d[0].value = totald;
}				
	
int main() {
	//Initialisation of Sparse Matrix A
	a[0].row=3;	a[0].col=3; a[0].value = 6;	
	a[1].row=0, a[1].col=1, a[1].value = 1;	
	a[2].row=0, a[2].col=2, a[2].value =2;	
	a[3].row=1, a[3].col=0, a[3].value =1;	
	a[4].row=1, a[4].col=1, a[4].value =2;	
	a[5].row=2, a[5].col=1, a[5].value =1;	
	a[6].row=2, a[6].col=2, a[6].value =1;	
	
	//Initialisation of Sparse Matrix B
	b[0].row = 3, b[0].col = 3, b[0].value=4;	
	b[1].row=0, b[1].col=0, b[1].value=1;
	b[2].row=0, b[2].col=1, b[2].value=3;
	b[3].row=1, b[3].col=0, b[3].value=2;
	b[4].row=1, b[4].col=2, b[4].value=7;
	
	printSparseMatrix(a);
	
	// transpose(a, );
	printf("======b======\n");
	printSparseMatrix(b);
	
	mmult(a, b, d);
	printf("======d======\n");
	
	printSparseMatrix(d);
}	

void transpose(a, b)	
term a[], b[];			
{
	int currentb=0;
	b[currentb].col = a[0].row;
	b[currentb].row = a[0].col;
	b[currentb].value = a[0].value;
	for (int i=0; i<=a[0].col; i++) {
		for(int j=1; j<=a[0].value; j++) {			
			if(i==a[j].col) {						
				b[++currentb].row = a[j].col;		
				b[currentb].col = a[j].row;			
				b[currentb].value = a[j].value;		
			}
		}
	}	
}		
		
void printSparseMatrix(a)
term a[];
{
	for (int i=0; i<a[0].row; i++) {
		for(int j=0; j<a[0].col; j++) {
			int flag=0;
			for(int k=0; k<=a[0].value; k++) {
				if(a[k].row==i && a[k].col == j) { 
					flag=1;
					printf("%3d ", a[k].value);
				}
			}
			if(!flag)
				printf("%3d ", 0);	
		}
		printf("\n");
	}
}
