#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define LINES 1000
#define LEN 64

int p[LINES][3];
int v[LINES][3];
int a[LINES][3];

int main(void) {
	char word[8];
	int k, c;
	char line[LEN];
	for(int i=0;i<LINES;i++)
	{
		fgets(line,LEN,stdin);
		k=0;
		
		while(line[k]!='<')
			k++;
		
		k++;
		c=0;
		while(line[k]!=',')
			word[c++]=line[k++];
		word[c]=0;
		p[i][0]=atoi(word);
		
		k++;
		c=0;
		while(line[k]!=',')
			word[c++]=line[k++];
		word[c]=0;
		p[i][1]=atoi(word);
		
		k++;
		c=0;
		while(line[k]!='>')
			word[c++]=line[k++];
		word[c]=0;
		p[i][2]=atoi(word);
		
		while(line[k]!='<')
			k++;
		
		k++;
		c=0;
		while(line[k]!=',')
			word[c++]=line[k++];
		word[c]=0;
		v[i][0]=atoi(word);

		k++;
		c=0;
		while(line[k]!=',')
			word[c++]=line[k++];
		word[c]=0;
		v[i][1]=atoi(word);
		
		k++;
		c=0;
		while(line[k]!='>')
			word[c++]=line[k++];
		word[c]=0;
		v[i][2]=atoi(word);
		
		while(line[k]!='<')
			k++;
		
		k++;
		c=0;
		while(line[k]!=',')
			word[c++]=line[k++];
		word[c]=0;
		a[i][0]=atoi(word);

		k++;
		c=0;
		while(line[k]!=',')
			word[c++]=line[k++];
		word[c]=0;
		a[i][1]=atoi(word);
		
		k++;
		c=0;
		while(line[k]!='>')
			word[c++]=line[k++];
		word[c]=0;
		a[i][2]=atoi(word);
		
	}
	
	int valid[LINES];
		for(int i=0;i<LINES;i++)
			valid[i]=1;
	
	for(int m=0;m<300;m++)
	{
		for(int i=0;i<LINES;i++)
		{
			v[i][0] += a[i][0];
			v[i][1] += a[i][1];
			v[i][2] += a[i][2];
			
			p[i][0] += v[i][0];
			p[i][1] += v[i][1];
			p[i][2] += v[i][2];			
		}
		

			
		for(int i=0;i<LINES-1;i++)
		{
			if(valid[i])
				for(int j=i+1;j<LINES;j++)
				{
					if(p[i][0]==p[j][0])
						if(p[i][1]==p[j][1])
							if(p[i][2]==p[j][2])
							{
								valid[i]=0;
								valid[j]=0;
							}
				}
		}
	}
	
	int sum=0;
	for(int i=0;i<LINES;i++)
		if(valid[i])
			sum++;
	printf("%d\n",sum);
	
	return 0;
}
