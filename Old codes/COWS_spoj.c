#include<stdio.h>
int arr[2001];
long long table[2001][2001];
long long find_ans(int i,int j,int age){
    if(j==i) return table[i][j]=arr[j]*age;
    else if(table[i][j]!=0) return table[i][j];
    else return table[i][j]=((arr[i]*age+find_ans(i+1,j,age+1))>(arr[j]*age+find_ans(i,j-1,age+1)))?(arr[i]*age+find_ans(i+1,j,age+1)):(arr[j]*age+find_ans(i,j-1,age+1));
}
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("%ld",find_ans(0,n-1,1));
    return 0;
}
    
