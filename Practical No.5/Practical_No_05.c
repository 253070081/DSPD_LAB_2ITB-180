#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node* left;
struct Node* right;
};
struct Node* createNode(int data){
struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
newNode->data=data;
newNode->left=NULL;
newNode->right=NULL;
return newNode;
}
struct Node* createTree(){
int data;
printf("Enter data (0 for no node): ");
scanf("%d",&data);
if(data==0)
return NULL;
struct Node* root=createNode(data);
printf("Enter left child of %d:\n",data);
root->left=createTree();
printf("Enter right child of %d:\n",data);
root->right=createTree();
return root;
}
void inorder(struct Node* root){
if(root==NULL)
return;
inorder(root->left);
printf("%d ",root->data);
inorder(root->right);
}
void preorder(struct Node* root){
if(root==NULL)
return;
printf("%d ",root->data);
preorder(root->left);
preorder(root->right);
}
void postorder(struct Node* root){
if(root==NULL)
return;
postorder(root->left);
postorder(root->right);
printf("%d ",root->data);
}
int search(struct Node* root,int key){
if(root==NULL)
return 0;
if(root->data==key)
return 1;
if(search(root->left,key))
return 1;
return search(root->right,key);
}
int main(){
printf("Create your binary tree:\n");
struct Node* root=createTree();
printf("\nInorder traversal:\n");
inorder(root);
printf("\nPreorder traversal:\n");
preorder(root);
printf("\nPostorder traversal:\n");
postorder(root);
int key;
printf("\n\nEnter element to search: ");
scanf("%d",&key);
if(search(root,key))
printf("Element %d found in the tree.\n",key);
else
printf("Element %d not found in the tree.\n",key);
return 0;
}
