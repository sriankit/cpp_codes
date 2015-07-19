/*JUDGE*/
#include<stdio.h>
char s1[500],s2[500];
int main()
{
    FILE *fp1,*fp2;
    fp1=fopen("F:\\output.txt","r");
    fp2=fopen("F:\\output2.txt","r");
    long long a,b,i=0;
    int flag=1;
    while(fscanf(fp1,"%s",s1)!=EOF && fscanf(fp2,"%s",s2)!=EOF)
    {
        if(strcmp(s1,s2)!=0) {flag=0;printf("WRONG ANSWER AT %I64d\n",i);}   
        i++;
    }
    if(flag) puts("Congratulations!!! you hav solved this problem ");
    system("pause");
    return 0;
}
