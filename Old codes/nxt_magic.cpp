#include<cstdio>
#include<stack>
using namespace std;
char c;
int main(){
    int t;
    scanf("%d\n",&t);
    while(t--){
        stack<int>st;
        stack<char>ans;
        int done=0;
        st.push(1);//dummy
        ans.push('0');//dummy
        while((c=getchar())!='\n'&&c!=EOF){
            done=(c=='7');
            st.push(done);
        }
    //long ans=0;
    //while(st.top()=='0') {ans++;st.pop();}
    //int cnt=0;
        done=0;
        while(st.size()>1){
            if(!done){
                if(st.top()==1) {ans.push('4');st.pop();}
                else{
                    ans.push('7');
                    done=1;
                    st.pop();
                }
            }
            else{
                if(st.top()==1) 
                    {ans.push('7');st.pop();}
                else {ans.push('4');st.pop();}   
            }
        }
        if(!done)ans.push('4');
        while(ans.size()>1){
            putchar(ans.top());
            ans.pop();
        }
        putchar('\n');
    }
    return 0;
}
