#include<stdio.h>
#include<stdlib.h>
int isoperator(char ch);
int postfixeval(char *postfix);
void push(int *s, int *t, int x);
int pop(int *s, int *t);
int main()
{
	char postfix[20];
	printf("enter the postfix expr\n");
	scanf("%s", postfix);
	int result = postfixeval(postfix);
	printf("result is %d\t", result);
}

int postfixeval(char *postfix)
{
	int s[10];
	int top=-1;
	int i =0;
	int r;
	while(postfix[i]!='\0')
	{
		char ch = postfix[i];
		if(isoperator(ch))
		{
			int op1 = pop(s,&top);
			int op2 = pop(s,&top);
			switch(ch)
			{
				case '+' : r = op1 + op2;
					printf("r = %d\n", r);
					push(s,&top,r);
					break;
				case '-' : r = op2 - op1;
					printf("r = %d\n", r);
					push(s,&top,r);
					break;

				case '*' : r = op1 * op2;
					printf("r = %d\n", r);
					push(s,&top,r);
					break;

				case '/' : r = op2 / op1;
					printf("r = %d\n", r);
					push(s,&top,r);
					break;
			}
		}
		else
		
			push(s, &top, ch-48);
			i++;
		
		
	}
	return pop(s,&top);
}

void push(int *s, int *t, int x)
{
	++(*t);
	s[*t]=x;
}

int pop(int *s, int *t)
{
	int x;
	x = s[*t];
	--(*t);
	return x;
}

int isoperator(char ch)
{
	switch (ch)
	{
		case '+':
		case'-':
		case '*':
		case '/': return 1;
		default : return 0;
	}
}

