#include<cstdio>
#include<set>
int n,l,i,ans=0;
using namespace std;
int main(){
    multiset<int> arr;
    scanf("%d%d",&n,&l);
    int *array = new int[n];
    for(i=0;i<n;i++){
        /*multiset<int>::iterator it=arr.begin();
        while(it!=)*/
        if(i>=l){
        printf("%d %d\n",*(arr.begin()),*(arr.rbegin()));
        ans+=(*(arr.rbegin())-*(arr.begin())+1==l);
        arr.erase(array[i-l]);
        }
        scanf("%d",&array[i]);
        arr.insert(array[i]);
    }
    ans+=(*(arr.rbegin())-*(arr.begin())+1==l);
    printf("%d",ans);
    return 0;
}
