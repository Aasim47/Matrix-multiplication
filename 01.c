#include <stdio.h>

void inputMatrix(int rows, int cols, int matrix[rows][cols], char name) {
    printf("Enter elements of matrix %c (%dx%d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c[%d][%d]: ", name, i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
    }
}

void multiplyMatrices(int m, int n, int p, int A[m][n], int B[n][p], int C[m][p]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transposeMatrix(int rows, int cols, int matrix[rows][cols], int transposed[cols][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m, n, p;

    // Input dimensions
    printf("Enter dimensions of matrix A (m x n): ");
    scanf("%d%d", &m, &n);
    printf("Enter dimensions of matrix B (n x p): ");
    scanf("%d%d", &n, &p);

    int A[m][n], B[n][p], C[m][p], T[p][m];

    // Input matrices
    inputMatrix(m, n, A, 'A');
    inputMatrix(n, p, B, 'B');

    // Multiply matrices
    multiplyMatrices(m, n, p, A, B, C);
    printf("Product matrix C (A x B):\n");
    printMatrix(m, p, C);

    // Transpose of resultant matrix
    transposeMatrix(m, p, C, T);
    printf("Transpose of the resultant matrix:\n");
    printMatrix(p, m, T);

    return 0;
}
