#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>



int main(){

	FILE *f = fopen("dominion.c.gcov", "rb");
	fseek(f, 0, SEEK_END);
	long fsize = ftell(f);
	fseek(f, 0, SEEK_SET);  //same as rewind(f);

	char *string = malloc(fsize + 1);
	fread(string, fsize, 1, f);
	fclose(f);

	string[fsize] = 0;
	
	
	int newLineChars = 0;
	/////////////////////////////////////
	//cleanup string
	char *clean = malloc(fsize + 1);
		long k=0;
	for(long i=0; string[i]!=0; i++){
		if(string[i]=='\n'){
			newLineChars++;
			for(long j = i; j<(i+16); j++){
				clean[k]=string[j];
				k++;
			//	printf("%d\n",k);
			}	
		}
		else{;}		
	}
	/////////////////////////////////////
	int taray[newLineChars+1];
	for(int m=0; m<(newLineChars+1); m++){taray[m]=0;}
	for(int i = 0; i < strlen(clean); i++){
		
		if(clean[i]==':'){
			printf("\nMade it into Clean");
			if(isdigit(clean[i-1])){
				
				char line[5];
				line[0] = clean[i+1];
				line[1] = clean[i+2];
				line[2] = clean[i+3];
				line[3] = clean[i+4];
				line[4] = clean[i+5];
				const char *linPtr = line;
				
				int lineNum = atoi(linPtr);
				printf("\n %d", lineNum);
				taray[lineNum]++;
				
			}
		}
		
		
		
	}
		
	
	
	
	
	//printf("%s",clean);
	
	printf("Size of clean is %d", strlen(clean));
	
	for(int i=0; i<=newLineChars; i++ ){
		printf("Line: %d  Instances: %d\n", i, taray[i]);

	}
}