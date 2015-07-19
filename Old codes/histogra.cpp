#include<stdio.h>
#define maX(a, b) ((a) > (b) ? (a) : (b))
struct node {
    long long pref, suf, tot, ans;
};
int a[100005];
node combine(int lo, int hi, node n1, node n2) {
    int mid = lo + hi >> 1;
    node ret;
    ret.pref = n1.pref;
    ret.suf = n2.suf;
    ret.tot = n1.tot + n2.tot;
    ret.ans = maX(n1.ans, n2.ans);
    if(a[mid] < a[mid + 1]) {
        if(n1.pref == n1.tot) {
            ret.pref = n1.tot + n2.pref;
            ret.ans = maX(ret.ans, a[lo] * ret.pref);
        }
        ret.ans = maX(ret.ans, a[mid] * (n1.suf + n2.pref));
    } else if(a[mid] > a[mid + 1]) {
        if(n2.suf == n2.tot) {
            ret.suf = n1.suf + n2.tot;
            ret.ans = maX(ret.ans, a[hi] * ret.suf);
        }
        ret.ans = maX(ret.ans, a[mid + 1] * (n1.suf + n2.pref));
    } else {
        if(n1.pref == n1.tot) {
            ret.pref = n1.pref + n2.pref;
            ret.ans = maX(ret.ans, a[lo] * ret.pref);
        }
        if(n2.suf == n2.tot) {
            ret.suf = n1.suf + n2.suf;
            ret.ans = maX(ret.ans, a[hi] * ret.suf);
        }
        ret.ans = maX(ret.ans, a[mid + 1] * (n1.suf + n2.pref));
    }
    return ret;
}
node solve(int lo, int hi) {
    if(lo == hi) {
        node n;
        n.pref = 1;
        n.suf = 1;
        n.tot = 1;
        n.ans = a[lo];
        return n;
    } else {
        int mid = lo + hi >> 1;
        return combine(lo, hi, solve(lo, mid), solve(mid + 1,hi));
    }
}
int main(){
    int n;
    scanf("%d", &n);
    do{
        for(int i = 0; i < n; i ++) {
            scanf("%d",a+i);
        }
        node res = solve(0, n-1);
        printf("%lld\n", res.ans);
        scanf("%d",&n);
    }
    while(n);
    return 0;
}
