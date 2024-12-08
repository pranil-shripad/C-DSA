#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(int data){
    struct Node * newNode = (struct Node *) malloc (sizeof(struct Node));
    newNode -> data = data;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

void preorder(struct Node * root){
    if(root != NULL){
        printf("%d", root-> data);
        preorder(root->left);
        preorder(root-> right);
    }
}

void inorder(struct Node * root){
    if(root != NULL){
        inorder(root -> left);
        printf("%d", root -> data);
        inorder(root -> right);
    }
}

void postorder(struct Node * root){
    if(root != NULL){
        postorder(root -> left);
        postorder(root -> right);
        printf("%d", root-> data);
    }
}

int main(){
    struct Node * root = createNode(1);
    root -> left = createNode(2);
    root -> right = createNode(3);
    root -> left -> left = createNode(4);
    root -> left -> right = createNode(5);
    root -> right -> left = createNode(6);
    root -> right -> right = createNode(7);
    printf("preorder Traversal: ");
    preorder(root);
    printf("\n");
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");
    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");
    return 0;
}