//asending bubble sorting//
#include <stdio.h>
int main()
{
	int a[20],n,i,j,temp;
	printf("enter the number:");
	scanf("%d",&n);
	printf("Enter the array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
     for(i=0;i<n;i++)
     {
     	for(j=i+1;j<n;j++)
     	{
     		if(a[i]>a[j])
     		{
     		  temp=a[j];
			  a[j]=a[i];
			  a[i]=temp;	
			 }																		
	    }
	    
	 }
	 printf("sorting elements:\n");
	 for(i=0;i<n;i++)
	 {
	 	printf("%d\t",a[i]);
	 }
	
}
