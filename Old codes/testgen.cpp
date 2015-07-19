#include<bits/stdc++.h>
using namespace std;
string proto,s;
string s1,s2,s3;
int main(){
	string fix[10]={"abwdxxscca","a","vcf","abab","wqcleehfcb","sdbhcsbbc","dhlkasdbvcdcsladsjj","jjjj","wwuwqoxnnxag","wwwllwww"};
	for(int i=0;i<10;i++){
		char buf[20]={0};
		sprintf(buf,"TestData//%d.in",i);
		freopen(buf,"w",stdout);
		int len=100000;
		proto=fix[i];
		s="";
		while(s.length()<(len/3)) {
			reverse_copy(proto.begin(),proto.end(),s.begin());
			s+=proto;
			proto=s;
		}
		cout<<s<<endl;
		int q=100000;
		printf("%d\n",q);
		int i1=2,l=5;
		while(q--){
			i1=(i1+234)%len;
			l=((l+321)%len);
			printf("%d %d\n",i1,l%1000);
		}
		fprintf(stderr,"done %d",i);
	}
	for(int i=10;i<15;i++){
		char buf[20]={0};
		sprintf(buf,"TestData//%d.in",i);
		freopen(buf,"w",stdout);
		int len=19;
		proto=fix[i%10];
		s="";
		while(s.length()<(len)) {
			reverse_copy(proto.begin(),proto.end(),s.begin());
			s+=proto;
			proto=s;
		}
		cout<<s<<endl;
		int q=100;
		printf("%d\n",q);
		int i1=2,l=5;
		while(q--){
			i1=(i1+234)%len;
			l=((l+321)%len);
			printf("%d %d\n",i1,l%1000);
		}
		fprintf(stderr,"done %d",i);
	}
	for(int i=15;i<20;i++){
		char buf[20]={0};
		sprintf(buf,"TestData//%d.in",i);
		freopen(buf,"w",stdout);
		int len=1900;
		proto=fix[i%10];
		s="";
		while(s.length()<(len)) {
			reverse_copy(proto.begin(),proto.end(),s.begin());
			s+=proto;
			proto=s;
		}
		cout<<s<<endl;
		int q=10000;
		printf("%d\n",q);
		int i1=23,l=1;
		while(q--){
			i1=(i1+234)%len;
			l=((l+321)%len);
			printf("%d %d\n",i1,l%(len-i1+10)%100000);
		}
		fprintf(stderr,"done %d",i);
	}
	for(int i=20;i<30;i++){
		char buf[20]={0};
		sprintf(buf,"TestData//%d.in",i);
		freopen(buf,"w",stdout);
		int len=100000;
		proto=fix[i%10];
		s1="";
		while(s1.length()<(len)/10) {
			reverse_copy(proto.begin(),proto.end(),s1.begin());
			s1+=proto;
			proto=s1;
		}
		s2="";
		proto=fix[(i+1)%10];
		while(s2.length()<(len)/10) {
			reverse_copy(proto.begin(),proto.end(),s2.begin());
			s2+=proto;
			proto=s2;
		}
		s3="";
		int p=1,r=5;
		for(int c=0;c<len/5;c++){
			p=(p*12213)%26;
			r=(r*10003)%26;
			s3+=(char)((p+r)%26+'a');
		}
		s=s1+s3+s2;
		assert(s.length()<=100000);
		cout<<s<<endl;
		int q=10000;
		printf("%d\n",q);
		int i1=23,l=1;
		while(q--){
			i1=(i1+23411)%len;
			l=((l+32221)%len);
			int x=len-i1+10;
			printf("%d %d\n",i1,l%(x)%100000);
		}
		fprintf(stderr,"done %d",i);
	}
}
