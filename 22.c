#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#define SIZE 25
#define MAXINF 10000
#define LINEMAX 30
#define ITERATIONMAX 10000

struct {
	int i;
	int j;
	int valid;
} inf[MAXINF];
int infcount=0;


int main(void) {
	char line[LINEMAX];
	int linecount=0;
	while(fgets(line,LINEMAX,stdin)!=NULL)
	{
		for(int i=0;i<strlen(line);i++)
			if(line[i]=='#')
			{
				inf[infcount].i = linecount;
				inf[infcount].j = i;
				inf[infcount].valid = 1;
				infcount++;
			}
		linecount++;
	}
	
	struct {
		int i;
		int j;
		int facing;
	} vir;
	
	vir.i = SIZE/2;
	vir.j = SIZE/2;
	vir.facing = UP;

	int totalinf=0;
	
	for(int k=0;k<ITERATIONMAX;k++)
	{
		int currentinf;
		currentinf = 0;
		
		for(int i=0;i<infcount;i++)
			if(inf[i].valid)
				if(inf[i].i == vir.i && inf[i].j == vir.j)
				{
					currentinf = 1;
					inf[i].valid = 0;
				}
		
		if(currentinf)
		{
			vir.facing++;
			vir.facing%=4;
		
		} else {
			vir.facing+=3;
			vir.facing%=4;

			inf[infcount].i = vir.i;
			inf[infcount].j = vir.j;
			inf[infcount].valid = 1;
			infcount++;
			totalinf++;
		}
		
		switch(vir.facing)
		{
			case UP:
			vir.i--;
			break;
			
			case DOWN:
			vir.i++;
			break;
			
			case RIGHT:
			vir.j++;
			break;
			
			case LEFT:
			vir.j--;
			break;
		}
	}
	
	printf("%d\n",totalinf);
	return 0;
}
