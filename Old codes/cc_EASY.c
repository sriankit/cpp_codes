#include<stdio.h>
#include<stdlib.h>
int main(){
    int t;
    scanf("%d\n",&t);
    while(t--){
        int n;
        scanf("%d\n",&n);
        int *a=(int*)calloc(n,sizeof(int));
        char c;
        int i=0;
        while(i<n && (c=getchar())!='\n'&&c!=EOF){
            if(c=='1'){
                if(i>0) a[i-1]=1;
                if(i<n-1) a[i+1]=1;
                a[i]=1;
            }
            i++;
        }
        long ans=0;
        for(i=0;i<n;i++)
            ans+=!a[i];
        printf("%ld\n",ans);
    }
    return 0;
}
