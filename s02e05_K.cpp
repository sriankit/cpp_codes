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
vector<string> vec;
void precompute() {
    
}
void read() {
    string s;
    while(cin >> s) {
        vec.push_back(s);
    }
    n = vec.size();
}
void preprocess() {
    
}
void go(int l, int r, int ind) {
    int st = l;
    char strk = ' ';
    for (int i = l; i <= r; ++i) {
        string s = vec[i];
        if(s[ind] != '*' and s[ind] != '#') {
            if(st < i - 1) {
                if(ind > 0) cout << "<li>\n";
                if(strk == '#') cout << "<ol>\n";
                else cout << "<ul>\n";
                go(st, i - 1, ind + 1);
                if(strk == '#') cout << "</ol>\n";
                else cout << "</ul>\n";
                if(ind > 0) cout << "</li>\n";
                st = i;
            }
            while(st <= i) {
                if(ind > 0) cout << "<li>\n";
                cout << vec[st++].substr(ind) << '\n';
                if(ind > 0) cout << "</li>\n";
            }
            strk = ' ';
        } else if(strk == ' ') {
            strk = s[ind];
        }
        else if(s[ind] != strk) {
            if(st < i - 1) {
                if(ind > 0) cout << "<li>\n";
                if(strk == '#') cout << "<ol>\n";
                else cout << "<ul>\n";
                go(st, i - 1, ind + 1);
                if(strk == '#') cout << "</ol>\n";
                else cout << "</ul>\n";
                if(ind > 0) cout << "</li>\n";
                st = i;
                strk = s[ind];
            }   
        }
    }
    int i = r + 1;
    if(st < i - 1) {
        if(ind > 0) cout << "<li>\n";
        if(strk == '#') cout << "<ol>\n";
        else cout << "<ul>\n";
        go(st, i - 1, ind + 1);
        if(strk == '#') cout << "</ol>\n";
        else cout << "</ul>\n";
        if(ind > 0) cout << "</li>\n";
        st = i;
    }   
    while(st < i) {
                if(ind > 0) cout << "<li>\n";
                cout << vec[st++].substr(ind) << '\n';
                if(ind > 0) cout << "</li>\n";
            }
}
void solve() {
    go(0, n - 1, 0);
}
int main() {
    precompute();
    read();
    preprocess();
    solve();
    return 0;
}