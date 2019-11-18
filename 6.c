#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACKSIZE 4

int m[STACKSIZE];

int index_of_max()
{
	int max=0;
	int maxindex;
	for(int i=0;i<STACKSIZE;i++)
		if(max<m[i])
		{
			max=m[i];
			maxindex=i;
		}
	return maxindex;
}
	
void distribute(int index)
{
	int value=m[index];
	m[index]=0;
	printf("distributing %d\n",value);
	for(int i=0;i<value;i++)
		m[(i+index+1)%STACKSIZE]++;
}

int compare()
{
	FILE *fp;
	fp=fopen("data6.txt","r");
	char line[128];
	int n[STACKSIZE];
	char *token;
	int k=0;
	while(fgets(line,128,fp)!=NULL)
	{
		token=strtok(line," ");
		while(token!=NULL)
		{
			n[k++]=atoi(token);
			token=strtok(NULL," ");
		}
		for(int i=0;i<STACKSIZE;i++)
			if(m[i]!=n[i])
			{
				fclose(fp);
				return 1;
			}
	}
	fclose(fp);
	
	fopen("data6.txt","a");
	for(int i=0;i<STACKSIZE-1;i++)
		fprintf(fp,"%d ",m[i]);
	fprintf(fp,"%d\n",m[STACKSIZE-1]);
	fclose(fp);
	
	return 0;
}

int main(int argc, char *argv[])
{
	if(argc!=2)
		return 0;
	
	FILE *fp;
	fp=fopen(argv[1],"r");
	
	for(int i=0;i<STACKSIZE;i++)
		fscanf(fp,"%d",&m[i]);
	fclose(fp);
	
	int count=0;
	while(!compare())
	{
		distribute(index_of_max());
		count++;
	}
	
	printf("%d\n",count);
	return 0;
}
