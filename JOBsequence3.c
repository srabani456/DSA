#include<stdio.h>
int n;
struct job {
	int id;
	int deadline;
	int profit;
};
struct job j[10];
void sort()
{
	struct job temp;
	int i,k;
	for(i=1;i<=n;i++)
	{
		for(k=i+1;k<=n;k++)
		{
			if(j[i].profit<j[k].profit)
			{
				temp=j[i];
				j[i]=j[k];
				j[k]=temp;
			}
		}
	}
	printf("\nAfter sorting :\n");
	for(i=1;i<=n;i++)
	printf("%d %d %d\n",j[i].id,j[i].deadline,j[i].profit);
}
void readgraph()
{
	int i;
	printf("\nEnter the number of jobs:-");
	scanf("%d",&n);
	printf("\nEnter job id deadline job profit:-\n");
	for(i=1;i<=n;i++){
		scanf("%d %d %d ",&j[i].id,&j[i].deadline,&j[i].profit);
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
		for(k=min(j[i].deadline,n);k>0;k--){
			if(slot[k]==0)
			{
				slot[k]=1;
				x[k]=i;
				result[k]=j[i].id;
				break;
			}
		}
	}
	int total=0;
	i=1;
	while(x[i]>0)
	{
		printf("\nJ%d",result[i]);
		total+=j[x[i]].profit;
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

