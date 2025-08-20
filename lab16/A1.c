#include <stdio.h>
#include <stdlib.h>

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

struct node *insertnode(struct node *root, int x)
{
    if (root == NULL)
        return createNode(x);
    if (x < root->value)
        root->left = insertnode(root->left, x);
    else if (x > root->value)
        root->right = insertnode(root->right, x);
    return root;
}

void search(int data, struct node *root)
{
    if (root == NULL)
    {
        printf("Node not found.\n");
        return;
    }
    if (root->value == data)
    {
        printf("Node found: %d\n", root->value);
    }
    else if (data < root->value)
    {
        search(data, root->left);
    }
    else
    {
        search(data, root->right);
    }
}

struct node *FindSuccessor(struct node *root)
{
    struct node *temp = root;
    while (temp->left != NULL)
    {
        temp = root->left;
    }
    return temp;
}
struct node *Deletenode(struct node *root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    // want to delete node which has  child in left or right
    else if (root->value > x)
    {
        root->left = Deletenode(root->left, x);
    }
    else if (root->value < x)
    {
        root->right = Deletenode(root->right, x);
    } // root->value == x condition
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node *temp = FindSuccessor(root->right);
            root->value = temp->value;
            root->right = Deletenode(root->right, temp->value);
        }
    }
    return root;
}
void Inorder(struct node *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    printf("%d ", root->value);
    Inorder(root->right);
}

void Preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->value);
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(struct node *root)
{
    if (root == NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->value);
}

int main()
{
    struct node *root = NULL;
    int choice, x;

    while (1)
    {
        printf("\n--- Menu ---\n");
        printf("1. Insert node\n");
        printf("2. Delete node\n");
        printf("3. Search node\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Inorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &x);
            root = insertnode(root, x);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &x);
            root = Deletenode(root, x);
            break;
        case 3:
            printf("Enter value to search: ");
            scanf("%d", &x);
            search(x, root);
            break;
        case 4:
            printf("Preorder Traversal: ");
            Preorder(root);
            printf("\n");
            break;
        case 5:
            printf("Postorder Traversal: ");
            Postorder(root);
            printf("\n");
            break;
        case 6:
            printf("Inorder Traversal: ");
            Inorder(root);
            printf("\n");
            break;
        case 7:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}