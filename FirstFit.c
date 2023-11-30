#include<stdio.h>

void firstfit(){
    int m,n;
    printf("Enter the number of blocks: ");
    scanf("%d",&n);
    printf("Enter the number of processes: ");
    scanf("%d",&m);

    int blockSize[m], processSize[n], allocation[n];
    printf("Enter the size of each block separated by spaces: ");
    for(int i=0; i<m; i++){
        scanf("%d", &blockSize[i]);
    }
    printf("Enter the size of each process separated by spaces: ");
    for(int i=0; i<n; i++){
        scanf("%d", &processSize[i]);
        allocation[i] = -1;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j < m; j++){
            if(blockSize[j] >= processSize[i]){
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for(int i=0; i<n; i++){
        printf("%d\t\t\t", i+1);
        printf("%d\t\t\t\t", processSize[i]);
        
        if(allocation[i] != -1){
            printf("%d",allocation[i] + 1);
        }
        else{
            printf("Not Allocated");
        }
        printf("\n");
    }
}

int main() {
    firstfit();

    return 0;
}