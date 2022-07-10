#include <stdio.h>
#include<stdlib.h>
#define size 5
void isFull();
void isEmpty();
void insert();
void delete();
void display();
int queue_array[size];
int rear=-1;
int front=-1;

int main()
{
	int choice;
	while(1)
	{
		printf("\n1-insert element\n");
		printf("2-delete element\n");
		printf("3-display element\n");
		printf("4-is full\n");
		printf("5-isempty\n");
		printf("6-Quit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
			break;
			case 2:
				delete();
			break;
			case 3:
				display();
			break;
			case 4:
			 isFull();
			 break;
			 case 5:
			 	isEmpty();
			break;
			case 6:
				exit(0);
			break;
			default: printf("Wrong choice n");
				
		}
	}
}

void insert()
{
	int item;
	if(rear==size-1)
	printf("\nQueue overflow n");
	else
	{
		if(front==-1)
		front=0;
		printf("\ninsert the element in Queue:\n ");
		scanf("%d",&item);
		rear=rear+1;
		queue_array[rear]=item;
	}
}
void delete()
{
	if(front==-1 || front>rear)
	{
		printf("Queue underflow n");
		return;
	}
	else
	{
		printf("Element deleted from Queue is=%d\n",queue_array[front]);
		front=front+1;
	}
}
void display()
{
	int i;
	if(front==-1)
	printf("Queue is empty n\n");
	else
	{
		printf("Queue is:\n");
		for(i=front;i<=rear;i++)
		printf("%d\n",queue_array[i]);
		printf("\n");
	}
}
void isFull()
{
	if(rear==size-1)
	printf("\nQueue is full\n");
	else
	printf("\nQueue is not full\n");
	
}
void isEmpty()
{
	if(front==-1 || front>rear)
	printf("\nQueue is empty\n");
	else 
	printf("\nQueue is not empty\n");
}
