class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2, 0));

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                int maxi = INT_MIN;
                for (int row = i; row < 3 + i; row++) {
                    for (int col = j; col < 3 + j; col++) {
                        maxi = max(maxi, grid[row][col]);
                    }
                }

                ans[i][j] = maxi;
            }
        }

        return ans;
    }
};