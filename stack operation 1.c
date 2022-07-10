//stack implementation using static array//
#include <stdio.h>
void push();
int pop();
int peek();
void Traverse();
int isFull();
int isEmpty();
void exit();
int n,stack[10],top=-1,ch,i,j;
void main()
{
	int ch,item,i,n;
	//printf("Enter your choice:");
	//scanf("%d",&ch);
	printf("Enter the size:\n");
	scanf("%d",&n);
	
	while(1)
	{
		printf("1. push \n");
		printf("2. pop \n");
		printf("3. peek \n");
		printf("4. Traverse \n");
		printf("5. isFull \n");
		printf("6. isEmpty \n");
		printf("Enter your choice:");
	scanf("%d",&ch);

		switch(ch)
		{
			case 1:
			push(item);
			break;
			case 2:pop();
			break;
			case 3: peek();
			break;
			case 4: Traverse();
			break;
			case 5: isFull();
			break;
			case 6: isEmpty();
			break;
			default: exit(0);
		}
	}
}
void push(int ele)
{
	if(isFull())
	{
		printf("stack is full\n");
	}
	else
	{
		top++;
		stack[top]=ele;
		printf("inserted element is:%d\n",ele);
	}
}
int pop()
{
	int ele;
	if(isEmpty())
	{
		return 0;
	}
	else
	{
		ele=stack[top];
		top--;
		
	}
	return top;
}
int peek()
{
	if(isEmpty())
	{
		return 0;
	}
	else
	{
		return stack[top];
	}
}
void Traverse()
{
	int i;
	if(isEmpty())
	{
		printf("no elements\n");
	}
	else
	{
		for(i=0;i<=top;i++)
		{
			printf("%d\t",stack[i]);
		}
	}
}
int isFull()
{
	if(top==SIZE)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isEmpty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

