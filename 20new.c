#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINES 1000
#define LEN 64
#define ITERATIONS 300

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
	
	int md[LINES];
	for(int m=0;m<ITERATIONS;m++)
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
		
		for(int i=0;i<LINES;i++)
			md[i]=abs(p[i][0]) + abs(p[i][1]) + abs(p[i][2]);
		
		int min=md[0];
		int minindex=0;
		for(int i=0;i<LINES;i++)
			if(md[i]<min)
			{
				min=md[i];
				minindex=i;
			}
		
		printf("min manhattan distance=%d\n",min);
		printf("min index=%d\n\n",minindex);
	}
	return 0;
}
