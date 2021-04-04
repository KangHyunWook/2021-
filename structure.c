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

struct male_struc {
	char name[30];
    short int age;
	
	int beard;
};


struct female_struc{
	char name[30];
    short int age;
	
	int pregnant;
	int children;
};

void printHumanInfo(struct male_struc, struct female_struc, SEX_TYPE sex);

int main(argc, argv)
int argc;
char *argv[];
{
	struct male_struc male; //male definition
	struct female_struc female; //female definition
	
    printf("1. male 2. female : ");
    SEX_TYPE sex;
    scanf("%d", &sex);
    switch(sex) {
    case MALE:
        printf("Enter name: ");
		scanf("%s", &male.name);
		printf("Enter age: ");
		scanf("%d", &male.age);
        printf("Does he have beard? 1. yes 2. no : ");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
        case 1:
            male.beard=TRUE;
            break;
        case 2:
            male.beard=FALSE;
            break;
        default:
            printf("Wrong choice!\n");
            exit(EXIT_FAILURE);
            break;
        }
        break;
    case FEMALE:
        printf("Enter name: ");
		scanf("%s", &female.name);
		printf("Enter age: ");
		scanf("%d", &female.age);
        printf("Is she pregnant? 1. yes 2. no : ");
        scanf("%d", &choice);
        switch(choice) {
        case 1:
            female.pregnant = TRUE;
            break;
        case 2:
            female.pregnant = FALSE;
            break;
        default:
            break;
        }
        printf("How many children? ");
        scanf("%d", female.children);
            
        break;
    default: 
		fprintf(stderr, "%s", "Wrong choice, program exits!\n");
		exit(EXIT_FAILURE);
        break;
    }

    printHumanInfo(male, female, sex);
}

void printHumanInfo(male, female, sex)
struct male_struc male;
struct female_struc female;
SEX_TYPE sex;
{
    printf("\n===========Human Info===========\n");
    
    if(sex==MALE) {
		printf("Name: %s\n", male.name);
		printf("Age: %hd\n", male.age);
		
        if(male.beard==TRUE) {
            printf("He has beard\n");
        }
        else printf("He has no beard\n");
    }
    else if(sex==FEMALE) {
		printf("Name: %s\n", female.name);
		printf("Age: %hd\n", female.age);
		
        if(female.pregnant == TRUE) 
            printf("She is pregnant.\n");
        else 
            printf("She is not pregnant.\n");
        printf("She has given birth to %d children",
            female.children);
    
    }
}







