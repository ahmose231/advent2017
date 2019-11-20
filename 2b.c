#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINESIZE 512

int main()
{
	char *line;
	line=malloc(sizeof(char)*LINESIZE);
	char *token;
	
	int cols=0;
	int rows=0;
	int m[16][16];
	
	while(fgets(line,LINESIZE,stdin)!=NULL)
	{
		token=strtok(line,"\t");
		while(token!=NULL)
		{
			m[rows][cols]=atoi(token);
			cols++;
			token=strtok(NULL,"\t");
		}
		cols=0;
		rows++;
	}
	int r[16];
	int rr=0;
	int flag;
	for(int i=0;i<16;i++)
	{
		flag=0;
		for(int j=0;j<16-1;j++)
		{
			for(int k=j+1;k<16;k++)
			{
				if(m[i][j]>m[i][k])
				{
					if(m[i][j]%m[i][k]==0)
					{
						r[rr++]=m[i][j]/m[i][k];
						flag=1;
						break;
					}
				}	
				else
				{
					if(m[i][k]%m[i][j]==0)
					{
						r[rr++]=m[i][k]/m[i][j];					
						flag=1;
						break;
					}
				}				
			}	
			if(flag) break;			
		}
	}
	int sum=0;
	for(int i=0;i<16;i++)
		sum=sum+r[i];
	printf("%d\n",sum);
	return 0;
}
