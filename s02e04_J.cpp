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
    Node * children[26];    // represents the 26 letters in the alphabet
    vector<int> indices;
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
    for (int i = 0; i < 26; ++i)
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
	int query(string word, int ind, int p);
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
		char currentChar = tolower(word.at(i));
		int index = currentChar - 'a';
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
        currentNode->indices.push_back(idx);
        //cerr << currentChar << " " << idx << '\n';
        if (i == word.size() - 1) {
            // the last character of the word has been reached
        	currentNode->end = idx;
        }
    }
}

int Trie::searchForWord(string word)
{
	Node * currentNode = root;
	for (int i = 0; i < word.size(); ++i) {
		char currentChar = tolower(word.at(i));
		int index = currentChar - 'a';
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

int Trie::query(string word, int ind, int present) {
	int ans = 0;
	Node * currentNode = root;
	for (int i = 0; i < word.size(); ++i) {
		char currentChar = tolower(word.at(i));
		int index = currentChar - 'a';
		assert(index >= 0);
        // if the current node has the current character as one of its decendants
		if (currentNode->children[index] != NULL)
			currentNode = currentNode->children[index];
		else
			break;
        vector<int>::iterator it = lower_bound(currentNode->indices.begin(), currentNode->indices.end(), ind);
        ans += it - currentNode->indices.begin();
        if(present) ans++;
	}
	return ans;
}
 
Trie *t;
void precompute() {
	
}
void read() {
	s(n);
	t = new Trie();
}
void preprocess() {
	
}
void solve() {	
	for (int i = 0; i < n; ++i) {
		string w;
		cin >> w;
		t->addWord(w, i);
	}
	int q;
	s(q);
	for (int i = 0; i < q; ++i) {
		string qry;
		cin >> qry;
		int ind = t->searchForWord(qry);
		//cerr << "  " << ind << '\n';
		int add = (ind == -1) ? n : (ind + 1);
		cout << add + (t->query(qry, ind == -1 ? n : ind, ind == -1 ? 0 : 1)) << '\n';
	}
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}