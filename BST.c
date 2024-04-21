#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *left;
struct node *right;
};
#define NEWNODE (struct node *)malloc(sizeof(struct node))
struct node *root = NULL;
struct node* insert(struct node* root, int num)
{
if (root == NULL)
{
struct node* newNode = NEWNODE;
newNode->data = num;
newNode->left = NULL;
newNode->right = NULL;
return newNode;
}
if (num < root->data)
{
root->left = insert(root->left, num);
}
else if (num > root->data)
{
root->right = insert(root->right, num);
}
else
{
printf("Duplicate values are not allowed in BST\n");
return root;
}
return root;
}
void createbst(int n)
{
int i, num;
struct node *p;
printf("Enter the Tree data\n");
for (i = 0; i < n; i++)
{
printf("Enter Node data\n");
scanf("%d", &num);
root = insert(root, num);
}
}
void preorder(struct node *root)
{
if (root != NULL)
{
printf("%d\t", root->data);
preorder(root->left);
preorder(root->right);
}
}
int main()
{
int n;
printf("How Many numbers: ");
scanf("%d", &n);
createbst(n);
printf("\npreorder traversal\n");
preorder(root);
return 0;
}