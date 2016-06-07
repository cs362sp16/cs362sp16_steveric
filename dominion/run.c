#include <stdio.h>
#include <string.h>

int main (int argc, char** argv) {
	
	// Seed system with input
	
	printf("%s",argv[1]);
	printf("%s",argv[2]);

   char command[500];
   
	char domcfile1[500];
	strcpy(domcfile1,argv[1]);
	strcat(domcfile1,"/dominion.c");
	char domhfile1[500];
	strcpy(domhfile1,argv[1]);
	strcat(domhfile1,"/dominion.h");
   
   
   
	char domcfile2[500];
	strcpy(domcfile2,argv[2]);
	strcat(domcfile2,"/dominion.c");
	char domhfile2[500];
	strcpy(domhfile2,argv[2]);
	strcat(domhfile2,"/dominion.c");


	
	
	strcpy(command, "gcc ");
	strcat(command, argv[1]);
	strcat(command,"/testdominion.c ");
	strcat(command,argv[1]);
	strcat(command,"/dominion.c ");
	strcat(command,argv[1]);
	strcat(command,"/dominion.h ");
	strcat(command,argv[1]);
	strcat(command,"/rngs.c ");
	strcat(command,argv[1]);
	strcat(command,"/rngs.h ");
	strcat(command,argv[1]);
	strcat(command,"/interface.c ");
	strcat(command,argv[1]);
	strcat(command,"/interface.h -o playdom21");
	system(command);
	printf("\n%s\n",command);


	
	strcpy(command, "gcc ");
	strcat(command, argv[2]);
	strcat(command,"/testdominion.c ");
	strcat(command,argv[2]);
	strcat(command,"/dominion.c ");
	strcat(command,argv[2]);
	strcat(command,"/dominion.h ");
	strcat(command,argv[2]);
	strcat(command,"/rngs.c ");
	strcat(command,argv[2]);
	strcat(command,"/rngs.h ");
	strcat(command,argv[2]);
	strcat(command,"/interface.c ");
	strcat(command,argv[2]);
	strcat(command,"/interface.h -o playdom22");
	system(command);
	printf("\n%s\n",command);

	system("cmd /c playdom21 42 > testtext1.txt");
	system("cmd /c playdom22 42 > testtext2.txt");
	
	FILE *fp1, *fp2;
	fp1 = fopen("testtext1.txt", "r");
	fp2 = fopen("testtext2.txt", "r");
	
    int  ch1 = getc(fp1);
    int  ch2 = getc(fp2);

      while ((ch1 != EOF) && (ch2 != EOF) && (ch1 == ch2)) {
         ch1 = getc(fp1);
         ch2 = getc(fp2);
      }

      if (ch1 == ch2){printf("\nPASS: Files are identical\n");}
      else if (ch1 != ch2){
        printf("\nFAIL: Files are Not identical /n Creating a diff file 'difffile.txt' \n");
		system("cmd /c diff testtext1.txt testtext2.txt > difffile.txt");
	  }
      fclose(fp1);
      fclose(fp2);
	  

	
	
	
	
	

		
	
   return(0);
} 
