#include <iostream>
#include <cstring>
using namespace std;
class Manachers
{
    string S,T;
    int n;
    // P[i] stands for the longest palindrome centered at location i.
    int *P;
    // 1221 becomes ^#1#2#2#1#$
    string preProcess(string s)
    {
        int n = s.length();
        if (n == 0) return "^$";
        string ret = "^";
        for (int i = 0; i < n; i++)
            ret += "#" + s.substr(i, 1);

        ret += "#$";
        return ret;
    }
public:
    int max_length,cnt;
    Manachers(string s)
    {
        S = s;
        T = preProcess(s);
        n = T.length();
        P = new int[n];
    }
    void longestPalindrome()
    {
        int C=0,R=0;
        for(int i=1; i<n-1; i++)
        {
            // Leverage previous computed P[i] when we calculate a P[x] where x>i
            P[i] = (R>i)?min(R-i,P[2*C-i]):0;
            // For a particular position, we check its left and right
            while(T[i+1+P[i]]==T[i-1-P[i]])
            {
                P[i]++;
            }
            // Expand center when a larger palindrome is found
            if(i+P[i]>R)
            {
                C = i;
                R = i+P[i];
            }
        }
        max_length = 0;
        int centerIndex = 0;
        for (int i = 1; i < n-1; i++)
        {
            if (P[i] > max_length)
            {
                max_length = P[i];
                cnt=1;
		centerIndex = i;
            }
	    else if(P[i]==max_length)
		cnt++;
        }
        delete[] P;
        //return S.substr((centerIndex - 1 - max_length)/2, max_length);
    }
};

int main()
{
    string s;
    int t;
    scanf("%d",&t);
    while(t--){
        cin>>s;
        Manachers m(s);
        m.longestPalindrome();
        //cout<<m.max_length<<" "<<m.cnt;
        printf("%d %d\n",m.max_length,m.cnt);
    }
    return 0;
}
