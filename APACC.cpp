#include<stdio.h>
int b,l,n,adj[401][80500],nei[81000][3];
double gl[401][80500];
void pre() {
    int i,j,k=1,idx;
    adj[1][1]=k++;
    for(i=2;i<=400;i++) {
        for(j=1;j<=i;j++)
            adj[i][j]=k++;
        for(j=1;j<i;j++) {
            idx=adj[i-1][j];
            nei[idx][0]=idx;
            nei[idx][1]=adj[i][j];
            nei[idx][2]=adj[i][j+1];
        }
    }
}
void go(double cap, int le, int nu) {
    if(le>l) return;
    double diff=250-gl[le][nu];
    if(cap>=diff) {
        double pass = (cap-diff)/3.0;
        gl[le][nu]=250.0;
        go(pass,le+1,nei[nu][0]);
        go(pass,le+1,nei[nu][1]);
        go(pass,le+1,nei[nu][2]);
    }
    else {
        gl[le][nu] += cap;
    }
}
int main()
{
    freopen("input.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,i,j;
    pre();
    scanf("%d",&t);
    for(int tcase = 1; tcase <= t; tcase++)
    {
        scanf("%d%d%d",&b,&l,&n);
        for(i=1;i<=l;i++)
            for(j=1;j<=(l*(l+1))/2;j++)
                gl[i][j]=0.0;
        go(b*750.0,1,1);
        //if(gl[l][n]<0.0) gl[l][n]=0.0;
        printf("Case #%d: %.7lf\n",tcase,gl[l][n]);
    }
    return 0;
