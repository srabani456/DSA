#include<stdio.h>
#define edge 9
#define vertex 6
struct Edge
{
    int vertex1;
    int vertex2;
    int wt;
};

struct Edge e[edge];
int makeSet[vertex+1];

void initialize()
{
    for(int i=1;i<=vertex;i++)
    {   
        makeSet[i]=-1;
    }
}

void input()
{
    printf("\n\nNote : Vertex 'A' = 1 , Vertex 'B' = 2 and so on");
    for(int i=0;i<edge;i++)
    {
        printf("\n\nFor edge %d :-\n\nEnter vertex 1 : ",i+1);
        scanf("%d",&e[i].vertex1);
        printf("\nEnter vertex 2 : ");
        scanf("%d",&e[i].vertex2);
        printf("\nEnter weight : ");
        scanf("%d",&e[i].wt);
    }
}

void merge_edges(int low,int mid,int high)
{
    int i=low,j=mid+1,k=0;
    struct Edge b[high-low+1];

    while(i<=mid && j<=high)
    {
        if(e[i].wt<=e[j].wt)
        {
            b[k++]=e[i++];
        }
        else
        {
            b[k++]=e[j++];
        }
    }
    while(i<=mid)
    {
        b[k++]=e[i++];
    }
    while(j<=high)
    {
        b[k++]=e[j++];
    }
    k=0;
    for(int a=low;a<=high;a++)
    {
        e[a]=b[k++];
    }
}

void mergeSort_edges(int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeSort_edges(low,mid);
        mergeSort_edges(mid+1,high);
        merge_edges(low,mid,high);
    }
}

int findSet(int i)
{
    int r=i;
    while(makeSet[r]>0)
    {
        r=makeSet[r];
    }
    while(i!=r)
    {
        int temp=makeSet[i];
        makeSet[i]=r;
        i=temp;
    }
    return r;
}

void Union(int a,int b)
{
    int count=makeSet[a]+makeSet[b];

    if (makeSet[a] <= makeSet[b])
    {
        makeSet[b]=a;
        makeSet[a]=count;
    }
    else
    {
        makeSet[a]=b;
        makeSet[b]=count;
    }
}

void kruskal()
{
    mergeSort_edges(0,edge-1);
    int path_cost=0;
    int count_edge=0;

    for(int i=0;i<=edge-1;i++)
    {
        int a=findSet(e[i].vertex1);
        int b=findSet(e[i].vertex2);
        if(a!=b)
        {
            printf("%c -> %c   ",(char)(e[i].vertex1+64),(char)(e[i].vertex2+64));
            path_cost+=e[i].wt;
            Union(a,b);
            count_edge++;
            if(count_edge==vertex-1)
            {
                break;    // MST creation process is completed since no. of edges = vertex-1
            }
        }
    }
    printf("\n\nThe cost of the Minimum Spanning Tree is : %d",path_cost);
}

void main()
{
    printf("\n\n---------- KRUSKAL ALGORITHM ----------\n\n");
    initialize();

    printf("\n-: Kindly enter the graph details :- \n");
    input();

    printf("\n\nThe Minimum Spanning Tree (applying Kruskal's Algorithm) is : ");
    kruskal();
}
