#include<stdio.h>
#include<string.h>
int mem[100][100];
int los(int n,int p){
    if(n<=0) return 0;
    if(mem[n][p]!=-1) return mem[n][p];
    int &r=mem[n][p];
    for(int t=1;t<=p;t++)
        if(los(n-t,t)) return r=1;
    return r=0;
} 
int main(){
    int n;
    memset(mem,-1,sizeof(mem));
    for(int n=1;n<20;n++){
        printf("%d ",n);
        int isLosing=los(n,n-1);
        if(isLosing) puts("Lost");
        else puts("win");
    }
    system("pause");
    return 0;
}
        
            
