

#include <stdlib.h>

int** constructProductMatrix(int** grid, int gridSize, int* gridColSize,
                              int* returnSize, int** returnColumnSizes) {
    
    int n = gridSize;
    int m = gridColSize[0];
    int mod = 12345;

    int** ans = (int**)malloc(n * sizeof(int*));
    *returnSize = n;

    *returnColumnSizes = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        ans[i] = (int*)malloc(m * sizeof(int));
        (*returnColumnSizes)[i] = m;
    }

    long long pref = 1;
    long long suff = 1;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            ans[i][j] = pref;

            pref = (pref * grid[i][j]) % mod;
        }
    }


    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {

            ans[i][j] = (ans[i][j] * suff) % mod;

            suff = (suff * grid[i][j]) % mod;
        }
    }

    return ans;
}