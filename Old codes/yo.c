#include<stdio.h>
typedef long long ll;
ll dp[2015][1005];
class fraction{
	public int num,den;
	fraction(int a,int b){
		num=a;
		den=b;
		this->standard();
	}
	public void standard(){
		int g = gcd(num,den);
		num/=g;
		den/=g;	
	}
};
int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int main(){
	fraction f = new fraction(4,8);
	printf("%d %d",f.num,f.den);
	return 0;
}
