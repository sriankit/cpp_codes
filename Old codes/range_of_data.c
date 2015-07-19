#include<stdio.h>
#include<string.h>
#define left(x) (x<<1)
#define right(x) (left(x)+1)
#define parent(x) (x>>1)
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define REP(i,b) for(i=b;i--;0)
#define g getchar()
#define SIZE 3000005
#include<time.h>
 int elements[3000005][3];
inline int inp()
{
   int noRead=0;
   char p=g;
   for(;p<33;)p=g;
   while(p>32)
   {
    	noRead = (noRead << 3) + (noRead << 1) + (p - '0');
    	p=g;
   }
   return noRead;
}
void init( int node, int begin, int end)
{
    if(begin==end)
    {
        elements[node][1]=elements[node][0]=begin;
		return;
    }
     int mid=(begin+end)>>1;
    init(left(node),begin,mid);
    init(right(node),mid+1,end);
    elements[node][1]=MAX(elements[left(node)][1],elements[right(node)][1]) ;
    elements[node][0]=MIN(elements[left(node)][0],elements[right(node)][0]) ;
}
void update( int node, int ibeg, int iend, int mbeg, int mend, int val, int w)
{
     int mid;
 
    if(elements[node][2]!=0)
    {
        elements[node][1]+=elements[node][2];
        elements[node][0]+=elements[node][2];
        if(mbeg!=mend)
        {
            elements[left(node)][2]+=elements[node][2];
            elements[right(node)][2]+=elements[node][2];
        }
        elements[node][2]=0;
    }
    if(ibeg==mbeg && iend==mend)
    {
        if(w==2)val=-val;
        elements[node][1]+=val;
        elements[node][0]+=val;
        if(ibeg!=iend)
        {
            elements[left(node)][2]+=val;
            elements[right(node)][2]+=val;
        }
        return;
    }
    mid=(mbeg+mend)>>1;
    if(ibeg<=mid)
        {
            if(iend>mid)
            {   
                update(left(node),ibeg,mid,mbeg,mid,val,w);
                update(right(node),mid+1,iend,mid+1,mend,val,w);
            }
            else update(left(node),ibeg,iend,mbeg,mid,val,w);
        }
    else update(right(node),ibeg,iend,mid+1,mend,val,w);
    elements[node][1]=MAX(elements[left(node)][1]+elements[left(node)][2],elements[right(node)][1]+elements[right(node)][2]);
    elements[node][0]=MIN(elements[left(node)][0]+elements[left(node)][2],elements[right(node)][0]+elements[right(node)][2]);
    return;
}
int main()
{
 int n,m,w,x,y,z,t,i,j;
FILE *fp;
fp=fopen("C:/Users/ankit/Desktop/input.txt","r");
if(fp==NULL)printf("yo");
//t=inp();
fscanf(fp,"%d",&t);
 REP(i,t)
 {
 // n=inp();m=inp();
fscanf(fp,"%d%d",&n,&m);	
	memset(elements,0,3*SIZE*sizeof (int));
	init(1,1,n);
	REP(j,m)
    {
  //     w=inp();x=inp();y=inp();z=inp();
  fscanf(fp,"%d%d%d%d",&w,&x,&y,&z);    
  update(1,x,y,1,n,z,w);
    }
    printf("%d\n",elements[1][1]-elements[1][0]);
 }
printf("%lu",clock());
return 0;
} 
