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
ll a[100005];
int loss[100005];
void precompute() {
	
}
void read() {
	s(n);
	for (int i = 0; i < n; ++i) {		
		int x;
		s(x);
		a[i] = -x;
		loss[i] = x;
	}
	for (int i = 0; i < n; ++i) {
		int x;
		s(x);
		a[i] += x;
	}	
}

struct node{
	ll neg, pos;
};

node t[4*100005];

node make_data(int val){
	node res;
	if(val > 0) {
		res.pos = val;
		res.neg = 0;
	} else {
		res.pos = 0;
		res.neg = -val;
	}
	return res;
}

node combine(node i,node j){
	node res;
	res.neg=i.neg;
	res.pos=j.pos;
	ll m = i.pos - j.neg;
	if(m > 0) res.pos+=m;
	else res.neg+=-m;
	return res;
}

void build(int v,int tl,int tr){
	if(tl==tr)
		t[v]=make_data(a[tl]);
	else{
		int tm=(tl+tr)>>1;
		build(v<<1,tl,tm);
		build(v<<1|1,tm+1,tr);
		t[v]=combine(t[v<<1],t[v<<1|1]);
	}
}

node query(int v, int tl, int tr, int l, int r) {
	if(tl == l and tr == r) return t[v];
	int mid = tl + tr >> 1;
	if(l > mid) return query(v << 1 | 1, mid + 1, tr, l, r);
	else if(r <= mid) return query(v << 1, tl, mid, l, r);
	else return combine(query(v << 1, tl, mid, l, mid), query(v << 1 | 1, mid + 1, tr, mid + 1, r));
}

void update(int v,int tl,int tr,int pos, ll val){
	if(tl==tr)
		t[v] = make_data(val - loss[tl]);
	else{
		int tm=(tl+tr)>>1;
		if(pos<=tm) update(v<<1,tl,tm,pos, val);
		else update(v<<1|1,tm+1,tr,pos, val);
		t[v]=combine(t[v<<1],t[v<<1|1]);
	}
}

void preprocess() {
	build(1, 0, n - 1);	
}

ll go(int idx) {
	int lo = idx, hi = n - 1;
	if(a[idx] < 0) return idx;
	int ans = idx;
	while(lo <= hi) {
		int mid = lo + hi >> 1;
		ll neg = query(1, 0, n - 1, idx, mid).neg;
		if(neg == 0) {
			ans = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return ans + 1;
}
void solve() {
	int q;
	s(q);
	while(q --) {
		int ch;
		s(ch);
		if(ch == 1) {
			int idx;
			ll d;
			s(idx);
			sl(d);
			--idx;
			a[idx] = d - loss[idx];
			update(1, 0, n - 1, idx, d);
		} else {
			int e;
			s(e);
			--e;			
			printf("%lld\n", go(e) + 1);
		}
	}
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}