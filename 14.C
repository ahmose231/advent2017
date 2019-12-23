#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
		printf("%s\n",final);
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
			
			while(tux!=0)
			{
				if(tux&1)
					bitcount++;
				tux=tux/2;
			}
		}
		
	}
	
	printf("%d\n",bitcount);
	return 0;
}
