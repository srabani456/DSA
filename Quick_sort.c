 #include <stdio.h>
int partition(int arr[],int start,int end)
{
	int pivort=arr[end];
	int i=start-1;
	int j;
	for(j=start;j<end;j++)
	{
		if(arr[j]<pivort)
		{
			i++;
			int t=arr[i];
			arr[i]=arr[j];
			arr[j]=t;
		}
	}
	int t=arr[i+1];
	arr[i+1]=arr[end];
	arr[end]=t;
	return (i+1);
}
void quick(int arr[],int start,int end)
{
	if(start<end)
	{
		int p=partition(arr,start,end);
		quick(arr,start,p-1);
		quick(arr,p+1,end);
	}
	
}
void printarray(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
}
void main()
{
	int arr[20],n,i;
	printf("enter the size of array:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nBefore sorting:\n");
	printarray(arr,n);
	quick(arr,0,n-1);
	printf("\nafter sorting :\n");
	printarray(arr,n);
}
