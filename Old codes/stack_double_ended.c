#include<stdio.h>
int a[1000];
int main()
{
    int i,n=0,x,y,z;
    //printf("Enter the initial array length: ");
    //scanf("%d",&n);
    /*if(n!=0&&n+1<1000)
    {
        printf("Enter the array: ");
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
    }*/
    while(n!=0&&n+1<1000)
    {
        printf("Choose: \n1. Left\n2. Right\n3. Exit\n");
        scanf("%d",&x);
        if(x==3)
            return 0;
        printf("Choose Operation: \n1. POP\n2. PUSH\n");
        scanf("%d",&y);
        if(y==2)
        {
            printf("Enter the element: ");
            scanf("%d",&z);
        }
        if(x==1&&y==1)
            {
                for(i=0;i<n;i++)
                    a[i]=a[i+1];
                n--;
            }
        else if(x==1&&y==2)
            {
                for(i=n;i>0;i--)
                    a[n]=a[n-1];
                a[0]=z;
                n++;
            }
        else if(x==2&&y==1)
            {
                a[n-1]='\0';
                n--;
            }
        else if(x==2&&y==2)
            {
                a[n]=z;
                n++;
            }
        for(i=0;i<n;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    if(n==0)
        printf("Underflow");
    else
        printf("Overflow");
    return 0;
}
