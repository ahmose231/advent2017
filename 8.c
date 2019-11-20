#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define NAMESIZE 8
#define LINESIZE 64

struct reg {
	char name[NAMESIZE];
	int value;
	struct reg *next;
};

struct reg *find_reg(struct reg *root, char *name)
{
	struct reg *node;
	node=root->next;
	while(node!=NULL)
	{
		if(strcmp(name, node->name)==0)
			return node;
		node=node->next;
	}
	return NULL;
}	

int value_of_reg(struct reg *root, char *name)
{
	struct reg *node;
	node=root->next;
	while(node!=NULL)
	{
		if(strcmp(name, node->name)==0)
			return node->value;
		node=node->next;
	}
	return 0;
}	

bool condition_holds(int value1, int value2, char *condition)
{
	if(strcmp(condition,"==")==0)
	{
		if(value1==value2)
			return true;
		return false;
	}
	
	if(strcmp(condition,"<=")==0)
	{
		if(value1<=value2)
			return true;
		return false;
	}
	
	if(strcmp(condition,">=")==0)
	{
		if(value1>=value2)
			return true;
		return false;
	}
	
	if(strcmp(condition,"<")==0)
	{
		if(value1<value2)
			return true;
		return false;
	}
	
	if(strcmp(condition,">")==0)
	{
		if(value1>value2)
			return true;
		return false;
	}
	
	if(strcmp(condition,"!=")==0)
	{
		if(value1!=value2)
			return true;
		return false;
	}

	return true;
}

int main(int argc, char *argv[])
{
	if(argc!=2)
	{
		printf("argument error\n");
		return 0;
	}
	
	FILE *fp;
	fp=fopen(argv[1],"r");
	if(fp==NULL)
	{
		printf("no file\n");
		return 0;
	}
	
	struct reg *root, *oldnode, *newnode;
	root=malloc(sizeof(struct reg));
	root->next=NULL;
	oldnode=root;
	
	char line[LINESIZE];
	char *token;

	while(fgets(line,LINESIZE,fp)!=NULL)
	{
		
		token=strtok(line," ");
		if(find_reg(root,token)==NULL)
		{
			newnode=malloc(sizeof(struct reg));
			oldnode->next=newnode;
			oldnode=newnode;
			
			strcpy(newnode->name,token);
			newnode->value=0;
			newnode->next=NULL;
		}
		
	}

	struct reg *temp;

	int max=INT_MIN;
	rewind(fp);

	int sign;
	int increment_value;
	char condition[4];
	int value1, value2;
	while(fgets(line,LINESIZE,fp)!=NULL)
	{
		token=strtok(line," ");
		temp=find_reg(root,token);
		
		token=strtok(NULL," ");
		if(strcmp(token,"inc")==0)
			sign=1;
		else
			sign=-1;
			
		token=strtok(NULL," ");
		increment_value=atoi(token);
			
		token=strtok(NULL," ");
		token=strtok(NULL," ");
		value1=value_of_reg(root,token);
			
		token=strtok(NULL," ");
		strcpy(condition,token);
			
		token=strtok(NULL," ");
		value2=atoi(token);

		token=strtok(NULL," ");

		if(condition_holds(value1,value2,condition))
			temp->value=temp->value + (sign * increment_value);
	}
	fclose(fp);
	
	temp=root->next;
	while(temp!=NULL)
	{
		if(max<temp->value)
			max=temp->value;
		temp=temp->next;
	}
	printf("%d\n",max);

	return 0;
}

