#include<stdio.h>
#define FOR(k,a,b) for(typeof(a) k=(a); k < (b); ++k)
typedef long long ll;
 
#define dim 3
 
struct matrix {
    int a[dim][dim];
};
 
#define MOD 1000000007
 
ll mod(ll n){
    if(n<0) return mod(n+MOD);
    else return n%MOD;
}
 
long long int powr(ll x, ll y)
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
 
matrix mul(matrix x, matrix y) {
    matrix res;
    FOR(a,0,dim) FOR(b,0,dim) res.a[a][b] = 0;
    FOR(a,0,dim) FOR(b,0,dim) FOR(c,0,dim) {
	res.a[a][c] += (x.a[a][b] * ll(y.a[b][c])) % MOD;
	res.a[a][c] %= MOD;
    }
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
 
ll trib(ll n) {
    FOR(a,0,dim) FOR(b,0,dim) M.a[a][b] = 0;
    M.a[0][0] = M.a[0][1] = M.a[0][2]=1;
    M.a[1][0] = M.a[2][1] = 1;
    C.a[0][0] = 1;
    C.a[1][0] = C.a[2][0] = 0;
	ll rs = n - 2;
	RP = power(M, rs);
	A = mul(RP, C);
	return A.a[0][0];
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll n;
        scanf("%lld",&n);
        printf("%ld\n",mod(powr(2,n)-trib(n+3)));
    }
    return 0;
}
