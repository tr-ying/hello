#include <stdio.h>
#include <string.h>

void nextFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n], j = 0;
    memset(allocation, -1, sizeof(allocation));

    for (int i = 0; i < n; i++) {
        while (j < m) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                j = (j + 1) % m;
                break;
            }
            j = (j + 1) % m; 
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);

        (allocation[i] != -1) ? printf("%d", allocation[i] + 1) : printf("Not Allocated");
        printf("\n");
    }
}

int main() {
    int m, n;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    int blockSize[m];
    printf("Enter the size of memory blocks: ");
    for (int i = 0; i < m; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processSize[n];
    printf("Enter the size of process: ");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }
    nextFit(blockSize, m, processSize, n);

    return 0;
}
