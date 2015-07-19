#include<iostream>
#include<conio.h>
#define INF 32767
//#include<stdio.h>
int weight[20][20],vertex[20],d[20],p[20];
int nv,ne;
using namespace std;
void primsalgorithm()
{
int now,v2,mincost,i;
now=1;d[now]=0;
v2=1;
vertex[now]=1;
while(v2!=nv)
{
  for(i=1;i<=nv;i++)
  {
    if(weight[now][i]!=0)
      if(vertex[i]==0)
    if(d[i]>weight[now][i])
    {
      d[i]=weight[now][i];
      p[i]=now;
    }
  }
  mincost=INF;
  for(i=1;i<=nv;i++)
  {
    if(vertex[i]==0)
      if(d[i]<mincost)
      {
    mincost=d[i];
    now=i;
      }
  }
  vertex[now]=1;
  v2++;
}
mincost=0;
for(i=1;i<=nv;i++)
  mincost+=d[i];
  cout<<"The weight of minimum spanning tree"<<endl<<mincost<<endl;
  cout<<"The vertices connecting each other in shortest path"<<endl;
for(i=1;i<=nv;i++)
  
  cout<<i<<" "<<p[i]<<'\n';
}
void initialize()
{
int i,j,a,b,w;
cout<<"Enter number of vertices\n";
cin>>nv;
cout<<"Enter the weight matrix\n";
for(i=1;i<=nv;i++)
  for(j=1;j<=nv;j++)
    cin>>weight[i][j];
 for(i=1;i<=nv;i++)
  {
   for(j=1;j<=nv;j++)
    {
    if(weight[i][j]==0)
      weight[i][j]=32767;   
    }
 } 
for(i=1;i<=nv;i++)
{
  p[i]=vertex[i]=0;
  d[i]=32767;
}

}
int main()
{
initialize();
primsalgorithm();
getch();
return 0;
}
