#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#define LEN 64
int main(int argc, char *argv[])
{
	if(argc!=2) return 1;
	FILE *fp;
	fp=fopen(argv[1],"r");
	
	char line[LEN];
	char *token;
	long long int alphabet[26];
	char c;
	int last=0;
	int linecount=0;
	int jumpcount;
	
	for(int i=0;i<26;i++)
		alphabet[i]=0;
	
	
	while(fgets(line,LEN,fp)!=NULL)
	{		
		linecount++;
		
		token=strtok(line," ");
		
		while(token!=NULL)
		{
			if(strcmp(token,"set")==0)
			{
				token=strtok(NULL," ");
				c=token[0];
				
				token=strtok(NULL," ");
				if(token[0]>='a'&&token[0]<='z')
					alphabet[c-'a'] = alphabet[token[0]-'a'];
				else
					alphabet[c-'a'] = atoi(token);
			}
			
			if(strcmp(token,"add")==0)
			{
				token=strtok(NULL," ");
				c=token[0];
				
				token=strtok(NULL," ");
				if(token[0]>='a'&&token[0]<='z')
					alphabet[c-'a'] += alphabet[token[0]-'a'];
				else
					alphabet[c-'a'] += atoi(token);
			}
			
			if(strcmp(token,"mul")==0)
			{
				token=strtok(NULL," ");
				c=token[0];
				
				token=strtok(NULL," ");
				if(token[0]>='a'&&token[0]<='z')
					alphabet[c-'a']*= alphabet[token[0]-'a'];
				else
					alphabet[c-'a'] *= atoi(token);
			}
			
			if(strcmp(token,"mod")==0)
			{
				token=strtok(NULL," ");
				c=token[0];
				
				token=strtok(NULL," ");
				if(token[0]>='a'&&token[0]<='z')
					alphabet[c-'a'] %= alphabet[token[0]-'a'];
				else
					alphabet[c-'a'] %= atoi(token);
			}
			
			if(strcmp(token,"snd")==0)
			{
				token=strtok(NULL," ");
				last=alphabet[token[0]-'a'];
			}
			
			if(strcmp(token,"rcv")==0)
			{
				token=strtok(NULL," ");
				if(alphabet[token[0]-'a'])
				{
					fclose(fp);
					printf("\t%d\n", last);
					return 0;
				}
			}
			
			if(strcmp(token,"jgz")==0)
			{
				token=strtok(NULL," ");
				if(alphabet[token[0]-'a']>0)
				{
					token=strtok(NULL," ");
					jumpcount=atoi(token);
					
					if(jumpcount>0)
						while(jumpcount>0)
						{
							fgets(line,LEN,fp);
							linecount++;
							jumpcount--;
						}
					else
					{
						rewind(fp);
						jumpcount=linecount+jumpcount;
						linecount=0;
						for(int i=0;i<jumpcount-1;i++)
						{
							fgets(line,LEN,fp);
							linecount++;
						}
					}
				}
			}
			
			token=strtok(NULL," ");
		}
		

	}
	
	return 0;
}
