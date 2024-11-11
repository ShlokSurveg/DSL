#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int top = -1;
int size = 10;

struct node *stack[10];

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
        return 0;
}

int isfull()
{
    if (top == size - 1)
    {
        return 1;
    }
    else
        return 0;
}

void push(struct node *ch)
{
    if (!isfull())
    {
        top = top + 1;
        stack[top] = ch;
    }
}

struct node *pop()
{
    if (!isEmpty())
    {
        struct node *temp = stack[top];
        top = top - 1;
        return (temp);
    }
}

void create_nr(struct node *root)
{
    int flag = 0;
    char choice = 'y';
    struct node *temp;

    do
    {
        temp = root;
        flag = 0;
        struct node *curr;
        curr = (struct node *)malloc(sizeof(struct node));
        curr->left = NULL;
        curr->right = NULL;
        printf("Enter data:\n");
        scanf("%d", &curr->data);

        while (flag == 0)
        {
            int ch;
            printf("Do you want to add a node to what position of %d?\n1. Left\n2. Right\n", temp->data);
            scanf("%d", &ch);

            if (ch == 1)
            {
                if (temp->left == NULL)
                {
                    temp->left = curr;
                    flag = 1;
                }
                temp = temp->left;
            }
            else if (ch == 2)
            {
                if (temp->right == NULL)
                {
                    temp->right = curr;
                    flag = 1;
                }
                temp = temp->right;
            }
            else
            {
                printf("Invalid choice!\n");
            }
        }

        printf("Do you want to continue adding nodes? (y/n)\n");
        scanf(" %c", &choice);
    } while (choice == 'y');
}

void inorder_nr(struct node *root)
{
    struct node *temp;
    temp = root;

    while (1)
    {
        while (temp != NULL)
        {
            push(temp);
            temp = temp->left;
        }
        if (isEmpty())
        {
            break;
        }
        temp = pop();
        printf("%d \t", temp->data);
        temp = temp->right;
    }
}

void preorder_nr(struct node *root)
{
    struct node *temp;
    temp = root;
    while (1)
    {
        while (temp != NULL)
        {
            printf("%d \t", temp->data);
            push(temp);
            temp = temp->left;
        }
        if (isEmpty())
        {
            break;
        }
        temp = pop();
        temp = temp->right;
    }
}

void postorder_nr(struct node *root)
{
    struct node *temp;
    temp = root;
    while (1)
    {
        while (temp != NULL)
        {
            push(temp);
            temp = temp->left;
        }
        if (stack[top]->right == NULL)
        {
            temp = pop();
            printf("%d \t", temp->data);
        }
        while (!isEmpty() && stack[top]->right == temp)
        {
            temp = pop();
            printf("%d \t", temp->data);
        }
        if (isEmpty())
        {
            break;
        }
        temp = stack[top]->right;
    }
}
int main()
{
    int s;
    struct node *root;
    root = (struct node *)malloc(sizeof(struct node));

    printf("Enter the data for the root:\n");
    scanf("%d", &root->data);

    root->left = NULL;
    root->right = NULL;

    do
    {
        printf("\n\n1. Create\n");
        printf("2. Display Inorder\n");
        printf("3. Display Preorder\n");
        printf("4. Display Postorder\n");

        scanf("%d", &s);
        switch (s)
        {
        case 1:
            create_nr(root);
            break;
        case 2:
            printf("Inorder Traversal:\n");
            inorder_nr(root);
            break;

        case 3:
            printf("\nPreorder Traversal:\n");
            preorder_nr(root);
            break;

        case 4:
            printf("\nPostorder Traversal:\n");
            postorder_nr(root);
            break;
        default:
            printf("Enter the valid input");
            break;
        }

    } while (s != 5);

    return 0;
}