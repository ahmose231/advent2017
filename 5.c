#include <stdio.h>
#include <stdlib.h>
#define LINESIZE 16
int main(int argc, char *argv[])
{
	if(argc!=2)
		return 0;
	FILE *fp;
	fp=fopen(argv[1],"r");
	int linecount=0;
	char line[LINESIZE];
	while(fgets(line,LINESIZE,fp)!=NULL)
		linecount++;
	rewind(fp);
	int stack[linecount];
	int k=0;
	while(fgets(line,LINESIZE,fp)!=NULL)
		stack[k++]=atoi(line);
	fclose(fp);
	
	k=0;
	int whereto;
	int count=0;
	while(k>=0 && k<linecount)
	{
		whereto=stack[k];
		if(whereto>=3) stack[k]--;
		else stack[k]++;
		k=k+whereto;
		count++;
	}
	printf("%d\n",count);
	return 0;
}
