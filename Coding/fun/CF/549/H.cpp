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
#define EPS                     1e-19
#define maX(a,b)                ((a)>(b)?(a):(b))
#define miN(a,b)                ((a)<(b)?(a):(b))
#define abS(x)                  ((x)<0?-(x):(x))

typedef long long ll;
typedef long double LD;
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
int arr[4];
void precompute() {
	
}
void read() {
	for (int i = 0; i < 4; ++i)
	{
		s(arr[i]);
	}
}
void preprocess() {
	
}

pair<LD, LD> getRange(LD a, LD b, LD dif) {
	vector<LD> v1[2];
	v1[0].push_back(a - dif);
	v1[0].push_back(a + dif);	
	v1[1].push_back(b - dif);
	v1[1].push_back(b + dif);
	//cerr << a << " " << dif << " " << v1[0][0] << " " << v1[0][1] << endl; 
	//system("pause");
	vector<LD> vals;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			vals.push_back(v1[0][i] * v1[1][j]);
		}
	}
	sort(vals.begin(), vals.end());
	return make_pair(vals[0], vals[3]);
}	

bool cando(long double dif) {
	pair<LD, LD> r1 = getRange(arr[0], arr[3], dif);
	pair<LD, LD> r2 = getRange(arr[1], arr[2], dif);
	//if(abs(dif - 0) > EPS) cerr << r1.first << " " << r1.second << " " << r2.first << " " << r2.second << endl;	
	if(r2.first - r1.second > EPS or r1.first - r2.second > EPS) return false;
	else return true;
}

void solve() {
	int cnt = 300;	
	long double lo = 0, hi = 2e9;
	double ans = -1;
	while(cnt--) {
		long double mid = (lo + hi) / 2.0;
		if(cando(mid)) {
			ans = mid;
			hi = mid;
			//system("pause");
		} else {
			lo = mid;			
		}
	}
	printf("%.9lf\n", ans);;
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}