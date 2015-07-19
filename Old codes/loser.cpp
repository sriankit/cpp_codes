#include<string>
#include<iostream>
#include<vector>
#define mp(a,b) make_pair((a),(b))
#define pb(x) push_back((x))
using namespace  std;
int main(){
    int n,a,k;
    string s;
    vector<pair<string,int> >v;
    cin>>n;
    while(n--){
        cin>>s>>a;
        int flag=1;
        for(k=0;k<v.size();k++)
            if(v[k].first==s) {flag=0;v[k].second+=a;break;}
        if (flag) v.pb(mp(s,a));
    }
    int max=v[0].second;
    int flags=new int[v.size()];
    for(k=0;k<v.size();k++)
        if(max<v[k].second) max=v[k].second;
    for(k=0;k<v.size();k++)
        if(v[k].second==max) flags[k]=1;
    
