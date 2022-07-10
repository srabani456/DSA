#include<stdio.h>

int n;
int graph[10][10];
int q[10],visited[10];
int front=-1,rear=-1;

void read(){
	FILE *fp;
	fp=fopen("6.txt","r");
	if(fp==NULL){
		printf("Error in opening file\n");
		return;
	}
	fscanf(fp,"%d",&n);
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			fscanf(fp,"%d",&graph[i][j]);
	}
	fclose(fp);
}

void show(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d ",graph[i][j]);
		printf("\n");
	}
}

int isEmpty(){
	if(rear==front)
		return 1;
	return 0;
}

void enQueue(int x){
	rear++;
	q[rear]=x;
}

int deQueue(){
	return q[++front];
}

void bfs_traverse(int v){
	int i;
	for(i=0;i<n;i++)
		visited[i]=0;
	visited[v]=1;
	enQueue(v);
	int a,b;
	while(!isEmpty()){
		a=deQueue();
		printf("%c ",a+'A');
		for(b=0;b<n;b++){
			if(graph[a][b]==1){
				if(visited[b]==0){
					visited[b]=1;
					enQueue(b);
				}
			}
		}
	}
	printf("\n");
}

int main(){
	read();
	show();
	int v;
	printf("Enter the starting vertex: ");
	scanf("%d",&v);
	bfs_traverse(v);
	return 0;
}
