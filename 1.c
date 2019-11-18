#include <stdio.h>
int main()
{
	int m[2200];
	int k=0;
	int x;
	x=getchar();
	while(x!=EOF && x!='\n')
	{
		m[k++]=x-'0';
		x=getchar();
	}
	int sum=0;
	for(int i=0;i<k;i++)
	{
		if(m[i]==m[((k/2)+i)%k])
			sum=sum+m[i];
	}
	printf("%d\n",sum);
	return 0;
}
