#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINESIZE 512

int main()
{
	char *line;
	line=malloc(sizeof(char)*LINESIZE);
	char *token;
	int k;
	int min,max;
	int sum=0;
	while(fgets(line,LINESIZE,stdin)!=NULL)
	{
		min=100000;
		max=0;
		token=strtok(line,"\t");
		while(token!=NULL)
		{
			k=atoi(token);
			if(k>max)
				max=k;
			if(k<min)
				min=k;
			token=strtok(NULL,"\t");
		}
		sum=sum+max-min;
	}
	
	printf("%d\n",sum);
	return 0;
}
