#include<stdio.h>
int st[20];
int top=-1;
void push(int x)
{	st[++top]=x;
}
int pop()
{	return st[top--];
}
int main()
{	char exp[20];
	char *e;
	int n1,n2,n3,num;
	printf("Enter expression:");
	scanf("%s",exp);
	e=exp;
	while(*e!='\0')
	{	if (isdigit(*e))
		{	num=*e-48;
			push(num);
		}
		else
		{	n1=pop();
			n2=pop();
			switch(*e)
			{	case'+':{n3=n1+n2;
						break;}
				case'-':{n3=n2-n1;
							break;}
				case'*':{n3=n1*n2;
						break;}
				case'/':{n3=n2/n1;
						break;}			
			}
			push(n3);
		}
		e++;
	}
	printf("\nThe result is %d",pop());
	return 0;
}
