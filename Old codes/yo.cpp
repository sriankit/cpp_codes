#include<stdio.h>
#include<string.h>
typedef long long ll;
ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
class fraction{
	public:
	ll num,den;
	fraction(){
	}
	fraction(ll a,ll b){
		num=a;
		den=b;
		if(num == 0) den=1;
		else this->standard();
	}
	fraction def(0,0);
	public:
	void standard(){
		ll g = gcd(num,den);
		num/=g;
		den/=g;	
	}
	void normal(int l){
		num *= (l/den);
		den = l;
	}
};
ll lcm(ll a,ll b){
	return (a/gcd(a,b))*b;
}
fraction operator *(fraction a,fraction b){
	return fraction(a.num*b.num,a.den*b.den);
}
bool operator ==(fraction a,fraction b){
	return (a.num==b.num && a.den==b.den);
}
fraction operator +(fraction a,fraction b){
	ll l = lcm(a.den,b.den);
	a.normal(l);
	b.normal(l);
	return fraction(a.num+b.num,a.den);
}
fraction dp[2015][1005];
fraction go(int tot,int sel) {
	if(dp[tot][sel]!=fraction.def) return dp[tot][sel];
	if(tot==2)
		if(sel == 1) return dp[tot][sel]=fraction(1,1);
		else return dp[tot][sel]=fraction(0,1);
	if(sel >= tot-1) return dp[tot][sel]=fraction(0,1);
	else return dp[tot][sel]=fraction(sel-1,tot-1)*go(sel-1,tot-1)+fraction(sel,tot-1)*go(sel,tot-1);
}
int main(){
	memset(dp,fraction.def,sizeof(dp));
	fraction f = go(2,1);
	printf("%d %d",f.num,f.den);
	return 0;
}
