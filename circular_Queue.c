#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int cq[SIZE]; // Circular queue
int f = -1;   // Front index
int r = -1;   // Rear index

// Function to check if the circular queue is full
int isFull() {
    return ((r + 1) % SIZE == f);
}

// Function to check if the circular queue is empty
int isEmpty() {
    return (f == r);
}

// Function to add an element to the circular queue
void AddCQ() {
    int element;
    printf("Enter the element to add to the circular queue: ");
    scanf("%d", &element);
    if (isFull()) {
        printf("Circular Queue is full\n");
    } else {
        r = (r + 1) % SIZE;
        cq[r] = element;
    }
}

// Function to delete an element from the circular queue
int DelCQ() {
    if (isEmpty()) {
        printf("Circular Queue is empty\n");
        return -1; // Indicating empty queue
    } else {
        f = (f + 1) % SIZE;
        return cq[f]; // Return the deleted element
    }
}

// Function to display the elements of the circular queue
void DisplayCQ() {
    if (isEmpty()) {
        printf("Circular Queue is empty\n");
    } else {
        printf("Circular Queue: ");
        for (int j = (f + 1) % SIZE; j != (r + 1) % SIZE; j = (j + 1) % SIZE) {
            printf("%d\t", cq[j]);
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
        printf("Choice 5: Display circular queue\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                AddCQ();
                break;
            case 2:
                DelCQ();
                break;
            case 3:
                if (isEmpty()) {
                    printf("Circular queue is empty\n");
                } else {
                    printf("Circular queue is not empty\n");
                }
                break;
            case 4:
                if (isFull()) {
                    printf("Circular queue is full\n");
                } else {
                    printf("Circular queue is not full\n");
                }
                break;
            case 5:
                DisplayCQ();
                break;
            default:
                printf("Enter a valid choice\n");
        }

        printf("Do you want to continue? (1 for Yes, 0 for No): ");
        scanf("%d", &cont);
    } while (cont == 1);

    return 0;
}
