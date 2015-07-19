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
		int lim;
	public:
        stack(int x)
            {
            front = 0;
            lim=x;
            rear = lim;
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
			if(rear==lim)
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
				cout<<"Stack:1 is empty.\n";
				}
			else
				{
				cout<<"--Stack:1--\n";
				for(i=0;i<front;i++)
					{
					cout<<a[i]<<" ";
					}
				cout<<"\n";
				}
			 i=lim;
			if(rear==lim)
				{
				cout<<"Stack:2 is empty.\n";
				}
			else
				{
				cout<<"--Stack:2--\n";
				for(i=lim;i>rear;i--)
					{
					cout<<a[i]<<" ";
					}
				cout<<"\n";
				}
			}
	};
int main()
	{
	int lim;
    cout<<"please enter desired size: ";cin>>lim;
    stack s(lim);
	int n=0;
	while (1)
		{
		cout<<"Enter your choice.\n1.Stack1\n2.Stack2\n3.Exit\n4.Display\n";cin>>n;
		if(n==1)
			{
			cout<<"1.Insertion 2.Deletion\n";cin>>n;
			if(n==1)
				{
				int x;
				cout<<"Enter element to insert: ";cin>>x;
				s.push1(x);
				}
			else if(n==2)
				{
				s.pop1();
				}
			}
		else if(n==2)
			{
			cout<<"1.Insertion 2.Deletion\n";cin>>n;
			if(n==1)
				{
				int x;
				cout<<"Enter element to insert: ";cin>>x;
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
	cout<<"Exiting..."
    return 0;
	}
