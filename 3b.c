#include <stdio.h>
#include <stdlib.h>

#define ROW 30
#define COL 30


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
	if(argc==1)
		return 0;
	
	int matrix[ROW][COL];
	
	for(int i=0;i<ROW;i++)
		for(int j=0;j<COL;j++)
			matrix[i][j]=0;
		
	int x,y;
	x=ROW/2;
	y=COL/2;
	
	int final=atoi(argv[1]);
	
	int jump;
	int step;
	int k;
	
	char direction;
	direction='r';
	
	jump=1;
	step=0;
	k=0;
	
	matrix[x][y]=1;
	int sum;
	
	while(matrix[x][y]<final)
	{	
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
		sum=0;
		sum=sum+matrix[x-1][y-1]+matrix[x-1][y]+matrix[x-1][y+1];
		sum=sum+matrix[x][y-1]+matrix[x][y+1];
		sum=sum+matrix[x+1][y-1]+matrix[x+1][y]+matrix[x+1][y+1];
		
		matrix[x][y]=sum;
		
		k++;
		if(k==jump)
		{
			if(step)
			{
				step=0;
				jump++;	
			}
			else
				step++;
			
			direction=change_direction(direction);
			k=0;
		}
	}
	
	printf("%d\n",matrix[x][y]);
	
	return 0;
}
	
