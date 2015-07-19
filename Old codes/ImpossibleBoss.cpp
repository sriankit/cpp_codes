//============================================================================
// Name        : MaximAndDividers.cpp
// Author      : Ankit Srivastava
//============================================================================
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>

using namespace std;

#define REP(n)                  for(int i=0;i<n;i++)
#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define ss(n) 					scanf("%s",n)
#define sc(n)                   {char temp[4]; ss(temp); n=temp[0];}
#define INF						(int)1e9
#define LINF					(long long)1e18
#define EPS						1e-9
#define maX(a,b)				((a)>(b)?(a):(b))
#define miN(a,b)				((a)<(b)?(a):(b))
#define abS(x)					((x)<0?-(x):(x))
#define foreach(v,c)            for( typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define mp						make_pair
#define FF						first
#define SS						second
#define tri(a,b,c)				mp(a,mp(b,c))
#define XX						first
#define YY						second.first
#define ZZ						second.second
#define pb						push_back
#define fill(a,v) 				memset(a,v,sizeof a)
#define all(x)					x.begin(),x.end()
#define SZ(v)					((int)(v.size()))
#define DREP(a)					sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)			(lower_bound(all(arr),ind)-arr.begin())


#define debugger cerr
#define debug(args...)			{mdbg,args; debugger<<endl;}
#define PRINT_CONTAINER(o,v)    {if(v.size()==0) return o<<"{}"; o<<"{"; foreach(it,v) o<<*it<<" "; return o<<"\b}";}
struct multidebug {template<typename T> multidebug& operator , (const T &v) {debugger<<v<<" "; return *this;}} mdbg;
template<class T> ostream& operator << (ostream& o,const vector<T> &v) PRINT_CONTAINER(o,v)
template<class T> ostream& operator << (ostream& o,const set<T> &v) PRINT_CONTAINER(o,v)
template<class A,class B> ostream& operator << (ostream& o,const map<A,B> &v) PRINT_CONTAINER(o,v)
template<class A,class B> ostream& operator << (ostream& o,const pair<A,B> &p) {o<<"("<<p.first<<","<<p.second<<")"; return o;}
template<class T> void debugarr(T* v,int n) {debugger<<"{"; for(int i=0;i<n;i++) debugger<<v[i]<<" "; debugger<<"\b}"<<endl;}


typedef unsigned long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<ll> vl;
typedef vector<PII> VII;
typedef vector<TRI> VT;

class Parabola {

public:
	LL a, c;

	Parabola(){
		a = -1;
		c = -1;
	}

	Parabola(LL _a, LL _c) {
		a = _a;
		c = _c;
	}

	LL getSum(int i, int j) {
		//System.out.println("i = " + i + " j = " + j);
		LL sum = c * (j - i + 1);
		int n = j - i + 1;
		sum += a * ((n * (n + 1)) >> 1);
		//System.out.println("returned " + sum);
		return sum;
	}

	void add(Parabola p) {
		a += p.a;
		c += p.c;
	}
};


	LL tree[400005];
	Parabola flagged[400005];
	int n;

	void init(int n1) {
		n=n1;
		//tree.resize(4*n, 0);
		memset(tree,0,sizeof(tree));
		for(int i=0;i<400005;i++) flagged[i]=Parabola();
		//flagged.resize(4*n);
	}

	LL combine(LL left, LL ryt) {
		LL ret = left + ryt;
		return ret;
	}

	void refresh(int v, Parabola par, int i, int j) {
		//System.out.println("refreshing " + v);
		tree[v] += par.getSum(i, j);
		if (flagged[v].a < 0) {
			flagged[v] = Parabola(par.a, par.c);
		} else flagged[v].add(par);
	}

	void push(int v, int l, int r) {
		if (flagged[v].a >= 0) {
			//System.out.println("pushing  v = " + v);
			if (v << 1 >= 4 * n) return;           //we're on a leaf
			//System.out.println("pushing " + v);
			int mid = l + r >> 1;
			refresh(v << 1, flagged[v], l, mid);
			Parabola add = Parabola(0, flagged[v].a * (mid + 1 - l));
			flagged[v].add(add);
			refresh(v << 1 | 1, flagged[v], mid + 1, r);
			flagged[v] = Parabola();
		}
	}

	void update(int v, int tl, int tr, int l, int r, Parabola par) {
		if (tl >= l && tr <= r) {
			refresh(v, par, tl, tr);
			return;
		}
		push(v, tl, tr);
		int mid = tl + tr >> 1;
		if (r <= mid) update(v << 1, tl, mid, l, r, par);
		else if (l > mid) update(v << 1 | 1, mid + 1, tr, l, r, par);
		else {
			update(v << 1, tl, mid, l, mid, par);
			Parabola add(0, par.a * (mid + 1 - l));
			//par.add(add);
			update(v << 1 | 1, mid + 1, tr, mid + 1, r, par);
			update(v << 1 | 1, mid + 1, tr, mid + 1, r, add);
		}
		tree[v] = combine(tree[v << 1], tree[v << 1 | 1]);
	}

	LL query(int v, int tl, int tr, int l, int r) {
		if (tl == l && tr == r) {
			return tree[v];
		}
		//System.out.printf("%d %d %d %d\n", tl, tr, l, r);
		push(v, tl, tr);
		int mid = tl + tr >> 1;
		if (r <= mid) return query(v << 1, tl, mid, l, r);
		else if (l > mid) return query(v << 1 | 1, mid + 1, tr, l, r);
		else {
			return combine(query(v << 1, tl, mid, l, mid), query(v << 1 | 1, mid + 1, tr, mid + 1, r));
		}
	}





void solve() {
	int n,q;
	s(n);
	s(q);
	init(n);
	while (q-- > 0) {
		int ch,l,r;
		scanf("%d%d%d",&ch,&l,&r);
		--l,--r;
		if (ch == 1) {
			printf("%lld\n",(query(1, 0, n - 1, l, r)));
		} else {
			Parabola p = Parabola(1, 0);
			update(1, 0, n - 1, l, r, p);
		}
	}
}


int main() {
	solve();
	return 0;
}

