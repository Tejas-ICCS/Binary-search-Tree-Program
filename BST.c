#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"BST.h"

int main()
{
	int i,size,item,val,ch;
	struct node *addr;
	while(1)
	{
		printf("\n1.insert\n 2.count\n 3.sum\n 4.even node\n 5.odd node\n 6.preorder\n7.inorder\n 8.postorder\n 9.search\n 10. total leafnode\n 11. min\n 12. max\n 13. sum of even\n 14. sum of odd\n 15. reverse\n 16. armstrong\n 17. palendrome\n 18.exit\n ");
		printf("\nenter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter size for data to be inserted :");
				scanf("%d",&size);
				for(i=1;i<=size;i++)
				{
					printf("\nenter node to be inserted");
					scanf("%d",&item);
					root = insert(root,item);
				}
				break;
			case 2:
				 val= count(root);
				 printf("total node in tree is %d\n",val);
				break;
			case 3:
				val=sum(root);
				printf("sum of node is %d\n",val);
				break;
			case 4:		
				printf("\neven nodes are:");
				evenNode(root);
				break;
			case 5:
				printf("\nodd nodes are:");
				oddNode(root);
				break;
			case 6:
	                        printf("\nlist of preorders:");
				preorder(root);
				break;
			case 7:
				printf("\nlist of inorders:");
				inorder(root);
				break;
			case 8:
				printf("\nlist of postorders:");
				postorder(root);
				break;
			case 9:
				printf("enter value to be search");
				scanf("%d",&item);
				addr=search(root,item);
				if(addr!=NULL)
				{
					printf("%d found",addr->data);
				}
				else
				{
					printf("element not found");
				}
				break;
			case 10:
				val=leafNode(root);
				printf("\ntotal leaf nodes is %d",val);
				break;
			case 11:
				min(root);
				break;
			case 12:
				max(root);
				break;
			case 13:
				val=sumEven(root);
				printf("\nsum of even is %d",val);
				break;
			case 14:
				val=sumOdd(root);
				printf("\n sum of odd is %d",val);
				break;
			case 15:
				reverse(root);
				break;
			case 16:
				printf("\narmstrong numbers are:");
				isArmstrong(root);
				break;
			case 17:
				printf("\npalendrome numbers are:");
				isPalendrome(root);
				break;
			case 18:
				exit(1);
				break;
			default :
				printf("invalid choice");
				break;
		}
	}
}
