#include <stdio.h>
#include <stdlib.h>

// Write  a  program  to  construct  a  binary  tree  from  given  Postorder  and  Preorder traversal sequence

struct node
{
    int value;
    struct node *left;
    struct node *right;
};

struct node *createNode(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->value = x;
    newnode->left = newnode->right = NULL;
    return newnode;
}

int linearSearch(int post[], int postst,int posted,int x)
{
    for (int i = postst; i < posted; i++)
    {
        if (post[i] == x)
        {
            return i;
        }
    }
    return -1;
}

struct node *binarytree(int pre[], int post[], int postst,int posted, int *preidx, int size)
{
    if (*preidx >= size || postst > posted)
        
        {
            return NULL;
        }
    struct node *root = createNode(pre[*preidx]);
    (*preidx)++;
    if (*preidx >= size || postst == posted)
    {
        return root;
    }
    int idx = linearSearch(post,postst,posted,pre[*preidx]);
    if(idx != 0){
        root->left = binarytree(pre,post, postst, idx,preidx,size);
        root->right =binarytree(pre,post,idx+1,posted-1,preidx,size);
    }
}

void Inorder(struct node *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    printf("%d ", root->value);
    Inorder(root->right);
}

void main()
{
    int pre[7] = {30, 40, 35, 60, 50, 55, 70};
    int post[7] = {35, 60, 40, 55, 70, 50, 30};
    struct node *root;
    int preidx =0;
    root = binarytree(pre, post, 0, 6,&preidx,7);
    Inorder(root);
}