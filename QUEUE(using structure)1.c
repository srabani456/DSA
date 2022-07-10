//Insertion and Deletion operation for Linear Queue
#include<stdio.h>
#include<stdlib.h>
#define MAX 3

struct linearqueue{
	int LQ[MAX];
    int front;
    int rear;
}lq;

void enQueue(int x);
int deQueue();
void displayQueue();
void isFull();
void isEmpty();

int main(){
	lq.front=0;
	lq.rear=-1;
	int x,v;
	char ch;
	while(1){
		printf("\n Press 1 to insert an element in Queue:");
		printf("\n Press 2 to display the elements in queue:");
		printf("\n Press 3 to delete an element from Queue:");
		printf("\n Press 4 check if the Queue is full or not:");
		printf("\n Press 5 to check if the Queue is empty or not:");
		printf("\n Press 6 to exit from the menu drive.");
		scanf("%d",&x);
		switch(x){
			case 1:
					printf("\n Enter an element to be inserted in queue:");
					scanf("%d",&v);
					enQueue(v);
					break;
			case 2:
					displayQueue();
					break;
			case 3:
				    v=deQueue();
					printf("\n The deleted Element is:%d",v);
					break;
		    case 4:
		    	    isFull();
		    	    break;
		    case 5:
		    	    isEmpty();
		    	    break;
            case 6:
				    exit(0);	    
			default:
					printf("\n Wrong choice");
		}
	}
}

void enQueue(int x){
	if(lq.rear == MAX-1){
		printf("\n The Queue is Full");
	}
	else{
		lq.LQ[++lq.rear]=x;
	}	  
}

int deQueue(){
	int x;
	if(lq.front>lq.rear){
		printf("\n The Queue is Empty");
	}
	else{
		x=lq.LQ[lq.front++];
		return x;
	}
}

void displayQueue(){
	if(lq.front>lq.rear){
		printf("\n There is no element in queue that can be displayed.");
		return;
	}
	int i;
	printf("\n The Queue elements are/is:");
	for(i=lq.front;i<=lq.rear;i++){
		printf("%d ",lq.LQ[i]);
	}
}

void isFull(){
	if(lq.rear==MAX-1){
		printf("\n The Queue is Full.");
		return;
	}
	printf("\n The queue has some free space left in it.");
}

void isEmpty(){
	if(lq.front>lq.rear){
		printf("\n the queue is empty.");
		return;
	}
	printf("\n The Queue has some elements in it.");
}
