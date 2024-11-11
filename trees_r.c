#include <stdio.h>
#include <stdlib.h>

struct treenode {
    int data;  
    struct treenode *left;
    struct treenode *right;
};
#define STACK_SIZE 100
struct treenode *stack[STACK_SIZE];
int top = -1; 



void create_r(struct treenode *root) {
    char a, b;
    struct treenode *temp = root;

    printf("Do you want to add it to the left side of %d (y/n)? \n", temp->data);
    scanf(" %c", &a);
    
    if (a == 'y') {
        struct treenode *curr = (struct treenode *)malloc(sizeof(struct treenode));
        printf("Enter the data to the left of %d:\n", temp->data);
        scanf("%d", &curr->data);
        curr->left = NULL;
        curr->right = NULL;
        temp->left = curr;
        create_r(curr);
    }

    printf("Do you want to add it to the right side of %d (y/n)? \n", temp->data);
    scanf(" %c", &b);

    if (b == 'y') {
        struct treenode *curr = (struct treenode *)malloc(sizeof(struct treenode));
        printf("Enter the data to the right of %d:\n", temp->data);
        scanf("%d", &curr->data);
        curr->left = NULL;
        curr->right = NULL;
        temp->right = curr;
        create_r(curr);
    }
}

void inorder_r(struct treenode *temp) {
    if (temp != NULL) {
        inorder_r(temp->left);
        printf("%d \t", temp->data);
        inorder_r(temp->right);
    }
}

void preorder_r(struct treenode *temp) {
    if (temp != NULL) {
        printf("%d \t", temp->data);
        preorder_r(temp->left);
        preorder_r(temp->right);
    }
}

void postorder_r(struct treenode *temp) {
    if (temp != NULL) {
        postorder_r(temp->left);
        postorder_r(temp->right);
        printf("%d \t", temp->data);
    }
}



int main() {
    int s;
    struct treenode *root;
    root = (struct treenode *)malloc(sizeof(struct treenode));

    printf("Enter the data for the root:\n");
    scanf("%d", &root->data);

    root->left = NULL;
    root->right = NULL;
do {
printf("\n\n1. Create\n");
printf("2. Display Inorder\n");
printf("3. Display Preorder\n");
printf("4. Display Postorder\n");

scanf("%d",&s);
switch (s) {
    case 1: create_r(root);
            break;
    case 2: printf("Inorder Traversal:\n");
            inorder_r(root);
            break;
            
    case 3 :printf("\nPreorder Traversal:\n");
            preorder_r(root);
            break;
            
   case 4: printf("\nPostorder Traversal:\n");
            postorder_r(root);
            break;
    default :  printf("Enter the valid input");
            break;

    
}     
}  
     while (s!=5);
    return 0;
}