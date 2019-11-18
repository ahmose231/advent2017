#include <stdio.h>
#include <string.h>

#define LINESIZE 256

struct proto_disc {
	char name[10];
	int size;
	int ref_count;
	char references[10][10];
};

int ref_size(char *name, struct proto_disc *disc, int total_lines)
{
	for(int i=0;i<total_lines;i++)
		if(strcmp(name, disc[i].name)==0)
			return disc[i].size;
}

int downthehole(char *name, struct proto_disc *disc, int total_lines)
{
	int sum=0;
	int i;
	for(i=0;i<total_lines;i++)
		if(strcmp(name, disc[i].name)==0)
		{
			if(disc[i].ref_count==0)
				return disc[i].size;
			int m[disc[i].ref_count];
			for(int j=0;j<disc[i].ref_count;j++)
			{
				m[j]=downthehole(disc[i].references[j],&disc[0],total_lines);
				sum = sum + m[j];
			}
			for(int j=0;j<disc[i].ref_count-1;j++)
				if(m[j]!=m[j+1])
				{ub
					for(int k=0;k<disc[i].ref_count;k++)
						printf("[%d - %d]",m[k],ref_size(disc[i].references[k],&disc[0],total_lines));
					printf("\n");
					
					break;
				}
			break;
		}
	
	return sum+disc[i].size;
}

int main(int argc, char *argv[])
{
	if(argc!=2) return 0;
	FILE *fp;
	fp=fopen(argv[1],"r");
	char line[LINESIZE];
	int total_lines=0;
	while(fgets(line,LINESIZE,fp)!=NULL)
		total_lines++;
	

	struct proto_disc disc[total_lines];
	
	rewind(fp);
	char *token;
	int k=0;

	while(fgets(line,LINESIZE,fp)!=NULL)
	{
		token=strtok(line," ");
		strcpy(disc[k].name, token);

		token=strtok(NULL," ");
		sscanf(token,"(%d)", &disc[k].size);

		token=strtok(NULL," ");
		if(token==NULL)
			disc[k].ref_count=0;
		else
		{

			token=strtok(NULL," ");
			int ref_count=0;
			while(token!=NULL)
			{
				strcpy(disc[k].references[ref_count], token);
				disc[k].references[ref_count][strlen(disc[k].references[ref_count])-1]='\0';

				ref_count++;
				token=strtok(NULL," ");
			}			
			disc[k].ref_count=ref_count;
		}
		k++;
	}
	fclose(fp);
	
	int checklist[total_lines];
	for(int i=0;i<total_lines;i++)
		checklist[i]=1;

	for(int i=0;i<total_lines;i++)
		if(disc[i].ref_count)
			for(int j=0;j<total_lines;j++)
				if(checklist[j])
					for(int h=0;h<disc[i].ref_count;h++)
						if(strcmp(disc[j].name, disc[i].references[h])==0)
							checklist[j]=0;

	for(int i=0;i<total_lines;i++)
	{
		if(checklist[i])
		{
			printf("%s\n",disc[i].name);
			downthehole(disc[i].name,&disc[0],total_lines);
			return 0;
		}
	}

	return 0;
}

