#include<stdio.h>
long table[1001][1001];
int r[1001];
int c[1001];
int main(){
    int n,m,a,b,i,j;
    char ch;
    long q;
    scanf("%d%d%ld",&n,&m,&q);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%ld",&table[i][j]);
    for(i=1;i<=n;i++)
        r[i]=i;
    for(j=1;j<=m;j++)
        c[j]=j;
    while(q--){
        scanf("%c%d%d",ch,&a,&b);
        if(ch=='r'){
            int t=r[a];
            r[a]=r[b];
            r[b]=t;
        }
        else if(ch=='c'){
            int t=c[a];
            c[a]=c[b];
            c[b]=t;
        }
        else printf("%ld\n",table[r[a]-1][c[b]-1]);
    }
    return 0;
}
