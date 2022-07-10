#include <stdio.h>
int getmax(int arr[],int n)
{
	int max=arr[0];
	int i;
	for(i=1;i<n;i++)
	{
		if(arr[i]>max)
		max=arr[i];
	}
	return max;
}
//counting sorting//
void countsort(int arr[],int n,int pow10)
{
	int count[10]={0},output[n+1];
	int i;
	for(i=0;i<n;i++)
	{
		int digit=(arr[i]/pow10)%10;
		count[digit]++;
	}
	for(i=1;i<10;i++)
	{
		count[i]=count[i-1]+count[i];
	}
	for(i=n-1;i>=0;i--)
	{
		int digit=(arr[i]/pow10)%10;
		int index=count[digit]-1;
		count[digit]--;
		output[index]=arr[i];
	}
	for(i=0;i<n;i++)
	{
		arr[i]=output[i];
	}
}
//radix sorting //
void radixsort(int arr[],int n)
{
	int max=getmax(arr,n);
	int pow10=1;
	while(max>0)
	{
		countsort(arr,n,pow10);
		pow10=pow10*10;
		max=max/10;
		int k=1,i;
		printf("\n%d of pass:\n",k);
		for(i=0;i<n;i++)
		{
		printf("%d\t",arr[i]);
		k++;
	    }
	}
}
void printarray(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}
int main()
{
	int arr[10],n,i;
	printf("enter the size:");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nbefore sorting array elements:\n");
	printarray(arr,n);
	radixsort(arr,n);
	printf("\nafter sorting array elements:\n");
	printarray(arr,n);
}
