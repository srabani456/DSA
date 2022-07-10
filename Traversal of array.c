//Traversal of array:-
#include <stdio.h>
int main()
{
  int a[50],size,i;
  printf("Enter the size: ");
  scanf("%d",&size);
  printf("Enter the array elements: ");
  for(i=0;i<size;i++)
  {
  	scanf("%d",&a[i]);
  }
  printf("Print the array elements:\t");
  for(i=0;i<size;i++)
  {
  	printf("%d\t",a[i]);
  }
  return 0;
}
