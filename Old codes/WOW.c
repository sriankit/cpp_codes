#include<stdio.h>
int store[10001][10];
int str[10001];
long long table[10001][37][4];
const MOD=1000000007;
long long find_ans(int i,int sum,int k){
    /*if(i==0&&k==3){
        if((sum+str[0])%9) return 0;
        else return 1;
    }
    else if(i==0 && k!=3) return 0;*/
    if(i==0){
        if(k==0 && (str[0]!=0)&& str[0]%9==0) return 1;
        else if((str[0]+sum!=0)&&(str[0]+sum)%9==0) return 1;
        else return 0;
    }
    if(table[i][sum][k]!=-1) return table[i][sum][k];
    else if(k==3){ 
        if(sum%9)return store[i][9-sum%9];
        else if(sum!=0) return store[i][9]+store[i][0];
        else return 0;
    }
    else return table[i][sum][k]=(((sum+str[i]!=0)&&(sum+str[i])%9==0)?1:0)+(find_ans(i-1,sum+str[i],k+1)+find_ans(i-1,sum,k))%MOD;
}
int main(){
    int t;
    scanf("%d\n",&t);
    char c;
    int j;
    while(t--){
        int i=0;
        memset(store,0,sizeof(store));
        memset(table,-1,sizeof(table));
        while((c=getchar())!='\n'&&c!=EOF){
            str[i]=c-'0';
            for(j=0;i>0&&j<10;j++)
                store[i][j]=store[i-1][j];
            switch(str[i]){
                case 0:
                    store[i][0]++;
                    break;
                case 1:
                    store[i][1]++;
                    break;
                case 2:
                    store[i][2]++;
                    break;
                case 3:
                    store[i][3]++;
                    break;
                case 4:
                    store[i][4]++;
                    break;
                case 5:
                    store[i][5]++;
                    break;
                case 6:
                    store[i][6]++;
                    break;
                case 7:
                    store[i][7]++;
                    break;
                case 8:
                    store[i][8]++;
                    break;
                case 9:
                    store[i][9]++;
                    break;
                }
            //store[i][strchr(s,c)-s]++;
            i++;
        }
        int k;
        /*for(j=0;j<i;j++){
            for(k=0;k<10;k++)
                printf("%ld ",store[j][k]);
            printf("\n");
        }*/
        printf("%ld\n",find_ans(i-1,0,0));
    }
    return 0;
}
    
