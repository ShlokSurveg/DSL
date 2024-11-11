#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int q[SIZE];  // Regular queue
int f = -1;   // Front index
int r = -1;   // Rear index

// Function to check if the queue is full
int isFull() {
    return (r == SIZE - 1);
}

// Function to check if the queue is empty
int isEmpty() {
    return (r == f);
}

// Function to add an element to the queue
void AddQ() {
    int element;
    printf("Enter the element to add to the queue: ");
    scanf("%d", &element);
    if (isFull()) {
        printf("Queue is full\n");
    } else {
        r++;
        q[r] = element;
    }
}

// Function to delete an element from the queue
int DelQ() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1; // Indicating empty queue
    } else {
        f++;
        return q[f]; // Return the deleted element
    }
}

// Function to display the elements of the queue
void DisplayQ() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("The Queue after the operation is:\n");
        for (int j = f + 1; j <= r; j++) {
            printf("%d ", q[j]);
        }
        printf("\n");
    }
}

// Main function to drive the program
int main() {
    int choice;
    int cont;

    do {
        printf("Your choices are:\n");
        printf("Choice 1: Enqueue\n");
        printf("Choice 2: Dequeue\n");
        printf("Choice 3: Check if empty\n");
        printf("Choice 4: Check if full\n");
        printf("Choice 5: Display queue\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                AddQ();
                break;
            case 2:
                DelQ();
                break;
            case 3:
                if (isEmpty()) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 4:
                if (isFull()) {
                    printf("Queue is full\n");
                } else {
                    printf("Queue is not full\n");
                }
                break;
            case 5:
                DisplayQ();
                break;
            default:
                printf("Enter a valid choice\n");
        }

        printf("Do you want to continue? (1 for Yes, 0 for No): ");
        scanf("%d", &cont);
    } while (cont == 1);

    return 0;
}
