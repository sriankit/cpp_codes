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
#define MAXN 100005

int a[MAXN];

struct Flag {
	int s1, final, s2, cur;
};

struct node {
	int c[2];
	ll sum;
	bool finalized;
};

node tree[4 * MAXN];
Flag flags[4 * MAXN];

Flag flag_init() {
	Flag flag;
	flag.s1 = flag.s2 = 0;
	flag.final = flag.cur = -1;
	return flag;
}

node make_data(int num) {
	node data;
	data.c[1] = num % 2 == 1;
	data.c[0] = num % 2 == 0;
	data.sum = num;
	data.finalized = false;
	return data;
}

node combine(node l, node r) {
	node res = make_data(0);
	res.c[0] = l.c[0] + r.c[0];
	res.c[1] = l.c[1] + r.c[1];
	res.sum = l.sum + r.sum;
	return res;
}

void build(int v, int tl ,int tr) {
	flags[v] = flag_init();
	if(tl == tr) tree[v] = make_data(a[tl]);
	else{
		int mid = tl + tr >> 1;
		build(v << 1, tl, mid);
		build(v << 1 | 1, mid + 1, tr);
		tree[v] = combine(tree[v << 1], tree[v << 1 | 1]);
	}
}

void passFlag(int v, Flag flag) {
	Flag &f2 = flags[v];
	f2.s1 += flag.s1;
	if(flag.final == -1) return;
	f2.final = flag.final;
	f2.s2 += flag.s2;
	if(f2.s2 % 2 == 0) f2.cur = f2.final;
	else f2.cur = 1 - f2.final;
}

void refresh(int v) {
	node &node = tree[v];
	Flag &flag = flags[v];
	cerr << "refresh " << v << " " << node.c[0] << " " << node.c[1] << " " << flag.final << " " << flag.s2 << " " << flag.cur << endl;
	int sz = node.c[0] + node.c[1];
	node.sum += flag.s1 * sz;
	if(flag.s1 & 1) 
		swap(node.c[0], node.c[1]);
	flag.s1 = 0;

	if(flag.final == -1) return;
	if(!node.finalized) {
		cerr << " finalized  " << v << '\n';
		node.sum += node.c[1 - flag.final];
		node.c[flag.final] = sz;
		node.c[1 - flag.final] = 0;
		node.finalized = true;
	}
	node.sum += flag.s2 * sz;
	if(flag.s2 & 1) {
		swap(node.c[0], node.c[1]);
		flag.cur = 1 - flag.final;
	} else flag.cur = flag.final;
	flag.s2 = 0;	
}

void push(int v) {
	passFlag(v << 1, flags[v]);
	passFlag(v << 1 | 1, flags[v]);
	refresh(v);	
}


void updateFlag(int v, int m) {
	Flag &flag = flags[v];
	if(flag.final == -1) {
		if(m == 2) flag.s1 ++;
		else {
			flag.final = m;
			flag.cur = m;
		}
	} else {
		if(m == 2 || m != flag.cur) {			
			flag.s2++;
			flag.cur = m;
		}
	}
}

void update(int v, int tl, int tr, int l, int r, int m) {
	if(tl == l and tr == r) {
		updateFlag(v, m);
		push(v);
		return;
	}
	push(v);
	int mid = tl + tr >> 1;
	if(r <= mid) update(v << 1, tl, mid, l, r, m);
	else if(l > mid) update(v << 1 | 1, mid + 1, tr, l, r, m);
	else update(v << 1, tl, mid, l, mid, m), update(v << 1 | 1, mid + 1, tr, mid + 1, r, m);
	tree[v] = combine(tree[v << 1], tree[v << 1 | 1]);
}

node query(int v, int tl, int tr, int l, int r) {
	if(tl == l and tr == r) {
		return tree[v];
	}
	push(v);
	int mid = tl + tr >> 1;
	if(r <= mid) return query(v << 1, tl, mid, l, r);
	else if(l > mid) return query(v << 1 | 1, mid + 1, tr, l, r);
	else return combine(query(v << 1, tl, mid, l, mid), query(v << 1 | 1, mid + 1, tr, mid + 1, r));
}

void precompute() {
	
}
void read() {
	s(n);
	for (int i = 0; i < n; ++i) {
		s(a[i]);
	}
}
void preprocess() {
	build(1, 0, n - 1);
}
void solve() {
	int q;
	s(q);
	while(q--) {
		char op;
		sc(op);
		int l, r;
		s(l), s(r);
		--l, --r;
		switch(op) {
			case 'E':
				update(1, 0, n - 1, l, r, 0);
				break;
			case 'O':
				update(1, 0, n - 1, l, r, 1);
				break;
			case 'I':
				update(1, 0, n - 1, l, r, 2);
				break;
			case 'M':
				printf("%lld\n", query(1, 0, n - 1, l, r).sum);
				break;
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