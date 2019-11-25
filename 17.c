#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int step=atoi(argv[1]);
	struct node {
		int value;
		struct node *next;
	};
	struct node *root, *new, *current, *temp;
	root=malloc(sizeof(struct node));
	current=root;
	root->value=0;
	root->next=NULL;
	
	int count=0;
	while(count<2017)
	{
		count++;

		temp=current;
		for(int i=0;i<step;i++)
		{
			if(temp->next!=NULL)
				temp=temp->next;
			else
				temp=root;
			
		}
		
		new=malloc(sizeof(struct node));
		new->value=count;
		if(temp->next!=NULL)
			new->next=temp->next;
		else
			new->next=NULL;
		
		temp->next=new;
		current=new;
		
		

	}
	
	if(current->next==NULL)
		printf("%d\n",root->value);
	else
		printf("%d\n",current->next->value);

	return 0;
}

			
