/*
Programmer: HYUN WOOK KANG
Description: union example
*/

#include <stdio.h>

#define BANANA 7
#define APPLE 5
#define ORANGE 130

struct StructFruit {
	int banana;
	char apple;
	int orange;
};

union UnionFruit { 
	int banana;
	char apple;
	int orange;
};

main() {
	struct StructFruit structFruit;
	union UnionFruit unionFruit;
	
	printf("==========Struct Fruit==========\n");
	structFruit.banana=7; 
	structFruit.apple=3; 
	structFruit.orange=130; 
	printf("banana: %d\n", structFruit.banana);		
	printf("apple: %d\n", structFruit.apple);		
	printf("orange: %d\n", structFruit.orange);
	
	printf("==========Union Fruit==========\n");	
	unionFruit.banana=7;
	unionFruit.apple=3; 
	unionFruit.orange=130; 

	printf("banana: %d\n", unionFruit.banana);		
	printf("apple: %d\n", unionFruit.apple);		
	printf("orange: %d\n", unionFruit.orange);		
}












