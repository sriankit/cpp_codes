#include <bits/stdc++.h>
using namespace std;
#define N 20000
#define M 500
char s[N + 10];
int dp[N + 10][M + 10];
int main()
{
    scanf("%s",s+1);
    int n = strlen(s+1);
    int tc,t;
    cin>>tc;
    while(tc--)
    {
        int l,m,i,j;
        cin>>m>>l;
        int ans = 0;
        dp[0][0] = 1;
        int nu = 0;
        for(i = 1 ; i<=n ; i++)
        {
            int d = s[i] - '0';
            nu = (10*nu + d)%m;
            for(j = 0 ; j<m ; j++) dp[i][j] = 0;

            for(j = 0 ; j<m ; j++)
            {
                int k = j*10%m;
                dp[i][k] = dp[i][k] + dp[i-1][j];
            }
            int tar = nu - l;
            if(tar < 0) tar = tar + m;
            ans = ans + dp[i][tar];
            dp[i][nu]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
