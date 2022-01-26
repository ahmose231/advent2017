# wrong answer

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

#define LEN 128
#define LINECOUNT 1000
#define ITERATION 15000000

struct node {
    long long int px,py,pz;
    long long int vx,vy,vz;
    long long int ax,ay,az;
};

void main(int argc, char *argv[])
{

    struct node particles[LINECOUNT];
    char line[LEN];
    int k=0;
    while(fgets(line,LEN,stdin)!=NULL)
    {
        if(strlen(line)<2) continue;
        sscanf(line, "p=<%lld,%lld,%lld>, v=<%lld,%lld,%lld>, a=<%lld,%lld,%lld>",
            &particles[k].px,
            &particles[k].py,
            &particles[k].pz,
            
            &particles[k].vx,
            &particles[k].vy,
            &particles[k].vz,
            
            &particles[k].ax,
            &particles[k].ay,
            &particles[k].az);
            
        k++;
    }
    
    long long int manhattan[LINECOUNT];

    
    
    for(int m=0;m<ITERATION;m++)
    {
        for(int i=0;i<LINECOUNT;i++)
        {
            particles[i].vx+=particles[i].ax;
            particles[i].vy+=particles[i].ay;
            particles[i].vz+=particles[i].az;
            
            particles[i].px+=particles[i].vx;
            particles[i].py+=particles[i].vy;
            particles[i].pz+=particles[i].vz;
       
        }
    }
    
    for(int i=0;i<LINECOUNT;i++)
        manhattan[i]=llabs(particles[i].px)+llabs(particles[i].py)+llabs(particles[i].py);
    
    int min=INT_MAX;
    int minindex;
    for(int i=0;i<LINECOUNT;i++)
        if(min>manhattan[i])
        {
            minindex=i;
            min=manhattan[i];
        }
    
    printf("%d\n",minindex);
    
    return;
    
}
                
            
