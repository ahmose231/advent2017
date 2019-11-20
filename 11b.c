#include <stdio.h>
#include <stdlib.h>
int main()
{
	int x,y;
	x=y=0;
	int c;
	int max=0;
	int a,b;

	top:
	a=abs(x);
	b=abs(y);
	if(a>=b)
		if(max<a)
			max=a;
	if(b>a)
		if(max < a+((b-a)/2))
			max = a+((b-a)/2);
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
	a=abs(x);
	b=abs(y);
	if(a>=b)
		if(max<a)
			max=a;
	if(b>a)
		if(max < a+((b-a)/2))
			max = a+((b-a)/2);
	x=abs(x);
	y=abs(y);
	printf("%d\n",x>=y?x:x+((y-x)/2));
	printf("max=%d\n",max);
	return 0;
}
		
