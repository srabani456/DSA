#include <stdio.h>
int factor(int n,int fact)
{
	if(n==1)
	return fact;
	else
	factor(n-1,n*fact);
}
	
	int main()
	{
		int n,m;
		printf("enter the number:");
		scanf("%d",&n);
		if(n<0)
		printf("factorial is not possible\n");
		else if(n==0)
		printf("factorial=1\n");
		else
		{
			m=factor(n,1);
			printf("factorial of %d is %d\n",n,m);
		}
		return 0;
	}

