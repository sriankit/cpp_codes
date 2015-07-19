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
		for(int i=0;i<n;i++){
			b[i]=i+1;
		}
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		int cyc=0;
		memset(done,0,sizeof(done));
		int c=1;
		for(int c=1;c<=n;c++){
			int do=0;
			while(done[c]==0){
				do=1;
				done[c]=1;
				c=a[c-1];
			}
			if(do) cyc++;
		}
		printf("%d\n",cyc);
	}
	return 0;
}
