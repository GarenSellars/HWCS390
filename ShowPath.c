#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int printStrings(const char* args[]);
int main() 
{
int argc;  
int index=0; 
const char*  argv[100];
char* path = getenv("PATH");
char *pToken=strtok(path,":");
while(pToken!= NULL)
	{
	argv[index] =  pToken;  
	pToken = strtok(NULL, ";"); 
	index++; 
	}

printStrings(argv);
return 0; 
}

int printStrings(const char* args[]) 
{
int index2=0;
while(args[index2]!='0')
	{
	printf("%s\n", args[index2]);
	index2++; 
	}		
return 0; 
}
