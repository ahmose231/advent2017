#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct list {
		int n[16];
		struct list *next;
	};
	int i;
	int m[16];
	for(i=0;i<16;i++)
		scanf("%d",&m[i]);
	int max;
	max=0;
	struct list *root,*temp,*old;
	root=malloc(sizeof(struct list));
	old=root;
	root->next=NULL;
	int maxindex;
	int flag;
	int count=0;
	int count2;
	for(;;)
	{
		count++;
		for(i=0;i<16;i++)
			if(max<m[i])
			{
				max=m[i];
				maxindex=i;
			}
		m[maxindex]=0;
		for(i=0;i<max;i++)
			m[(i+maxindex+1)%16]++;
		max=0;
		temp=root->next;
		count2=0;
		while(temp!=NULL)
		{
			count2++;
			flag=1;
			for(i=0;i<16;i++)
			{
				if(temp->n[i]!=m[i])
				{
					flag=0;
					break;
				}
			}
			if(flag)
			{
				printf("%d\n",count-count2);
				return 0;
			}
			temp=temp->next;
		}
		temp=malloc(sizeof(struct list));
		old->next=temp;
		temp->next=NULL;
		old=temp;
		for(i=0;i<16;i++)
			temp->n[i]=m[i];
	}
	
	return 0;
}
	
