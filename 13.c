#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LISTLEN 89
#define LINESIZE 16

int main()
{
	int m[LISTLEN];
	for(int i=0;i<LISTLEN;i++)
		m[i]=0;
	char line[LINESIZE];
	char *token;
	int a,b;
	while(fgets(line,LINESIZE,stdin)!=NULL)
	{
		token=strtok(line," ");
		a=atoi(token);
		token=strtok(NULL," ");
		b=atoi(token);
		m[a]=b;

	}

	int sum=0;
	for(int i=0;i<LISTLEN;i++)
		if(m[i])
			if(i%((m[i]*2)-2)==0)
				sum=sum+(i*m[i]);
	
	printf("%d\n",sum);
	
	return 0;
}
