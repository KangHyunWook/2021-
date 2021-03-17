#include "array.h"

int greater(int x, int y) {
	if(x>y) return TRUE;
	return FALSE;
}

int smaller(int x, int y) {
	if(x<y) return TRUE;
	return FALSE;
}

void printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sort(int arr[], int size, int (*fp)()) {
	for(int i=0; i<size-1; i++) {
		for (int j=i+1; j<size; j++) {
			if((*fp)(arr[i], arr[j])>0) { //generic sort
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			} 
		} 	
	}	
}