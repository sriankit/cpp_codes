
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<iterator>
#include<string>
#include<sstream>
using namespace std;

int BIT[10005];

void update(int idx,int val){
    while(idx <= 10000){
        BIT[idx] = max(BIT[idx] , val);
        idx += (idx&-idx);
    }
}

int query(int idx){
    int mx = -1;
    while(idx ){
        mx = max(mx,BIT[idx]);
        idx -= (idx&-idx);
    }
    return mx;
}

int main(){
    int N,K,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&K);
        for(int i=1;i<=10000;i++) BIT[i] =0 ;
        int max_ans  = 1 ,ele , tmp;
        for(int i=1;i<=N;i++){
            ele = ((long long)i * i)%10000 + 1;
            tmp = query(ele-1) + 1;
            max_ans = max(max_ans , tmp);
            update(ele , tmp);
        }
        printf("%d\n",max_ans >= K);
    }
    return 0;
}
