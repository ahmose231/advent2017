#include <stdio.h>
#include <string.h>

#define LSIZE 512

int main()
{
	struct word {
		int alphabet[26];
	};
	struct word words[32];

	char line[LSIZE];
	char *token;
	int k;
	int good;
	int valid;
	int count=0;
	while(fgets(line,LSIZE,stdin)!=NULL)
	{
		k=0;
		line[strlen(line)-1]='\0';
		token=strtok(line," ");

		while(token!=NULL)
		{
			for(int i=0;i<26;i++)
				words[k].alphabet[i]=0;
			for(int i=0;i<strlen(token);i++)
				words[k].alphabet[token[i]-'a']++;

			k++;
			token=strtok(NULL," ");
		}
		
		for(int i=0;i<k-1;i++)
		{
			valid=1;

			for(int j=i+1;j<k;j++)
			{
				good=0;
				for(int m=0;m<26;m++)
				{
					if(words[i].alphabet[m]!=words[j].alphabet[m])
					{
						good=1;
						break;
					}
				}
				if(!good)
				{
					valid=0;
					break;
				}
			}
			if(!valid)
				break;
		}
		printf("-%d\n",valid);
		if(valid)
			count++;
	}
	
	printf("%d\n",count);
	return 0;
}
