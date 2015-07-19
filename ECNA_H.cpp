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
char str[505];
string text;
string crib;
void precompute() {
	
}
void read() {
	scanf("%d\n", &n);
	int len = 0;
	text = "";
	while(len < n) {
		string buf;
		cin >> buf;
		text += buf;
		len += 5;
	}
	n = text.size();
	cin >> crib;
	//cerr << "  " << text << " " << crib << endl;
}
void preprocess() {
	
}
string shiftby(string s, int sh) {
	string res = "";
	for (int i = 0; i < s.size(); ++i) {
		res += (char)('A' + (s[i] - 'A' + sh + 26) % 26);
	}
	return res;
}
string modifyText(string text, int m) {
	string res = "";	
	int len = text.size();
	for (int i = 0; i < len; i += m) {
		int ptr = i + m - 1;
		while(ptr >= len) ptr--;
		while(ptr >= i) res += text[ptr --];
	}	
	assert(res.size() == len);
	return res;
}
bool verify(string modText, string crib, int shift) {
	string mtext = shiftby(modText, -shift);
	return mtext.find(crib) != string::npos;
}
void solve() {	
	int done = 0;
	for (int shift = 1; shift < 26 and !done; ++shift) {
		string shCrib = shiftby(crib, shift);
		for (int m = 5; m <= 20; ++m) {
			string modText = modifyText(text, m);
			if(modText.find(shCrib) != string::npos and verify(modText, crib, shift)) {				
				printf("%d %d\n", shift, m);
				done = 1;
				break;
			}
		}
	}
	if(!done) puts("Crib is not encrypted.");
}
int main() {
	precompute();
	int t;
	scanf("%d\n", &t);
	for(TEST_NO = 1; TEST_NO <= t; TEST_NO ++) {
		read();
		preprocess();
		solve();
	}
	return 0;
}