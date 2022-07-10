#include <stdio.h>
#include <stdlib.h>
#define max 6
int queue[max],rear=-1,front=-1;
void enqueue(int item)
{
	if(rear==-1 && front==-1)
	{
		rear=0;
		front=0;
		queue[rear]=item;
	}
	else if((rear+1)%max==front)
	{
		printf("\nQueue is overflow\n");
	}
	else
	{
		rear=(rear+1)%max;
		queue[rear]=item;
	}
}
int dequeue()
{
	int item;
	if(front==-1 && rear==-1)
	{
		printf("\nqueue is underflow\n");
	}
	else if(front==rear)
	{
		item=queue[front];
		front=-1;
		rear=-1;
	}
	else
	{
		printf("\ndequeue element %d\n",queue[front]);
		front=(front+1)%max;
	}
	return(item);
}
void display()
{
	int i=front;
	if(front==-1 && rear==-1)
	{
		printf("\nunderflow\n");
	}
	else
	{
		 for (i = front; i != rear; i = (i + 1) %max) {
      printf("%d ", queue[i]);
    }
	}
}
void main()
{
	enqueue(7);
	enqueue(8);
	enqueue(9);
	enqueue(10);
	enqueue(99);
	enqueue(101);
	enqueue(19);
	display();
	dequeue();
	display();
	enqueue(77);
	display();
	



}
