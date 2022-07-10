#include<stdio.h>
#define infy 9999
int key[100];
int parent[100];
int mstset[100];
int arr[100][100];
int n;
void graph(){
	int i,j;
	printf("ENter the numebr of vertices");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%5d",arr[i][j]);
		}
		printf("\n");
	}
}

int find_min(){
  int index,min=infy,i;
  for(i=0;i<n;i++){
    if(mstset[i]==0 && key[i]<min){
      min=key[i];
      index=i;
    }
  }
  return index;
}

int isAllFunctionIncluded(){
  int i;
  for(i=0;i<n;i++){
    if(mstset[i]==0) return 0;
  }
  return 1;
}

void show(){
  int i;
  printf("Tree edges are .............\n");
  for(i=1;i<n;i++){
    printf("%c->%c\n",parent[i]+'A',i+'A');
  }
}
void mst_prims(){
  int i;
  for(i=0;i<n;i++){
    key[i]=infy;
    parent[i]=0;
    mstset[i]=0;
  }
  key[0]=0;
  while(1){
    int u=find_min();
    mstset[u]=1;
    for(i=0;i<n;i++){
      if(mstset[i]==0 && arr[u][i]<key[i]){
        key[i]=arr[u][i];
        parent[i]=u;
      }
    }
    if(isAllFunctionIncluded()) break;
  }
  int s=0;
  for(i=0;i<n;i++){
    s=s+key[i];
  }
  printf("\nTotal Cost is %d\n",s);
  
}
int main(){
  graph();
  int i;
  mst_prims();
  show();
  return 0;
}

