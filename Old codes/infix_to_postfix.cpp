#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	int i,top,t,s,p1,p2;
	string postfix;
	char infix[1000],stack[1000];
		i=0,top=-1;
		cout<<"enter infix expression: ";
		scanf("%s",infix);
		cout<<"postfix expression: ";
		while(infix[i]!='\0')
		{
			if((infix[i]>=65&&infix[i]<=90)||(infix[i]>=97&&infix[i]<=122)||(infix[i]>=48&&infix[i]<=57))
				printf("%c",infix[i]);
				//postfix+=infix[i];
			else if(infix[i]=='(')
				stack[++top]=infix[i];
			else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='^')
			{
				if(top>-1)
				{
 
						if((infix[i]=='+')||(infix[i]=='-'))
							p1=1;
						else if((infix[i]=='*')||(infix[i]=='/'))
							p1=2;
						else if(infix[i]=='^')
							p1=3;
						else
							p1=0;
					do
					{
						if((stack[top]=='+')||(stack[top]=='-'))
							p2=1;
						else if((stack[top]=='*')||(stack[top]=='/'))
							p2=2;
						else if(stack[top]=='^')
							p2=3;
						else
							p2=0;
						if(p1<=p2)
							printf("%c",stack[top--]);
							//postfix+=stack[top--];
					}while(p1<=p2);
				}
				stack[++top]=infix[i];
			}
			else if(infix[i]==')')
			{
				while(stack[top]!='(')
					printf("%c",stack[top--]);
				    //postfix+=stack[top--];
                if(stack[top]=='(')
					top--;
			}
			i++;
		}
		//cout<<postfix;
		for(i=top;i>=0;i--)
			cout<<stack[i];
		printf("\n");
		
	system("pause");
	return 0;
}
