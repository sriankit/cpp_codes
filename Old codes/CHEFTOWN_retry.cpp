#include<cstdio>
#include<set>
int n,l,i,ans=0;
using namespace std;
int black[400001];
/*
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
 */
int main(){
    multiset<int> arr;
    scanf("%d%d",&n,&l);
    multiset<int>::iterator it;
    multiset<int>::reverse_iterator itr;
    int *array = new int[n];
    for(i=0;i<n;i++){
        if(i>=l){
        it=arr.begin();
        itr=arr.rbegin();
        while(black[*it]) arr.erase(it++);
        while(black[*itr]) arr.erase(itr--);
        
        //printf("%d %d\n",*(arr.begin()),*(arr.rbegin()));
        ans+=((*itr)-*it+1==l);
        black[array[i-l]]=1;
        }
        scanf("%d",&array[i]);
        //array[i]=scanInt();
        arr.insert(array[i]);
    }
    ans+=(*(arr.rbegin())-*(arr.begin())+1==l);
    printf("%d",ans);
    return 0;
}
