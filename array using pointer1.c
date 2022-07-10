#include <stdio.h>
int main()
{
	int a[5],i;
	int *p=a;
	printf("enter the array elements:\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",(a+i));//&a[i]
	}
	printf("print the array elements:\n");
	for(i=0;i<5;i++)
	{
		printf("%d\t",*(p+i));
	}
}
