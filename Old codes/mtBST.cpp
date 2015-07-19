#include <stdio.h>
#include <stdlib.h>
typedef struct node_t node_t;
/* Binary tree node */
struct node_t
{
    int data;
    int lCount;
    node_t* left;
    node_t* right;
};
node_t *insert_node(node_t *root, node_t* node)
{
    node_t *pTraverse = root;
    node_t *currentParent = root;

    while(pTraverse)
    {
        currentParent = pTraverse;
 
        if( node->data < pTraverse->data )
        {
            pTraverse->lCount++;
            /* left subtree */
            pTraverse = pTraverse->left;
        }
        else
        {
            /* right subtree */
            pTraverse = pTraverse->right;
        }
    }
 
    /* If the tree is empty, make it as root node */
    if( !root )
    {
        root = node;
    }
    else if( node->data < currentParent->data )
    {
        /* Insert on left side */
        currentParent->left = node;
    }
    else
    {
        /* Insert on right side */
        currentParent->right = node;
    }
 
    return root;
} 
int k_smallest_element(node_t *root, int k)
{
    int ret = -1;
 
    if( root )
    {
        node_t *pTraverse = root;
 
        /* Go to k-th smallest */
        while(pTraverse)
        {
            if( (pTraverse->lCount + 1) == k )
            {
                ret = pTraverse->data;
                break;
            }
            else if( k > pTraverse->lCount )
            {
                k -=  (pTraverse->lCount + 1);
                pTraverse = pTraverse->right;
            }
            else
            {
                pTraverse = pTraverse->left;
            }
        }
    }
 
    return ret;
}
 
int main()
{
    long t,n,m,l=0,i;
    node_t* root = NULL;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld",&m);
        if(m==1)
        {
        scanf("%ld",&n);
        node_t *new_node = NULL;
        new_node = (node_t *)malloc( sizeof(node_t) );
 
        /* initialize */
        new_node->data   = n;
        new_node->lCount = 0;
        new_node->left   = NULL;
        new_node->right  = NULL;
 
        /* insert into BST */
        root = insert_node(root, new_node);
        l++;
        }
        else
        {
        i=l-l/3+1;
        if(l<3) puts("No ratings yet");
        else printf("%ld\n",k_smallest_element(root, i));
        }
    } 
    //getchar();
    return 0;
}
