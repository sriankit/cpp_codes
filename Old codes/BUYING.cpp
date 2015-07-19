//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
 
 
//Other Includes
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
 
using namespace std;
 
#define FOR(i,a,b)					for(int i=a;i<b;i++)
#define REP(i,n)					FOR(i,0,n)
#define pb						 	push_back
#define fill(a,v) 					memset(a, v, sizeof a)
#define sz							size()
#define INF							(int)1e9
#define EPS							1e-9
#define bitcount					__builtin_popcount
#define all(x)						x.begin(), x.end()
#define gcd							__gcd
#define maX(a,b)					(a>b?a:b)
#define miN(a,b)					(a<b?a:b)
 
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef pair<int, int > PII;

int main(){
    int t,n,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        int arr[n];
        int s=0;
        REP(i,n){
            scanf("%d",&arr[i]);
            s+=arr[i];
        }
        {
            int num=s/k;
            REP(i,n){
                if((s-arr[i])/k==num) {puts("-1");goto nxt;}
            }
            printf("%d\n",num);
            nxt:;
        }
    }
    return 0;
}
            
        
