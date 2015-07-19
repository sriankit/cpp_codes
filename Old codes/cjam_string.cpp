#include<cstdio>
#include<string>
#include<stack>
#include<iostream>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int I=1;I<=t;I++){
        stack<string> st;
        string str;
        while(cin>>str) st.push(str);
        while(st.size()>0){
            str=st.top();
            st.pop();
            cout<<str+" ";
        }
        cout<<'\n';
    }
    return 0;
}
        
