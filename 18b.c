#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 32
#define QLEN 10000

int is_numeric(char*);
long long get_value(char*, int);
int process_line(char *line, int turn, int i);


long long alphabet[2][26];
long long q[2][QLEN];
int qindex[2];
int trailing_q_index[2];
int command_index[2];


void main(int argc, char *argv[])
{
    alphabet[1]['p'-'a']=1;

    char line[LEN];
    
    if (argc!=2) return;
    
    FILE*fp=fopen(argv[1],"r");
    if(fp==NULL) return;
    
    int linecount=0;
    
    while(fgets(line,LEN,fp)!=NULL)
    {   
        if(strlen(line)<2) continue;
        linecount++;
    }
    
    char lines[linecount][LEN];
    
    rewind(fp);
    
    int k=0;
    int len;
    
    while(fgets(line,LEN,fp)!=NULL)
    {   
        len=strlen(line);
        if(len<2) continue;
        if(line[len-1]=='\n' || line[len-1]==EOF)
            line[len-1]='\0';
        strcpy(lines[k++], line);
    }
    
    fclose(fp);
    
	int a,b;
	
	while(1)
	{
		a=command_index[0];
		b=command_index[1];
		
		for(int i=0;i<2;i++)
			command_index[i] = process_line(lines[command_index[i]], i, command_index[i]);
		 
		if(a==command_index[0] && b==command_index[1])
			break;
		
		if(command_index[0]<0 || command_index[0]>linecount)
			break;
		
		if(command_index[1]<0 || command_index[1]>linecount)
			break;
		
	}
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<26;j++)
			printf("%d ",alphabet[i][j]);
		puts("");
	}
	
	printf("commandindex0=%d commandindex=%d\n",command_index[0], command_index[1]);
	printf("linecount=%d\n",linecount);
	printf("qindex[0]=%d\n",qindex[0]);
	printf("qindex[1]=%d\n",qindex[1]);
	
		
    return;
}

int is_numeric(char *token)
{
    int len=strlen(token);
    for(int i=0;i<len;i++)
        if(token[i]>='a' && token[i]<='z')
            return 0;
    return 1;
}


long long get_value(char *token, int turn)
{
    if(is_numeric(token))
        return atoll(token);
    
    return alphabet[turn][token[0]-'a'];
}


int process_line(char *original_line, int turn, int i)
{
	char *line=malloc(LEN);
	strcpy(line, original_line);
	
	char *token1, *token2;

	token1=strtok(line," ");
	
	if(strcmp(token1,"snd")==0)
	{
		token2=strtok(NULL," ");
		q[1-turn][qindex[1-turn]++] = get_value(token2, turn);
	}
	
	else if(strcmp(token1,"set")==0)
	{
		token1=strtok(NULL," ");
		token2=strtok(NULL," ");
		alphabet[turn][token1[0]-'a'] = get_value(token2, turn);
	}
	
	else if(strcmp(token1,"add")==0)
	{
		token1=strtok(NULL," ");
		token2=strtok(NULL," ");
		alphabet[turn][token1[0]-'a'] += get_value(token2, turn);
	}
	
	else if(strcmp(token1,"mul")==0)
	{
		token1=strtok(NULL," ");
		token2=strtok(NULL," ");
		alphabet[turn][token1[0]-'a'] *= get_value(token2, turn);
	}
	
	else if(strcmp(token1,"mod")==0)
	{
		token1=strtok(NULL," ");
		token2=strtok(NULL," ");
		alphabet[turn][token1[0]-'a'] %= get_value(token2, turn);
	}
	
	else if(strcmp(token1,"rcv")==0)
	{
		token1=strtok(NULL," ");
		if(trailing_q_index[turn] == qindex[turn])
			return i;
		alphabet[turn][token1[0]-'a'] = q[turn][trailing_q_index[turn]++];
	}
	
	else if(strcmp(token1,"jgz")==0)
	{
		token1=strtok(NULL," ");
		token2=strtok(NULL," ");
		if(get_value(token1, turn) > 0)
			i = i - 1 + get_value(token2, turn);
	}

	return i+1;
}
