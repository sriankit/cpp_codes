#include<stdio.h>
int tree[400005];
int mark[400005];
#define MaxVal 400005
int freqTo(int idx){
	int sm=0;
	while(idx>0){
		sm+=tree[idx];
		idx-=(idx & -idx);
	}
	return sm;
}
void update(int idx,int val){
	while(idx<=MaxVal){
		tree[idx]+=val;
		idx+=(idx & -idx);
	}
}
int main(){
    int t,a,b,n,i;
    scanf("%d",&t);
    while(t--){
        memset(tree,0,sizeof(tree));
        memset(mark,0,sizeof(mark));
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            int v1,v2;
            v1=freqTo(a);v2=freqTo(b);
            update(a,i+1-v1);
            update(b+1,-(i+1-v2));
        }
        int cnt=0;
        for(i=1;i<=n;i++){
            int v=freqTo(i);
            printf("%d  ",v);
            if(mark[v]==0){
                cnt++;
                mark[v]++;
            }
        }
        printf("%d\n",cnt);
    }
    system("pause");
    return 0;
}
            
        
            
        
        
