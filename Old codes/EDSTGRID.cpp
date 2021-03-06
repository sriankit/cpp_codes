//============================================================================
// Name        : EditDistanceOnFGrid.cpp
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
typedef vector<vector<int> > Matrix;
typedef vector<string> charMat;
/*Main code begins now */

class solver{
public:
	Matrix map;
	int n,m;
	int totalCost[101][101], lo[101][101], hi[101][101];
	vector<vector<int> >ans, rival;
	vector<vector<int> >steps[101][101];
	int c2, c3;

	solver(charMat mat, int cst2, int cst3) {
		n = SZ(mat);
		m = SZ(mat[0]);
		map.resize(n);
		for (int i = 0; i < n; ++i) {
			vector<int>v(m);
			for (int j = 0; j < m; ++j) {
				v[j] = ((mat[i][j] == 'B') ? 1 : 0);
			}
			map[i].assign(v.begin(), v.end());
		}
		c2 = cst2;
		c3 = cst3;
	}

	void columnConnect(int c, int median) {
		vector<int>up;
		for (int i = median - 1; i >= 0; i--) {
			if(map[i][c] == 1) up.pb(i);
		}
		vector<int> down;
		for (int i = median; i < n; i++) {
			if(map[i][c] == 1) down.pb(i);
		}

		if(up.size() + down.size() == 0) {
			totalCost[c][median] = -1;
			lo[c][median] = -1;
			hi[c][median] = -1;
			return;
		}


		int target;
		if(map[median][c] == 0 && SZ(down) == 0) target = median;
		else {
			target = median - 1;
		}

		foreach(rr, up) {
			int r = *rr;
			while (r < target) {
				int arr[] = {1, r, c, r + 1, c};
				vector<int> vec (arr, arr + 5);
				steps[c][median].pb(vec);
				totalCost[c][median] += 1;
				r++;
			}
			target--;
		}
		lo[c][median] = target + 1;

		target = median;

		foreach(rr, down) {
			int r = *rr;
			while (r > target) {
				static const int arr[] = {1, r, c, r - 1, c};
				vector<int> vec (arr, arr + 5);
				steps[c][median].pb(vec);
				totalCost[c][median] += 1;
				r--;
			}
			target++;
		}
		if(target == median) hi[c][median] = median;
		else hi[c][median] = target - 1;
	}
public:
	void solveIt() {

		fill(totalCost, 0);
		fill(lo, 0);
		fill(hi, 0);

		for (int c = 0; c < m; ++c) {
			for (int median = 0; median < n; ++median) {
				columnConnect(c, median);
			}
		}

		int lowestCost = 10000000;

		for (int median = 0; median < n; median++) {
			int startCol = -1;
			for (int j = 0; j < m; j++) {
				if(totalCost[j][median] != -1) {
					startCol = j;
					break;
				}
			}
			int endCol = -1;
			for (int j = m - 1; j >= 0; j--) {
				if(totalCost[j][median] != -1) {
					endCol = j;
					break;
				}
			}
			if(startCol == -1) continue;
			int currentCost = 0;
			rival.clear();
			for (int i = startCol; i <= endCol; i++) {
				if(totalCost[i][median] != -1) {
					currentCost += totalCost[i][median];
					rival.pb(steps[i][median]);
				}
				else {
					currentCost += c2;
					static const int arr[] = {2, median, i};
					vector<int> vec (arr, arr + 3);
					rival.pb(steps[i][median]);
				}
			}
			if(currentCost < lowestCost) {
				ans.resize(SZ(rival));
				for (int i = 0; i < SZ(rival); ++i) {
					ans[i] = rival[i];
				}
				lowestCost = currentCost;
			}
		}

	}

};

int main() {
	int t;
	s(t);
	while(t--){
		int n, m, c2, c3;
		scanf("%d%d%d%d",&n,&m,&c2,&c3);
		charMat table(n);
		for (int i = 0; i < n; ++i) {
			cin >> table[i];
		}
		solver soln(table, c2, c3);
		vector<vector<int> > v(soln.ans.begin(), soln.ans.end());
		printf("%d\n",SZ(v));

		foreach(vc, v) {
			vector<int> ops((*vc).begin(), (*vc).end());
			foreach(op, ops) {
				printf("%d ",*op);
			}
			printf("\n");
		}
	}
	return 0;
}

