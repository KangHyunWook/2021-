/*
Programmer: HYUN WOOK KANG
Description: union example
*/

#include <stdio.h>

union fruit{
	int banana;
	char apple;
	int orange;
};

main() {
	union fruit f;
	f.banana=7;
	f.apple=5;
	f.orange=130;
	
	printf("banana: %d\n", f.banana);
	printf("apple: %d\n", f.apple);
	printf("orange: %d\n", f.orange);
}












