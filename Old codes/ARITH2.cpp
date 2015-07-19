#include<stdio.h>
#include<iostream>
using namespace std;
typedef long long ll;
int main(){
    int t;
    ll a,b;
    scanf("%d\n",&t);
    while(t--){
        char c;
        cin>>a;
        while(cin>>c,c!='='){
            cin>>b;
            switch(c){
                case '+':
                    a=a+b;
                    break;
                case '-':
                    a=a-b;
                    break;
                case '*':
                    a=a*b;
                    break;
                case '/':
                    a=a/b;
                    break;
            }
        }
        printf("%lld\n",a);
    }
    return 0;
}
