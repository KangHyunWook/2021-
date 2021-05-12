#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 10
#define true 1
#define false 0
typedef int bool;

int stack[MAX_SIZE];

int top=-1;

bool isFull() {
	if((top+1)==MAX_SIZE) {
		return true;
	}	
	return false;
}		

bool isEmpty() {
	if(top==-1)
		return true;
	return false;
}

void add(int data) {
	if(isFull()) {
		fprintf(stderr, "%s", "Stack is full!\n\
Program exits");
		exit(EXIT_FAILURE);
	}
	stack[++top]=data;
	printf("data %d successfully added to the stack!\n", data);
}

int pop() {
	if(isEmpty()) {
	
		fprintf(stderr, "%s", "Stack is empty!\n\
Program exits");
		exit(EXIT_FAILURE);
	}
	return stack[top--];
}




#endif