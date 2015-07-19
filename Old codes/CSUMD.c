#include<stdio.h>
FILE *fp;
int main()
{
    fp=fopen("C:\\Users\\ankit\\Documents\\brute_force.txt","w");
    long n,t,mod=1000000007;
    //scanf("%ld",&t);
    t=10000;
    long long a=100000;
    while(t--)
    {
        n=a;
        if(n==1) puts("1");
        else if(n==2) puts("3");
        else
        {
            n-=2;
            long long cur=3,trail=1;long long newc;
            while(n--)
            {
                newc=(2*(cur+trail))%mod;
                if(n==0) {fprintf(fp,"%ld\n",newc);fprintf(stdout,"%ld\n",newc);goto nxt;}
                trail=cur;
                cur=newc;
            } 
            
        }    
    nxt: ;
    a--;
    }    
    return 0;
}
