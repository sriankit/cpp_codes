#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template< class T > T abs(T n) { return (n < 0 ? -n : n); }
template< class T > T max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }

#define MP(x, y) make_pair(x, y)
#define REV(s, e) reverse(s, e)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ALL(c) c.begin(), c.end()
#define SIZE(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >

#define DEBUG 0
const double EPS = 1e-9;
const double BIG = 1e19;
const int INF = 0x7f7f7f7f;

i64 base[16][16], X[16], mod = 1000000007;
int d;
i64 n;

void print2D(i64 (*mat)[16], int r) {
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 16; ++j) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void mul(i64 a[16][16], i64 b[16][16]) {
	int i, j, k;
	i64 r[16][16];
	for(i = 0; i < 16; i++) {
		for(j = 0; j < 16; j++) {
			r[i][j] = 0;
			for(k = 0; k < 16; k++) {
				r[i][j] += (a[i][k]*b[k][j]) % mod;
				if(r[i][j] >= mod) r[i][j] -= mod;
			}
		}
	}
	CPY(a, r);
}

void pwr(i64 r[16][16], i64 e) {
	i64 b[16][16];
	for(int i = 0; i < 16; i++) {
		for(int j = 0; j < 16; j++) {
			r[i][j] = 0;
			b[i][j] = base[i][j];
		}
		r[i][i] = 1;
	}
	#if DEBUG 	
	printf("2D for r\n");
	print2D(r, 16);
	#endif
	while(e > 0) {
		if(e & 1) mul(r, b);
		e >>= 1;
		mul(b, b);
	}
}


int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, i;
	i64 a, b, tot;
	test = 1;
	while(test--) {
		scanf("%lld", &n);
		scanf("%d", &d);
		CLR(base);

		for(i = 1; i < 16; i++) base[i][i-1] = 1;
		for(i = 0; i < d; i++) {
			int k;
			scanf("%d", &k);
			base[0][k - 1] = 1;
			X[k] = 1;
		}
		for (int i = 1; i < 16; ++i) {
			for (int j = 1; i - j >= 0; ++j) {
				if(base[0][j - 1] == 1) {
					X[i] += X[i - j];
				}
			}
		}		
		if(n <= 15) {
			printf("%lld\n", 2 * X[n]);
			continue;
		}
		i64 a[16][16];
		pwr(a, n - 15);
		#if DEBUG
		print2D(a, 16);
		print2D(base, 16);
		#endif
		i64 ans = 0;
		for (int i = 0; i < 16; ++i)
		{
			ans += (X[15 - i] * a[0][i]) % mod;
			if(ans >= mod) ans -= mod;
		}
		ans <<= 1;
		printf("%lld\n", ans % mod);
	}
	return 0;
}