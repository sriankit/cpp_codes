#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#define pb(x) push_back(x)
#define INF 105.0
typedef long long ll;
const ll MOD=(ll)1e8;
using namespace std;
ll mod(ll x){
    if(x<0) return mod(x+MOD);
    else return x%MOD;
}
int main(){
    int t,n,a,b,x;
    double w;
    scanf("%d",&t);
    while(t--){
        map<int,vector<pair<int,double> > > arr;
        map<int,double> dp;
        scanf("%d",&n);
        while(scanf("%d%d%lf",&a,&b,&w),a!=-1){
            printf("%d %d %lf    \n",a,b,w);
            arr[b].pb(make_pair(a,w));
            
            dp[a]+=0.0;
            dp[b]+=0.0;
            if(a==b) dp[b]=max(dp[b],w);
        }
        map<int,double>::iterator it=dp.begin();
        map<int,double>::iterator p;
        vector<pair<int,double> >::iterator itv;
        //dp.begin()->second+=1;
        p=it;
        it++;
        dp[1]=INF;
        for(;it!=dp.end();it++){
            dp[x]=INF;
            x=it->first;
            itv=arr[x].begin();
            while(itv!=arr[x].end()){
                dp[x]=max(dp[x],min(dp[itv->first],itv->second));
                //dp[x]=mod(dp[x]);
                itv++;
            }
            dp[x]=max(dp[x],p->second);
            //dp[x]=mod(dp[x]);
            p=it;
        }
        printf("%lld\n",dp.rbegin()->second);
    }
    return 0;
}
