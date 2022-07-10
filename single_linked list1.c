#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node* next;	
};
struct node* head;
void beginsert();
void endinsert();
void midinsert();
void begdelete();
void enddelete();
void middelete();
void display();
void reverse();
void main()
{
	int ch;
	while(1)
	{
		printf("\n1.Beginning insert:-\n");
		printf("\n2.End insert:-\n");
		printf("\n3.Mid insert:-\n");
		printf("\n4.begining element delete:-\n");
		printf("\n5.end element delete:-\n");
		printf("\n6.random element delete:-\n");
		printf("\n7.Display:-\n8.reverse:-\n");
		printf("\n9.exit:-\n");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:beginsert();
					break;
			case 2:endinsert();
					break;
			case 3:midinsert();
					break;
			case 4: begdelete();
					break;
			case 5: enddelete();
					break;
			case 6: middelete();
					break;
			case 7:display();
					break;
			case 8:reverse();
				break;
			case 9:exit(0);
					break;
			default:printf("\nEnter the valid input:\n");
		}
	}
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
void endinsert()
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
}
void midinsert()
{
	int item,loc,i;
	struct node* ptr,*temp;
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
		printf("\nEnter the loc:-");
		scanf("%d",&loc);
		temp=head;
		for(i=1;i<loc;i++)
		{
			temp=temp->next;
			if(temp==NULL)
			{
				printf("\ncan't insert\n");
				return;
			}
		}
		ptr->next=temp->next;
		temp->next=ptr;
		printf("\nnode inserted\n");
		 
	}
}
void begdelete()
{
	struct node* ptr;
	if(head==NULL)
		printf("\nlist is empty\n");
	else
	{
		ptr=head;
		head=ptr->next;
		free(ptr);
		printf("\nnode deleted\n");
	}
}
void enddelete()
{
	struct node* ptr,*temp;
	if(head==NULL)
		printf("\nlist is empty\n");
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
		printf("\nnode deleted\n");
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
		{
			temp=ptr;
			ptr=ptr->next;
		}
		temp->next=NULL;
		free(ptr);
		printf("\nnode deleted\n");
	}
}
void middelete()
{
	struct node* ptr,*ptr1;
	int loc,i;
	printf("\nEnter the loc:-");
	scanf("%d",&loc);
	ptr=head;
	for(i=0;i<loc;i++)
	{
		ptr1=ptr;
		ptr=ptr->next;
	}
	ptr1->next=ptr->next;
	free(ptr);
	printf("\nnode deleted\n");
}
void display()
{
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
void reverse()
{
	struct node* prev=NULL;
	struct node*ptr;
	ptr=head;
	struct node*next=NULL;
	while(ptr!=NULL)
	{
		//
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
