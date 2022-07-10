//merge sort
#include <stdio.h>
void merge(int a[],int low,int mid,int high)
{
	int i=low;
	int j=mid+1;
	int k=low;
	int b[100];
	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
		{
			b[k]=a[i];
			i++;
		}
		else
		{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	while(i<=mid)
	{
		b[k]=a[i];
		i++;
		k++;
	}
	while(j<=high)
	{
		b[k]=a[j];
		j++;
		k++;
	}
	for(i=low;i<=high;i++)
	a[i]=b[i];
	}
void mergesort(int a[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
void printarray(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}
int main()
{
	int a[20],n,i;
	printf("Enter the size of array:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nBefore sorting:\n");
	printarray(a,n);
	mergesort(a,0,n-1);
	printf("\nAfter sorting:\n");
	printarray(a,n);
	return 0;
}
