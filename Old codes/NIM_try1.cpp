#include<stdio.h>
typedef long long ll;
inline ll scanInt()
{
register ll noRead=0;
char p=getchar_unlocked();
for(;p<33;){p=getchar_unlocked();};
while(p>32)
{
noRead = (noRead << 3) + (noRead << 1) + (p - '0');
p=getchar_unlocked();
}
return noRead;
};
int main(){
    int t,n,i,k,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ll *a=new ll[n];
	    int *b=new int[n];
        for(i=0;i<n;i++)
            //scanf("%lld",&a[i]);
            a[i]=scanInt();
        int nxt=1;
        for(i=0;i<n-1;i++){
            if(b[i]) continue;
            for(j=i+1;j<n;j++){
                if(b[i]||b[j]) continue;
                if((a[i]^a[j])==0) b[i]=b[j]=nxt++;
            }
        }
        int cnt=0;
        for(i=0;i<n-2&&cnt<10;i++){
            cnt++;
            if(b[i]) continue;
            for(j=i+1;j<n-1&&cnt<10;j++){
                if(b[i]||b[j]) continue;
                if(b[i]) break;
                for(k=j+1;k<n&&cnt<10;k++){
                    if(b[k]) continue;
                    if((a[i]^a[j]^a[k])==0) {b[i]=b[j]=b[k]=nxt++;break;}
                }
            }
        }
        for(i=0;i<n;i++)
            printf("%d ",(b[i]==0)?nxt:b[i]);
        printf("\n");
    }
    return 0;
}
