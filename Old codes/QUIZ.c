#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int t,i;
    scanf("%d\n",&t);
    while(t--){
        string s;
        cin>>s;
        int arr[3];
        for(i=0;i<3;i++) arr[i]=0;
        for(i=0;s[i]!='\0';i++)
            arr[s[i]-'A']++;
        for(i=0;s[i]!='\0';i++){
            printf("%d ",arr[0]>0+arr[1]>0+arr[2]>0);
            arr[s[i]-'A']--;
        }
        putchar('\n');
    }
    system("pause");
    return 0;
}
