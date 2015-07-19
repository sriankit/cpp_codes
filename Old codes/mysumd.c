#include<stdio.h>
#include<string.h>
typedef long long ll;
ll D[5][5];
ll T[5][5];
ll C[5][5];
#define MOD 1000000007
ll mod(ll n){
    if(n<0) return (n+(-n/MOD+1)*MOD)%MOD;
    else return n%MOD;
}
void mul(ll (*A)[5],ll (*B)[5])
{
ll i,j,k;
memset(D,0,sizeof(D));
for(i=0;i<5;i++) 
	for(j=0;j<5;j++)
		for(k=0;k<5;k++)
			D[i][j] =mod (D[i][j] +mod (A[i][k] * (ll)B[k][j]));
for(i=0;i<5;i++)
for(j=0;j<5;j++)
A[i][j]=D[i][j];
//system("pause");
}
//FILE *fpw;
//FILE *fp;

int main()
{
//fpw=fopen("C:\\Users\\ankit\\Documents\\mysumd.txt","w");
//fp=fopen("C:\\Users\\ankit\\Documents\\mysumd_test.txt","r");
ll t,n,i,j;
//fscanf(fp,"%I64d",&t);
scanf("%lld",&t);
//t=10000;
//ll a=1000000000;
while(t--)
{
	    T[0][0]=0;T[0][1]=1,T[0][2]=T[0][3]=T[0][4]=0;
            T[1][0]=T[1][1]=0;T[1][2]=1;T[1][3]=T[1][4]=0;
            T[2][0]=T[2][1]=T[2][2]=0;T[2][3]=1;T[2][4]=0;
            T[3][0]=1;T[3][1]=0;T[3][2]=-1;T[3][3]=2;T[3][4]=1;
            T[4][0]=T[4][1]=T[4][2]=T[4][3]=0;T[4][4]=1;
for(i=0;i<5;i++)
                for(j=0;j<5;j++)
                    C[i][j]=(i==j);
//scanf("%I64d",&n);
scanf("%lld",&n);
//fscanf(fp,"%ld",&n);
//n=a;
if(n==1||n==2){puts("0");continue;}
if(n==3) {puts("1");continue;}
if(n==4) {puts("3");continue;}
ll p=n-1;
for(;p;p/=2)
{
//printf("%I64d\n",p);
//display(T);
if (p%2) mul(C,T);
mul(T,T); //display(C);
}
//printf("%I64d\n",p);
// display(T);
//display(C);
//fprintf(fpw,"%I64d\n",(C[0][0]+3*C[0][1])%MOD);
printf("%ld\n",mod((C[0][2]+3*C[0][3]+C[0][4])));
//cout<<(C[0][2]+3*C[0][3]+C[0][4])%MOD<<'\n';
//a--;
}
//printf("\t%u",clock());
//system("pause");
return 0;
} 
