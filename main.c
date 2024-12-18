#include <stdio.h>
#include <stdlib.h>

void tranverseLapisTerluar(int** matrix, int size, int offset, int* result) {
    int index = 0;

    for (int i = offset; i < size - offset; i++) {
        result[index++] = matrix[offset][i];
    }

    for (int i = offset + 1; i < size - offset; i++) {
        result[index++] = matrix[i][size - offset - 1];
    }

    for (int i = size - offset - 2; i >= offset; i--) {
        result[index++] = matrix[size - offset - 1][i];
    }

    for (int i = size - offset - 2; i > offset; i--) {
        result[index++] = matrix[i][offset];
    }
}

int countRemainingElements(int size, int offset) {
    int newSize = size - 2 * offset;
    if (newSize <= 2) {
        return 0;
    }
    int totalElements = newSize * newSize;
    int outerLayerElements = (4 * newSize) - 4;
    return totalElements - outerLayerElements;
}

void rotateAndPrintLayers(int** matrix, int size) {
    int offset = 0;
    while (size - 2 * offset > 1) {
        int banyakElemen = (4 * (size - 2 * offset)) - 4;
        int* tm = malloc(sizeof(int) * banyakElemen);

        tranverseLapisTerluar(matrix, size, offset, tm);
        
        printf("Lapisan ke-%d", offset + 1);
        printf("Lapisan ukuran %d:\n", size - 2 * offset);
        for (int i = 0; i < banyakElemen; i++) {
            printf("%d ", tm[i]);
        }
        printf("\n");

        int remainingElements = countRemainingElements(size, offset);
        printf("Sisa elemen setelah lapisan ukuran %d: %d\n", size - 2 * offset, remainingElements);

        offset++;

        free(tm);
    }
}

int main() {
    int size = 6;

    int** matrix = malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix[i] = malloc(size * sizeof(int));
    }

    int count = 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = count++;
        }
    }

    printf("Matriks:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }

    rotateAndPrintLayers(matrix, size);

    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
