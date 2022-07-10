#include<stdio.h>
#include<stdlib.h>

struct tree_node{
	struct tree_node *lchild;
	int data;
	struct tree_node *rchild;
};

struct tree_node *root=NULL;

void insert(int item)
{
	struct tree_node *curr=(struct tree_node *)malloc(sizeof(struct tree_node));
	curr->data=item;
	curr->lchild=NULL;
	curr->rchild=NULL;
	if(root==NULL)
	{
		root=curr;
		return;
	}
	struct tree_node *temp=root,*parent;
	while(temp!=NULL)
	{
		parent=temp;
		if(item>temp->data)
			temp=temp->rchild;
		else if(item<temp->data)
			temp=temp->lchild;
	}
	if(item>parent->data)
		parent->rchild=curr;
	else if(item<parent->data)
		parent->lchild=curr;
}
void inorder(struct tree_node *r)
{
	if(r!=NULL)
	{
		inorder(r->lchild);
		printf("%3d",r->data);
		inorder(r->rchild);
	}	
}
void preorder(struct tree_node *r)
{
	if(r!=NULL)
	{
		printf("%3d",r->data);
		inorder(r->lchild);
		inorder(r->rchild);
	}
}
void postorder(struct tree_node *r)
{
	if(r!=NULL)
	{
		inorder(r->lchild);
		inorder(r->rchild);
		printf("%3d",r->data);
	}
}
void search(int item)
{
	if(root==NULL)
	{
		printf("Empty tree\n");
		return;
	}
	struct tree_node *temp=root;
	while(temp!=NULL)
	{
		if(item==temp->data)
		{
			printf("Item found\n");
			return;
		}
		else if(item>temp->data)
			temp=temp->rchild;
		else
			temp=temp->lchild;	
	}
	printf("Item not found\n");
}
int main()
{
	insert(20);
	insert(10);
	insert(30);
	insert(40);
	insert(25);
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	search(10);
	search(25);
	search(5);
	return 0;
}
