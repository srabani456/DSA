#include <stdio.h>
#define infy 999;
int g[10][10];
int mst[10];
int parent[10];
int key[10];
int n;
void readGraph(){
	int i,j;
	printf("Enter the number of vertices");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&g[i][j]);
		}
	}
	printf("The Adjacency matrix of the graph:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%2d",g[i][j]);
		}
		printf("\n");
	}	
}

int extractMin(){
	int i,minIndex,min=infy;
	for(i=1;i<=n;i++){
		if(mst[i]==0 && key[i]<min){
				min=key[i];
				minIndex=i;
			}
		}
	return minIndex;
}
int visited(){
	int i=0;
	for(i=1;i<=n;i++)
	{
		if(mst[i]==0)
			return 0;
	}
	return 1;
}
void prims(){
	int i,j;
	for(i=1;i<=n;i++)
	{
		key[i]=infy;
		mst[i]=0;
		parent[i]=0;
	}
	key[1]=0;
	while(1){
		int u=extractMin();
		mst[u]=1;
		for(i=1;i<=n;i++){
			if(mst[i]==0 && g[u][i]<key[i]){
				key[i]=g[u][i];
				parent[i]=u;
			}
		}
		if(visited()) 
			break;
	}
}

int main(void){
	readGraph();
	prims();
	int i=1;
	while(i<n){
		printf("%c ->%c\n",(char)parent[i]+65,(char)i+65);
		i++;
	}
	return 0;
}

