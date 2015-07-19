#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
 
 
struct data {
    int sum; 
    int pref;
    int suff;
    int ans ;
} ;
data t[150005];
int a[50005];
data combine ( data l, data r ) {
    data res ;
	res. sum = l. sum + r. sum ;
	res. pref = max ( l. pref , l. sum + r. pref ) ;
	res. suff = max ( r. suff , r. sum + l. suff ) ;
	res. ans = max ( max ( l. ans , r. ans ) , l. suff + r. pref ) ;
	return res ;
} 
 
data make_data ( int val ) {
    data res ;
	res. sum = val ;
	res. pref = res. suff = res. ans = max( 0, val) ;
	return res ;
}
 
void build ( int a [ ] , int v, int tl, int tr ) {
	if ( tl == tr )
		t [ v ] = make_data ( a [ tl ] ) ;
	else {
		int tm = ( tl + tr ) / 2 ;
		build ( a, v * 2 , tl, tm ) ;
		build ( a, v * 2 + 1 , tm + 1 , tr ) ;
		t [ v ] = combine ( t [ v * 2 ] , t [ v * 2 + 1 ] ) ;
	}
}
 
void update ( int v, int tl, int tr, int pos, int new_val ) {
	if ( tl == tr )
		t [ v ] = make_data ( new_val ) ;
	else {
		int tm = ( tl + tr ) / 2 ;
		if ( pos <= tm )
			update ( v * 2 , tl, tm , pos, new_val ) ;
		else
			update ( v * 2 + 1 , tm + 1 , tr, pos, new_val ) ;
		t [ v ] = combine ( t [ v * 2 ] , t [ v * 2 + 1 ] ) ;
	}
} 
 
data query ( int v, int tl, int tr, int l, int r ) {
    if(l>r ) return make_data(0);
    if ( l == tl && tr == r )
		return t [ v ] ;
	int tm = ( tl + tr ) / 2 ;
	if ( r <= tm )
		return query ( v * 2 , tl, tm , l, r ) ;
	if ( l > tm )
		return query ( v * 2 + 1 , tm + 1 , tr, l, r ) ;
	return combine (
		query ( v * 2 , tl, tm , l, tm ) ,
		query ( v * 2 + 1 , tm + 1 , tr, tm + 1 , r )
	) ;
}
 
int main() {
    int tc;
    scanf("%d",&tc);
    while(tc--){
    int n, i, j, m,x1,x2,y1,y2;
	scanf("%d", &n);
	int pre[n];
	memset(pre,0,sizeof(pre));
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	//puts("read success");
	build(a,1, 0, n-1);
	scanf("%d", &m);
	while(m--) {
        int res;
		scanf("%d%d%d%d", &x1, &y1,&x2,&y2);
		--x1,--x2,--y1,--y2;
		if(y1 < x2) {
				res = query(1, 0, n-1, x1, y1).suff;
				res += query(1, 0, n-1, y1+1, x2-1).sum;
				res += query(1, 0, n-1, x2, y2).pref;
			}
			else {
				res = query(1, 0, n-1, x2, y1).ans;
				res = max(res, max(
					query(1, 0, n-1, x1, x2-1).suff + query(1, 0, n-1, x2, y2).pref,
					query(1, 0, n-1, x1, y1).suff + query(1, 0, n-1, y1+1, y2).pref
				));
			}
		printf("%d\n", res);
	}
    }
	return 0;
}
