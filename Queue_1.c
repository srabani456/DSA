#include <stdio.h>
#include <stdlib.h>
#define max 50
int queue_array[max];
int front=-1;
int rear=-1;
void insert();
void delet();
void display();
void main()
{
	int choice;
	while(1)
	{
		printf("\n1.enter the insert element in queue array n\n");
		printf("\n2.delete an element from queue array n\n");
		printf("\n3.display the queue array elements \n");
		printf("\n4.exit\n");
		printf("Enter the choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insert();
			break;
			case 2: delet();
			break;
			case 3: display();
			break;
			case 4: exit(1);
			break;
			default: printf("wrong input\n");
			break;
		}
	}
}
void insert()
{
	int item;
	if(rear==max-1)
	{
		printf("\nqueue is overflow\n");
	}
	else
	{
	if(front==-1)
	front=0;
	printf("\nenter the item:");
	scanf("%d",&item);
	rear=rear+1;
	queue_array[rear]=item;
    }
}
void delet()
{
	if(front==-1 || front>rear)
	{
		printf("\nqueue is underflow\n");
	}
	else
	{
		if(front == rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
		printf("\ndeleted element from queue:%d\n",queue_array[front]);
		front= front+1;
		}
	}
}
void display()
{
	int i;
	if(front==-1)
	{
		printf("queue is empty\n");
	}
	else
	{
		printf("queue array elements:\n");
		for(i=front;i<=rear;i++)
		{
			printf("%d\t",queue_array[i]);
		}
    }
}
