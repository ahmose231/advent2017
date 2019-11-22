#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINESIZE 128

struct protolist {
	int id;
	int refcount;
	int *refs;
};

struct protolist list[2000];

int checklist[2000];

int citings=0;

void delvedeeper(int k)
{
	checklist[k]=1;
	citings++;
	
	for(int i=0;i<list[k].refcount;i++)
		if(!checklist[list[k].refs[i]])
			delvedeeper(list[k].refs[i]);
	return;
}

int main()
{
	char line[LINESIZE];
	char *token;
	int k=0;
	
	int temp[10];
	int count;
	while(fgets(line,LINESIZE,stdin)!=NULL)
	{
		line[strlen(line)-1]='\0';
		token=strtok(line," ");
		
		list[k].id=atoi(token);
		token=strtok(NULL," "); 	// "<-->"
			
		count=0;
		token=strtok(NULL," ");
		while(token!=NULL)
		{
			temp[count++]=atoi(token);
			token=strtok(NULL," ");
		}
		
		list[k].refcount=count;
		list[k].refs=malloc(sizeof(int)*count);
		for(int i=0;i<count;i++)
			list[k].refs[i]=temp[i];
		
		k++;
	}
	
	for(int i=0;i<2000;i++)
		checklist[i]=0;
	int m=0;
	for(int i=0;i<2000;i++)
	{
		if(!checklist[i])
		{
			m++;
			delvedeeper(i);
		}
	}
	printf("\n%d\n",m);
	return 0;
}
