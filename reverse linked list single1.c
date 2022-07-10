#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node* next;	
};
struct node* head;
void reverse()
{
	struct node* prev=NULL;
	struct node*ptr;
	ptr=head;
	struct node*next=NULL;
	while(ptr!=NULL)
	{
		
		//printf("%4d",ptr->data);
		next=ptr->next;
		ptr->next=prev;
		//printf("%4d",ptr->data);
		prev=ptr;
		ptr=next;
		//printf("%4d",ptr->data);
	}
	head=prev;
}
void beginsert()
{
	struct node* ptr;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr==NULL)
	{
		printf("\nOverflow\n");
	}
	else
	{
		printf("\nEnter the item:-");
		scanf("%d",&item);
		ptr->data=item;
		ptr->next=head;
		head=ptr;
	}
}
/*void endinsert()
{
	struct node* ptr,*temp;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("\nOverflow\n");
	}
	else
	{
		printf("\nEnter the item:-");
		scanf("%d",&item);
		ptr->data=item;
		if(head==NULL)
		{
			ptr->next=NULL;
			head=ptr;
			printf("\nnode inserted\n");
		}
		else
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
		temp->next=ptr;
		ptr->next=NULL;
		printf("\nnode inserted\n");
	}
}*/
void main()
{
	while(1)
	{
		beginsert();
		reverse();
		struct node* ptr;
	ptr=head;
	if(ptr==NULL)
	{
		printf("\nno element print\n");
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
	}
	}
}
