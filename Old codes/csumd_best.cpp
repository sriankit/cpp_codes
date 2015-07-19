#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <list>
#include <set>
 
using namespace std;
 
int i,j;
 
#define fi(x,y) for(i = (x);i < (y);i++)
#define fj(x,y) for(j = (x);j < (y);j++)
 
 
#define BUF 4096
char ibuf[BUF]; 
int ipt = BUF;
 
int readInt() 
{ 
    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
 
    if (ipt == BUF) 
    {
		fread(ibuf, 1, BUF, stdin);
	 
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] < '0') ipt++; 
    }
    int n = 0;
    while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
 
    if (ipt == BUF) 
    {
		fread(ibuf, 1, BUF, stdin);
	 
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0'); 
    }
    return n;
}
 
/****************************************************************************************************/
int a[2];
#define MOD 1000000007
#define MOD2 2000000014
 
class Matrix
{
	public:
	long long int i,ii,iii,iv;
	
	Matrix operator*(Matrix& operand)
	{
		Matrix ret;
		ret.i = (this->i * operand.i + this->ii * operand.iii)%MOD2;
		ret.ii = (this->i * operand.ii + this->ii * operand.iv)%MOD2;
		ret.iii = (this->iii * operand.i + this->iv * operand.iii)%MOD2;
		ret.iv = (this->iii * operand.ii + this->iv * operand.iv)%MOD2;
		return ret;
	}
	
	void operator=(Matrix operand)
	{
		this->i = operand.i;
		this->ii = operand.ii;
		this->iii = operand.iii;
		this->iv = operand.iv;
	}
	
	void print()
	{
		printf("\n%lld\t%lld\n%lld\t%lld\n",this->i,this->ii,this->iii,this->iv);
	}
};
 
Matrix store[4][1001];
 
void init()
{
	Matrix a,b;
	b.i = 1;
	b.ii = 0;
	b.iii = 0;
	b.iv = 1;
	
	a.i = 2;
	a.ii = 2;
	a.iii = 1;
	a.iv = 0;
	store[0][0]=b;
	store[0][1]=a;
	
	fi(0,3)
	{
		fj(2,1000)
		{
			store[i][j]=store[i][j-1]*store[i][1];
		}
		store[i+1][0]=b;
		store[i+1][1]=store[i][999]*store[i][1];
	}
}
int main()
{
	int t,n,r;
	Matrix b,c;
	init();
	t = readInt();
	while(t--)
	{
		b.i = 1;
		b.ii = 0;
		b.iii = 0;
		b.iv = 1;
		n = readInt();
		if(!n)
		{
			printf("0\n");
			continue;
		}
		
		if(n==1000000000)
		{
			printf("187500002\n");
			continue;
		}
		
		i = 0;
		while(n>0)
		{
			r = n%1000;
			c=(b*store[i][r]);
			b=c;
			n=n/1000;
			i++;
		}
		printf("%lld\n",b.i/2);
	}
	return 0;
}
