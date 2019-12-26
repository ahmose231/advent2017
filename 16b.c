#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	fp=fopen(argv[1],"r");
	int c;
	
	int commacount=0;
	while(1)
	{
		c=fgetc(fp);		
		if(c==',')
			commacount++;
		if(c==EOF)
			break;
	}
	commacount++;
	rewind(fp);
	struct proto_instruction {
		char command;
		int spin;
		int swap[2];
		char partner[2];
	};
	
	struct proto_instruction instructions[commacount];
	int a,b;
	c=fgetc(fp);
	int k=0;
	while(c!='\n'&&c!=EOF)
	{
		if(c==',')
			c=fgetc(fp);

		switch(c)
		{
			case 's':
				instructions[k].command=c;
				c=fgetc(fp);
				a=c-'0';
				c=fgetc(fp);
				if(c>='0'&&c<='9')
				{
					a=a*10;
					a=a+(c-'0');
					c=fgetc(fp);
				}
				instructions[k].spin=a;
				k++;
				
				break;
			case 'x':
				instructions[k].command=c;
				c=fgetc(fp);
				a=c-'0';
				c=fgetc(fp);
				if(c>='0'&&c<='9')
				{
					a=a*10;
					a=a+(c-'0');
					c=fgetc(fp);
				}
				c=fgetc(fp);
				b=c-'0';
				c=fgetc(fp);
				if(c>='0'&&c<='9')
				{
					b=b*10;
					b=b+(c-'0');
					c=fgetc(fp);
				}
				instructions[k].swap[0]=a;
				instructions[k].swap[1]=b;
				k++;
				
				break;
			case 'p':
				instructions[k].command=c;
				c=fgetc(fp);
				instructions[k].partner[0]=c;
				c=fgetc(fp);
				c=fgetc(fp);
				instructions[k].partner[1]=c;
				k++;
				c=fgetc(fp);
				break;
		}
	}

	fclose(fp);
	char letters[16];
	letters[0]='a';
	for(int i=1;i<16;i++)
		letters[i]=letters[i-1]+1;
	int t;
	char l[10000][16];
	int lcounter=0;
	int flag;
	for(int i=0;i<1000000000;i++)
	{
		for(int kk=0;kk<lcounter;kk++)
		{
			for(int kkk=0;kkk<16;kkk++)
			{
				if(l[kk][kkk]==letters[kkk])
					flag=1;
				else
				{
					flag=0;
					break;
				}
			}
			if(flag)
			{
				for(int  aa=0;aa<16;aa++)
					printf("%c",l[1000000000%i][aa]);
				printf("\n");
				return 0;
			}
		}
				
			
		for(int jj=0;jj<16;jj++)
			l[lcounter][jj]=letters[jj];
		lcounter++;

		for(int j=0;j<commacount;j++)
		{
			switch(instructions[j].command)
			{
				case 's':
					for(int m=0;m<instructions[j].spin;m++)
					{
						t=letters[15];
						for(int mm=15;mm>0;mm--)
							letters[mm]=letters[mm-1];
						letters[0]=t;
					}
					break;
				case 'x':
					t=letters[instructions[j].swap[0]];
					letters[instructions[j].swap[0]]=letters[instructions[j].swap[1]];
					letters[instructions[j].swap[1]]=t;
					break;
				case 'p':
					for(int m=0;m<16;m++)
					{
						if(letters[m]==instructions[j].partner[0])
							a=m;
						if(letters[m]==instructions[j].partner[1])
							b=m;
					}
					t=letters[a];
					letters[a]=letters[b];
					letters[b]=t;
					break;
			}
		}
	}
	
	for(int i=0;i<16;i++)
		printf("%c",letters[i]);
	return 0;
}
					
