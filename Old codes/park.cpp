#include<stdio.h>
#define INF 2147483647L
#include<cmath>
using namespace std;
int abs(int a)
{
    if(a>0)return a;
    else return -a;
}
int main()
{
    int t,m,n,i,j,min=2147483647,x,y,mind,flag,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        int a[m][n],emp[m];
        for(i=0;i<m;i++)
        {
            flag=0;emp[i]=n;
            for(j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j]==INF && flag==0)
                {emp[i]=j;flag=1;}
                if(a[i][j]<min)
                {x=i;y=j;min=a[i][j];}
            }
        }
        mind=m+n+1;
        for(i=1;i<m;i++)
        {
            if(emp[i]<emp[i-1])
            {
                d=abs((int)(x-i-1))+abs((int)(y-emp[i-1]-1));
                if(d<=mind)mind=d;
            }
        }
        printf("%d\n",mind);
    }
    return 0;
}
