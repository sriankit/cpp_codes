#include<stdio.h>
long long int t,n,i,j,a[100001],m;
int main()
{
    char sp[15];
    double s,p,q,sum=0;
        s=0;
    scanf("%lld%lld",&n,&t);
    for(i=0;i<n;i++)
    {scanf("%lld",&a[i]);
    if(a[i]<=t) {s++;sum+=a[i];}}
    if(n==1) {sprintf(sp,"%.9lf",sum/s); goto f;}
    else{
    for(i=0;i<n;i++)
    {
        p=a[i];
        j=i+1;
        while(j<n)
        {
           p+=a[j];
           if(p<=t) {s++;sum+=p;}
           j++;
        }
    }
    sprintf(sp,"%.9lf",sum/s);}
    f:
    for(i=10;i>=0;i--)
    {
        if(sp[i]=='0') sp[i]='\0';
        else if(sp[i]=='.') {sp[i]='\0';break;}
        else break;}
    puts(sp);
    return 0;
}
