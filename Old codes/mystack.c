#include<stdio.h>
int stack[1000];
int lim,i,c1;
int main(){
    printf("enter limit of stack: ");
    scanf("%d",&lim);
    int top1=-1;
    int top2=lim;
    int choice;
    printf("\nenter choice...\n1.stack 1\n2.stack 2\n0.exit\n");
    scanf("%d",&choice);
    while(choice){
        switch(choice){
            case 1:
                printf("1.push\t2.pop\n");
                scanf("%d",&c1);
                if(c1==1){
                    int num;
                    printf("enter number: ");
                    scanf("%d",&num);
                    if(top2==top1+1) printf("overflow\t  aborted\n");
                    else stack[++top1]=num;
                }
                else{
                    if(top1==-1) {printf("underflow \taborted\n");break;}
                    else printf("element popped: %d\n",stack[top1--]);
                    
                }
                printf("Displaying stack 1: ");
                for(i=0;i<=top1;i++)
                    printf("%d ",stack[i]);
                printf("\n");
                break;
            case 2:
                printf("1.push\t2.pop\n");
                scanf("%d",&c1);
                if(c1==1){
                    int num;
                    printf("enter number: ");
                    scanf("%d",&num);
                    if(top2==top1+1) printf("overflow\t aborted\n");
                    else stack[--top2]=num;
                }
                else{
                    if(top2==lim) printf("underflow \taborted\n");
                    else printf("element popped: %d\n",stack[top2++]);
                }
                printf("Displaying stack 2: ");
                for(i=top2;i<lim;i++)
                    printf("%d ",stack[i]);
                break;
        }
        printf("\nenter choice...\n1.stack 1\n2.stack 2\n0.exit\n");
        scanf("%d",&choice);
    }
    printf("BYE\n");
    return 0;
}
    
