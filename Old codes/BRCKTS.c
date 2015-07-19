#include<stdio.h>
#include<string.h>
int tree[30005];
int MaxVal;
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
int freqAt(int idx){
	int sm=tree[idx],y;
	if(idx>0){
		int z=idx-(idx & -idx);
		y=idx-1;
		while(y!=z){
			sm-=tree[y];
			y-=(y & -y);
		}
	}
	return sm;
}
int main(){
    int W;
    for(W=1;W<=10;W++){
        memset(tree,0,sizeof(tree));
        int i,n,k;
        scanf("%d",&n);
        char arr[n];
        scanf("%s",arr);
        MaxVal=n+3;
        for(i=0;i<n;i++){
            if(arr[i]=='(') update(i+1,1);
            else update(i+1,-1);
        }
        //getchar();
        scanf("%d",&n);
        printf("Test %d:\n",W);
        while(n--){
            scanf("%d",&k);
            if(k>0){
                if(freqAt(k)==1) update(k,-2);
                else update(k,2);
            }
            else{
                if(freqTo(MaxVal-1)) puts("NO");
                else puts("YES");
            }
        }
    }
    return 0;
}
