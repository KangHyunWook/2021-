/*
	Date: 2021-Apr-12
	Course: Data Structures
	Tutorial: Week5
	TA: HYUN WOOK KANG
	Description: This program implements KMP algorithm.
*/

#include <stdio.h>
#include <string.h>
	
int main() {
	char *txt="AAAABACAABABA";
	char* pat="AABA";
	int M=strlen(pat);
	int lps[M];
	lps[0] = 0;
	int len=0;
	for(int i=1; i<M;) {
		if(pat[i]==pat[len]) {
			lps[i]=++len;
			i++;
		}
		else {
			if(len==0) {
				lps[i]=0;
				i++;
			}
			else {
				len = lps[len-1];
			}
		}
	}
	
	printf("lps table: \n");
	for(int i=0; i<M; i++) {
		printf("%d ", lps[i]);
	}
	printf("\n");
	
	//kmp algorithm
	int i=0;
	int j=0;
	while(i<strlen(txt)) {
		if(pat[j]==txt[i]) {
			i++;
			j++;
		}
		
		if(M==j) {
			printf("Pattern found at index %d\n", i-j);
			j=lps[j-1];
		}
		
		if(pat[j]!=txt[i]) {
			if(j!=0) {
				j=lps[j-1];
			}
			else {
				i++;
			}
		}
	}	
	
	return 0;
}	