#include<stdio.h>
#include<string.h>
int main(){
    int t;
    scanf("%d\n",&t);
    while(t--){
        char s[105]={'\0'};
        scanf("%s",s);
        int l=strlen(s);
        int j=l-1;
        while(j>=0){
            if(s[j]=='4'){
                s[j]='7';
                break;
            }
            else s[j]='4';
            j--;
        }
        if(j<0) putchar('4');
        puts(s);
    }
    return 0;
}
