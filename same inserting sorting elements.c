//asending order insertoin sorting//
#include <stdio.h>
int main()
{
	int a[20],i,j,key,n;
	printf("Enter the number:");
	scanf("%d",&n);
	printf("Enter the array elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}
	printf("print the sorting elements:");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]); 
	}
}
