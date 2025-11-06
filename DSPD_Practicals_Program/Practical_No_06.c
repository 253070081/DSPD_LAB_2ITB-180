#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *left, *right;
};
struct node* createNode(int data) {
struct node* newNode = (struct node*)malloc(sizeof(struct node));
if (!newNode) {
printf("allocation failed!\n");
exit(1);
}
newNode->data = data;
newNode->left = newNode->right = NULL;
return newNode;
}
struct node* insert(struct node* root, int data) {
if (root == NULL)
return createNode(data);
if (data < root->data)
root->left = insert(root->left, data);
else if (data > root->data)
root->right = insert(root->right, data);
return root;
}
void search(struct node* root, int key) {
if (root == NULL) {
printf("not found\n");
return;
}
if (root->data == key)
printf("found\n");
else if (key < root->data)
search(root->left, key);
else
search(root->right, key);
}
struct node* deleteLeaf(struct node* root, int key) {
if (root == NULL)
return NULL;
if (key < root->data)
root->left = deleteLeaf(root->left, key);
else if (key > root->data)
root->right = deleteLeaf(root->right, key);
else {
if (root->left == NULL && root->right == NULL) {
free(root);
printf("leaf node deleted.\n");
return NULL;
} else {
printf("node cannot delete\n");
}
}
return root;
}
void inorder(struct node* root) {
if (root != NULL) {
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
}
int main() {
struct node* root = NULL;
int choice, val;
printf("enter root node data: ");
scanf("%d", &val);
root = createNode(val);
printf("root node created with data = %d\n", root->data);
while (1) {
printf("\n\n1. insert");
printf("\n2. search");
printf("\n3. delete leaf node");
printf("\n4. display");
printf("\n5. exit");
printf("\nenter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("enter value to insert: ");
scanf("%d", &val);
root = insert(root, val);
printf("Node inserted.\n");
break;
case 2:
printf("enter element to search: ");
scanf("%d", &val);
search(root, val);
break;
case 3:
printf("enter leaf node value to delete: ");
scanf("%d", &val);
root = deleteLeaf(root, val);
break;
case 4:
printf("BST: ");
inorder(root);
printf("\n");
break;
case 5:
printf("exiting program\n");
exit(0);
default:
printf("invalid choice.\n");
}
}
return 0;
}
