//insertion of array
#include <stdio.h>
int main()
{
	int a[10],size,i,num;
	printf("enter the size of array: ");
	scanf("%d",&size);
	//enter array elements:-
	printf("Enter the array elements: ");
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	//shift the position and insert the elements:-
	printf("Enter the insert element: ");
	scanf("%d",&num);
		for(i=size-1;i>=0;i--)
	{
		a[i+1]=a[i];
	}
	a[0]=num;
	size++;
	//print the modified array elements:-
	printf("Modified array elements are:\t");
	for(i=0;i<size;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}
