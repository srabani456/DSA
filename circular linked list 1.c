#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node* next;	
};
struct node* head;
void beginsert();
void endinsert();
void begdelete();
//void enddelete();
void display();
void main()
{
	int ch;
	while(1)
	{
		printf("\n1.Beginning insert:-\n");
		printf("\n2.End insert:-\n");
		printf("\n3.begining element delete:-\n");
	//	printf("\n4.end element delete:-\n");
		printf("\n5.Display:-\n");
		printf("\n6.exit:-\n");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:beginsert();
					break;
			case 2:endinsert();
					break;
			case 3: begdelete();
					break;
		/*	case 4: enddelete();
					break;*/
			case 5:display();
					break;
			case 6:exit(0);
					break;
			default:printf("\nEnter the valid input:\n");
		}
	}
}
void beginsert()
{
	struct node*ptr,*temp;
	ptr=(struct node*)malloc(sizeof(struct node));
	int item;
	if(ptr==NULL)
	printf("\noverflow\n");
	else
	{
		printf("\nEnter the item:");
		scanf("%d",&item);
		ptr->data=item;
		if(head==NULL)
		{
			head=ptr;
			ptr->next=head;
		}
		else
		{
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
				
			}
			ptr->next=head;
			temp->next=ptr;
			head=ptr;
		}
	}
}
void endinsert()
{
	struct node *ptr,*temp;
	ptr=(struct node*)malloc(sizeof(struct node));
	int item;
	if(ptr==NULL)
	printf("\nOverflow\n");
	else
	{
		printf("\nEnter the item:");
		scanf("%d",&item);
		ptr->data=item;
		if(head==NULL)
		{
			head=ptr;
			ptr->next=head;
		}
		else
		{
			temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->next=head;
		}
	}
}
void display()
{
	struct node *ptr;
	ptr=head;
	if(head=NULL)
	printf("\nnothing to print\n");
	else
	{
		while(ptr->next!=head)
		{
			printf("%4d",ptr->data);
			ptr=ptr->next;
		}
		printf("%4d",ptr->data);
	}
}
void begdelete()  
{  
    struct node *ptr;   
    if(head==NULL)  
    {  
        printf("\nunderflow\n");    
    }  
    else if(head->next==head)  
    {  
        head=NULL;  
        free(head);  
        printf("\nnode deleted\n");  
    }  
      
    else  
    {   ptr=head;   
        while(ptr->next!=head)  
            ptr=ptr->next;   
        ptr->next=head->next;  
        free(head);  
        head=ptr->next;  
        printf("\nnode deleted\n");  
  
    }  
}  
