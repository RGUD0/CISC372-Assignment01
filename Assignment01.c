#include <stdio.h>
#include <stdlib.h>

#define N 5
#define M 6

void matrixArrayOfArrays(int n, int m);
void matrixOneBigArray(int n, int m);


int main(int argc,char** argv){ 
     matrixArrayOfArrays(N,M); 
     matrixOneBigArray(N,M); 
     return 0; 
} 

void matrixArrayOfArrays(int n, int m) {
    // Allocate memory for an array of pointers to float arrays
    float **arr = (float **)malloc(m * sizeof(float *));
    if (arr == NULL) {
        printf("Error: Could not allocate memory.\n");
        return;
    }

    // Allocate memory for each float array
    for (int i = 0; i < m; i++) {
        arr[i] = (float *)malloc(n * sizeof(float));
        if (arr[i] == NULL) {
            printf("Error: Could not allocate memory.\n");
            // Free memory for previously allocated float arrays
            for (int j = 0; j < i; j++) {
                free(arr[j]);
            }
            // Free memory for the array of pointers
            free(arr);
            return;
        }
    }

    // Fill the array with numbers
    int num = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = num++;
        }
    }

    // Print the array as a matrix
    printf("Array:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.0f\t", arr[i][j]);
        }
        printf("\n");
    }

    // Print the array transposed
    printf("Array transposed:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.0f\t", arr[j][i]);
        }
        printf("\n");
    }

    // Free memory for float arrays
    for (int i = 0; i < m; i++) {
        free(arr[i]);
    }
    // Free memory for the array of pointers
    free(arr);
}

void matrixOneBigArray(int n, int m) {
    float** matrix = (float**) malloc(m * sizeof(float*));
    float* data = (float*) malloc(n * m * sizeof(float));

    // Set each pointer in matrix to the corresponding row in data
    for (int i = 0; i < m; i++) {
        matrix[i] = &data[i * n];
    }

    // Fill the array with numbers 1 to n*m
    int count = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = count;
            count++;
        }
    }

    // Print the matrix
    printf("Matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%-8.2f ", matrix[i][j]);
        }
        printf("\n");
    }

    // Print the matrix transposed
    printf("Transposed matrix:\n");
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            printf("%-8.2f ", matrix[i][j]);
        }
        printf("\n");
    }

    // Deallocate memory
    free(matrix);
    free(data);
}