#include <stdio.h>

int main() {
    int i, j, n, m, k, avail = 0;
    printf("enter the no of processes\n");
    scanf("%d", &n);
    printf("enter the no of resources\n");
    scanf("%d", &m);

    int alloc[n][m];
    int max[n][m];

    printf("enter the allocation matrix");
    for (int i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("enter the max matrix");
    for (int i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("enter the available resources");
    for (j = 0; j < m; j++) {
        scanf("%d", &avail);
    }

    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }

    int need[n][m];
    for (int i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int y = 0;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++) {
                        avail += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (f[i] == 0) {
            flag = 0;
            printf(" not safe sequence\n");
            break;
        }
    }

    if (flag == 1) {
        printf("safe system\n");
        for (i = 0; i < n; i++) {
            printf("P%d ", ans[i]);
        }
    }

    return 0;
}
