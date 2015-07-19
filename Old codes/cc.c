#include<stdio.h>
inline int scanInt()
{
int noRead=0;
char p=getc_unlocked(stdin);
for(;p<33;){p=getc_unlocked(stdin);};
while(p>32)
{
noRead = (noRead << 3) + (noRead << 1) + (p - '0');
p=getc_unlocked(stdin);
}
return noRead;
};
int main(){
    long int t,n;
    //scanf("%d",&t);
    t=scanInt();
    while(t--){
        int flag=1;
        //scanf("%ld",&n);
        n=scanInt();
        long int i,a;
        long tot=1;
        for(i=0;i<n;i++){
            //scanf("%ld",&a);
            a=scanInt();
            if(tot-a<0) {putc('N',stdout);putc('o',stdout);putc('\n',stdout);flag=0;break;}
            tot=2*(tot-a);
        }
        if(flag){
            if(tot) {putc('N',stdout);putc('o',stdout);putc('\n',stdout);}
            else {putc('Y',stdout);putc('e',stdout);putc('s',stdout);putc('\n',stdout);}
        }
    }
    return 0;
} 
            
