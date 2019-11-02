#include <stdio.h>
#include <stdlib.h>
struct btnode
	{int val;
	struct btnode *l,*r;
	};
void insert(struct btnode **sr, int num)
	{if(*sr==NULL)
			{*sr=(struct btnode*)malloc(sizeof(struct btnode));
			(*sr)->l=NULL;
			(*sr)->val=num;
			(*sr)->r=NULL;
			return;
			}
	else
		{if (num<((*sr)->val))
			insert(&(*sr)->l,num);
		else
			insert(&((*sr)->r),num);
		}
	return;
	}
void inorder(struct btnode *sr)
	{if(sr!=NULL)
		{inorder(sr->l);
		printf("%d",sr->val);
		inorder(sr->r);
		}
	else
		return;
	}
void preorder(struct btnode *sr)
	{if(sr!=NULL)
			{printf("%d",sr->val);
			preorder(sr->l);
			preorder(sr->r);
			}
	else
		return;
	}
void postorder(struct btnode *sr)
	{if(sr!=NULL)
		{postorder(sr->l);
		postorder(sr->r);
		printf("%d",sr->val);
		}
	else
		return;
	}
int main()
	{struct btnode *bt;
	int dt,i=1,num;
	bt=NULL;
	printf("enter number of nodes:");
	scanf("%d",&dt);
	printf("Enter the numbers:");
	while(i++<=dt)
		{scanf("%d",&num);
		insert(&bt,num);
		}
	printf("\nInorder:");
	inorder(bt);
	printf("\nPreorder:");
	preorder(bt);
	printf("\nPostorder:");
	postorder(bt);
	}
