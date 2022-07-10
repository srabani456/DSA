#include<stdio.h>
void toh(int n,char from,char to,char temp)
{
	if(n>0)
	{
		//count=count+1;
		toh(n-1,from,temp,to);
		printf("move disk %d from %c to %c\n",n,from,to);
		toh(n-1,temp,to,from);
		//printf("number of moves = %d\n",count);
	}
	//else
}
int main ()
{
	int n;
	printf("enter The number of disks :- ");
	scanf("%d",&n);
	printf("\n");
	toh(n,'L','R','C');
}
