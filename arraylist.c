/*
    DATE:2021-May-25
    TA: HYUN WOOK KANG
    Tutorial: Week8
    Description: This program shows an example of ArrayList
*/

#include <stdio.h>
#define MAX_SIZE 5

typedef int itemType;

itemType arr[MAX_SIZE]; //array declaration

void delete(itemType data) {
    int index=0; //index at which the target element exists
    
    for( ; index<MAX_SIZE; ) {
        if(arr[index]==data) //data to be deleted is found
            break;
        index++;
    }
    
    /*data movements are occurred to preserve 
    sequential mapping */
    int i=index;
    for(; i<MAX_SIZE; i++) {
        arr[i]=arr[i+1]; 
    }
    arr[i-1]=0;
}

int main() {
    //insert elements to array
    for(int i=0; i<5; i++) {
        arr[i]=2*i+1;
    }
    
    printf("====Array Example====\n");
    printf("====Before delete====\n");
    printf("Address\titem\n");
    for(int i=0; i<5; i++) {
        printf("%u\t%d\n", &arr[i], arr[i]);
    }
    delete(3); //delete 3
    printf("====After delete====\n");
    printf("Address\titem\n");
    for(int i=0; i<5; i++) {
        printf("%u\t%d\n", &arr[i], arr[i]);
    }
        
}