//belmanford
#include<stdio.h>
#define infy 9999
int d[100],p[100];
int n,m;
struct belman{
	int s;
	int d;
	int w;
};
struct belman b[100];

void read_graph(){
	int i;
	FILE *fp;
	fp=fopen("prims.txt","r");
	if(fp==NULL){
		printf("Unable");
	}
	fscanf(fp,"%d",&n);
	fscanf(fp,"%d",&m);
	printf("%d\n%d\n",n,m);
	for(i=0;i<m;i++){
		fscanf(fp,"%d %d %d",&b[i].s,&b[i].d,&b[i].w);	
	}
	for(i=0;i<m;i++){
		printf("%d %d %d",b[i].s,b[i].d,b[i].w);
		printf("\n");
	}
}
int main(){
	int i;
	read_graph();
	if(bellman(0)>0){
		printf("Solution possible");
	}
	printf("\n");
	print(0,2);
}

int bellman(int s){
	int i,j;
	for(i=0;i<n;i++){
		d[i]=infy;
		p[i]=0;
	}
	d[s]=0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(d[b[j].s]+b[j].w<d[b[j].d]){
				d[b[j].d]=d[b[j].s]+b[j].w;
				p[b[j].d]=b[j].s;
			}
		}
	}
	for(i=0;i<m;i++){
		if(d[b[i].s]+b[i].w<d[b[i].d]){
			return 0;
		}
	}
	return 1;
}

void print(int src,int dest){
	int i;
	printf("%3c<-",dest+'A');
	i=dest;
	while(i>0){
		if(p[i]==0){
			printf("%3c",p[i]+'A');
		}
		else{
			printf("%3c<-",p[i]+'A');
		}
		i=p[i];
	}
}

