#include<stdio.h>
#include<conio.h>
#define END printf("\npress any key to continue...");getch();
int main()
{
    int m,n,i,j;
    scanf("%d %d",&m,&n);
    long dat[m][n],max,min;
    int flag[100][100]={0};
    for(i=0;i<m;i++)
       for(j=0;j<n;j++)
          scanf("%ld",&dat[i][j]);
    for(j=0;j<n;j++)
    {
       max=dat[0][j];
       for(i=1;i<m;i++)
          if(dat[i][j]>max) max=dat[i][j];
       for(i=0;i<m;i++)
          if(dat[i][j]==max) flag[i][j]=1; 
    }
    long cur,ans=1e8+1;
    for(i=0;i<m;i++)
    {
       cur=1e8;
       min=1e8;
       for(j=0;j<n;j++)
       {
          if(dat[i][j]<min) min=dat[i][j];
          if(flag[i][j]&&dat[i][j]<cur) cur=dat[i][j];                
       }
       if(cur==min) if(cur<ans) ans=cur;
    }
    if(ans==(1e8+1)) puts("GUESS");
    else printf("%ld",ans);
    END
    return 0;
}
