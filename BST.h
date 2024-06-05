#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
}*root=NULL;

int s=0,s1=0,x,r,c=0,c1=0;

struct node *insert(struct node*,int);
int count(struct node *);
int sum(struct node *);
void evenNode(struct node*);
void oddNode(struct node*);
void preorder(struct node *);
void inorder(struct node*);
void postorder(struct node*);
struct node *search(struct node *,int);
void  min(struct node *);
void max(struct node *);
int sumEven(struct node*);
int sumOdd(struct node*);
void reverse(struct node*);
void isArmstrong(struct node *);
void isPalendrome(struct node *);
int leafNode(struct node *);

struct node *insert(struct node *root,int item)
{
	int info;
	if(root==NULL)
	{
		root=(struct node *)malloc(sizeof(struct node));
		root->data=item;
		root->left=root->right=NULL;
		return root;
	}
	else if(root->data==item)
	{
		printf("data already exist");
		printf("\nenter alternate node data");
		scanf("%d",&info);
		insert(root,info);
	}
	else if(root->data>item)
	{
		root->left=insert(root->left,item);
	}
	else
	{
		root->right=insert(root->right,item);
	}
	return root;
}

int count(struct node *root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root!= NULL)
	{
		return(1+count(root->left)+count(root->right));
	}
}
int sum(struct node* root)
{
	if (root==NULL)
	{
		return 0;
	}
	if ( root!=NULL )
	{
		return(sum(root->left)+sum(root->right)+root->data);
	}
}

void evenNode(struct node *root)
{
	
	if(root)
	{
		if(root->data%2==0)
		{
			printf("%d ",root->data);
		}
		evenNode(root->left);
		evenNode(root->right);
	}
}
 
void oddNode(struct node *root)
{
	if(root)
	{
		if(root->data%2!=0)
		{
			printf("%d ",root->data);
		}
		oddNode(root->left);
		oddNode(root->right);
	}
}

void preorder(struct node *root)
{
	if(root)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(struct node *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

void postorder(struct node *root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}

struct node *search(struct node*root,int item)
{
	if(root==NULL || root->data==item)
	{
		return root;
	}
	else if(root->data>item)
	{
		return(search(root->left,item));
	}
	else
	{
		return(search(root->right,item));
	}
}

void min(struct node *root)
{

	if(root->left!=NULL)
	{
		return min(root->left);
	}
	printf("\nmin data is %d",root->data);
}

void max(struct node *root)
{
	if(root->right!=NULL)
	{
		return max(root->right);
	}
	printf("\nmax data is%d",root->data);
}

int sumEven(struct node *root)
{
	if(root)
	{
		if(root->data % 2==0)
		{
			s=s+root->data;
		}
		sumEven(root->left);
		sumEven(root->right);
	}
	return s;
}

int sumOdd(struct node*root)
{
	if(root)
	{
		if(root->data%2!=0)
		{
			s1=s1+root->data;
		}
		sumOdd(root->left);
		sumOdd(root->right);
	}
	return s1;
}

int leafNode(struct node *root)
{
	if(root)
	{
		if(root->left==NULL && root->right==NULL)
		{
			c++;
		}
		leafNode(root->left);
		leafNode(root->right);
	}
	return c;
}

void reverse(struct node *root)
{
	int sum=0;
	if(root!=NULL)
	{
		x=root->data;
		while(x!=0)
		{
			r=x%10;
			sum=sum*10+r;
			x=x/10;
		}
		printf("\nreverse of %d is %d",root->data,sum); 
   		reverse(root->left);
		reverse(root->right);
	}
}

void isArmstrong(struct node *root)
{
	int temp,sum=0,r;
	if(root!=NULL)
	{
		x=root->data;
		temp=root->data;
		while(temp>0)
		{
			r=temp%10;
			sum=sum+r*r*r;
			temp=temp/10;
		}
		if(x==sum)
		{
			printf("\%d ",x);
		}
		isArmstrong(root->left);
		isArmstrong(root->right);
	}
}

void isPalendrome(struct node *root)
{
	int temp,sum=0,r;
	if(root!=NULL)
	{
		temp=root->data;
		while(temp>0)
		{
			r=temp%10;
			sum=sum*10+r;
			temp=temp/10;
		}
		if(root->data==sum)
		{
			printf("%d ",root->data);
		}
		isPalendrome(root->left);
		isPalendrome(root->right);
	}
}
