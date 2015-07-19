#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define END printf("Press any key to continue...");getch();
struct node
{
	int info;
	struct node *lchild;
	struct node *rchild;
    int lc;
}*root;
long l=0;
void display(struct node *ptr,int level);
void find(int item,struct node **par,struct node **loc)
{
	struct node *ptr,*ptrsave;

	if(root==NULL)  /*tree empty*/
	{
		*loc=NULL;
		*par=NULL;
		return;
	}
	if(item==root->info) /*item is at root*/
	{
		*loc=root;
		*par=NULL;
		return;
	}
	/*Initialize ptr and ptrsave*/
	if(item<root->info)
		ptr=root->lchild;
	else
		ptr=root->rchild;
	ptrsave=root;

	while(ptr!=NULL)
	{
		if(item==ptr->info)
		{       *loc=ptr;
			*par=ptrsave;
			return;
		}
		ptrsave=ptr;
		if(item<ptr->info)
			ptr=ptr->lchild;
		else
			ptr=ptr->rchild;
	 }/*End of while */
	 *loc=NULL;   /*item not found*/
	 *par=ptrsave;
}/*End of find()*/

void insert(int item)
{       struct node *tmp,*parent,*location;
	find(item,&parent,&location);
	/*if(location!=NULL)
	{
		printf("Item already present");
		return;
	}*/

	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=item;
	tmp->lchild=NULL;
	tmp->rchild=NULL;
    tmp->lc=0;
    ///tmp->rc=0;
	if(parent==NULL)
		root=tmp;
	else
		if(item<=parent->info)
			{
            parent->lchild=tmp;
            parent->lc++;	
            }
        else
			{
            parent->rchild=tmp;
            ///parent->rc++;
            }
}/*End of insert()*/

long long find_ans(long i,struct node *ptr)
{
        if(i==ptr->lc) return ptr->info;
        else if(i<ptr->lc) return find_ans(i,ptr->lchild);
        else return find_ans(i,ptr->rchild);
}
long c;
void inorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}
	if(ptr!=NULL)
	{
		inorder(ptr->lchild);
		if(c==0) {printf("%d  ",ptr->info);return;}
		else c--;
        inorder(ptr->rchild);
	}
}/*End of inorder()*/
int main()
{
    root=NULL;
    long n;
    long long x;
    int mode;
    scanf("%ld",&n);
    while(n--)
    {
            scanf("%d",&mode);
            if(mode==1) {scanf("%I64d",&x);insert(x);l++;}
            else if(l<3) puts("No reviews yet");
            else {c=l-l/3+1;inorder(root);puts("");display(root,1);
                //printf("%I64d",find_ans(l-l/3+1,root));
                }
    }
    END
    return 0;
}
void display(struct node *ptr,int level)
{
	int i;
	if ( ptr!=NULL )
	{
		display(ptr->rchild, level+1);
		printf("\n");
		for (i = 0; i < level; i++)
			printf("    ");
		printf("%d", ptr->info);
		display(ptr->lchild, level+1);
	}/*End of if*/
}/*End of display()*/
