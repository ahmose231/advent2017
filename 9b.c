#include <stdio.h>

int main()
{
	int x;
	int sum=0;

	int nest=0;	
	int garbage=0;
	int count=0;

	for(x=getchar();x!=EOF&&x!='\n';x=getchar())
	{		
		if(garbage)
		{
			if(x=='!')
			{
				getchar();
				continue;
			}
			if(x=='>')
			{
				garbage=0;
				continue;
			}
			count++;
			continue;
		}
		
		switch(x)
		{
			case '{':
				nest++;
				break;
			case '}':
				sum=sum+nest;
				nest--;
				break;
			case '!':
				getchar();
				break;
			case '<':
				garbage=1;
				break;
		}
	}
	
	printf("%d\n",count);
	return 0;
}
				
