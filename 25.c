#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STATES 6
#define LEN 128
#define WORD 8
#define TAPELEN 500000

struct proto_state {
    char name;

    char move2slot0[WORD];
    int writeslot0;
    char nextstate0;

    char move2slot1[WORD];
    int writeslot1;
    char nextstate1;
};

void main()
{
    char line[LEN];
    
    int tape[TAPELEN];
    int cursor=TAPELEN/2;
    for(int i=0;i<TAPELEN;i++)
        tape[i]=0;
    
    char current_state;
    fgets(line,LEN,stdin);
    sscanf(line, "Begin in state %c.", &current_state);
    
    int checksum_after;
    fgets(line,LEN,stdin);
    sscanf(line, "Perform a diagnostic checksum after %d steps.", &checksum_after);
    
    struct proto_state state[STATES];
    
    for(int i=0;i<STATES;i++)
    {
        fgets(line,LEN,stdin);          // the empty line
        
        fgets(line,LEN,stdin);
        sscanf(line,"In state %c:",&state[i].name);
        
        fgets(line,LEN,stdin);          // if current value is 0
        
        fgets(line,LEN,stdin);
        sscanf(line, "    - Write the value %d.", &state[i].writeslot0);
        fgets(line,LEN,stdin);
        sscanf(line, "    - Move one slot to the %s.", state[i].move2slot0);
        fgets(line,LEN,stdin);
        sscanf(line, "    - Continue with state %c.", &state[i].nextstate0);

        fgets(line,LEN,stdin);          // if current value is 1
        
        fgets(line,LEN,stdin);
        sscanf(line, "    - Write the value %d.", &state[i].writeslot1);
        fgets(line,LEN,stdin);
        sscanf(line, "    - Move one slot to the %s.", state[i].move2slot1);
        fgets(line,LEN,stdin);
        sscanf(line, "    - Continue with state %c.", &state[i].nextstate1); 
    }
    
    
    for(int index=0; index < checksum_after; index++)
    {
        if(tape[cursor]==0)
        {
            tape[cursor]=state[current_state-'A'].writeslot0;
            if(state[current_state-'A'].move2slot0[0]=='r')
                cursor++;
            else
                cursor--;
            current_state=state[current_state-'A'].nextstate0;
        }
        else
        {
            tape[cursor]=state[current_state-'A'].writeslot1;
            if(state[current_state-'A'].move2slot1[0]=='r')
                cursor++;
            else
                cursor--;
            current_state=state[current_state-'A'].nextstate1;
        }
        
    }
    
    int count=0;
    for(int i=0;i<TAPELEN;i++)
        if(tape[i])
            count++;
    
    printf("%d\n",count);
    
    return;
}
        
        
