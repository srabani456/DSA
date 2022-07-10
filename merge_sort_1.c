#include <stdio.h>
void merge(int a[],int beg,int mid,int end)
{
	int n1,n2,i,j,k;
	n1=mid-beg+1;
	n2=end-mid;
	int leftarray[n1],rightarray[n2];
	for(i=0;i<n1;i++)
	{
		leftarray[i]=a[beg+i];
	}
	for(j=0;j<n2;j++)
	{
		rightarray[j]=a[mid+1+j];
	}
	i=0;
	j=0;
	k=beg;
	while(i<n1 && j<n2)
	{
		if(leftarray[i]<=rightarray[j])
		{
			a[k]=leftarray[i];
			i++;
	    }
	    else
	    {
	    	a[k]=rightarray[j];
	    	j++;
		}
		k++;
	}
	while(i<n1)
	{
		a[k]=leftarray[i];
		i++;
	}
	while(j<n2)
	{
		a[k]=rightarray[j];
		j++;
	}
	
}
void mergesort(int a[],int beg,int end)
{
	if(end>beg)
	{
	int mid=(end+beg)/2;
	mergesort(a,beg,mid);
	mergesort(a,mid+1,end);
	merge(a,beg,mid,end);
    }
}
void arrayprint(int a[],int n)
{
	int i;
//	printf("print the sorting elements:\n");//
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
int main()
{
	int a[20],n,i;
	printf("enter the size:");
	scanf("%d",&n);
	printf("Enter the array elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nbefore sorting array elements are:\n");
	arrayprint(a,n);
	mergesort(a,0,n-1);
	printf("\nafter sorting array elements are:\n");
	arrayprint(a,n);
	
	return 0;
}
