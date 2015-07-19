#include<stdio.h>
int f[333],g[333],h[333],gr[333],hr[333];
int cst[333][333];

#define INF 1000000000

int maxmin(int a,int b,int c){
	int mx=(a>b&&a>c)?a:(b>c?b:c);
	int mn=(a<b&&a<c)?a:(b<c?b:c);
	return mx-mn;
}

int fn(int i){
	if(f[i]==-1){
		f[i]=fn(i-2);
		int c1=INF;
		if(i>0) c1=maxmin(cst[i][0],cst[i][1],cst[i-1][0]);
		int c2=INF;
		if(i>0) c2=maxmin(cst[i][2],cst[i-1][2],cst[i-1][1]);
		int v2=INF,v0=INF,v1=INF;
		if(i>=2) {
			v0=maxmin(cst[i][0],cst[i-1][0],cst[i-2][0]);
			v1=maxmin(cst[i][1],cst[i-1][1],cst[i-2][1]);
			v2=maxmin(cst[i][2],cst[i-1][2],cst[i-2][2]);				
		}
		int h=INF;
		h=maxmin(cst[i][0],cst[i][1],cst[i][2]);
		
	}
	return f[i];
}

int gn(int i){
	if(g[i]==-1){
		int c1=INF;
		if(i>2) c1=maxmin(cst[i-1][0],cst[i-2][0],cst[i-3][0]);
		int c2=INF;
		if(i>=2) c2=maxmin(cst[i][1],cst[i-1][1],cst[i-2][1]);
		int cL=INF;
		if(i>0) cL=maxmin(cst[i][1],cst[i-1][1],cst[i-1][0]);
		
	}
}

int fn(int i){
	if(h[i]==-1){
		int cL=INF;
		if(i>0) cL=maxmin(cst[i][2],cst[i-1][2],cst[i-1][1]);
		int v=INF;
		if(i>=2) v=maxmin(cst[i][2],cst[i-1][1],cst[i-1][0]);
	}
}

int hrn(int i){
	if(hr[i]==-1){
		
	}
}

int grn(int i){
	
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		memset(cst,0,sizeof(cst));
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		memset(h,0,sizeof(h));
		printf("%d\n",fn(n-1));	
	}
	return 0;
}
