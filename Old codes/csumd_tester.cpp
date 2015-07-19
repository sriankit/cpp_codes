#include<stdio.h>

#define FOR(k,a,b) for(typeof(a) k=(a); k < (b); ++k)
typedef long long ll;
 
#define dim 4
 /*
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
*/
struct matrix {
    ll a[dim][dim];
};
 
#define MOD 1000000007

inline ll mod(ll n){
    if(n<0) return mod(n+MOD);
    else return n%MOD;
}

matrix mul(matrix x, matrix y) {
    matrix res;
    FOR(a,0,dim) FOR(b,0,dim) res.a[a][b] = 0;
    FOR(a,0,dim) FOR(b,0,dim) FOR(c,0,dim) {
	res.a[a][c] +=mod (x.a[a][b] * ll(y.a[b][c]));
	res.a[a][c] = mod(res.a[a][c]);
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
 
int main() {
    FOR(a,0,dim) FOR(b,0,dim) M.a[a][b] = 0;
    M.a[0][0] = 3; M.a[0][1] = -1; M.a[0][2]= -1; M.a[0][3]=-2;
    M.a[1][0] = M.a[2][1]=M.a[3][2]=1;
    C.a[0][0] = 3;
    C.a[1][0] = 1;
    C.a[2][0] = 0;
    C.a[3][0] = 0;
    int nt;
    scanf("%d",&nt);
    while(nt--) {
	ll n;
	scanf("%lld",&n);
	//cin>>n;
	//n=scanInt();
	if(n <= 4) {
	    if(n==4)printf("3\n");
	    else if(n==3) printf("1\n");
	    else puts("0");
        continue;
	}
	ll rs = n - 3;
	RP = power(M, rs);
	A = mul(RP, C);
	printf("%lld\n",mod(A.a[0][0]),nt);
    }
    return 0;
}
