#include<stdio.h>
#include<vector>
using namespace std;
typedef long long ll;
vector<ll> mul2,mul3,mul5,mul7;
int main(){
    int cnt = 0;
    ll lim = (ll)(1e18);
    mul2.push_back(1);
    mul3.push_back(1);
    mul5.push_back(1);
    mul7.push_back(1);
    for(int i = 1;;i++){
        if(mul2[i-1]>(lim>>1)) break;
        mul2.push_back(2*mul2[i-1]);
    }    
    for(int i = 1;;i++){
        if(mul3[i-1]>(lim/3)) break;
        mul3.push_back(3*mul3[i-1]);
    }   
    for(int i = 1;;i++){
        if(mul5[i-1]>(lim/5)) break;
        mul5.push_back(5*mul5[i-1]);
    }     
    for(int i = 1;;i++){
        if(mul7[i-1]>(lim/7)) break;
        mul7.push_back(7*mul7[i-1]);
    }    
    for(int i=0;i<mul2.size();i++)
        for(int j = 0;j<mul3.size();j++)
            for(int k=0;k<mul5.size();k++)
                for(int l =0;l<mul7.size();l++){
                    ll num=mul2[i]*mul3[j]*mul5[k]*mul7[l];
                    if(num>0 && num<=lim) cnt++;
                }
    printf("%d\n",cnt);
    system("pause");
    return 0;
}
        
    
