#include <stdio.h>

int main()
{
	int len[]={14,58,0,116,179,16,1,104,2,254,167,86,255,55,122,244};
	int t=0;
	int m[256];
	int i,j;
	for(i=0;i<256;i++)
		m[i]=i;
	int skip=0;

	int subset[256];
	int k;
	int p;
	p=0;
	
	while(t<16)
	{
		k=0;
		i=(p+len[t]-1)%256;
		for(j=0;j<len[t];j++)
		{
			subset[k]=m[i];
			i--;
			if(i==-1)
				i=255;
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
	
	}
	
	printf("%d\n",m[0]*m[1]);
	return 0;
	
}
			
