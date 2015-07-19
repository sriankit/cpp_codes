#include<stdio.h>
#include<string.h>
#include<math.h>
#include<map>
#include<vector>
using namespace std;
int arr[100005];
int let[100005],ryt[100005];
int mark[100005];
map<int,vector<int> > ma;
typedef long long ll;
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n; i++) {
		scanf("%d",&arr[i]);
		ma[arr[i]].push_back(i+1);
	}
	ll mx = 0;
	for(int a=0;a<100005;a++){
		if(ma.count(a)==0) continue;
		vector<int> now = ma[a];
		for(vector<int>::iterator it = now.begin();it!=now.end();it++){		
			int rawind = (*it)-1;
			//mx += a;
			int ind = rawind;
			while(ind >0 && arr[ind-1]<=a) {
				printf("%d\n",arr[ind-1]);
				ind = let[ind-1];
			}
			let[rawind] = ind;
			printf("%d ",let[rawind]);
			//mx += a*abs(ind - mark[a] + 1);               
			ll l = rawind - ind + 1;
			ind = rawind;
			while(ind + 1<n && arr[ind+1]<a) {
				ind = ryt[ind+1];
			}
			ryt[rawind] = ind;
			//mx += a*abs(ind - mark[a] + 1);
			int r = ind - rawind + 1;
			mx += a*l*r;
			printf("%d %d %lld\n",ryt[rawind],rawind,mx);
		}
	}
	printf("%lld\n",mx);
	ll mn = 0;
	memset(let,0,sizeof(let));
	memset(ryt,0,sizeof(ryt));
	for(int a=100005;a>=0;a--){
		if(ma.count(a)==0) continue;
		vector<int> now = ma[a];
		for(vector<int>::iterator it = now.begin();it!=now.end();it++){		
			int rawind = (*it)-1;
			//mx += a;
			int ind = rawind;
			while(ind >0 && arr[ind-1]>=a) {
				printf("%d\n",arr[ind-1]);
				ind = let[ind-1];
			}
			let[rawind] = ind;
			printf("%d ",let[rawind]);
			//mx += a*abs(ind - mark[a] + 1);               
			ll l = rawind - ind + 1;
			ind = rawind;
			while(ind + 1<n && arr[ind+1]>a) {
				ind = ryt[ind+1];
			}
			ryt[rawind] = ind;
			//mx += a*abs(ind - mark[a] + 1);
			int r = ind - rawind + 1;
			mn += a*l*r;
			printf("%d %d %lld\n",ryt[rawind],rawind,mn);
		}
	}
	printf("%lld\n",mn);
	printf("%lld",mx-mn);
}
