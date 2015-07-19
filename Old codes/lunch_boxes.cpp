#include<cstdio>
#include<set>
#include<utility>
#include<vector>
using namespace std;
int main(){
	int n,w;
	scanf("%d%d",&n,&w);
	vector<pair<int,int> > v;
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		v.push_back(pair<int,int>(a,i));
		
	}
	vector<vector<int> > ans;
	multiset<pair<int,int> ,greater<pair<int,int> > > q;
	vector<int> l;
	int cw=0;
	int ind=n-1;
	int cnt=1;
	for(int i=n-1;i>=0;i--){
		int ok=0;
		if(!q.empty()){
			int req=w-v[i].first;
			multiset<pair<int,int> ,greater<pair<int,int> > >::iterator it = q.lower_bound(pair<int,int>(req,n));		
			if(it!=q.end()){			
			pair<int,int> m=*it;		
			if(m.first+v[i].first<=w) {
				q.erase(it);
				ind=m.second;
				ans[ind].push_back(i);
				m.first+=v[i].first;
				q.insert(m);
				ok=1;
			}}
		}
		if(ok) continue;
		if(cw+v[i].first<=w){
			l.push_back(v[i].second);
			cw+=v[i].first;
		}
		else{
			ans.push_back(l);
			q.insert(pair<int,int>(cw,cnt-1));	
			cw=v[i].first;
			l.clear();
			l.push_back(v[i].second);
			cnt++;
		}		
	}
	ans.push_back(l);
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++){
		printf("%d ",ans[i].size());
		for(int j=0;j<ans[i].size();j++) printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
	
}
