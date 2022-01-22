#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 32

int numeric(char*);
long long int get_value(char*);

long long int alphabet[26];


void main(int argc, char *argv[])
{
    for(int i=0;i<26;i++)
        alphabet[i]=0;
    
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
    
    char *token1, *token2;
    int lastsound;
    
    for(int i=0;i>=0 && i<linecount;i++)
    {
        strcpy(line, lines[i]);
        
        token1=strtok(line," ");
        
        if(strcmp(token1,"snd")==0)
        {
            token2=strtok(NULL," ");
            lastsound = get_value(token2);
        }
        
        else if(strcmp(token1,"set")==0)
        {
            token1=strtok(NULL," ");
            token2=strtok(NULL," ");
            alphabet[token1[0]-'a'] = get_value(token2);
        }
        
        else if(strcmp(token1,"add")==0)
        {
            token1=strtok(NULL," ");
            token2=strtok(NULL," ");
            alphabet[token1[0]-'a'] += get_value(token2);
        }
        
        else if(strcmp(token1,"mul")==0)
        {
            token1=strtok(NULL," ");
            token2=strtok(NULL," ");
            alphabet[token1[0]-'a'] *= get_value(token2);
        }
        
        else if(strcmp(token1,"mod")==0)
        {
            token1=strtok(NULL," ");
            token2=strtok(NULL," ");
            alphabet[token1[0]-'a'] %= get_value(token2);
        }
        
        else if(strcmp(token1,"rcv")==0)
        {
            if(get_value(strtok(NULL," ")))
            {
                printf("LASTSOUND: %d\n",lastsound);
                break;
            }
        }
        
        else if(strcmp(token1,"jgz")==0)
        {
            token1=strtok(NULL," ");
            token2=strtok(NULL," ");
            if(get_value(token1) > 0)
                i = i - 1 + get_value(token2);
        }

    }  
    
    
    return;
}

int numeric(char *token)
{
    int len=strlen(token);
    for(int i=0;i<len;i++)
        if(token[i]>='a' && token[i]<='z')
            return 0;
    return 1;
}


long long int get_value(char *token)
{
    if(numeric(token))
        return atoll(token);
    
    return alphabet[token[0]-'a'];
}

