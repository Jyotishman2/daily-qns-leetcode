#include<iostream>
#include<bits/stdc++.h>

using namespace std; 
   class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<long long>> rowPrefix(n, vector<long long>(m));
        vector<vector<long long>> colPrefix(n, vector<long long>(m));

        // row prefix
        for (int i = 0; i < n; i++) {
            rowPrefix[i][0] = grid[i][0];
            for (int j = 1; j < m; j++) {
                rowPrefix[i][j] = rowPrefix[i][j - 1] + grid[i][j];
            }
        }

        // col prefix
        for (int j = 0; j < m; j++) {
            colPrefix[0][j] = grid[0][j];
            for (int i = 1; i < n; i++) {
                colPrefix[i][j] = colPrefix[i - 1][j] + grid[i][j];
            }
        }

        for (int side = min(n, m); side >= 2; side--) {
            for (int i = 0; i + side - 1 < n; i++) {
                for (int j = 0; j + side - 1 < m; j++) {

                    long long targetSum =
                        rowPrefix[i][j + side - 1] -
                        (j > 0 ? rowPrefix[i][j - 1] : 0);

                    bool allSame = true;

                    // rows
                    for (int r = i + 1; r < i + side; r++) {
                        long long rowSum =
                            rowPrefix[r][j + side - 1] -
                            (j > 0 ? rowPrefix[r][j - 1] : 0);
                        if (rowSum != targetSum) {
                            allSame = false;
                            break;
                        }
                    }
                    if (!allSame) continue;

                    // cols
                    for (int c = j; c < j + side; c++) {
                        long long colSum =
                            colPrefix[i + side - 1][c] -
                            (i > 0 ? colPrefix[i - 1][c] : 0);
                        if (colSum != targetSum) {
                            allSame = false;
                            break;
                        }
                    }
                    if (!allSame) continue;

                    // diagonals
                    long long diag = 0, anti = 0;
                    for (int k = 0; k < side; k++) {
                        diag += grid[i + k][j + k];
                        anti += grid[i + k][j + side - 1 - k];
                    }

                    if (diag == targetSum && anti == targetSum)
                        return side;
                }
            }
        }

        return 1;
    }
};
