/*
Date: 2021-Aprl-4
Course: Data Structures, Tutorial
TA: HYUN WOOK KANG
Description: This program shows an example how to save the memory
			by taking advantage of union.

*/

#include <stdio.h>  
#include <stdlib.h>
                    
#define TRUE 1      
#define FALSE 0     

typedef enum {MALE =1, FEMALE} SEX_TYPE;

struct HumanBeing { 
    char name[30];
    short int age;
    
    SEX_TYPE sex;
    
	struct {
		int beard;
	} male;
	
	struct {
		int pregnant;
		int children;
	} female;

};

void enter(struct HumanBeing *human);

void printHumanInfo(struct HumanBeing human, SEX_TYPE sex);

int main(argc, argv)
int argc;
char *argv[];
{
    struct HumanBeing human;
    printf("1. male 2. female : ");
    SEX_TYPE sex;
    scanf("%d", &sex);
    switch(sex) {
    case MALE:
        enter(&human);
        printf("Does he have beard? 1. yes 2. no : ");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
        case 1:
            human.male.beard=TRUE;
            break;
        case 2:
            human.male.beard=FALSE;
            break;
        default:
            printf("Wrong choice!\n");
            exit(EXIT_FAILURE);
            break;
        }
        break;
    case FEMALE:
        enter(&human);
        printf("Is she pregnant? 1. yes 2. no : ");
        scanf("%d", &choice);
        switch(choice) {
        case 1:
            human.female.pregnant = TRUE;
            break;
        case 2:
            human.female.pregnant = FALSE;
            break;
        default:
            break;
        }
        printf("How many children? ");
        scanf("%d", &human.female.children);
            
        break;
    default: 
		fprintf(stderr, "%s", "Wrong choice, program exits!\n");
		exit(EXIT_FAILURE);
        break;
    }

    printHumanInfo(human, sex);
}

void enter(human)
struct HumanBeing *human;
{
    printf("Enter name: ");
    scanf("%s", human->name);
    printf("Enter age: ");
    scanf("%d", &human->age);
}

void printHumanInfo(human, sex)
struct HumanBeing human;
SEX_TYPE sex;
{
    printf("\n===========Human Info===========\n");
    printf("Name: %s\n", human.name);
    printf("Age: %hd\n", human.age);
    if(sex==MALE) {
        if(human.male.beard==TRUE) {
            printf("He has beard\n");
        }
        else printf("He has no beard\n");
    }
    else if(sex==FEMALE) {
        if(human.female.pregnant == TRUE) 
            printf("She is pregnant.\n");
        else 
            printf("She is not pregnant.\n");
        printf("She has given birth to %d children",
            human.female.children);
    
    }
}
