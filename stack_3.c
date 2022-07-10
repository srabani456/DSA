//Stack in c
#include <stdio.h>
#include <stdlib.h>
#define maxsize 5
void push();
void pop();
void display();
int stack[maxsize],top=-1;
void main()
{
	while(1)
	{
		printf("\n1.push\n");
		printf("\n2.pop\n");
		printf("\n3.display\n");
		printf("\n4.exit\n");
		int ch;
		printf("\nenter the choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: push();
			break;
			case 2: pop();
			break;
			case 3: display();
			break;
			case 4: exit(0);
			break;
			default: printf("\nchoose the correct input\n");
		}
	}
}
void push()
{
	int item;
	if(top==maxsize)
	{
		printf("\nstack is full\n");
	}
	else
	{
		printf("\nenter the item=");
		scanf("%d",&item);
		top=top+1;
		stack[top]=item;
		
	}
}
void pop()
{
	if(top==-1)
	printf("\nstack is empty\n");
	else
	{
		int item;
		item=stack[top];
		top=top-1;	
	}
}
void display()
{
	int i;
	for(i=top;i>=0;i--)
	{
		printf("%d\t",stack[i]);
	}
}
