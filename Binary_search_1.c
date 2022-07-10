#include <stdio.h>
int binary_search(int a[],int beg,int end,int val)
{
	if(beg<=end)
	{
		int mid=(beg+end)/2;
		if(a[mid]==val)
			return (mid+1);
		else if(a[mid]<val)
			return binary_search(a,mid+1,end,val);
		else
			return binary_search(a,beg,mid-1,val);
		//return -1;
	}
	return -1;
}
int main()
{
	int a[20],n,i,val;
	printf("Enter the size of array:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nEnter the value:");
	scanf("%d",&val);
	int res=binary_search(a,0,n-1,val);
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\nElement to be searched:-%d\n",val);
	if(res==-1)
	printf("\nvalue is not in array\n");
	else
	printf("\nvalue in the position of%din the array\n",res);
	return 0;
}
