#include <stdio.h>
#include <stdlib.h>

struct tbtnode {
    char data;
    int rbit, lbit;
    struct tbtnode *rightc;
    struct tbtnode *leftc;
};


void create(struct tbtnode *head) {
    struct tbtnode *root, *temp, *curr;
    char ch;
    int flag;

    root = (struct tbtnode*)malloc(sizeof(struct tbtnode));
    printf("Enter root data: ");
    scanf(" %c", &root->data);
    head->lbit = 1;
    root->leftc = root->rightc = head;
    root->lbit = root->rbit = 0;
    head->leftc = root;

    do {
        flag = 0;
        temp = root;
        curr = (struct tbtnode*)malloc(sizeof(struct tbtnode));
        printf("Enter node data: ");
        scanf(" %c", &curr->data);
        curr->lbit = curr->rbit = 0;

        while(flag == 0) {
            char ch1;
            printf("Enter 'l' for left or 'r' for right of %c: ", temp->data);
            scanf(" %c", &ch1);

            if(ch1 == 'l') {
                if(temp->lbit == 0) {
                    curr->rightc = temp;
                    curr->leftc = temp->leftc;
                    temp->leftc = curr;
                    temp->lbit = 1;
                    flag = 1;
                } else {
                    temp = temp->leftc;
                }
            }

            if(ch1 == 'r') {
                if(temp->rbit == 0) {
                    curr->leftc = temp;
                    curr->rightc = temp->rightc;
                    temp->rightc = curr;
                    temp->rbit = 1;
                    flag = 1;
                } else {
                    temp = temp->rightc;
                }
            }
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &ch);
    } while(ch == 'y');
}

struct tbtnode* inordersucc(struct tbtnode *temp) {
    struct tbtnode *x = temp->rightc;
    if(temp->rbit == 1) {
        while(x->lbit == 1)
            x = x->leftc;
    }
    return x;
}

void inorder(struct tbtnode *head) {
    struct tbtnode *temp = head;
    while(1) {
        temp = inordersucc(temp);
        if(temp == head) break;
        printf("%c ", temp->data);
    }
}

void preorder(struct tbtnode *head) {
    struct tbtnode *temp = head->leftc;
    while(temp != head) {
        printf("%c ", temp->data);
        while(temp->lbit != 0) {
            temp = temp->leftc;
            printf("%c ", temp->data);
        }
        while(temp->rbit == 0)
            temp = temp->rightc;
        temp = temp->rightc;
    }
}

int main() {
    struct tbtnode *head;
    int choice;

    do {

        printf("1. Create to Tree\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                head = (struct tbtnode*)malloc(sizeof(struct tbtnode));
                head->rbit = 1;
                head->lbit = 0;
                head->leftc = head->rightc = head;
                create(head);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(head);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder(head);
                printf("\n");
                break;
            case 4:
                printf("BYE\n");
                break;

            default:
                printf("Enter a valid option\n");
                break;
    }

    } while (choice != 3);
    return 0;
}