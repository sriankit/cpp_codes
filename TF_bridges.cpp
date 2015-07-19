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

int TEST_NO;
#define NIL -1

class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists
    map<PII, int> brd;
    int ans;
    void bridgeUtil(int v, bool visited[], int disc[], int low[], int parent[]);
    int go(int v, bool visited[]);
    void addBridge(int v, int w);
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void bridge();    
    int find_ans();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    brd.clear();
    ans = 0;
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
}

int Graph::go(int v, bool visited[]) {
	//cout << " tr " << v << endl;
    visited[v] = true;
    if(v == V - 1) return 1;
    int ret = 0;
    list<int>::iterator it;
    for (it = adj[v].begin(); it != adj[v].end(); ++it) {
        int w = *it;
        //cout << " tr " << v  << " " << w << endl;
        if(visited[w]) continue;
        int res = go(w, visited);
        ret |= res;
        if(res == 1 and brd.count(make_pair(v, w))) {
            ans++;
            //cout << v << " " << w << endl;
        }
    }
    return ret;
}

int Graph::find_ans() {
    bool *visited = new bool[V];
    memset(visited, false, sizeof visited);
    go(0, visited);
    return ans;
}

void Graph::addBridge(int v, int w) 
{
    brd[make_pair(v, w)] = 1;
    brd[make_pair(w, v)] = 1;
}

void Graph::bridgeUtil(int u, bool visited[], int disc[], 
                                       int low[], int parent[])
{
    // A static variable is used for simplicity, we can avoid use of static
    // variable by passing a pointer.
    static int time = 0;
 
    // Mark the current node as visited
    visited[u] = true;
 
    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
 
    // Go through all vertices aadjacent to this
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;  // v is current adjacent of u
 
        // If v is not visited yet, then recur for it
        if (!visited[v])
        {
            parent[v] = u;
            bridgeUtil(v, visited, disc, low, parent);
 
            // Check if the subtree rooted with v has a connection to
            // one of the ancestors of u
            low[u]  = min(low[u], low[v]);
 
            // If the lowest vertex reachable from subtree under v is 
            // below u in DFS tree, then u-v is a bridge
            if (low[v] > disc[u])
                addBridge(u, v);
        }
 
        // Update low value of u for parent function calls.
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}
 
// DFS based function to find all bridges. It uses recursive function bridgeUtil()
void Graph::bridge()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
 
    // Initialize parent and visited arrays
    for (int i = 0; i < V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
    }
 
    // Call the recursive helper function to find Bridges
    // in DFS tree rooted with vertex 'i'
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            bridgeUtil(i, visited, disc, low, parent);
}

void precompute() {
    
}
void read() {
    int n, m;
    s(n), s(m);
    Graph g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        s(u), s(v);
        --u, --v;
        g.addEdge(u, v);
    }   
    g.bridge();
    printf("%d\n", g.find_ans());       
}
void preprocess() {
    
}
void solve() {
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