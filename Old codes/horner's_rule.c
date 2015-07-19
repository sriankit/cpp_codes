#include<stdio.h>
int a[1000];
int x;
int i,n;
long find_ans(int m){
    if(m==n) return a[m];
    return a[m]+x*find_ans(m+1);
}
int main(){
    scanf("%d",&n);
    for(i=0;i<=n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&x);
    long c=a[n];
    for(i=n;i>0;){
        c=c*x+a[--i];
    }
    printf("\n%ld",c);
    printf("\n%ld",find_ans(0));
    system("pause");
    return 0;
}
