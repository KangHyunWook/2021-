/*
    DATE:2021-May-25
    TA: HYUN WOOK KANG
    Tutorial: Week8
    Description: This program shows an example of LinkedList
*/

#include <stdio.h>
#include <stdlib.h>

typedef int itemType;

typedef struct Node{
    itemType data; //data item
    struct Node* next; //pointer to the next item address
} Node;

Node *head=NULL;
Node *tail=NULL;

struct Node* createNode(int data) {
    Node *newNode=malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    
    return newNode;
}

void insert(itemType item) {
    //creates a new node
    Node *newNode=createNode(item);

    if(head==NULL) {
        head=newNode;
        tail=head;
    }
    else if(head==tail){
        tail=newNode;
        head->next=tail;
    }
    else {
        tail->next=newNode;
        tail=newNode;
    }
}

void print() {
    printf("Address\tItem\n");
    for(Node *temp=head; temp; temp=temp->next) {
        printf("%u\t%d\n",temp,temp->data);
    }
}

void delete(itemType data) {
    /*pointer to head*/
    Node* temp=head;
    
    /*node to store the location of 
    the target node to be deleted*/
    Node *parent; 
    while(temp!=NULL) {
        if(temp->data==data) {
            break;
        }
        parent=temp;
        temp=temp->next;
    }
    
    if(temp==head)
        head=head->next;
    else if(temp==tail) 
        tail=parent;
    else
        parent->next=temp->next;
}

int main() {
    printf("Linked List Example\n");
    insert(1);
    insert(3);
    insert(5);
    insert(7);
    insert(9);
    printf("====before delete====\n");
    print();
    delete(3);
    printf("====after delete====\n");
    print();
    
    return 0;

}








