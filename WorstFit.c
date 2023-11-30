#include<stdio.h>

void worstFit(int blockSize[], int m, int processSize[], int n){
    int allocation[n];

    for(int i=0; i<n; i++){
        allocation[i] = -1;
    }

    for(int i=0; i<n; i++){
        int wstIdx = -1;
        for(int j=0; j<m; j++){
            if(blockSize[j] >= processSize[i]){
                if(wstIdx == -1 || blockSize[wstIdx] < blockSize[j]){
                    wstIdx = j;
                }
            }
        }
        if(wstIdx != -1){
            allocation[i] = wstIdx;
            blockSize[wstIdx] -= processSize[i];
        }
        
    }
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for(int i=0; i<n; i++){
        printf("%d\t\t%d\t\t", i+1, processSize[i]);

        (allocation[i] != -1) ? printf("%d",allocation[i] + 1): printf("Not Allocated");
        printf("\n");
    }
}

int main() {
    int m,n;
    printf("Enter the number of memory blocks: ");
    scanf("%d",&m);
    int blockSize[m];
    printf("Enter the size of memory blocks: ");
    for(int i=0; i<m; i++){
        printf("Block %d: ", i+1);
        scanf("%d", &blockSize[i]);
    }
    
    printf("Enter the number of processes: ");
    scanf("%d",&n);    
    int processSize[n];
    printf("Enter the size of process: ");
    for(int i=0; i<n; i++){
        printf("Process %d: ", i+1);
        scanf("%d", &processSize[i]);
    }
    worstFit(blockSize,m,processSize,n);
    
    return 0;
}