#include <stdio.h>
int main()
{
	int a[20],n,i,searching_element,s=0;
	printf("Enter the number:");
	scanf("%d",&n);
	printf("Enter the searching element:");
	scanf("%d",&searching_element);
	
	printf("enter the array elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		if(searching_element==a[i]){	
		printf("searching elements is %d in the position %d\n",a[i],i);
		s++;
		 }
	}
		if(s==0)
		printf("there are no searching element");
	}
	

