#include<stdio.h>
int arr[10010010];
int cnt=0;
int main(){
    FILE *fp=fopen("F:\\primes.txt","w");
    int i,j;
    long n=1500;
    fprintf(fp," ");
    int lst=2;
    for(i=2;i<10000007;i++){
        if(arr[i]) continue;
        lst=i;
        //fprintf(fp,"%d, ",i);
        cnt++;
        for(j=2*i;j<n;j+=i)
            arr[j]=1;
    }
    /*fprintf(fp,"{");
    for(i=2;i<n;i++){
        if(arr[i]==0) {fprintf(fp,"%ld ,",i);cnt++;}
    }
    fprintf(fp,"}");
    fclose(fp);*/
    printf("%d ",lst);
    printf("%6d",cnt);
    system("pause");
    return 0;
}
