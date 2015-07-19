#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
class stack
	{
	private:
		int a[100];
		int front;
		int rear;
	public:
        stack(int x)
            {
            front = 0;
            rear = 99;
            }
		void pop1()
			{
			if(front==0)
				{
				cout<<"Stack Underflow\n";
				}
			else
				{
				front--;
				}
			}
		void pop2()
			{
			if(rear==99)
				{
				cout<<"Stack Underflow\n";
				}
			else
				{
				rear++;
				}
			}
		void push1(int x)
			{
			if(front<rear)
				{
				a[front]=x;
				front++;
				}
			else
				{
				cout<<"Stack Overflow\n";
				}
			}
		void push2(int x)
			{
			if(front<rear)
				{
				a[rear]=x;
				rear--;
				}
			else
				{
				cout<<"Stack Overflow\n";
				}
			}
		void display()
			{
			int i=0;
			if(front==0)
				{
				cout<<"Stack:1 empty.\n";
				}
			else
				{
				cout<<"Stack:1\n";
				for(i=0;i<front;i++)
					{
					cout<<a[i]<<" ";
					}
				cout<<"\n";
				}
			 i=99;
			if(rear==99)
				{
				cout<<"Stack:2 empty.\n";
				}
			else
				{
				cout<<"Stack:2\n";
				for(i=99;i>rear;i--)
					{
					cout<<a[i]<<" ";
					}
				cout<<"\n";
				}
			}
	};
int main()
	{
	stack s(10);
	int n=0;
	while (1<2)
		{
		cout<<"enter your choice.\n1.Stack1  \n2.Stack2  \n3.Exit \n4.Display\n";cin>>n;
		if(n==1)
			{
			cout<<"1.push 2.pop";cin>>n;
			if(n==1)
				{
				int x;
				cout<<"Enter the element to be pushed: ";cin>>x;
				s.push1(x);
				}
			else if(n==2)
				{
				s.pop1();
				}
			}
		else if(n==2)
			{
			cout<<"1.push 2.pop\n";cin>>n;
			if(n==1)
				{
				int x;
				cout<<"Enter the element to be pushed: ";cin>>x;
				s.push2(x);
				}
			else if(n==2)
				{
				s.pop2();
                }
			}
		else if(n==4)
			{
			s.display();
			}
        else    {
        break;}
		}
	return 0;
	}
