//Decending order sorting//
#include <stdio.h>
int main()
{
	int a[20],n,i,j,min,temp;
	printf("Enter the number:");
	scanf("%d",&n);
	printf("Enter the array elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]>a[min])
			{
				min=j;
			}
		}
		temp=a[min];
		a[min]=a[i];
		a[i]=temp;
	}
	printf("print the sorting elements:");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	
}
