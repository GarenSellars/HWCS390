#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
int main() 
{
char *PS1 = malloc(20); 
strcpy(PS1,"$"); 
while(true){
printf("%s",PS1); 
char input[6];
scanf("%s", input);  
	if(strcmp(input,"exit")==0) 
	{
	break; 
	}
	else if(strcmp(input,"echo")==0)
	{
	char echo; 
	while((echo=getchar())!='\n') 
		{
		putchar(echo);  
		}
	printf("\n"); 
	}
	else if(strcmp(input,"PS1")==0)
	{
	scanf("%s", PS1);   
	}
	else if(strcmp(input,"cat")==0)
	{
	FILE *file; 
	char name[20], i; 
	scanf("%s", name);
	file = fopen(name, "r"); 
		if (file == NULL) 
		{
		printf("File does not exist");
		break;   
		}
		while (i != EOF)
		{
		printf("%c", i);
		i = fgetc(file);
		}
	fclose(file);
	printf("\n");  
	}
	else if(strcmp(input,"cp") ==0) 
	{
	 FILE *file1, *file2;
	 char name1[20], i;
	file1 = fopen(name1, "r");
	if (file1==NULL)
	{
	printf("file does not exist"); 
	break; 
	}  
	 scanf("%s", file1); 
	file2 = fopen(name1, "w"); 
	if (file2 == NULL)
	{
	printf("file doesn not exist"); 
	break;
	}
	i= fgetc(file1); 
	while(i != EOF) 
	{
	fputc(i, file2); 
	i = fgetc(file1); 
	}
	fclose(file1); 
	fclose(file2); 
	} 
	else if(strcmp(input,"rm") == 0) 
	{
	int yeetfile; 
 	FILE *file3; 
	char name3[20];
	scanf("%s", file3); 
	file3 = fopen(name3, "w"); 
	fclose(file3); 
	yeetfile = remove(name3); 
	} 
	else if(strcmp(input,"mkdir")==0) 
	{
	char dirname[20];
	scanf("%s", dirname); 
	mkdir(dirname, 0777); 
	}
	else if(strcmp(input,"rmdir")==0)
	{
	char input[20];
	scanf("%s", input); 
	rmdir(input); 
	}
	else
	{
	printf("Usage:The proper commands are listed as:  \n echo- echo (text)  \n PS1- PS1 (text to change prompts display) \n cat- cat (filename)  \n cp- (cp filename1 filename 2) \n rm- rm (filename)  \n mkdir- mkdir (directory name) \n rmdir- rmdir (directory name)  \n exit - exit \n "); 
	} 
}
}
