#include <stdio.h>
#include <stdlib.h>

struct Node {
    char name[100];
    int prn;
    struct Node *next;
};

void createl(struct Node *H) {
    struct Node *temp = H;
    struct Node *curr;
    int choice;
    int count = 0; 

    do {
        curr = (struct Node *)malloc(sizeof(struct Node));
        printf("\nEnter the PRN of the member:\n");
        scanf("%d", &curr->prn);
        printf("\nEnter the name of the member:\n");
        scanf("%s", curr->name);
        curr->next = NULL;

        if (count == 0) {
            printf("\nPresident.\n");
        }

        temp->next = curr;
        temp = curr;
        count++;

        printf("\nDo you want to add another member? (1 for Yes, 0 for No):\n");
        scanf("%d", &choice);
    } while (choice == 1);

    printf("\nSecretary.\n");
}

int length(struct Node *H) {
    int i = 0;
    struct Node *curr = H->next;
    while (curr != NULL) {
        i++;
        curr = curr->next;
    }
    return i;
}

void display(struct Node *H) {
    struct Node *curr = H->next; 
    if (curr == NULL) {
        printf("\nList is empty:\n");
    } else {
        printf("\nThe Linked list:\n");
        int pos = 1;
        int len = length(H);

        while (curr != NULL) {
            if (pos == 1) {
                printf("President: \tCurrent: %d\tPRN: %d\tName: %s\tNext: %d\n",
                        curr, curr->prn, curr->name, curr->next);
            } else if (pos == len) {
                printf("Secretary: \tCurrent: %d\tPRN: %d\tName: %s\tNext: %d\n",
                        curr, curr->prn, curr->name, curr->next);
            } else {
                printf("Member: \tCurrent: %d\tPRN: %d\tName: %s\tNext: %d\n",
                        curr, curr->prn, curr->name, curr->next);
            }
            curr = curr->next;
            pos++;
        }
    }
}

void Insertbypos(struct Node *H) {
    int i = 1, pos;
    struct Node *nnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *curr = H;

    printf("\nEnter the position:\n");
    scanf("%d", &pos);
    printf("\nEnter the new PRN:\n");
    scanf("%d", &nnode->prn);
    printf("\nEnter the new name:\n");
    scanf("%s", nnode->name);
    int k = length(H);
    if (pos < 1 || pos > k + 1) {
        printf("\nPRN can't be inserted at this position\n");
    } else {
        while (curr != NULL && i < pos) {
            i++;
            curr = curr->next;
        }
        nnode->next = curr->next;
        curr->next = nnode;
    }
}

void Deletebypos(struct Node *H) {
    int i = 1, pos;
    struct Node *curr = H;
    struct Node *prev = NULL;

    printf("\nEnter the position to delete:\n");
    scanf("%d", &pos);

    int k = length(H);
    if (pos < 1 || pos > k) {
        printf("\nInvalid position\n");
        return;
    }

    
    if (pos == 1) {
        struct Node *nodeToDelete = curr->next;
        if (nodeToDelete != NULL) {
            curr->next = nodeToDelete->next;
            free(nodeToDelete);
            printf("\nNode deleted successfully.\n");
        } else {
            printf("\nNo node to delete.\n");
        }
        return;
    }

   
    while (i < pos && curr->next != NULL) {
        prev = curr;
        curr = curr->next;
        i++;
    }

    if (curr->next != NULL) {
        prev->next = curr->next;
        free(curr);
        printf("\nNode deleted successfully.\n");
    } else {
        printf("\nNo node to delete.\n");
    }
}

void Reverse(struct Node *H) {
    struct Node *prev = NULL;
    struct Node *curr = H->next;
    struct Node *next = NULL;

    while (curr != NULL) {
        next = curr->next; 
        curr->next = prev; 
        prev = curr;       
        curr = next;
    }
    H->next = prev;
}

void Sort(struct Node *H) {
    int len = length(H);

    for (int i = 1; i < len; i++) {
        struct Node *prev = H;
        struct Node *curr = H->next;
        
        for (int j = 1; j < len - i; j++) {
            struct Node *temp = curr->next;
            if (curr->prn > temp->prn) {
                prev->next = temp;
                curr->next = temp->next;
                temp->next = curr;
                prev = temp;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }
}

void Merge(struct Node *H1, struct Node *H2) {
    struct Node *temp;
    struct Node *curr1 = H1->next;
    struct Node *curr2 = H2->next;
    struct Node *mergedHead = NULL;
    struct Node *mergedTail = NULL;

   
    if (curr1 == NULL) {
        mergedHead = curr2;
    } else if (curr2 == NULL) {
        mergedHead = curr1;
    } else if (curr1->prn < curr2->prn) {
        mergedHead = curr1;
        curr1 = curr1->next;
    } else {
        mergedHead = curr2;
        curr2 = curr2->next;
    }
    
    mergedTail = mergedHead;

   
    while (curr1 != NULL && curr2 != NULL) {
        if (curr1->prn < curr2->prn) {
            mergedTail->next = curr1;
            curr1 = curr1->next;
        } else {
            mergedTail->next = curr2;
            curr2 = curr2->next;
        }
        mergedTail = mergedTail->next;
    }

    
    if (curr1 != NULL) {
        mergedTail->next = curr1;
    } else {
        mergedTail->next = curr2;
    }

    
    H1->next = mergedHead;

    
    free(H2);

    
    display(H1);
}

int main() {
    int y;
    int choice;
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->next = NULL;
    struct Node *head1 = (struct Node *)malloc(sizeof(struct Node));
    head1->next = NULL;

    while (1) {
        printf("\nMenu:\n 1) Create linked list\n 2) Display linked list\n 3) Length of list\n 4) Insertion\n 5) Deletion\n 6) Reverse\n7) Sort\n8) Merge\n 9) Exit\n");
        printf("\nEnter your choice:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createl(head);
                break;
            case 2:
                display(head);
                break;
            case 3: 
                y = length(head);
                printf("\nThe length of the list is %d\n", y);
                break;
            case 4:
                Insertbypos(head);
                break;
            case 5:
                Deletebypos(head);
                break;
            case 6:
                Reverse(head);
                break;
            case 7:
                Sort(head);
                break;
            case 8:
                printf("\nPlease input for another linked list:\n");
                createl(head1);
                display(head1);
                Sort(head);
                printf("\nThe sorted 1st linked list is:\n");
                display(head);
                Sort(head1);
                printf("\nThe sorted 2nd linked list is:\n");
                display(head1);
                printf("\nMerging the two linked lists:\n");
                Merge(head, head1);
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Invalid Input!\n");
                break;
        }
    }

    return 0;
}
