#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int front = -1;
int rear = -1;
struct BST* q[SIZE];
struct BST *stack[SIZE];
int top = -1;

struct BST {
    char word[10];
    char meaning[10];
    struct BST* left;
    struct BST* right;
};

int isFull() {
    return rear == SIZE - 1;
}

int isEmpty() {
    return rear == front;
}

void Addq(struct BST* elem) {
    if (isFull()) {
        printf("\nQueue is Full:\n");
    } else {
        rear++;
        q[rear] = elem;
    }
}

struct BST* Deleteq() {
    if (isEmpty()) {
        printf("\nQueue is Empty:\n");
        return NULL;
    } else {
        front++;
        return q[front];
    }
}

void DisplayQueue() {
    if (isEmpty()) {
        printf("\nQueue is empty\n");
    } else {
        printf("\nThe elements of the queue are:\n");
        for (int i = front + 1; i <= rear; i++) {
            printf("%s\t", q[i]->word);
        }
        printf("\n");
    }
}

int isStackFull() {
   if(top== SIZE-1)
   {
    return 1;
   }
   else{
    return 0;
   }
}

int isStackEmpty() {
    if(top==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct BST* temp) {
    if (isStackFull()) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = temp;
    }
}

struct BST *pop() {
    if (isStackEmpty()) {
        printf("Stack underflow\n");
        return NULL;
    } else {
        return stack[top--];
    }
}

void create(struct BST* R) {
    struct BST *temp;
    struct BST *curr;
    char cont_choice;

    do {
        temp = R;
        int flag = 0;
        curr = (struct BST*)malloc(sizeof(struct BST));

        printf("\nEnter the word to be added:\n");
        scanf("%s", curr->word);
        curr->left = NULL;
        curr->right = NULL;

        while (flag == 0) {
            if (strcmp(curr->word, temp->word) < 0) {
                if (temp->left == NULL) {
                    temp->left = curr;
                    flag = 1;
                } else {
                    temp = temp->left;
                }
            } else {
                if (temp->right == NULL) {
                    temp->right = curr;
                    flag = 1;
                } else {
                    temp = temp->right;
                }
            }
        }

        printf("\nDo you want to add more nodes? (y/n): ");
        scanf(" %c", &cont_choice);

    } while (cont_choice == 'y');
}

void inorder(struct BST* R) {
    if (R != NULL) {
        inorder(R->left);
        printf("%s\t", R->word);
        inorder(R->right);
    }
}

void BFS(struct BST *R)
{
    if(R==NULL) return;
    int p =1, r=0;
    struct BST *temp = R;
    front = rear= -1;
    Addq(R);
    while(!isEmpty())
    {
        for(int i =0; i<p;i++)
        {
            temp = Deleteq();
            printf("%s\t", temp->word);
            if(temp->left!=NULL)
            {
                Addq(temp->left);
                r++;
            }
            if(temp->right!=NULL)
            {
                Addq(temp->right);
                r++;
            }
        }
        printf("\n");
        p=r;
        r=0;
    }
}

int mirror_r(struct BST *R)
{
  if(R != NULL){
   struct BST *temp =  R->left;
   R->left = R->right;
   R->right = temp;
   mirror_r(R->left);
   mirror_r(R->right);
  }
   }

struct BST *copy_r(struct BST *R) {
    struct BST *temp = NULL;
    if (R != NULL) {
        temp = (struct BST*)malloc(sizeof(struct BST));
        strcpy(temp->word, R->word);
        temp->left = copy_r(R->left);
        temp->right = copy_r(R->right);
    }
    return temp;
}

struct BST *copy_nr(struct BST *R2) {
   struct BST *R1 = (struct BST*)malloc(sizeof(struct BST));
    strcpy(R1->word, R2->word);
    R1->left = NULL;
    R1->right = NULL;

    struct BST *temp1 = R1;
    struct BST *temp2 = R2;

    while (1) {
        
        while (temp2 != NULL) {
            
            if (temp2->left != NULL) {
                temp1->left = (struct BST*)malloc(sizeof(struct BST));
                strcpy(temp1->left->word, temp2->left->word);
                temp1->left->left = NULL;
                temp1->left->right = NULL;
            }
            
            if (temp2->right != NULL) {
                temp1->right = (struct BST*)malloc(sizeof(struct BST));
                strcpy(temp1->right->word, temp2->right->word);
                temp1->right->left = NULL;
                temp1->right->right = NULL;
            }

            
            push(temp1);
            push(temp2);
            temp1 = temp1->left;
            temp2 = temp2->left;
        }

        
        if (isStackEmpty()) {
            break;
        }

    
        temp2 = pop();
        temp1 = pop();
        temp1 = temp1->right;
        temp2 = temp2->right;
    }

    return R1;
}

struct BST *delete_nr(struct BST* R) {
    char str[10];
    struct BST *parent = NULL;
    struct BST *temp = R;
    struct BST *curr = NULL;
    struct BST *currp = NULL;
    int flag = 0;

    printf("\nEnter the word to be deleted:\n");
    scanf("%s", str);

    while (temp != NULL) {
        if (strcmp(str, temp->word) == 0) {
            flag = 1;
            break;
        } else {
            parent = temp;
            if (strcmp(str, temp->word) < 0) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
    }

    if (flag == 0) {
        printf("\nWord not found.\n");
        return R; 
    }

    if (temp->left == NULL && temp->right == NULL) {
        if (temp == R) { 
            free(temp);
            return NULL;
        } else if (parent->left == temp) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        free(temp);
    } else if (temp->left == NULL || temp->right == NULL) {
        struct BST* child = (temp->left != NULL) ? temp->left : temp->right;
        if (temp == R) { 
            free(temp);
            return child;
        } else if (parent->left == temp) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        free(temp);
    } else {
        currp = temp;
        curr = temp->right;

        while (curr->left != NULL) {
            currp = curr;
            curr = curr->left;
        }

        strcpy(temp->word, curr->word);

        if (currp == temp) {
            currp->right = curr->right;
        } else {
            currp->left = curr->right;
        }
        free(curr);
    }

    return R;
}

int main() {
    struct BST* root = (struct BST*)malloc(sizeof(struct BST));
    root->left = NULL;
    root->right = NULL;
  
    char key[10];

    int choice;
    struct BST* copied_tree = NULL;

    while (1) {
        printf("\nMenu:\n");
        printf("1) Create BST\n");
        printf("2) Display inorder\n");
        printf("3) BFS\n");
        printf("4) Copy of BST recursive\n");
        printf("5) Mirror of BST at specific depth\n");
        printf("6) Copy BST non-recursive\n");
        printf("7) Delete node in BST\n");
        printf("8) Exit\n");

        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the word for the root:\n");
                scanf("%s", key);
                strcpy(root->word, key);
                create(root);
                break;

            case 2:
                printf("\nThe inorder traversal of the tree is:\n");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("\nThe level order traversal of the tree is:\n");
                BFS(root);
                printf("\n");
                break;

            case 4:
                copied_tree = copy_r(root);
                BFS(root);
                printf("\n");
                break;

            case 5:
                mirror_r(root);
                BFS(root);
                printf("\n");
                break;

            case 6:
              copied_tree = copy_nr(root);
                BFS(copied_tree);
                printf("\n");
                break;

            case 7:
                root = delete_nr(root);
                printf("\nNode successfully deleted.\n");
                break;

            case 8:
                exit(0);
                break;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
