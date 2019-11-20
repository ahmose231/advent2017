#include <stdio.h>
#include <string.h>
int main()
{
	int i,j;
	char l[]="14,58,0,116,179,16,1,104,2,254,167,86,255,55,122,244";
	int slen=strlen(l);
	slen=slen+5;
	char len[slen];
	
	sprintf(len,"%s%c%c%c%c%c", l, 17, 31, 73, 47, 23);

	int t=0;
	int m[256];
	
	for(i=0;i<256;i++)
		m[i]=i;
	int skip=0;

	int subset[256];
	int k;
	int p;
	p=0;
	int counter=0;
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
	
	int hash[16];

	for(i=0;i<16;i++)
	{
		hash[i]=0;
		for(j=0;j<16;j++)
			hash[i]=hash[i]^m[(i*16)+j];
	}
	
	for(i=0;i<16;i++)
		printf("%02x",hash[i]);
	return 0;
	
}
