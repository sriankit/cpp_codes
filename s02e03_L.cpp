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
int TEST_NO;
int turn, na, nb;
vector<pair<pair<int, int>, int> > a, b;
void precompute() {
	
}
int extract_minutes(string s) {
	stringstream stream;
	stream << s;
	int h, m;
	sscanf(s.c_str(), "%d:%d", &h, &m);
	//cout << s << " " << h * 60 + m << "         ";
	return h * 60 + m;
}
pair<int, int> parse_time() {	
	string s1, s2;
	cin >> s1 >> s2;	
	return make_pair(extract_minutes(s1), extract_minutes(s2));
}
void read() {
	a.clear();
	b.clear();
	s(turn), s(na), s(nb);
	for (int i = 0; i < na; ++i) {
		a.push_back(make_pair(parse_time(), 0));
	}
	for (int i = 0; i < nb; ++i) {		
		b.push_back(make_pair(parse_time(), 1));
	}
}
void preprocess() {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
}
void solve() {
	int tr[2];
	tr[0] = tr[1] = 0;
	priority_queue<int, vector<int>, greater<int> > pq [2];
	int pta = 0, ptb = 0;
	while(pta < a.size() and ptb < b.size()) {		
		pair<pair<int,int>, int> nxt;
		if(a[pta] < b[ptb]) {
			nxt = a[pta];
			pta ++;
		} else {
			nxt = b[ptb];
			ptb ++;
		}
		assert(nxt.FF.FF <= nxt.FF.SS);
		if(pq[nxt.SS].empty() or pq[nxt.SS].top() > nxt.FF.FF) {
			tr[nxt.SS]++;
			pq[1 - nxt.SS].push(nxt.FF.SS + turn);
		} else {
			pq[nxt.SS].pop();
			pq[1 - nxt.SS].push(nxt.FF.SS + turn);
		}		
	}
	while(pta < a.size()) {
		pair<pair<int,int>, int> nxt = a[pta++];
		if(pq[nxt.SS].empty() or pq[nxt.SS].top() > nxt.FF.FF) {
			tr[nxt.SS]++;
			pq[1 - nxt.SS].push(nxt.FF.SS + turn);
		} else {
			pq[nxt.SS].pop();
			pq[1 - nxt.SS].push(nxt.FF.SS + turn);
		}	
	}
	while(ptb < b.size()) {
		pair<pair<int,int>, int> nxt = b[ptb++];
		if(pq[nxt.SS].empty() or pq[nxt.SS].top() > nxt.FF.FF) {
			tr[nxt.SS]++;
			pq[1 - nxt.SS].push(nxt.FF.SS + turn);
		} else {
			pq[nxt.SS].pop();
			pq[1 - nxt.SS].push(nxt.FF.SS + turn);
		}	
	}
	printf("Case #%d: %d %d\n", TEST_NO, tr[0], tr[1]);
}
int main() {
	precompute();
	int t;
	s(t);
	for(TEST_NO = 1; TEST_NO <= t; TEST_NO ++) {
		read();
		preprocess();
		solve();
	}
	return 0;
}