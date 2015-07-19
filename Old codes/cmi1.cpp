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

int BIT[100005];

void update(int idx,int val){
    while(idx <= 100004){
        BIT[idx] += val;
        idx += (idx&-idx);
    }
}

int query(int idx){
    int mx = 1000000;
    while(idx){
        mx = min(mx,BIT[idx]);
        idx -= (idx&-idx);
    }
    return mx;
}
int freqAt(int idx){
	int sm=BIT[idx],y;
	if(idx>0){
		int z=idx-(idx & -idx);
		y=idx-1;
		while(y!=z){
			sm-=BIT[y];			
			y-=(y & -y);
		}
	}
	return sm;
}
int main(){
	int n;
	scanf("%d",&n);
	int ans=0;
	vector<int>sol;
	map<int,int> m;
	while(n--){
		int s,e;
		scanf("%d%d",&s,&e);
		
	}
	printf("%d\n",ans);
	for(vector<int>::iterator it = sol.begin();it!=sol.end();it++) printf("%d ",*it);
	return 0;
}

