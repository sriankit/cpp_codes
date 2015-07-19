#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
int main()
{
    long n,k,a,x,y,i;
    scanf("%ld%ld",&n,&k);
    vector<pair<long,long> >v;
    for(i=0;i<n;i++)
        {
        scanf("%ld",&a);
        v.pb(mp(a,i));
        }
    sort(v.begin(),v.end());
    i=0;
    long ans=0;
    while(i<n)
    {
    x=v[i].first;
    y=v[i].second;
    while (i<n && v[i].first==x && v[i].second-y<k)
        i++;
    ans++;
    }
    printf("%ld",ans);
    return 0;
}
