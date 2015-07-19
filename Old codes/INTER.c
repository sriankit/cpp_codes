#include<stdio.h>
#define mod(x) ((x)%1000000007)
inline int scanInt()
{
int noRead=0;
char p=getchar_unlocked();
for(;p<33;){p=getchar_unlocked();};
while(p>32)
{
noRead = (noRead << 3) + (noRead << 1) + (p - '0');
p=getchar_unlocked();
}
return noRead;
};
long long int power(int x, unsigned int y)
{
    // printf("%d\n",y);
    long long int temp=0;
    if( y == 0)
        return 1;
    else if(y==1)
        return x;
    else if (y%2 == 0)
    {
        temp=power(x,y/2)%1000000007;
        return (temp*temp)%1000000007;
    }
 
    else
    {
        temp=power(x,y/2)%1000000007;
        return (x*((temp*temp)%1000000007))%1000000007;
    }
 
}
int main(){
    long int t,n,i,j,k;
    //scanf("%d",&t);
    t=scanInt();
    while(t--){
        int trans[100001];
        //scanf("%ld",&n);
        n=scanInt();
        long cnt=0;
        if(n%2&&n!=1) cnt=1;
        for(i=2,k=1;i<=n;i+=2,k++)
            trans[k]=i;
        for(i=1;i<=n;i+=2,k++)
            trans[k]=i;
        trans[0]=1;
        int v[100001]={0},nxt=0;
        i=0;
        while(1){
            while(nxt<n&&v[nxt])
                nxt++;
            if(nxt>=n)  
                goto end;
            v[nxt]=1;
            i=nxt;
            while(1){
                i=trans[i];
                if(v[i]){
                    cnt++;
                    //printf("\n");
                    break;
                }
                else
                    v[i]=1;
            }
            
        }
        end:;
        /*long long int ans=1,var=26;
            while(cnt){
                if(cnt&1) ans=mod(ans*var);
                var=mod(var*var);
                cnt/=2;
            }
        printf("%ld\n",ans);*/
        printf("%ld\n",power(26,cnt)%1000000007);
    }
    return 0;
}
