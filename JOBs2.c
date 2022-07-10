#include <stdio.h>
int n;
struct job{
	int id;
	int deadline;
	int profit;
};
struct job job[10];
void sort()
{
	struct job temp;
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(job[i].profit<job[j].profit)
			{
				temp=job[i];
				job[i]=job[j];
				job[j]=temp;
			}
		}
	}
	printf("\nAfter sorting:\n");
	for(i=1;i<n;i++)
	{
		printf("%d %d %d ",job[i].id,job[i].deadline,job[i].profit);
		printf("\n");
	}
}
void readgraph()
{
	int i;
	printf("Enter the number of jobs:");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d %d %d",&job[i].id,&job[i].deadline,&job[i].profit);
		printf("\n");
	}
	sort();
}
int min(int x,int y)
{
	if(x>y)
		return y;
	return x;
}
void jsd()
{
	int slot[n];
	int x[n],i=0,k;
	int result[n];
	for(i=1;i<=n;i++)
	{
		slot[i]=0;
		x[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		for(k=min(job[i].deadline,n);k>0;k--){
			if(slot[k]==0)
			{
				slot[k]=1;
				x[k]=i;
				result[k]=job[i].id;
				break;
			}
		}
	}
	int total=0;
	i=1;
	while(x[i]>0)
	{
		printf("\nJ%d",result[i]);
		total+=job[x[i]].profit;
		i++;
	}
	printf("\nThe total profit:%d",total);	
}
int main(void)
{
	readgraph();
    jsd();
	return 0;
}
