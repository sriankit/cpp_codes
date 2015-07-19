/*ankit's template*/
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iostream>
#include<queue>
#include<deque>
#include<map>
#include<algorithm>
#include<conio.h>

#include<cmath>
using namespace std;
typedef long long ll;
#define MOD(a) ((a)%1000000007)
#define readl(c) while((c=getchar())!='\n'&&c!=EOF)
#define until(x) while(!(x))
#define PII pair<int,int>  
#define PLI pair<ll,int> 
#define PIL pair<int,ll>  
#define PLL pair<ll,ll> 
#define pb(x) push_back((x))
#define mp(a,b) (make_pair((a),(b)))
#define VI vector <int> 
#define VL vector <ll> 
#define END printf("\nPress Any Key To Continue...");getch();
#define whole(a) a.begin(),a.end()
//useful constants
#define PI 3.14258
#define EPS (1e(-8))
VL v;
int n,c,t;
bool p(ll x){
    ll i=0,k=v[0],cnt=1;
    VL::iterator it=v.begin();
    while(cnt<c){
        it=lower_bound(it,v.end(),k+x);
        if(it-v.begin()<n) {cnt++;k=*it;if(cnt==c) return 1;}
        else return 0;
    }
}
int find_ans(int lo,int hi)
{
 if(lo>hi) 
           return hi;
 int mid=(lo+hi)/2;
 if(p(mid)==0) 
                           hi=mid-1;
 else 
      lo=mid+1;
 return find_ans(lo,hi);
}
int main(){
    cin>>t;
    while(t--){
        ll i,a;
        cin>>n>>c;
        for(i=0;i<n;i++){
            cin>>a;
            v.pb(a);
        }
        sort(whole(v));
        ll lo=0,hi=v[n-1]-v[0];
        /*until(lo>hi){
            ll mid=(lo+hi)/2;
            if(p(mid)==1) lo=mid+1;
            else hi=mid-1;
        }*/
        cout<<find_ans(lo,hi)<<'\n';
    }
    END
    return 0;
}
        
    
