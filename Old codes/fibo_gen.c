#include<stdio.h>
#define MOD 1000000007
typedef long int ll;
int main(){
    int i=0;
    ll a=2,c;
    ll b=1;
    int cnt=2;
    FILE *fpw=fopen("D:\\fibo.txt","w");
    fprintf(fpw,"{%ld,%ld,",a,b);
    while(i++<1000){
        c=(a+b)%MOD;
        fprintf(fpw,"%ld,",c);cnt++;
        a=b;
        b=c;
    }
    printf("reachd %d",cnt);
    fprintf(fpw,"\b}");
    system("pause");
    return 0;
}
