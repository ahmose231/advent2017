#include <stdio.h>
#include <stdlib.h>
int main()
{
	int x,y;
	x=y=0;
	int c;
	
	top:
	c=getchar();
	if(c=='s')
	{
		c=getchar();
		if(c=='e')
		{
			x++;
			y--;
			c=getchar();
			if(c==EOF||c=='\n')
				goto next;
			goto top;
		}
		if(c=='w')
		{
			x--;
			y--;
			c=getchar();
			if(c==EOF||c=='\n')
				goto next;
			goto top;
		}
		if(c==',')
			y=y-2;
		
		goto top;
	}
	if(c=='n')
	{
		c=getchar();
		if(c=='e')
		{
			x++;
			y++;
			c=getchar();
			if(c==EOF||c=='\n')
				goto next;
			goto top;			
		}
		if(c=='w')
		{
			x--;
			y++;
			c=getchar();
			if(c==EOF||c=='\n')
				goto next;
			goto top;			
		}
		if(c==',')
			y=y+2;

		goto top;
	}
	next:
	x=abs(x);
	y=abs(y);
	printf("%d\n",x>=y?x:x+((y-x)/2));
	return 0;
}
		
