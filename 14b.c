#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int grid[128][128];
int sgrid[128][128];

void checkneighbors(int a, int b);

int main(int argc, char *argv[])
{
	int i,j;
	char keys[128][32];
	for(i=0;i<128;i++)
		sprintf(keys[i],"%s-%d%c%c%c%c%c",argv[1],i, 17, 31, 73, 47, 23);

	int slen;
	char *len;
	int bitcount=0;
	
	int t;
	int m[256];
	
	int skip;

	int subset[256];
	int k;
	int p;
	int counter;

	char final[256];
	int tux;

	int hash[16];
	
	for(int ni=0;ni<128;ni++)
	{
		for(i=0;i<256;i++)
			m[i]=i;
		
		t=0;
		skip=0;
		p=0;
		counter=0;
		
		slen=strlen(keys[ni]);
		len=keys[ni];

		while(t<slen && counter<64)
		{
			k=0;
			i=(p+len[t]-1)%256;
			for(j=0;j<len[t];j++)
			{
				subset[k]=m[i];
				i--;
				if(i==-1)
					i=256-1;
				k++;
			}
			for(j=0;j<len[t];j++)
			{
				m[p]=subset[j];
				p++;
				if(p==256)
					p=0;
			}
			
			p=p+skip;
			p=p%256;
			skip++;
			
			t++;
			if(t==slen)
			{
				t=0;
				counter++;
			}
		}
		
		for(i=0;i<16;i++)
		{
			hash[i]=0;
			for(j=0;j<16;j++)
				hash[i]=hash[i]^m[(i*16)+j];
		}
		
		final[0]='\0';
		for(i=0;i<16;i++)
			sprintf(final,"%s%02x",final,hash[i]);
		//printf("%s\n",final);
		for(i=0;i<32;i++)
		{
			if(final[i]>='0'&&final[i]<='9')
				tux=final[i]-'0';
			else
				switch(final[i])
				{
					case 'a':
					tux=10;
					break;
					
					case 'b':
					tux=11;
					break;
					
					case 'c':
					tux=12;
					break;
					
					case 'd':
					tux=13;
					break;
					
					case 'e':
					tux=14;
					break;
					
					case 'f':
					tux=15;
					break;
				}
			
			/*
			while(tux!=0)
			{
				if(tux&1)
					bitcount++;
				tux=tux/2;
			}
			*/
			
			switch(tux)
			{
				case 0:
					grid[ni][(i*4)+0]=0;
					grid[ni][(i*4)+1]=0;
					grid[ni][(i*4)+2]=0;
					grid[ni][(i*4)+3]=0;
					break;
				case 1:
					grid[ni][(i*4)+0]=0;
					grid[ni][(i*4)+1]=0;
					grid[ni][(i*4)+2]=0;
					grid[ni][(i*4)+3]=1;
					break;
				case 2:
					grid[ni][(i*4)+0]=0;
					grid[ni][(i*4)+1]=0;
					grid[ni][(i*4)+2]=1;
					grid[ni][(i*4)+3]=0;
					break;
				case 3:
					grid[ni][(i*4)+0]=0;
					grid[ni][(i*4)+1]=0;
					grid[ni][(i*4)+2]=1;
					grid[ni][(i*4)+3]=1;
					break;
				case 4:
					grid[ni][(i*4)+0]=0;
					grid[ni][(i*4)+1]=1;
					grid[ni][(i*4)+2]=0;
					grid[ni][(i*4)+3]=0;
					break;
				case 5:
					grid[ni][(i*4)+0]=0;
					grid[ni][(i*4)+1]=1;
					grid[ni][(i*4)+2]=0;
					grid[ni][(i*4)+3]=1;
					break;
				case 6:
					grid[ni][(i*4)+0]=0;
					grid[ni][(i*4)+1]=1;
					grid[ni][(i*4)+2]=1;
					grid[ni][(i*4)+3]=0;
					break;
				case 7:
					grid[ni][(i*4)+0]=0;
					grid[ni][(i*4)+1]=1;
					grid[ni][(i*4)+2]=1;
					grid[ni][(i*4)+3]=1;
					break;
				case 8:
					grid[ni][(i*4)+0]=1;
					grid[ni][(i*4)+1]=0;
					grid[ni][(i*4)+2]=0;
					grid[ni][(i*4)+3]=0;
					break;
				case 9:
					grid[ni][(i*4)+0]=1;
					grid[ni][(i*4)+1]=0;
					grid[ni][(i*4)+2]=0;
					grid[ni][(i*4)+3]=1;
					break;
				case 10:
					grid[ni][(i*4)+0]=1;
					grid[ni][(i*4)+1]=0;
					grid[ni][(i*4)+2]=1;
					grid[ni][(i*4)+3]=0;
					break;
				case 11:
					grid[ni][(i*4)+0]=1;
					grid[ni][(i*4)+1]=0;
					grid[ni][(i*4)+2]=1;
					grid[ni][(i*4)+3]=1;
					break;
				case 12:
					grid[ni][(i*4)+0]=1;
					grid[ni][(i*4)+1]=1;
					grid[ni][(i*4)+2]=0;
					grid[ni][(i*4)+3]=0;
					break;
				case 13:
					grid[ni][(i*4)+0]=1;
					grid[ni][(i*4)+1]=1;
					grid[ni][(i*4)+2]=0;
					grid[ni][(i*4)+3]=1;
					break;
				case 14:
					grid[ni][(i*4)+0]=1;
					grid[ni][(i*4)+1]=1;
					grid[ni][(i*4)+2]=1;
					grid[ni][(i*4)+3]=0;
					break;
				case 15:
					grid[ni][(i*4)+0]=1;
					grid[ni][(i*4)+1]=1;
					grid[ni][(i*4)+2]=1;
					grid[ni][(i*4)+3]=1;
					break;
			}
			
		}
		
	}
	
	//printf("%d\n",bitcount);
	int rcount=0;
	for(i=0;i<128;i++)
		for(j=0;j<128;j++)
			sgrid[i][j]=0;
	
	for(i=0;i<128;i++)
		for(j=0;j<128;j++)
			if(grid[i][j] && !sgrid[i][j])
			{
				checkneighbors(i,j);
				rcount++;
			}
	
	printf("%d\n",rcount);
	return 0;
}


void checkneighbors(int a, int b)
{
	if(!grid[a][b] || sgrid[a][b])
		return;
	sgrid[a][b]=1;
	if(a>0)
		checkneighbors(a-1,b);
	if(b>0)
		checkneighbors(a,b-1);
	if(a<127)
		checkneighbors(a+1,b);
	if(b<127)
		checkneighbors(a,b+1);
	return;
}
