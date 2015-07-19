#include<stdio.h>
#define END printf("Press any key to continue...");getchar();
#include<stdlib.h> 
struct node {
                long key;
                struct node *lchild;
                struct node* rchild;
                struct node* p;
            }*root;
long c=0;
void inorder_walk(struct node *ptr)
{
    if (ptr!=NULL)
    {    inorder_walk(ptr->lchild);
        if (c==0) printf("%ld\n",ptr->key);
        else if(c<0) {puts("done");return;}
        else c--;
        inorder_walk(ptr->rchild);
    }
}
/*void insert(long k)
{
    struct node *x,*y,*z;    
    x=root;
    y=NULL;
    z->lchild=NULL;
    z->p=NULL;
    z->rchild=NULL;
    z->key=k;
    while (x!=NULL)
    {
        y=x;
        if(k<x->key)  
            x=x->lchild;
        else
            x=x->rchild;  
    }
    z->p=y;
    if(y==NULL) 
        root=z;
    else if(z->key<y->key)
            {
            y->lchild=z;
            z->p=y;
            }
        else
            {
            y->rchild=z;
            z->p=y;
            }
}*/
void insert(int item)
{       struct node *tmp,*parent,*location;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->key=item;
	tmp->lchild=NULL;
	tmp->rchild=NULL;

	if(parent==NULL)
		root=tmp;
	else
		if(item<=parent->key)
            parent->lchild=tmp;
        else
			parent->rchild=tmp;
}/*End of insert()*/
int main()
{
    long n,l=0,x;
    scanf("%ld",&n);
    int m;
    root=NULL;
    while(n--)
    {
            scanf("%d",&m);
            if(m==1)
                {
                l++;
                scanf("%ld",&x);
                insert(x);
                }
            else if(l<3) puts("No ratings yet");
            else
                {
                c=l-l/3+1;
                inorder_walk(root);
                }
    }
    END
    return 0;    
}
