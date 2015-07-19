#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int ord(char a){
    return a-'0';
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        int table[2][5]={0};
        int i;
        for(i=0;i<s1.size();i++){
            if(ord(s1[i])>7) table[0][0]++;
            else if(ord(s1[i])==7) table[0][1]++;
            else if(ord(s1[i])<7 && ord(s1[i])>4) table[0][2]++;
            else if(ord(s1[i])==4) table[0][3]++;
            else table[0][4]++;
        }
        for(i=0;i<s2.size();i++){
            if(ord(s2[i])>7) table[1][0]++;
            else if(ord(s2[i])==7) table[1][1]++;
            else if(ord(s2[i])<7 && ord(s2[i])>4) table[1][2]++;
            else if(ord(s2[i])==4) table[1][3]++;
            else table[1][4]++;
        }
        
        if(table[0][0]==table[1][0]){ table[0][0]=0;table[1][0]=0;}
        
        else if(table[0][0]>table[1][0]){
            table[0][0]-=table[1][0];table[1][0]=0;
        }
        else{ 
            table[1][0]-=table[0][0];table[0][0]=0;
        }
        int ans7=0,ans4=0;
            
            while(table[0][1]){
                if(table[1][2]) {table[1][2]--;table[0][1]--;ans7++;}
                else if (table[1][4]) {table[1][4]--;table[0][1]--;ans7++;}
                else if (table[1][3]) {table[1][3]--;table[0][1]--;ans7++;}
                else break;
            }
            
            while(table[1][1]){
                if(table[0][2]) {table[0][2]--;table[1][1]--;ans7++;}
                else if (table[0][4]) {table[0][4]--;table[1][1]--;ans7++;}
                else if (table[0][3]) {table[0][3]--;table[1][1]--;ans7++;}
                else break;
            }
            
            while(table[0][3]){
                if(table[1][4]) {table[1][4]--;table[0][3]--;ans4++;}
                else break;
            }
            
            while(table[1][3]){
                if(table[0][4]) {table[0][4]--;table[1][3]--;ans4++;}
                else break;
            }
            ans7+=min(table[0][1],table[1][1]);
            ans4+=min(table[0][3],table[1][3]);
            while(ans7--) putchar('7');
            while(ans4--) putchar('4');
            putchar('\n');
    }
    return 0;
}
