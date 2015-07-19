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

int n, k, l;
int TEST_NO;
bool sieve[10000007];
int nmax = 10000007;
vector<string> pr;
vector<string> ans;
string str(int i) {
	ostringstream stream;
	stream << i;
	return stream.str();
}
int toInt(string s) {
	return atoi(s.c_str());
}
int mask[8];
void precompute() {
	sieve[0] = sieve[1] = 1;
	for (ll i = 0; i < nmax; ++i) {
		if(sieve[i] == 1) continue; 
		pr.push_back(str(i)); 
		for (ll j = i * i; j < nmax; j += i) {
			sieve[j] = 1;
		} 
	}
}
void read() {
	s(n);
	s(k);
	s(l);
}
void preprocess() {
	
}
int go(string num) {
	std::vector<string> family;		
	for (int dig = 0; dig < 10; ++dig){
        string newNum = num;
		for (int i = 0; i < num.size(); ++i) {
			if(mask[i] == 1) newNum[i] = '0' + dig;
		}
		if(newNum[0] == '0') continue;
		if(sieve[toInt(newNum)] == 0) {
			family.push_back(newNum);
		}
	}
	if(family.size() >= l) {
		if(ans.size() == 0 || ans[0] > family[0]) ans = family;            
		return 1;
	}	
	return 0;
}
void compute() {
	do{
		for (std::vector<string>::iterator it = pr.begin(); it != pr.end(); ++it) {
			string s = *it;
			if(s.size() == n) {
				int res = go(s);
				if(res) return;
			}		
		}
	} while(next_permutation(mask, mask + n));
}
void solve() { 
	for (int i = n - k; i < n; ++i) {
		mask[i] = 1; 	
	} 
	compute();
	int cntr = 0;	
	for (std::vector<string>::iterator it = ans.begin(); cntr < l and it != ans.end(); ++it) {
		cntr++;
		cout << *it << " ";
	}
}
int main() {
	precompute();
	int t;
	t = 1;
	for(TEST_NO = 1; TEST_NO <= t; TEST_NO ++) {
		read();
		preprocess();
		solve();
	}
	return 0;
}