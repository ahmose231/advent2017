#include <stdio.h>
#include <stdlib.h>

char change_direction(char direction)
{
	switch(direction)
	{
		case 'r':
			return 'u';
		case 'u':
			return 'l';
		case 'l':
			return 'd';
		case 'd':
			return 'r';
	}
	return 0;
}

int main(int argc, char *argv[])
{
	if(argc==1) return 0;
	
	int x,y;
	int m;

	int final;
	int step;
	int jump;
	
	char direction;
	int i;
	
	m=1;
	y=x=0;
	direction='r';
	i=0;
	jump=1;
	step=0;
	final=atoi(argv[1]);
	
	while(m<final)
	{
		m++;
		
		switch(direction)
		{
			case 'r':
				x++;
				break;
			case 'l':
				x--;
				break;
			case 'u':
				y++;
				break;
			case 'd':
				y--;
				break;
			default:
				printf("error");
				return 0;
		}
		
		i++;
		if(i==jump)
		{
			if(step)
			{
				step=0;
				jump++;	
			}
			else
				step++;
			
			direction=change_direction(direction);
			i=0;
		}
	}
	
	printf("%d",abs(x)+abs(y));
	return 0;
}
		
		
