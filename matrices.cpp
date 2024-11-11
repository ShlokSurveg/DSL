#include <stdio.h>

void compactMatrix(int A[30][30], int B[30][30], int r, int c) {
    B[0][0] = r;
    B[0][1] = c;
    int k = 1;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (A[i][j] != 0) {
                B[k][0] = i - 1;
                B[k][1] = j - 1;
                B[k][2] = A[i][j];
                k++;
            }
        }
    }
    B[0][2] = k - 1;
}

void simpleTrans(int A[30][30], int B[30][30]) {
    int m = A[0][0];
    int n = A[0][1];
    int t = A[0][2];
    if (t == 0) {
        return;
    }
    B[0][0] = n;
    B[0][1] = m;
    B[0][2] = t;
    int q = 1;
    for (int col = 0; col < n; col++) {
        for (int p = 1; p <= t; p++) {
            if (A[p][1] == col) {
                B[q][0] = A[p][1];
                B[q][1] = A[p][0];
                B[q][2] = A[p][2];
                q++;
            }
        }
    }
}

void fastTrans(int A[30][30], int B[30][30]) {
    int m = A[0][0];
    int n = A[0][1];
    int t = A[0][2];
    if (t == 0) {
        return;
    }
    B[0][0] = n;
    B[0][1] = m;
    B[0][2] = t;
    int S[n];
    int T[n];
    for (int i = 0; i < n; i++) {
        S[i] = 0;
    }
    for (int i = 1; i <= t; i++) {
        S[A[i][1]]++;
    }
    T[0] = 1;
    for (int i = 1; i < n; i++) {
        T[i] = T[i - 1] + S[i - 1];
    }
    for (int i = 1; i <= t; i++) {
        int j = A[i][1];
        B[T[j]][0] = A[i][1];
        B[T[j]][1] = A[i][0];
        B[T[j]][2] = A[i][2];
        T[j]++;
    }
}

void accept(int A[30][30], int r, int c) {
    printf("Enter the elements of matrix A:\n");
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            printf("Enter element a[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
}

void displayOriginal(int A[30][30], int r, int c) {
    printf("Matrix A:\n");
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

void displayCompact(int B[30][30]) {
    int num_elements = B[0][2];
    printf("\nMatrix B after compacting:\n");
    printf("%d %d %d\n", B[0][0], B[0][1], num_elements);
    for (int i = 1; i <= num_elements; i++) {
        printf("%d %d %d\n", B[i][0], B[i][1], B[i][2]);
    }
}

void displaySimpleTransposed(int B[30][30]) {
    int num_elements = B[0][2];
    printf("%d %d %d\n", B[0][0], B[0][1], num_elements);
    for (int i = 1; i <= num_elements; i++) {
        printf("%d %d %d\n", B[i][0], B[i][1], B[i][2]);
    }
}

int main() {
    int r, c;
    int choice;
    int a[30][30], b[30][30], transposeMatrix[30][30];
    int continue_choice;
    do {
        printf("Enter the number of rows: ");
        scanf("%d", &r);
        printf("Enter the number of columns: ");
        scanf("%d", &c);
        
        for (int i = 0; i <= r; i++) {
            for (int j = 0; j <= c; j++) {
                a[i][j] = 0;
                b[i][j] = 0;
                transposeMatrix[i][j] = 0;
            }
        }

        accept(a, r, c);
        printf("\nEnter what function would you like to perform:\n");
        printf("1. Compact the matrix\n2. Simple transpose\n3. Fast transpose\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        displayOriginal(a, r, c);
        
        switch (choice) {
            case 1:
                compactMatrix(a, b, r, c);
                if (b[0][2] > 0) {
                    displayCompact(b);
                } else {
                    printf("\nNo non-zero elements found.\n");
                }
                break;
            case 2:
                compactMatrix(a, b, r, c);
                printf("Compacted matrix:\n");
                if (b[0][2] > 0) {
                    displayCompact(b);
                    printf("\nMatrix B after simple transpose:\n");
                    simpleTrans(b, transposeMatrix);
                    printf("Simple transpose result:\n");
                    if (transposeMatrix[0][2] > 0) {
                        displaySimpleTransposed(transposeMatrix);
                    } else {
                        printf("\nNo non-zero elements found in the transposed matrix.\n");
                    }
                } else {
                    printf("\nNo non-zero elements found in the original matrix.\n");
                }
                break;
            case 3:
                compactMatrix(a, b, r, c);
                printf("Compacted matrix:\n");
                if (b[0][2] > 0) {
                    displayCompact(b);
                    fastTrans(b, transposeMatrix);
                    printf("Fast transpose result:\n");
                    if (transposeMatrix[0][2] > 0) {
                        printf("\nMatrix B after Fast transpose:\n");
                        displaySimpleTransposed(transposeMatrix);
                    } else {
                        printf("\nNo non-zero elements found in the transposed matrix.\n");
                    }
                } else {
                    printf("\nNo non-zero elements found in the original matrix.\n");
                }
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        printf("\nDo you want to continue? (1 = yes, 0 = no): ");
        scanf("%d", &continue_choice);
    } while (continue_choice == 1);
    return 0;
}
