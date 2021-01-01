#include<stdio.h>
int isempty(int top);
void push(char *s, int *t, char x );
char pop(char *s, int *t);
int match(char *expr);
int main()
{
	char expr[10];
	printf("enter the expression\n");
	scanf("%s", expr);
	int result = match(expr);
	if(result)
		printf("matching\n");
	else
		printf("Not Matching\n");
}

int match(char *expr)
{
	int i =0;
	char s[10];
	int top = -1;
	while(expr[i] != '\0')
		{
		char x;
		char ch = expr[i];
		switch(ch)
		{
			case '{' :
			case '[' :
			case '(' : push (s, &top, ch); break;
			case ')' : if(!isempty(top))
					{
						x = pop(s, &top);
						if ( x == '(')
							break;
						else
							return 0;
					}
					else
						return 0;
			case ']' : {if(!isempty(top))
					{
						x = pop(s, &top);
						if ( x == '[')
							break;
						else
							return 0;
					}
					else
						return 0;} break;
			case '}' : if(!isempty(top))
					{
						x = pop(s, &top);
						if ( x == '{')
							return 1;//break;
						else
							return 0;
					}
					else
						return 0;


		}
		i++;
	}
	if (isempty(top))
		return 1;
	else
		return 0;
}

int isempty(int top)
{
	if(top == -1) return 1;
		return 0;
}


void push(char *s, int *t, char x )
	{
		
		++(*t);
		s[*t]=x;
	}


char pop(char *s, int *t)
{
	char x;
	x = s[*t];
	-- (*t);
	return x;
}











