#include <stdlib.h>

/*
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *returnColumnSizes array must be malloced,
 *       assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    if (numRows <= 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    *returnSize = numRows;
    // allocate array of pointers to rows
    int** res = (int**)malloc(numRows * sizeof(int*));
    // allocate column sizes array
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    for (int i = 0; i < numRows; ++i) {
        int cols = i + 1;
        (*returnColumnSizes)[i] = cols;
        res[i] = (int*)malloc(cols * sizeof(int));

        // first and last elements are 1
        res[i][0] = 1;
        res[i][cols - 1] = 1;

        // fill middle values using previous row
        if (i >= 2) {
            for (int j = 1; j < cols - 1; ++j) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        } else if (i == 1) {
            // second row is [1,1] - already set by assignments above
            // nothing else to do
        }
    }

    return res;
}
