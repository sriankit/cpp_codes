#include<cstdio>
#include<map>
#include<cstring>
#include<set>
using namespace std;
typedef long long ll;
int tree[50005];
const int MaxVal=50005;
multiset<ll>val;
map<ll,pair<ll,int> > sort;
void update(int idx,int val){
	while(idx<=MaxVal){
		tree[idx]+=val;
		idx+=(idx & -idx);
	}
}
int freqTo(int idx){
	int sm=0;
	while(idx>0){
		sm+=tree[idx];
		idx-=(idx & -idx);
	}
	return sm;
}
int main(){
    int n;
    scanf("%d",&n);
    ll arr[n],grtl[n],grtr[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
        val.insert(arr[i]);
    }
    int j=2;
    ll t=0,p=-1;
    multiset<ll>::iterator it;
    for(it=val.begin();it!=val.end();it++){
        if(*it!=p) sort[*it]=make_pair(t,j++);
        t+=*it;
        p=*it;
    }
    for(int i=0;i<n;i++){
        int hash=sort[arr[i]].second;
        int k=freqTo(hash-1);
        grtl[i]=i+1-k;
        update(hash,1);
    }
    memset(tree,0,sizeof(tree));
    for(int i=n-1;i>=0;i--){
        int hash=sort[arr[i]].second;
        int k=freqTo(hash-1);
        grtr[i]=n-1-i-k;
        update(hash,1);
    }
    for(int i=0;i<n;i++){
        printf("%lld\n",sort[arr[i]].first+arr[i]*grtl[i]+(arr[i]-1)*grtr[i]);
    }
    return 0;
}
