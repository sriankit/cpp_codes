#include<conio.h>
#include<cstdio>
#include<vector>
using namespace std;
const int l=(int)1e8;
bool a[(int)1e8];
int main(){
    puts("2");
    int cnt=1;
    for(int i=3;i<1e8;i+=2){
        if(a[i]) continue;
        if(cnt%100==0) printf("%d\n",i);
        cnt++;
        for(int j=i*i;j<l;j+=i)
            a[j]=1;
    }
    getch();
    return 0;}
