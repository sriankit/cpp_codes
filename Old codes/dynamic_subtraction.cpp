#include<stdio.h>
#include<string.h>
int mem[1006][1006];
int res(int n,int p){
    if(n<=0) return 0;
    if(mem[n][p]!=-1) return mem[n][p];
    int &r=mem[n][p];
    for(int t=1;t<=p;t++)
        if(res(n-t,t)==0) return r=1;
    return r=0;
} 
int main(){
    int n;
    for(int n=1;n<100000;n++){
        memset(mem,-1,sizeof(mem));
        //printf("%d ",n);
        int r=res(n,n-1);
        if(r==0) //puts("Lost");
        //else //puts("win");
        printf("%d\n",n);
    }
    scanf("%d",&n);
    return 0;
}
        
            
