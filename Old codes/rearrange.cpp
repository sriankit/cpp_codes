#include<stdio.h>
#include<string.h>

int a[100005];
int b[100005];
int done[100005];
void go(int c){
	
}
int main(){
	int t;
	
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			b[a[i]]=i+1;	
		}
		int cyc=0;
		memset(done,0,sizeof(done));
		int c=1,d=0;
		for(int i=0;i<n;i++){
			c=a[i];
			if(b[c]==c || done[c] == 1) continue;
			while(done[c]==0) {
				done[c]=1;
				c=b[c];
			} 
			cyc++;
		}
		printf("%d\n",cyc);
	}
	return 0;
}
