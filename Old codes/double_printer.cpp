#include<cstdio>
void doit(double p){
    char s[40]={'\0'};
    sprintf(s,"%.10lf",p);
    int l=strlen(s)-1;
    while(s[l]=='0') {s[l]='\0';l--;}
    if(s[l]=='.') s[l]='\0';
    int dec=0,cnt=0;
    REP(i,strlen(s)){
        if(cnt==9){s[i]='\0';break;}
        if(dec) cnt++;
        if(s[i]=='.') dec=1;
    }    
    puts(s);
}
int main(){
    double p;
    while(1){scanf("%lf",&p);
    doit(p);}
    return 0;
}
    
