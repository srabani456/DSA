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
void display();
void main()
{
	int ch;
	while(1)
	{
		printf("\n1.insert element in the beginning:-\n");
		printf("\n2.insert element in the end:-\n");
		printf("\n3.insert element in the middle:-\n");
		printf("\n4.display the elements:-\n");
		printf("\n5.Exit:-\n");
		printf("\nEnter the choice:-");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: beginsert();
					break;
			case 2: endinsert();
					break;
			case 3: midinsert();
					break;
			case 4: display();
					break;
			case 5: exit(0);
					break;
			default: printf("\nEnter the right choice:-\n");
		}
	}
}
void beginsert()
{
	struct node* ptr;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
		printf("\nOverflow\n");
	else
	{
		printf("\nEnter the item:-");
		scanf("%d",&item);
		ptr->data=item;
		ptr->next=head;
		head=ptr;
		printf("\nitem inserted\n");
	}
}
void endinsert()
{
	struct node* ptr,*temp;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
		printf("\nOverflow\n");
	else
	{
		printf("\nEnter the item:-");
		scanf("%d",&item);
		ptr->data=item;
		if(head==NULL)
		{
			ptr->next=NULL;
			head=ptr;
			printf("\nitem inserted\n");
		}
		else
		{
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->next=NULL;
			printf("\nitem inserted\n");	
		}
	}
}
void midinsert()
{
	int i,loc,item;
	struct node* ptr,*temp;
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
		printf("\nOverflow\n");
	else
	{
		printf("\nEnter the item:-");
		scanf("%d",&item);
		ptr->data=item;
		printf("\nEnter the location:-");
		scanf("%d",&loc);
		temp=head;
		for(i=0;i<loc;i++)
		{
			temp=temp->next;
			if(temp==NULL)
			{
				printf("\nnot inserted\n");
				return;
			}
		}
		ptr->next=temp->next;
		temp->next=ptr;
		printf("\nitem inserted\n");
	}
}
void display()
{
	struct node* ptr;
	ptr=head;
	if(ptr==NULL)
		printf("\nempty\n");
	else
	{
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
	}
}
