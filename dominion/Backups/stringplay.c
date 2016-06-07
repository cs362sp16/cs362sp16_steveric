#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

int main()
{
int number1 = '0';
int number9 = '9';
printf("\n\nNumber 1 = %d\n",number1);
printf("\nNumber 9 = %d\n",number9);
   
char randStr[10];
for(int i=0; i<10; i++){
	randStr[i]=(rand()%10+48);
	if(i==9){randStr[i]='\0';}
	
	
}
   
printf("\n\nString: %s\n\n",randStr);   
   
   return(0);
}