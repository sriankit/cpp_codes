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

/**
* Class: Node
* Represents a node within a trie tree
*/
class Node
{
public:
    char value;             // the character value (a-z)
    int end;               // indicates whether this node completes a word
    Node * children[10];    // represents the 26 letters in the alphabet    
    Node(char value);
    ~Node();
};
 
/**
* Constructor method
*/
Node::Node(char value)
{
    this->value = value;
    // Initializes all of the children with NULL value
    for (int i = 0; i < 10; ++i)
        children[i] = NULL;
    end = -1;
}
 
/**
* Destructor method
*/
Node::~Node()
{
    // free resources
}
 
/**
* Class: Trie
* Represents a trie tree data structure
*/
class Trie
{
public:
    Trie();
    ~Trie();
    void addWord(string word, int idx);
    int searchForWord(string word);
    Node * getRoot();
private:
    Node * root;
};

/**
* Constructor method
*/
Trie::Trie()
{
    // Initialize the trie
    root = new Node(' ');
    root->end = -1;
}

/**
* Destructor method
*/
Trie::~Trie()
{
    // Free resources
}

/**
* Gets the root of the trie
* @return Node *    Pointer to the root node
*/
Node * Trie::getRoot()
{
    return root;
}

/**
* Add a word to the trie
* @param string Word to add to the trie
* @return void
*/
void Trie::addWord(string word, int idx)
{
    Node * currentNode = root;

    for (int i = 0; i < word.size(); ++i)
    {
        char currentChar = word.at(i);
        int index = currentChar - '0';
        assert(index >= 0);     // Makes sure the character is between a-z
        if (currentNode->children[index] != NULL)
        {
            // check if the current node has the current character as one of its decendants
            currentNode = currentNode->children[index];
        }
        else
        {
            // the current node doesn't have the current character as one of its decendants
            Node * newNode = new Node(currentChar);
            currentNode->children[index] = newNode;
            currentNode = newNode;
        }
        //cerr << currentChar << " " << idx << '\n';
        if (i == word.size() - 1) {
            // the last character of the word has been reached
            currentNode->end = idx;
        }
        cerr << i << " " << word << endl;
    }
}

int Trie::searchForWord(string word)
{
    Node * currentNode = root;
    for (int i = 0; i < word.size(); ++i) {
        char currentChar = word.at(i);
        int index = currentChar - '0';
        assert(index >= 0);
        // if the current node has the current character as one of its decendants
        if (currentNode->children[index] != NULL)
            currentNode = currentNode->children[index];
        else
            return -1;
        // makes sure the last node is marked as an end for a word
        if (i == word.size() - 1 and currentNode->end != -1)
            return currentNode->end;
    }
    return -1;
}
 
ll a, b, c;
void precompute() {
    
}
void read() {
    sl(a);
    sl(b);
    sl(c);  
}
void preprocess() {
    
}
void solve() {
    Trie *t = new Trie();
    ll last = 1;
    t->addWord("1", 0); 
    int fr = -1, ans = -1;
    for (int i = 1; i <= 2e7; ++i) {
        ll num = (a * last + last % b) % c;
        stringstream ss;
        ss << num;
        string nms;
        ss >> nms;
        int rs = t -> searchForWord(nms);
        //cout << nms << " " << rs << '\n';
        if(rs != -1) {
            int idx = rs;
            if(fr == -1 || idx < fr) {
                fr = idx;
                ans = i;
            }
        } else t->addWord(nms, i);
        last = num;
    }
    cout << ans;
}
int main() {
    precompute();
    read();
    preprocess();
    solve();
    return 0;
}