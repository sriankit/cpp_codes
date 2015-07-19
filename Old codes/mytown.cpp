#include<cstdio>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
int b[400001];
priority_queue<int> maxq;
priority_queue< int, vector<int>, greater<int> > minq;
int black[400001];
int ans=0;
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
int main(){
    int n,l,i,bl;
    scanf("%d%d",&n,&l);
    for(i=0;i<l;i++){
        //scanf("%d",&b[i]);
        b[i]=scanInt();
        maxq.push(b[i]);
        minq.push(b[i]);
    }
    if(maxq.top()-minq.top()+1==l) ans++;
    bl=0;
    while(i<n){
        black[b[bl]]=1;
        //scanf("%d",&b[i]);
        b[i]=scanInt();
        maxq.push(b[i]);
        minq.push(b[i]);
        while(black[maxq.top()])
            maxq.pop();
        while(black[minq.top()])    
            minq.pop();
        if(maxq.top()-minq.top()+1==l) ans++;
        bl++;
        i++;
    }
    printf("%d",ans);
    return 0;
}
    
        
