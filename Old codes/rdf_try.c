#include<stdio.h>
#include<vector>
#include<>
using namespace std;
typedef long long ll;
const ll lim = 100005;
#define pb(x) push_back(x)
vector<long double> arr[100005];
int maxk[100005];
const long double EPS = 1e(-7);
long double get(int i,int j){
	if(j>maxk[i]) return 0.0;
	else return arr[i][j];
}
int compare(long double d1,long double d2){
	if(abs(d1-d2)<=EPS) return 1;
	else return 0;	
}
int main(){
	int n,k;
	arr[0][0]=0;
	maxk[0]=0;
	for(n=1;n<lim;n++) {
		for(k=0;k<=n;k++) {
			if(k==0) arr[n].pb((long double)n);
			else {
				arr[n][k] = get(n-1,k-1)/n + ((n-1)/n)*get(n-1,k);
				if(compare(arr[n][k],0.0)) {
					maxk[n]=k;
					break;
				}
			}		
		}
	}
	puts("FINISHED");
	return 0;	
}
