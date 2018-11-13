/* Q: Write a program to demonstrate the use of stack in converting arithmetic expression from infix notation to postfix
      notation and in evaluating arithmetic postfix expression.*/
#include<iostream>
#include<stack>
#include<math.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
int top=-1;
char post[100];
int prec(char ch)
{
	switch(ch)
	{
		case '+':
			return 1;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 2;
		case '^':
			return 3;
	}
	return -1;
}
void push(int num)
{
	post[++top]=num;
}
int pop()
{
	return post[top--];
}
void evaluate_postfix(char post[20],int l)
		{
			int n1,n2,n3,num;
			for(int i=0;i<l;)
			{
				if(isdigit(post[i]))
				{
					num=post[i]-'0';
					push(num);
				}
				else if(post[i]==' ')
				{
					
				}
				else
				{
					n1=pop();
					n2=pop();
					switch(post[i])
					{
						case '+':
							{
								n3=n1+n2;
								break;
							}
						case '-':
							{
								n3=n2-n1;
								break;	
							}
						case '*':
							{
								n3=n1*n2;
								break;	
							}
						case '/':
							{
								n3=n2/n1;
								break;	
							}
						case '^':
							{
								n3=pow(n2,n1);
								break;	
							}
					}
					push(n3);
				}
				i++;
			}
			cout<<"The result of expression is "<<pop();
		}
int main()
{
	char a[100];
	char post[100];
	int k=0;
	cout<<"enter the infix expression"<<endl;
	cin>>a;
	stack<char>s;
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i]>='0' && a[i]<='9')
		  {
		  	post[k]=a[i];
		    k++;
		  }
		else if(a[i]=='(')
		  s.push(a[i]);
		else if(a[i]==')')
		{
			while(s.top()!='(')
			{
				post[k]=s.top();
				k++;
				s.pop();
			}
			s.pop();
		}
		else if(a[i]=='*'|| a[i]=='/'|| a[i]=='+'|| a[i]=='-'|| a[i]=='^')
		{
			while(prec(a[i]) < prec(s.top()))
			{
				post[k]=s.top();
				k++;
				s.pop();
			}
			s.push(a[i]);
		}
	}
	cout<<"Postfix Expression : ";
	int l=strlen(post);
	for(int i=0;i<k;i++)
	{
		cout<<post[i];
	}
	cout<<endl;
	evaluate_postfix(post,l);
	return 0;
}
