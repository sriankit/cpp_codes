#include<cstdio>
#include<math.h>
#include<iostream>
using namespace std;
int stk[1000];
int main(){
    cout<<"enter postfix expression to evaluate\n";
    string s;
    cin>>s;
    int top=-1;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')
            stk[++top]=s[i]-'0';
        else{
            int p=stk[top--];
            int q=stk[top--];
            switch(s[i]){
                case '*':
                    stk[++top]=q*p;
                    break;
                case '^':
                    stk[++top]=pow(q,p);
                    break;
                case '/':
                    stk[++top]=q/p;
                    break;
                case '+':
                    stk[++top]=q+p;
                    break;
                case '-':
                    stk[++top]=q-p;
                    break;
                }
            }
        }
    printf("answer: %d",stk[top]);
    system("pause");
    return 0;
} 
