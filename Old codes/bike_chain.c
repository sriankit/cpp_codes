#include<cstdio>
#include<stack>
using namespace std;
stack <char> st;
char c;
int main(){
    while((c=getchar())!='\n'&&c!=EOF){
    st.push(c);
    long ans=0;
    while(st.top()=='0') {ans++;st,pop();}
    while(!st.empty()){
        st.top()='1';
        cnt=0;
        while(st.top()=='1' && !st.empty()){
            cnt++;
            st.pop();
        }
        ans+=cnt+1;
    }
    printf("%ld",ans);
    return 0;
}    
