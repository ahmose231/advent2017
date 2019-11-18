#include <stdio.h>
#include <string.h>

#define LINESIZE 256
#define WORDSIZE 16
#define WORDCOUNT 16

int main()
{
	char words[WORDCOUNT][WORDSIZE];
	char line[LINESIZE];
	char *token;
	int k;
	int valid;
	int anagram;
	int count=0;
	int len;
	int alphabet1[26];
	int alphabet2[26];
	int lines=0;

	while(fgets(line,LINESIZE,stdin)!=NULL)
	{
		k=0;
		lines++;
		
		token=strtok(line," ");

		while(token!=NULL)
		{
			strcpy(words[k++],token);
			token=strtok(NULL," ");
		}
		
		len=strlen(words[k-1]);
		words[k-1][len-1]='\0';

		valid=1;

		for(int i=0;i<k-1;i++)
		{
			for(int z=0;z<26;z++)
				alphabet1[z]=0;
			
			len=strlen(words[i]);
			
			for(int z=0;z<len;z++)
				alphabet1[words[i][z]-'a']++;
			
			for(int j=i+1;j<k;j++)
			{
				for(int z=0;z<26;z++)
					alphabet2[z]=0;
				
				for(int z=0;z<len;z++)
					alphabet2[words[j][z]-'a']++;
				
				anagram=1;
				
				for(int z=0;z<26;z++)
				{
					if(alphabet1[z]!=alphabet2[z])
					{
						anagram=0;
						break;
					}
				}
				
				if(anagram)
				{
					printf("on line #%d: word #%d and word #%d are anagrams: %s = %s\n",
								lines,i+1,j+1,words[i],words[j]);
					valid=0;
					break;
				}
			}
			
			if(!valid)
				break;
		}
		
		if(valid)
		{
			printf("line #%d is valid!",lines);
			count++;
			printf(" - count = %d\n",count);
		}

	}
	
	printf("%d\n",count);
	return 0;
}
