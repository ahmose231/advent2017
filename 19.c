#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 1024

void main(int argc, char* argv[])
{
    FILE *fp=fopen(argv[1],"r");
    if(fp==NULL) {
        printf("cant open file\n");
        return;
    }
    
    int linecount=0;
    char line[LEN];
    int len;
    int rowsize;

    while(fgets(line,LEN,fp)!=NULL)
    {
        len=strlen(line);
        
        if(len<2) continue;        
        
        if(!linecount)
            rowsize=len-1;
        
        linecount++;
    }
    
    
    
    char map[linecount][rowsize];
    int k=0;
    rewind(fp);
    
    while(fgets(line,LEN,fp)!=NULL)
    {
        len=strlen(line);
        if(len<2) continue;
        if(line[len-1]=='\n' || line[len-1]==EOF)
            line[len-1]='\0';
        
        strcpy(map[k++], line);
    }
    fclose(fp);
    

    
    
    int dir;
    int found=0;
    int x,y;
    for(int i=0;i<rowsize;i++)
        if(map[0][i]=='|')
         {
            found=1;
            y=0;
            x=i;
            dir='d';
            break;
        }
    
    if(!found)
        for(int i=0;i<rowsize;i++)
            if(map[linecount-1][i]=='|')
             {
                found=1;
                y=linecount-1;
                x=i;
                dir='u';
                break;
            }

    if(!found)
        for(int i=0;i<linecount;i++)
            if(map[i][0]=='-')
             {
                found=1;
                y=i;
                x=0;
                dir='r';
                break;
            }
            
    if(!found)
        for(int i=0;i<linecount;i++)
            if(map[i][rowsize-1]=='-')
             {
                found=1;
                y=i;
                x=rowsize-1;
                dir='l';
                break;
            }
     
     line[0]='\0';
     k=0;
     
     while(1)
     {
     
        switch(dir)
        {
            case 'u':
                y--;
                if(map[y][x]=='|') break;
                if(map[y][x]=='+')
                {
                    if(x>0)
                        if(map[y][x-1]=='-' || (map[y][x-1]>='A'&&map[y][x-1]<='Z'))
                        {
                            dir='l';
                            break;
                        }
                
                    dir='r';
                    break;
                }        
                if(map[y][x]>='A' && map[y][x]<='Z')
                    line[k++]=map[y][x];
                break;   
                
            case 'd':
                y++;
                if(map[y][x]=='|') break;
                if(map[y][x]=='+')
                {
                    if(x>0)
                        if(map[y][x-1]=='-' || (map[y][x-1]>='A'&&map[y][x-1]<='Z'))
                        {
                            dir='l';
                            break;
                        }
                
                    dir='r';
                    break;
                }            
                if(map[y][x]>='A' && map[y][x]<='Z')
                    line[k++]=map[y][x];
                break;                  
            
            case 'r':
                x++;
                if(map[y][x]=='-') break;
                if(map[y][x]=='+')
                {
                    if(y>0)
                        if(map[y-1][x]=='|' || (map[y-1][x]>='A'&&map[y-1][x]<='Z'))
                        {
                            dir='u';
                            break;
                        }
                
                    dir='d';
                    break;
                }
                if(map[y][x]>='A' && map[y][x]<='Z')
                    line[k++]=map[y][x];
                break;   
                
             case 'l':
                x--;
                if(map[y][x]=='-') break;
                if(map[y][x]=='+')
                {
                    if(y>0)
                        if(map[y-1][x]=='|' || (map[y-1][x]>='A'&&map[y-1][x]<='Z'))
                        {
                            dir='u';
                            break;
                        }
                
                    dir='d';
                    break;
                }
                if(map[y][x]>='A' && map[y][x]<='Z')
                    line[k++]=map[y][x];
                break;    
        }
        if(map[y][x]==' ')
            break;
    }
    
    line[k]='\0';
    printf("%s\n",line);
    
    return;  
    
    
}
     
     
