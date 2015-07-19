//============================================================================
// Name        : Kamehameha.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Kamehameha in C++, Ansi-style
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
int mat[2002][2002];
int dp[2002][2002];

int go(int r, int c){
	if(r < 0 || c < 0) return 0;
	int &res = dp[r][c];
	if(dp[r][c] == -1) {
		int sum = 0;
		for (int i = 0; i <= c; ++i) {
			sum += mat[r][i];
		}
		if(sum == 0) res = go(r - 1, c);
		sum = 0;
		for (int i = 0; i <= r; ++i) {
			sum += mat[i][c];
		}
		if(sum == 0) res = go(r, c - 1);
		int val1 = 0, val2 = 0;
		vector<int> onesR, onesC;
		for (int i = 0; i <= c; ++i) {
			if(mat[r][i]==1) onesR.pb(i);
			mat[r][i] = 0;
		}
		val1 = 1 + go(r - 1, c);
		foreach(v, onesR){
			mat[r][*v] = 1;
		}
		for (int i = 0; i <= r; ++i) {
			if(mat[i][c]==1) onesC.pb(i);
			mat[i][c] = 0;
		}
		val2 = 1 + go(r, c - 1);
		foreach(v, onesC){
			mat[*v][c] = 1;
		}
		res = miN(val1, val2);
	}
	return res;
}

int maxInd(int *a, int n) {
	int mx = a[0], ind = 0;
	for (int i = 0; i < n; ++i) {
		if(mx < a[i]) {
			mx = a[i];
			ind = i;
		}
	}
	return ind;
}

int mark[2002][2002];
int clone[2002][2002];
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		fill(mat,0);
		fill(dp,-1);
		fill(mark, 0);
		int n;
		scanf("%d",&n);
		vector<pair<int,int> > vn;


		map<int, int> cols, rows;
		for (int i = 0; i < n; ++i) {
			int u,v;
			scanf("%d%d",&u,&v);
			vn.pb(pair<int,int>(u, v));
			cols[v]=1;
			rows[u]=1;
		}
		sort(vn.begin(),vn.end());
		//cout << vn;
		int r = 0, c = 0;


		foreach(col, cols) {
			col -> SS = c++;
		}

		foreach(row, rows) {
			row -> SS = r++;
		}

		foreach(p, vn){
			p -> FF = rows[p->FF];
			p -> SS = cols[p->SS];
		}
		int cntR[2002],cntC[2002];
		fill(cntR, 0);
		fill(cntC, 0);

		foreach(p, vn) {
			mat[p->FF][p->SS]=1;
		}
		//puts("mapped the values");

		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				cntR[i] += mat[i][j];
				cntC[j] += mat[i][j];
			}
		}

		//int ans = go(r - 1, c - 1);
		int ans = r;
		ans = miN(ans, c);

		int rival = 0;

		vector<int> cold, rowd;

		memcpy(clone, mat, sizeof(mat));

		while(1) {
			int indR = maxInd(cntR, r);
			int indC = maxInd(cntC, c);
			if(cntR[indR] <= 0) break;
			if(cntR[indR] >= cntC[indC]) {
				rival ++;
				cntR[indR] = 0;
				rowd.pb(indR);
				for (int i = 0; i < c; ++i) {
					cntC[i] -= mat[indR][i];
					mat[indR][i] = 0;
				}
			} else {
				rival ++;
				cntC[indC] = 0;
				cold.pb(indC);
				for (int i = 0; i < r; ++i) {
					cntR[i] -= mat[i][indC];
					mat[i][indC] = 0;
				}
			}
		}

		//debug(r,c);

		foreach(col, cold) {
			for (int i = 0; i < r; ++i) {
				if(clone[i][*col]) mark[i][*col]++;
			}
		}

		foreach(row, rowd) {
			for (int j = 0; j < c; ++j) {
				if(clone[*row][j]) mark[*row][j]++;
			}
		}

		for (int i = 0; i < r; ++i) {
			int res = 1;
			for (int j = 0; j < c; ++j) {
				if(clone[i][j]) res &= (mark[i][j] >= 2);
			}
			if(res) rival--;
		}

		for (int j = 0; j < c; ++j) {
			int res = 1;
			for (int i = 0; i < r; ++i) {
				if(clone[i][j]) res &= (mark[i][j] >= 2);
			}
			if(res) rival--;
		}

		printf("%d\n",miN(ans, rival));
	}

	return 0;
}

