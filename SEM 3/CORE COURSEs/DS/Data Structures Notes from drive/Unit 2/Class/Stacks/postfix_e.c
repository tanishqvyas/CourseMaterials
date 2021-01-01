#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void infixtopostfix(char infix[], char postfix[]);
int f(char symbol);
int g(char symbol);
int main()
{
	char infix[20];
	char postfix[20];
	printf("enter the string\n");
	scanf("%s", infix);
	infixtopostfix(infix, postfix);
	printf("Postfix expression is \n");
	printf("%s", postfix);
}

void infixtopostfix(char infix[], char postfix[])
{
	int top;// pointing to TOS
	int i;
	char symbol;
	int j = 0;
	char s[30];//stack
	top = -1;
	s[++top] = '#';
	for(i=0;i<strlen(infix);i++)
		{
			symbol = infix[i];
			while(f(s[top]) > g(symbol))
			{
				postfix[j]= s[top--];
				j++;
			}
			if(f(s[top]) != g(symbol))
				s[++top] = symbol;
			else
				top--;

		}
	while(s[top]!='#')
	{
		postfix[j] = s[top--];
		j++;
	}
	postfix[j] ='\0';		
}

int f(char symbol)
{
	switch(symbol)
		{
			case '+':
			case '-': return 2;
			
			case '*':
			case '/' : return 4;
			
			case '(': return 0;

			case '#': return -1;

			default : return 8;
		}
}

int g(char symbol)
{
	switch(symbol)
		{
			case '+':
			case '-': return 1;
			
			case '*':
			case '/' : return 3;
			
			case '(': return 9;

			case ')': return 0;

			default : return 7;
		}
}




















