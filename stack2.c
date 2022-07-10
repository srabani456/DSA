#include <stdio.h>
int stack[100],i,j,choice=0,n,top=-1;
void push();
void pop();
void display();

void main()
{
	printf("Enter the size of array:\n");
	scanf("%d",&n);
	printf("\n-----------------\n");
	while(choice !=4)
	{
		printf("\nchoose the choice :\n");
		printf("\n1.push\n2.pop\n3.display\n4.Exit\n");
		printf("\nEnter your choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: push();
			break;
			case 2: pop();
			break;
			case 3: display();
			break;
			case 4: printf("Exit\n");
			break;
			default: printf("invalid choice\n");
		}
	}
}
void push()
{
	int ele;
	if(top==n)
	printf("array is overflow\n");
	else
	{
    printf("Enter the value:");
    scanf("%d",&ele);
    top=top+1;
    stack[top]=ele;
    }
}
void pop()
{
	if(top==-1)
	printf("stack is underflow\n");
	else
	top=top-1;
}
void display()
{
	for(i=top;i>=0;i--)
	{
		printf("%d\t",stack[i]);
	}
	if(top==-1)
	{
		printf("stcak is empty\n");
	}
}
