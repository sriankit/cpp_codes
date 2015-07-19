/* Ankit Srivastava */
#include <bits/stdc++.h>
using namespace std;

#define MOD                     1000000007
#define pb(x)                   push_back(x)
#define mp(x,y)                 make_pair(x,y)
#define FF                      first
#define SS                      second
#define s(n)                    scanf("%d",&n)
#define sl(n)                   scanf("%lld",&n)
#define sf(n)                   scanf("%lf",&n)
#define ss(n)                   scanf("%s",n)
#define sc(n)                   {char temp[4]; ss(temp); n=temp[0];}
#define INF                     (int)1e9
#define LINF                    (long long)1e18
#define EPS                     1e-9
#define maX(a,b)                ((a)>(b)?(a):(b))
#define miN(a,b)                ((a)<(b)?(a):(b))
#define abS(x)                  ((x)<0?-(x):(x))

typedef long long ll;
typedef unsigned long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<ll> vl;
typedef vector<PII> VII;
typedef vector<TRI> VT;

int n;
int a[6];
void precompute() {
	
}
void read() {
	for (int i = 0; i < 6; ++i) {
		s(a[i]);
	}
}
void preprocess() {
	
}
bool chk(int e1, int e2, int e3) {
	int arr[] = {a[e1], a[e2], a[e3]};
	sort(arr, arr + 3);
	return arr[2] < arr[0] + arr[1];
}
void solve() {
	int inds[6] = {0,1,2,3,4,5};
	do{
		bool res = 1;
		int cond[][3] = {
			{0, 1, 2},
			{2, 3, 4},
			{0, 3, 5},
			{0, 4, 5}
		};
		for (int i = 0; i < 4; ++i) {
			res &= chk(inds[cond[i][0]], inds[cond[i][1]], inds[cond[i][2]]);
		}
		if(res) {
			puts("YES");
			return;
		}
	}while(next_permutation(inds, inds + 6));
	puts("NO");
}
int main() {
	precompute();
	int t;
	s(t);
	for (int i = 0; i < t; ++i)
	{
		read();
		preprocess();
		solve();
	}
	return 0;
}