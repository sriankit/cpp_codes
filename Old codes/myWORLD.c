#include<stdio.h>
#define FOR(k,a,b) for(typeof(a) k=(a); k < (b); ++k)
typedef long long ll;
//using namespace std;
 
#define dim 2
 
struct matrix {
    ll a[dim][dim];
};
 
#define MOD 1000000007

inline ll scanInt()
{
ll noRead=0;
char p=getchar_unlocked();
for(;p<33;){p=getchar_unlocked();};
while(p>32)
{
noRead = (noRead << 3) + (noRead << 1) + (p - '0');
p=getchar_unlocked();
}
return noRead;
}; 
 
ll mod(ll n){
    if(n<0) return mod(n+MOD);
    else return n%MOD;
}
 
/*long long int powr(ll x, ll y)
{
    // printf("%d\n",y);
    ll temp=0;
    if( y == 0)
        return 1;
    else if(y==1)
        return x;
    else if (y%2 == 0)
    {
        temp=powr(x,y/2)%1000000007;
        return (temp*temp)%1000000007;
    }
 
    else
    {
        temp=powr(x,y/2)%1000000007;
        return (x*((temp*temp)%1000000007))%1000000007;
    }
 
}
 */
struct matrix mul(matrix x, matrix y) {
    matrix res;
    res.a[0][0]=mod(mod(x.a[0][0]*y.a[0][0])+mod(x.a[0][1]*y.a[1][0]));
    res.a[0][1]=mod(mod(x.a[0][0]*y.a[0][1])+mod(x.a[0][1]*y.a[1][1]));
    res.a[1][0]=mod(mod(x.a[1][0]*y.a[0][0])+mod(x.a[1][1]*y.a[1][0]));
    res.a[1][1]=mod(mod(x.a[1][0]*y.a[0][1])+mod(x.a[1][1]*y.a[1][1]));
    return res;
}
 
matrix power(matrix m, ll n) {
    if(n == 1) return m;
    matrix u = mul(m, m);
    u = power(u, n/2);
    if(n&1) u = mul(u, m);
    return u;
}
 
matrix M, C, RP, A;
 
ll luc(ll n) {
    FOR(a,0,dim) FOR(b,0,dim) M.a[a][b] = 0;
    M.a[0][0] = M.a[0][1] = 1;
    M.a[1][0] = 1;
    C.a[0][0] = 1;
    C.a[1][0] = 2;
	if(n==0) return 2;
	else if(n==1) return 1;
	ll rs = n - 1;
	RP = power(M, rs);
	A = mul(RP, C);
	return A.a[0][0];
}

ll fib(ll n) {
    FOR(a,0,dim) FOR(b,0,dim) M.a[a][b] = 0;
    M.a[0][0] = M.a[0][1] = 1;
    M.a[1][0] = 1;
    C.a[0][0] = 1;
    C.a[1][0] = 0;
	if(n==0) return 0;
	if(n==1) return 1;
	ll rs = n - 1;
	RP = power(M, rs);
	A = mul(RP, C);
	return A.a[0][0];
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll n,N;
      //scanf("%lld",&N);
	N=scanInt();
	n=N+5;
        printf("%ld\n",mod(mod((mod(n)*luc(n)-fib(n))/5)-2*fib(n-1)-2*fib(n-2)-3*fib(n-3)+2*fib(N)));
    }
    return 0;
}
