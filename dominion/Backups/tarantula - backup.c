#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_TESTS 10

//FUNCTIONS
void taran(int *taray);

int main(){

   char command[500];

	// GENERATE INITAL GCOV FILE //
	strcpy(command, "make testdom");
	system(command);
	////////////////////////////////////


	// GENERATING PASS FAIL ARRAY //
	FILE *f = fopen("dominion.c.gcov", "rb");
	fseek(f, 0, SEEK_END);
	long fsize = ftell(f);
	fseek(f, 0, SEEK_SET);  //same as rewind(f);
	char *string = malloc(fsize + 1);
	fread(string, fsize, 1, f);
	fclose(f);
	string[fsize] = 0;
	int newLineChars = 0;
	for(int i=0; i<fsize; i++){if(string[i]=='\n'){newLineChars++;}}
	int passFailArray[newLineChars+1][2];	
	for(int n = 0; n<2; n++){	
		for(int m=0; m<(newLineChars+1); m++){passFailArray[m][n]=0;}
	}
	printf("\n\nNewLines: %d \n\n", newLineChars);
	////////////////////////////////////
	
	// LOOP FOR TESTING MANY TIMES //
	int totalPasses=1;
	int totalFails=1;
	for(int tsts = 0; tsts<MAX_TESTS; tsts++){
		//Recompile with coverage
		//strcpy(command,"rm dominion.c.gcov");
		//system(command);
		strcpy(command, "gcc -fprofile-arcs -ftest-coverage testdominion.c -g  dominion.o rngs.o interface.o $(CFLAGS)");
		system(command);
		//generate and execute command
		strcpy(command, "./a ");
		char randStr[10];
		for(int i=0; i<10; i++){
			randStr[i]=(rand()%10+48);
			if(i==9){randStr[i]='\0';}	
		}
		strcat(command,randStr);
		int xxx = system(command);
		
		// decide whether the test was passed or failed
		int passed;
		if(xxx){passed=1;}
		else{passed=0;}
		int taray[newLineChars]; //Declaration of taray
		for(int i=0; i<newLineChars+1; i++){taray[i]=0;}
		char *tarPtr = &taray;
		taran(tarPtr);
		printf("\n\n\nX is : %d \n\n\n",xxx);
		
		for(int i=0; i<newLineChars+1; i++){
		//	printf("\nline: %d Hit: %d ",i,taray[i]);
		}
		//printf("\n%d\n",sizeof(passFailArray));
		printf("\n\nPassorfail: %d\n\n",xxx);
		
		// GENERATE PASS/FAIL ARRAY
		
		
		if(xxx){				
			totalPasses++;
			for(int i=0; i<newLineChars; i++){
				passFailArray[i][1]=passFailArray[i][1]+taray[i];
			}
		}	
		else{
			totalFails++;
			for(int i=0; i<newLineChars; i++){
				passFailArray[i][0]=passFailArray[i][0]+taray[i];
			}
		}
	}
	
	
	////////////////////////////////////

	// GENERATE SUSPICIOUSNESS ARRAY //

	int passes_e;
	int fails_e;
	float suspiciousnessArray[newLineChars];

	printf("\nTotalPasses: %d  TotalFails: %d", totalPasses, totalFails);
	
	
	for(int i=0; i<newLineChars; i++){
		passes_e = passFailArray[i][1];
		fails_e = passFailArray[i][0];
		


		
		if(passes_e==0 && fails_e==0){suspiciousnessArray[i]=999;}
		else{
			float failfrac=(float)fails_e/totalFails;
			float passfrac=(float)passes_e/totalPasses;
			float bottom = failfrac+passfrac;
			printf("\n\nPF epass %d   efails %d \n\n",passes_e,fails_e );
			printf("\n\nTPF passes: %d  fails %d \n\n",totalPasses,totalFails);
			printf("\n\nPassFrac %f  FailFrac %f \n\n",passfrac,failfrac);
			printf("\n\nFrac %f / %f \n\n",failfrac,bottom );
			suspiciousnessArray[i]=failfrac/bottom;;

		}

		
		//printf("\n\nFrac %d / %d \n\n",failfrac,bottom );
		//suspiciousnessArray[i]=failfrac/bottom;
		
		//suspiciousnessArray[i]=((fails_e/totalFails)/((fails_e/totalFails)+(passes_e/totalPasses)));
	}

	for(int i=0; i<newLineChars; i++){
		if(suspiciousnessArray[i]<10){printf("\n Line: %d   Suspiciousness: %f",i,suspiciousnessArray[i]);}
		else{printf("\n Line: %d   Suspiciousness: No Coverage Data",i);}
	}
	
	

}



void taran(int *taray){

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
	//int taray[newLineChars+1];
	//for(int m=0; m<(newLineChars+1); m++){taray[m]=0;}
	for(int i = 0; i < strlen(clean); i++){
		
		if(clean[i]==':'){
		//	printf("\nMade it into Clean");
			if(isdigit(clean[i-1])){
				
				char line[5];
				line[0] = clean[i+1];
				line[1] = clean[i+2];
				line[2] = clean[i+3];
				line[3] = clean[i+4];
				line[4] = clean[i+5];
				const char *linPtr = line;
				
				int lineNum = atoi(linPtr);
				//printf("\n %d", lineNum);
				taray[lineNum]++;
				
			}
		}	
	}
	//for(int z=0;z<newLineChars+1;z++){	
	//	*taray1[z]=taray[z];
	//}
	//printf("%s",clean);
	
	//printf("Size of clean is %d", strlen(clean));
	
	for(int i=0; i<=newLineChars; i++ ){
		//printf("Line: %d  Instances: %d\n", i, taray[i]);
	
	}
}